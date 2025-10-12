#include <cstdio>
#include <cstdlib>

struct ONF {
    int hj = 0422;
    int cy = 1224;
};

int main(){

    ONF* onf[10] = { nullptr, };

    for (int i = 0; i<10; i++){
        onf[i] = (ONF*)malloc(sizeof(ONF));
        onf[i]->hj = 10;
        onf[i]->cy = 20;
    }
    

    for (int i = 0; i<10; i++){
        printf("onf[%d].cy = %d\n", i, onf[i]->cy);
    }


    return 0;
}