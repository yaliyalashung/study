#include <cstdio>
#include <functional>
#include <string>

void foo(){
    printf("Hello, World!\n");
}

int sum(int value1, int value2){
    return value1+value2;
}

class Marine{
    public:
        void attackTo(const char* target){
            printf("마린은 %s를 공격했다\n");
        }
};

int main(){

    Marine* m = new Marine();
    auto attack = std::bind(&Marine::attackTo, m, std::placeholders::_1);
    attack("바보");

    return 0;
}