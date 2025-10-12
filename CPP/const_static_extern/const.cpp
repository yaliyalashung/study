#include <cstdio>
#include <cstring>

#define VAL 100

class Person {
    public :
        const int age;

        Person(int n) : age(n){

        }
};

int main(){

    const char* str;
    char* myStr = new char[100];
    strcpy(myStr, "Hello, world");
    str = myStr;

    int input;
    fseek(stdin, 0, SEEK_END);
    scanf("%d",&input);

    Person* p = new Person(input);

    printf("%d\n", p->age);

    return 0;
}