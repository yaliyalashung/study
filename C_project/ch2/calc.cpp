#include <cstdio>
#include "type.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

int main(){


    float value1;
    float value2;
    char oper;
    int num = 0;
    bool valid = true;

    printf("첫번째 숫자를 입력해주세요.\n");
    value1 = getfloat();
    printf("두번째 숫자를 입력해주세요.\n");
    value2 = getfloat();
    printf("연산 방식을 입력해주세요.(p, x, r)\n");
    oper = getChar();


    switch(oper)
    {
        case 'p' :
            result = pow(value1, value2);
            break;
        case 'x' :
            printf("종료 버튼을 선택하셨습니다.\n");
            valid = false;
            break;
        case 'r' :
            srand(time(0));
            num = rand()%5;
            printf("선택하신 숫자는 %d입니다.\n", num);
            result = choiceoper(num, value1, value2);
            break;
        default :
            printf("잘못된 문자입니다.\n");
            valid = false;   
            
    }

    if (valid){
        printf("정답은 %.3f입니다.\n", result);
    }
    else{
        printf("프로그램을 종료합니다.\n");
    }

    return 0;
}