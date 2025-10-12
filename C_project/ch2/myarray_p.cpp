#include "myarray_p.h"

int main(){

    int *myArray;
    int input;
    fseek(stdin, 0, SEEK_END);
    printf("원하는 수열의 크기를 입력해주세요.\n");
    scanf("%d", &input);

    myArray = (int*)malloc(sizeof(int) * input);
    
    for (int i=0; i<input; i++){
        myArray[i] = (i+1)*2;
    }

    for (int i=0; i<input; i++){
        printf("myArray[%d] = %d\n", i, myArray[i]);
    }
    
    free(myArray);
    
    return 0;
}