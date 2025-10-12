#include <cstdio>
#include <string>

namespace kim{
    void foo(){
        printf("I'm kim's foo!!\n");
    }
}

namespace Lee{
    void foo(){
        printf("I'm lee's foo!\n");
    }
}

int main(){

    kim::foo();
    Lee::foo();
    
    return 0;
}