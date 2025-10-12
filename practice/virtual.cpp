#include <cstdio>
#include <cstdlib>
#include <cstring>

class Animal{
    public:
        int legs;
        char* name;

        Animal(int legs, char* name){
            this->legs = legs;
            this->name = new char[strlen(name)+1];
            strcpy(this->name, name);
        }

        virtual ~Animal(){
            delete[] name;
        }

        virtual PrintInfo(){
            printf("동물 이름 : %s, 다리 개수 : %d\n", this->name, this->legs);
        }


};

class Person : public Animal{
    public:
        char* number;
        
        Person(char* number) : Animal(2, "사람"){
            this->number = new char[strlen(number)+1];
            strcpy(this->number, number);
        }

        ~Person(){
            delete[] number;
        }

        virtual PrintInfo(){
            printf("핸드폰번호 : %s\n",number );
        }
};

int main(){
    Animal* p = new Person("010-1234-5678");
    p->PrintInfo();

    delete p;

    return 0;
}