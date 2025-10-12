#include "array.h"

int main(){

    char input1[100];
    char input2[100];

    printf("첫번째 문자열을 입력해주세요.\n");
    fseek(stdin, 0, SEEK_END);
    scanf("%99[^\n]s", input1);

    printf("두 번째 문자열을 입력해주세요.\n");
    fseek(stdin, 0, SEEK_END);
    scanf("%99[^\n]s", input2);

    if(strcmp(input1, input2)==0){
        printf("ture\n");
    }
    else{
        printf("false\n");
    }
    return 0;
}