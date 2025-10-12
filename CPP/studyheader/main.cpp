#include "Person.h"

int main(){
    Animal* animal = new Animal(4, "호랑이");
    animal->printInfo();

    Person* person = new Person("1234-5678", "김효진");
    person->printInfo();
    
    return 0;
}