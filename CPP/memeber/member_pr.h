#include <cstring>
#include <cstdio>

int number_counter = 1;

class Employee{
 public:

    int no;
    char* name;
    int gender; //0은 남자, 1은 여자
    char* rank;

    Employee(const char * name, int gender, const char * rank){

        this->name = new char[strlen(name)+1];
        this->rank = new char[strlen(rank)+1];
        strcpy(this->name, name);
        this->gender = gender;
        strcpy(this->rank, rank);
        this->no = number_counter;
        number_counter++;

    }

    ~Employee() {
        delete[] name;
        delete[] rank;
        printf("%d의 사원번호를 가진 사원이 삭제되었습니다.", no);
    }

    //사원 정보를 출력하는 함수
    void printInfo(){
        printf("사원번호 : %d /", no);
        printf("이름     : %s\n", name);
        printf("성별     : %s /", gender == 0? "남성" : "여성");
        printf("직급     : %s\n", rank);
    }


};

int getInt(const char* prompt);

//함수 실행 후 해제 필요
char* getString(const char* prompt);