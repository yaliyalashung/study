#include <cstdio>
#include <cmath>
#include <cstdlib>


int getInt() {

    int input;
    printf("숫자를 입력해주세요 : ");
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &input);

    return input;

}

char getOper(){

    char input;

    printf("연산자를 입력해주세요 : ");
    fseek(stdin, 0, SEEK_END);
    scanf("%c", &input);

    return input;
}