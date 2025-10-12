#include <cstdio>
#include <cstring>

enum class Time{
    Morning, Afternoon, Night
};

class  Animal {
    public :
        char name[50];

        Animal(const char* name){
            strcpy(this->name, name);
        }

        virtual int getLegs() = 0;

        void printAnimalInfo(){
            printf("이름 : %s, 다리의 갯수 : %d\n", name , getLegs());
        }


};

class Person : public Animal{
    private :
        Time time = Time::Morning;
    public :

        Person(const char* name) : Animal(name) {}

        virtual int getLegs(){
            switch(time){
                case Time::Morning: return 4;
                case Time::Afternoon: return 2;
                case Time::Night: return 3;
            }
            return 2;
        }

        void setTime(Time t){
            this->time = t;
        }
};

class Dog : public Animal{
    public :

        Dog() : Animal("개"){}

        virtual int getLegs(){
            return 4;
        }

};

int main(){

    Person* p = new Person("영희");
    p->setTime(Time::Night);
    p->printAnimalInfo();

    Dog* d = new Dog();
    d->printAnimalInfo();

    return 0;
}