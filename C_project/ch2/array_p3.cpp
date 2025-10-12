#include "array.h"

int main(){

    printf("거꾸로 출력할 문자열을 입력해주세요.\n");
    
    char input[100];
    fseek(stdin, 0, SEEK_END);
    scanf("%99[^\n]s", input);

    for(int i=strlen(input); i>0; i--){
        printf("%c", input[i-1]);
    }
    return 0;
}