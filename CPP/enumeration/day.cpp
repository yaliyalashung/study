#include <cstdio>
#include <cstring>

enum Month {
    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

int main(){

    Month m = Month::JAN;

    switch (m){
        case Month::JAN:
            printf("1월입니다\n");
            break;
        case Month::FEB:
            printf("2월입니다.\n");
            break;
    }
    return 0;
}