#include <cstdio>

#define SWAP(X,Y,TYPE) TYPE temp = X; X=Y; Y=temp;  

int main(){
    int a = 10;
    int b = 20;
    SWAP(a, b, int)
    printf("a = %d, b = %d\n", a, b);
    
    return 0;
}