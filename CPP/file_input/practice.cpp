#include "practice.h"

int getIntser(const char* prompt){
    
    printf(prompt);
    int input;
    fseek(stdin, 0, SEEK_END);
    scanf("%d", &input);
    return input;
}

std::string getString(const char* prompt){
    printf(prompt);
    char str[100];
    fseek(stdin, 0, SEEK_END);
    scanf("%99[^\n]", str);
    return str;

}

Student::Student(std::string name, int korean, int math, int eng){
    this->name = name;
    this->korean = korean;
    this->math = math;
    this->eng = eng;
}

void Student::printInfo(){
    printf("이름 : %s / 국어 : %d / 수학: %d / 영어: %d \n", name.c_str(), korean, math, eng);

}

int main(){
    std::vector<Student> students;
    FILE* infile = fopen("students.txt", "r");
    while (true){
        char name[100];
        int korean, math, eng, result;
        if (fscanf(infile, "%99[^\n]", name) != 1) break;
        fgetc(infile);
        result = (fscanf(infile, "%d %d %d", &korean, &math, &eng));
        if (result == -1) break;
        fgetc(infile);
        Student s = Student(name, korean, math, eng);
        students.push_back(s);
    }
    fclose(infile);
    
    while (true){
        for(int i = 0; i<students.size(); i++){
            students[i].printInfo();
        }
        std::string name = getString("학생의 이름을 입력해 주세요 : ");
        int korean = getIntser("국어 : ");
        int math = getIntser("수학 : ");
        int eng = getIntser("영어 : "); 

        Student s = Student(name, korean, math, eng);
        students.push_back(s);

        FILE* outfile = fopen("students.txt", "w");
        for (int i = 0; i<students.size(); i++){
            fprintf(outfile, "%s\n", students[i].name.c_str());
            fprintf(outfile, "%d %d %d\n", students[i].korean, students[i].math, students[i].eng);
        }
        fclose(outfile);
    }
    return 0;
}