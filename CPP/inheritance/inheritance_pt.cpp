#include <cstdio>
#include <cstring>
#include <cmath>

class Monster{
    public:
        char name[20];
        int power;
        int attack;
        int distance;
        int speed;

        Monster(const char* name, int power, int attack, int distance, int speed){
            strcpy(this->name,name);
            this->power = power;
            this->attack = attack;
            this->distance = distance;
            this->speed = speed;
        }

    void printInfo(){
        printf("이름 : %s\n", name);
        printf("체력 : %d\n", power);
        printf("공격력 : %d\n", attack);
        printf("사정거리: %d\n", distance);
        printf("이동속도 : %d\n", speed);
    }
};

class Goblin : public Monster {
    public :

        Goblin() : Monster("고블린", 60, 6, 10, 10){

        }

};

class Orc : public Monster {
    public :

        Orc() : Monster("오크", 80, 10, 12, 8){

        }

};

class Slime : public Monster{
    public :
        Slime() : Monster("슬라임", 100, 3, 5, 4){

        }

};

int main(){

    Monster* units[10];

    for (int i=0; i<10; i++){
        switch (rand()%3){
            case 0 :
                units[i] = new Goblin();
                break;
            case 1 :
                units[i] = new Orc;
                break;
            case 2 :
                units[i] = new Slime;
                break;
        }
    }

    for (int i=0; i<10; i++){
        units[i]->printInfo();
    }

    return 0;
}