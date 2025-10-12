#include <stdio.h>

int input1 = 0;
int input2 = 0;
int operation = 0;
int answer = 0;

int getinput(){

    int input;
    
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &input);

    return input;

}

int plus (int a, int b){
    return a+b;
}

int minus (int a, int b){
    return a-b;
}

int cross (int a, int b){
    int answer = 0;
    answer = 1;
    for (int i=0; i < b; i++){
        answer = answer * a;
    }
    return answer;
}
int main(){

    
    printf("0, 1, 2 중 원하는 숫자를 입력해주세요.\n");
    operation = getinput();


    if (operation == 0) {

        printf("첫번째  숫자를 입력해주세요.\n");
        input1 = getinput();
    
        printf("두번째  숫자를 입력해주세요.\n");
        input2 = getinput();

        answer = plus(input1, input2);
        printf("결과는 %d입니다.\n", answer);
    }
    else if (operation == 1){
        
        printf("첫번째  숫자를 입력해주세요.\n");
        input1 = getinput();
    
        printf("두번째  숫자를 입력해주세요.\n");
        input2 = getinput();

        answer = minus(input1, input2);
        printf("결과는 %d입니다.\n", answer);
    }
    else if (operation == 2){
        
        printf("첫번째  숫자를 입력해주세요.\n");
        input1 = getinput();
    
        printf("두번째  숫자를 입력해주세요.\n");
        input2 = getinput();
        
        answer = cross(input1, input2);
        printf("결과는 %d입니다.\n", answer);
    }
    else{
        printf("잘못된 숫자를 입력하셨습니다.\n");
        return 0;
    }
    return 0;
}