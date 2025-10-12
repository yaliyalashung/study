#include <cstdio>

int main(){

    int array_1[5][5];
    int array_2[5][5];
    int array_3[5][5];

    for (int i=0; i<5; i++){
        for (int k=0; k<5; k++){
            array_1[i][k]=i*5+k+1;
            array_2[i][k]=(i*5+k+1)*2;
            array_3[i][k]=array_1[i][k]+array_2[i][k];   
        }
    }


    for (int i=0; i<5; i++){
        for (int k=0; k<5; k++){
            printf("%d ", array_1[i][k]);
        }
    }
    printf("\n");

    for (int i=0; i<5; i++){
        for (int k=0; k<5; k++){
            printf("%d ", array_2[i][k]);
        }
    }
    printf("\n");

    for (int i=0; i<5; i++){
        for (int k=0; k<5; k++){
            printf("%d ", array_3[i][k]);
        }
    }
    printf("\n");

    return 0;
} 