#include <cstdio>
#include <cstring>

//부모 클래스
class  Animal {
    public :
        int legs;
        char name[50];

        Animal(int legs, const char* name){
            printf("Animal!!\n");
            this->legs = legs;
            strcpy(this->name, name);
        }

        void printAnimalInfo(){
            printf("다리의 갯수 : %d\n", legs);
            printf("이름 : %s\n", name);
        }


};

class Dog : public Animal {
    public:
        Dog() : Animal(4, "강아지"){
            printf("Dog!!!\n");
        }
};


//자식 클래스
class Person : public Animal{
    public :
        char regist_no[30];

        Person(const char* regist_no) : Animal(2, "사람"){
            printf("Person!!\n");
            strcpy(this->regist_no, regist_no);
        }
};

int main(){

    Person* p = new Person("96032322222");
    p->printAnimalInfo();
    
    Dog* d = new Dog();
    d->printAnimalInfo();

    return 0;
}