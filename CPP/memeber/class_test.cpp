#include <cstdio>
#include <cstring>

class Student {

    public: 

        int student_no;
        char* name;
        int gender; // 0=남자 / 1=여자

        Student(int pStdNo, const char * n, int g){
            student_no = pStdNo;
            name = new char[strlen(n) + 1];
            strcpy(name, n);
            gender = g;
        }

        ~Student(){
            printf("%s의 소멸자 호출\n",name);
            delete[] name;
        }

        void printStudentInfo(){
            printf("학생번호 : %d\n", student_no);
            printf("학생 이름 : %s\n", name);
            printf("성별 : %s\n", gender == 0? "남자" : "여자");
        }
};


int main(){
    Student s = Student(1124, "김효진", 0);
    s.printStudentInfo();

    Student* s2 = new Student(1113, "박민균", 0);
    s2->printStudentInfo();
    delete s2;

    return 0;
}