#include <cstdio>

int main(){

    int input;
    
    printf("숫자를 입력해 주세요.\n");

    fseek(stdin, 0, SEEK_END);

    scanf("%d", &input);

    for(int i=0; i<input; i++){
        for(int k=0; k<input-i-1; k++){
            printf(" ");
        }
        for(int j = 0; j<i+1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}