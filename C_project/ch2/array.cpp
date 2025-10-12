#include "array.h"
int main(){


    char myString[100];

    //scanf("%99[^\n]s", myString);

    printf("입력된 문자열은 %s 입니다.\n", myString);

/*
    //strcpy 예제
    char inputString[100];

    printf("문자열을 입력해주세요:\n");
    fseek(stdin, 0, SEEK_END );
    scanf("%99[^\n]s", inputString);

    char duplicatedString[100];
    strcpy(duplicatedString, inputString);
    printf("입력된 문자열은 %s 입니다.\n", duplicatedString);
*/

/*
    //strcmp 예제
    char str1[100];
    char str2[100];

    strcpy(str1, "Hello B");
    strcpy(str2, "Hello B");

    int result = strcmp(str1, str2);

    printf("%d", result);
*/
    return 0;
}