#include <cstdio>
#include <cstring>
#include <cmath>

class Matrix{
    public:
        float x;
        float y;
        float z;

        Matrix(float x, float y, float z){
            this->x = x;
            this->y = y;
            this->z = z;
        }

    void printInfo(){
        printf("%.2f, %.2f, %.2f\n", x, y, z);
    }
};

Matrix operator+(Matrix& m1, Matrix& m2){
    return Matrix(m1.x+m2.x, m1.y+m2.y, m1.z+m2.z);
}

int main(){

    Matrix m1 = Matrix(100, 200, 300);
    Matrix m2 = Matrix(1, 2, 3);

    Matrix m3 = m1 + m2;

    m3.printInfo();

    return 0;
}