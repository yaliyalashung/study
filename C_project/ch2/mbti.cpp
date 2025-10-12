#include <cstdio>
#include <cstdlib>
#include <cmath>

//MBTI = I or E / S or N / T or F / J or P

int getScore(){
    int input;
    int score = 0;
    fseek(stdin, 0, SEEK_END);
    scanf("선택하신 숫자자를 입력해주세요 %d : \n", &input);
    if(input == 1){
        score += 1;
    }
    else{
        score += -1;
    }
    return score;
}

int judge(int a, char c, char b){
    if (a>0){
        return b;
    }
    else{
        return c;
    }
}

int checkIE(){
    
    int IEscore = 0;
    char result;
    printf("나는 여행지에서...\n 1) 새로운 사람들과 어울리는 게 좋다.\n 2) 친한 친구랑만 노는 게 좋다.\n");

    IEscore = getScore();

    result = judge(IEscore, 'E', 'I');
    
    return result;    
}

int checkSN(){
    
    int SNscore = 0;
    char result;
    printf("나는 여행지에서 아름다운 풍경을 보면...\n 1) 예쁘다고 생각한다.\n 2) 풍경을 즐기는 사람들의 모습을 상상한다.\n");

    SNscore = getScore();

    result = judge(SNscore, 'S', 'N');
    
    return result;    
}

int checkTF(){
    
    int TFscore = 0;
    char result;
    printf("친구가 여행 도중 우울하다며 빵을 샀다. 나의 대답은?\n 1) 무슨 빵?\n 2) 왜 우울했어?ㅠㅠㅠ\n");

    TFscore = getScore();

    result = judge(TFscore, 'T', 'F');
    
    return result;    
}

int checkJP(){
    
    int JPscore = 0;
    char result;
    printf("여행 일정을 짤 때 나는...\n 1) 일정은 30분 단위로! 2안, 3안도 필요하다.\n 2) 발길이 닿는 곳이 내 일정!\n");

    JPscore = getScore();

    result = judge(JPscore, 'J', 'P');
    
    return result;    
}

int main(){
    printf("나의 여행 MBTI는?!\n");

    char result[5];

    result[0] = checkIE();
    result[1] = checkSN();
    result[2] = checkTF();
    result[3] = checkJP();
    result[4] = '\0';

    printf("당신의 여행 MBTI는 %s입니다.\n", result);
    return 0;
}