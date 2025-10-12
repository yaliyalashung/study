#ifndef __AINIMAL_H__
#define __AINIMAL_H__


#include "main_header.h"

class Animal{
    public :
        int legs;
        char name[50];

        Animal(int legs, const char* name){
            this->legs = legs;
            strcpy(this->name, name);
        }

        void printInfo(){
            printf("동물의 이름 : %s, 다리 개수 : %d\n", name, legs);
        }
};

#endif