#include "array.h"

int main(){

    char input1[100];
    char input2[100];
    bool same = true;

    printf("첫 번째 문자열을 입력해주세요.\n");
    fseek(stdin, 0, SEEK_END);
    scanf("%99[^\n]s", input1);
    
    printf("두 번째 문자열을 입력해주세요.\n");
    fseek(stdin, 0, SEEK_END);
    scanf("%99[^\n]s", input2);

    for(int i=0; ; i++){
        if (strlen(input1)>strlen(input2)){
            if (input1[i] == '\0') break;
        }
        else{
            if (input2[i] == '\0') break;
        }
        if(input1[i]!=input2[i]) same = false;
    }

    if(same){
        printf("true\n");
    }
    else{
        printf("false");
    }
    return 0;
}