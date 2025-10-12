#include "static.h"


int MyClass::b = 100;

int main(){
    MyClass* c = new MyClass();
    c->foo();
    
    MyClass::goo();
    
    printf("%d", MyClass::b);
    return 0;
}