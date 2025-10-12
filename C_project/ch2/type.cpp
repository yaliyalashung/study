#include <cstdio>
#include "type.h"

int main(){

    printf("첫번째 숫자를 입력해주세요.\n");
    input_1 = getfloat();
    printf("두번째 숫자를 입력해주세요.\n");
    input_2 = getfloat();
    printf("연산자를 입력해주세요.(+, -, *, /, %)\n");
    input_3 = getChar();

    switch (input_3)
    {
        case '+':
            result = input_1+input_2;
            break;
        case '-':
            result = input_1-input_2;
            break;
        case '*':
            result = input_1*input_2;
            break;
        case '/':
            if(input_2==0){
                printf("0으로 나눌 수 없습니다.\n");
            }
            else{
                result = input_1/input_2;
            }
            break;
        case '%':
            result = (int)input_1%(int)input_2;
            break;
        
        default:
            printf("잘못된 연산식을 입력하셨습니다.\n");
            valid = false;
            break;
    }

    if(valid){
        printf("정답은 %.3f 입니다.\n", result);
    }
    else{
        printf("프로그램이 종료되었습니다.\n");
    }
    return 0;
}