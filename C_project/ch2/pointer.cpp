#include "pointer.h"

int main(){

    int v1;
    int v2;
    int result;

    char oper;

    bool err = true;

    int* pv1 = &v1;
    int* pv2 = &v2;
    int* presult = &result;

    char* poper = &oper;

    *pv1 = getInt();
    *poper = getOper();
    *pv2 = getInt();


    switch(oper){

        case '+':
            *presult = *pv1 + *pv2;
            break;
        case '-':
            *presult = *pv1 - *pv2;
            break;
        case '*':
            *presult = *pv1 * *pv2;
            break;
        case '/':
            if (*pv2 ==0)
                printf("잘못된 수를 입력하셨습니다.\n");
            else
                *presult = *pv1 / *pv2;
            break;
        default :
            printf("잘못된 연산자입니다.\n");
            err = false;
            break;
    }

    if(err)
        printf(" %d %c %d = %d", v1, oper, v2, result);
    else
        printf("프로그램이 종료되었습니다.\n");
    return 0;
}
