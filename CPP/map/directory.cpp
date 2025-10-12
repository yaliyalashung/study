#include "directory.h"



int main()
{

    std::map<std::string, std::string> direct;
    
    for( ; ;){
        
        printf("1. 단어 등록\n");
        printf("2. 단어 검색\n");
        printf("3. 프로그램 종료\n");

        int menu = getInteger("실행할 번호를 입력해주세요 : ");

        switch (menu)
        {
            case 1:
            {
                std::string word = getString("등록할 단어를 입력해주세요 : ");
                std::string mean = getString("단어의 뜻을 입력해주세요 : ");
                
                if(direct.count(word)){
                    printf("중복된 단어입니다.\n");
                }else{
                    direct[word] = mean;
                    printf("단어 등록이 완료되었습니다\n");
                }
                
                break;
            }
            case 2:
            {
                std::string findWord = getString("검색할 단어를 입력해주세요 : ");

                auto it = direct.find(findWord);

                if(it == direct.end()){
                    printf("등록된 단어가 없습니다.\n");
                }
                else{
                    printf("%s \n", it->second.c_str());
                }

                break;
            }
            case 3:
            {
                printf("프로그램이 종료되었습니다.\n");
                return 0;
            }
            default:
            {
                printf("잘못된 번호를 입력하셨습니다.\n");
                break;
            }
        }
    }

    return 0;
}