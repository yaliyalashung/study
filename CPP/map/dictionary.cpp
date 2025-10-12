#include "dictionary.h"

int getInteger(const char* prompt){
    
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

void Dictionary::insertWord(const std::string& word, const std::string& mean){
    words[word] = mean;

}
bool Dictionary::exists(const std::string& word){
    return words.count(word) == 1;
}

std::string Dictionary::getMean(const std::string& word){
    return words[word];
}

int main(){


    Dictionary* dict = new Dictionary();


    for(;;){
        
        printf("1. 단어 등록\n");
        printf("2. 단어 검색\n");
        printf("3. 프로그램 종료\n");

        int input = getInteger("실행할 번호를 입력해주세요 : ");

        if(input==1){

            std::string word = getString("등록할 단어를 입력해주세요 : ");
            std::string mean = getString("단어의 뜻을 입력해주세요 : ");
            dict->insertWord(word, mean);
            printf("등록이 완료되었습니다.\n");
        }
        else if(input == 2){
            std::string word = getString("찾을 단어 : ");
            if(dict->exists(word)){
                printf("%s \n", dict->getMean(word).c_str());
            }
            else{
                printf("등록되지 않은 단어입니다.\n");
            }

        }
        else if(input == 3){
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else{
            printf("잘못된 번호를 입력하셨습니다\n");
        }

    }
    return 0;
}