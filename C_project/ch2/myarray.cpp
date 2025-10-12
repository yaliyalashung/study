#include "myarray.h"

int main(){
    
    int * myArray;

    int input;
    fseek(stdin, 0, SEEK_END);
    printf("숫자를 입력하면 배열이 만들어집니다.\n");
    scanf("%d", &input);

    myArray = (int*)malloc(sizeof(int) * input);
    
    for (int i = 0; i < input; i++){
        myArray[i] = i*10;
    }

    
    for (int i = 0; i < input; i++){
        printf("myArray[%d]= %d\n", i, myArray[i]);
    }

    return 0;
}