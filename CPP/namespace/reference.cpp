#include <string>
#include <cstdio>

void swap(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void swap_string(std::string& a, std::string& b){
    std::string temp;
    temp = a;
    a = b;
    b = temp;
}

int main(){
    int v1 = 100;
    int v2 = 200;

    swap(v1, v2);

    printf("v1 = %d, v2 = %d\n", v1, v2);

    std::string a ="Hyojin";
    std::string b ="kim";

    swap_string(a, b);
    
    printf("%s %s\n", a.c_str(), b.c_str());
    return 0;
}