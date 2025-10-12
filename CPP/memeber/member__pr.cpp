#include "member_pr.h"

int main(){

    Employee* employee[100];
    int count = 0;

    while (true){
        printf("명령을 입력하세요.\n");
        printf("1. 사원보기\n");
        printf("2. 사원 추가\n");
        printf("3. 사원 삭제\n");
        printf("4. 프로그램 종료\n");

        fseek(stdin, 0, SEEK_END);
        int input;
        scanf("%d", &input);

        switch(input){
            case 1 : {
                //사원 보기

                for (int i=0; i<count; i++){
                    employee[i]->printInfo();
                }
                break;
            }
            case 2 : {
                //사원 추가
                char* name = getString("사원명을 입력해주세요 : \n");
                int gender = getInt("성별을 입력해주세요(0: 남성, 1 : 여성) : \n");
                char* rank = getString("직위를 입력해주세요 :\n");

                Employee* e = new Employee(name, gender, rank);
                delete[] name;
                delete[] rank;
                employee[count] = e;
                count++;

                break;
            }
            case 3 : {
                //사원 삭제
                int number = getInt("사원번호를 입력해주세요.\n");
                int deletedIndex = -1;
                for(int i = 0; i <count; i++){
                    if (number == employee[i]->no){
                        delete employee[i];
                        deletedIndex = i;
                    }
                }
                if(deletedIndex >= 0){
                    for (int i= deletedIndex; i<count-1; i++){
                        employee[i] = employee[i+1];
                    }
                    count--;
                }
                printf("삭제가 완료되었습니다.\n");
                break;
            }
            case 4 : {
                //프로그램 종료
                printf("프로그램을 종료합니다.\n");
                return 0;
            }
            default : {
                printf("잘못된 숫자를 입력하셨습니다. 다시 입력해주세요.\n");
                break;
            }
        }
    }
    
    return 0;
}


int getInt(const char* prompt){
    int input;
    printf("%s\n", prompt);
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &input);
    return input;
}

char* getString(const char* prompt){
    char* input = new char[100];
    printf("%s", prompt);
    fseek(stdin, 0, SEEK_END);
    scanf("%99[^\n]s", input);
    return input;
}