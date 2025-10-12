#ifndef __PERSON_H__
#define __PERSON_H__

#include "Animal.h"

class Person : public Animal {
    public :
        char regist_no[50];
        Person(const char* regist_no, const char* person_name) : Animal(2, person_name){
            strcpy(this->regist_no, regist_no);
        }

        void printInfo(){
            printf("사람 이름 : %s, 주민등록번호 : %s\n", name, regist_no);
        }
};

#endif