//비트와이즈 연산

#include <cstdio>


void foo(int params) {
    int cate1 = 1;
    int cate2 = 1 << 1;
    int cate3 = 1 << 2;

    if((cate1 & params) != 0){
        printf("category1\n");
    }
    if((cate2 & params) != 0){
        printf("category2\n");
    }
    if((cate3 & params) !=0){
        printf("category3\n");
    }
}
int main(){
    int v1 = 1;
    int v2 = 3;

    int bitwise_or = v1 | v2;

    printf("bitwise_or = %d\n", bitwise_or);

    int bitwise_and = v1 & v2;
    printf("bitwise_and = %d\n", bitwise_and);

    int shift_left = v2 <<1 ;
    printf("shift_left = %d\n", shift_left);

    
    int shift_right = v2 >> 1 ;
    printf("shift_right = %d\n", shift_right);


    foo(1 | 4);
    
    return 0;

}