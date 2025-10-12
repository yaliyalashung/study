#include <cstdio>
#include <cstring>
#include <cmath>

enum Gender{
    MALE, FEMALE
};

class Student{
    public:
    int student_no;
    char name[20];
    Gender gender;

    Student(const char* name, int number, Gender gender){
        strcpy(this->name, name);
        this->student_no = number;
        this->gender = gender;
    }

    void printInfo(){
        printf("%s 학생의 번호는 %d이며 성별은 %s 입니다.\n", name, student_no, gender == Gender::MALE? "남성" : "여성");
    }
};

int main(){

    Student* student = new Student("효진", 422, Gender::MALE);
    student->printInfo();
    
    return 0;
}