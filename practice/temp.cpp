#include <cstdio>
#include <cstring>

template<typename T>

class comb{
    public:        
        T add(T a, T b){
            return a+b;
        }

        void swap(T &a, T &b){
            T temp;
            temp = b;
            b = a;
            a = temp;
        }
    
};


int main(){

    comb<int>* m = new comb<int>;
    int a = 5;
    int b = 6;

    int c = m->add(a, b);
    m->swap(a, b);
    printf("a = %d, b = %d, c = %d \n", a, b, c);
    return 0;
}