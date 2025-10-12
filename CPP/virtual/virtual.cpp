#include <cstdio>
#include <cstring>

//부모 클래스
class  Animal {
    public :
        int legs;
        char* name;

        Animal(int legs, const char* name){
            this->legs = legs;
            this->name = new char[strlen(name)+1];
            strcpy(this->name, name);
        }
        
        virtual ~Animal(){
            printf("Animal 소멸자 호출!\n");
            delete[] name;
        }

        virtual void printInfo(){
            printf("다리의 갯수 : %d\n", legs);
            printf("이름 : %s\n", name);
        }


};

//자식 클래스
class Person : public Animal{
    public :
        char* regist_no;

        Person(const char* regist_no) : Animal(2, "사람"){
            this->regist_no = new char[strlen(regist_no)+1];
            strcpy(this->regist_no, regist_no);
        }

        ~Person(){
            printf("사람 소멸자 호출!\n");
            delete[] regist_no;
        }

        virtual void printInfo(){
            printf("이름 : %s, 주민등록번호 : %s", name, regist_no);
        }
};

int main(){

    
    Animal* animal = new Person("1234-5678");
    delete animal;

    return 0;
}