#include <cstdio>
#include <cstring>

class MyClass {
    public:
        int a;
        static int b;


        void foo(){
            printf("foo\n");
        }
        static void goo(){
            printf("goo\n");
        }
};
