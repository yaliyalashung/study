#include <cstdio>
#include <cstring>
#include <cmath>

class Sword {
    public :
        char name[20];
        int attack;
        int distance;
        int price;

        Sword(const char* name, int attack, int distance, int price){
            strcpy(this->name, name);
            this->attack = attack;
            this->distance = distance;
            this->price = price;
        }

        void printInfo(){
            printf("이름 : %s\n", name);
            printf("공격력 : %d\n", attack);
            printf("사정거리 : %d\n", distance);
            printf("가격 : %d\n", price);
        }
};

class Short_sword : public Sword{
    public :
        Short_sword() : Sword("숏 소드", 10, 5, 500){

        }
};

class Long_sword : public Sword{
    public :
        Long_sword() : Sword("롱 소드", 20, 10, 2000){
            
        }
};

class Hammer : public Sword{
    public :
        Hammer() : Sword("해머", 30, 7, 3000){
            
        }
};

int main(){

    Sword* units[10];

    for (int i=0; i<10; i++){
        switch(rand()%3){
            case 0 :
                units[i] = new Short_sword();
                break;
            case 1 :
                units[i] = new Long_sword();
                break;
            case 2 :
                units[i] = new Hammer();
                break;
        }

        units[i]->printInfo();
    }

    return 0;
}
