#include <cstdio>
#include <cstring>
#include <cmath>


class Vector {
    public :
        float x;
        float y;

        Vector(float x, float y){
            this->x = x;
            this->y = y;
        }

        Vector(){
            x = 0.0f;
            y = 0.0f;
        }

    void printInfo(){
        printf("%.2f, %.2f\n", x, y);
    }
};

Vector operator+(Vector& v1, Vector& v2){
    return Vector(v1.x + v2.x, v1.y + v2.y);
}


int main(){

    Vector v1 = Vector(100, 200);
    Vector v2 = Vector(1,2);

    Vector v3 = v1 + v2;

    v3.printInfo();
    return 0;
}