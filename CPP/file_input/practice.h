#ifndef __HEADER_H__
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>

int getIntser(const char* prompt);
std::string getString(const char* prompt);

class Student{
    public :
        std::string name;
        int korean;
        int math;
        int eng;


        Student(std::string name, int korean, int math, int eng);
        void printInfo();

};

#endif