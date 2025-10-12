#include <stdio.h>

int get_input(){
    
    int input= 0 ;
    printf("숫자를 입력해주세요.\n");
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &input);
    return input;
}

int main(){

    int input = get_input();

    if(input <= 0){
        printf("잘못된 숫자를 입력하셨습니다. 다시 입력해주세요.\n");
    }
    else{
        for (int i=0; i < input; i++){
        printf("A");
        }
        printf("\n");
    }

    input = get_input();

    if(input <= 0){
        printf("잘못된 숫자를 입력하셨습니다. 다시 입력해주세요.\n");
    }
    else{
        for (int i=0; i < input; i++){
        printf("B");
        }
        printf("\n");
    }
    
    return 0;
}