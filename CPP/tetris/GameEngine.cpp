#include "GameEngine.h"

GameState state = GameState::PLAYING;

int GameEngine::gameGridData[GRID_HEIGHT][GRID_WIDTH] = { 0, };
int GameEngine::userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = {0, };

int GameEngine::userBlockVarious[4][USERBLOCK_SIZE][USERBLOCK_SIZE] = {
    {
        {0,1,0},
        {0,1,0},
        {0,1,0}
    },
    {
        {0,0,0},
        {1,0,0},
        {1,1,0}
    },
    {
        {0,1,0},
        {0,1,1},
        {0,0,1}
    },
    {
        {0,0,0},
        {0,1,1},
        {0,1,1}
    }
};

void GameEngine::init(){
    //처음 게임 엔지는 초기화
    makeUserBlock();
}

//while 루프에서 매번 불려지는 함수
void GameEngine::next(float dt, char keyboardInput){

    if (state == GameState::GAMEOVER) return;

    elapsed += dt;
    if (elapsed >= 0.5f){
        if(canGoDown()){
            blockY++;
        }
        else{
            trans();
            if (gameOverDecision()) state = GameState::GAMEOVER;
        }                
        elapsed -= 0.5f;                
    }

    controlCheck += dt;

    if (keyboardInput == 'a' && canGoLeft() && controlCheck > 0.1){
        blockX--;
        controlCheck = 0.0f;
    }
    if (keyboardInput == 'd' && canGoRight() && controlCheck > 0.1){
        blockX++;
        controlCheck = 0.0f;
    }
    if (keyboardInput == 's' && canGoDown() && controlCheck > 0.1){
        blockY++;
        controlCheck = 0.0f;
    }
}




void GameEngine::rotate(){

    if(canRotate()){
        int tempBlock[USERBLOCK_SIZE][USERBLOCK_SIZE];

        //회전
        for(int i=0; i<USERBLOCK_SIZE; i++){
            for(int k = 0; k<USERBLOCK_SIZE; k++){
                tempBlock[k][USERBLOCK_SIZE-i-1] = userBlock[i][k]; 
            }
        }

        for(int i=0; i<USERBLOCK_SIZE; i++){
            for(int k = 0; k<USERBLOCK_SIZE; k++){
                userBlock[i][k] = tempBlock[i][k]; 
            }
        }

    }
}

//블록이 아래로 내려갈 수 있는지
bool GameEngine::canGoDown()
{
    for (int i =0; i<USERBLOCK_SIZE; i++){
        for (int k = 0; k<USERBLOCK_SIZE; k++){
            if(userBlock[i][k]==1 && (i+ blockY+1) >=GRID_HEIGHT)
                return false;
            if(userBlock[i][k]==1 && gameGridData[i+blockY+1][k+blockX]==1)
                return false;
        }
    }
    return true;
}


//블록이 왼쪽으로 갈 수 있는지
bool GameEngine::canGoLeft(){
    for (int i =0; i<USERBLOCK_SIZE; i++){
        for (int k = 0; k<USERBLOCK_SIZE; k++){
            if(userBlock[i][k] == 1 && (k+blockX -1) <0){
                return false;
            }
            if(userBlock[i][k] == 1 && gameGridData[i+blockY][k+blockX-1]==1)
                return false;
        }
    }            
    return true;

}

//블록이 오른쪽으로 갈 수 있는지 
bool GameEngine::canGoRight(){
    for (int i =0; i<USERBLOCK_SIZE; i++){
        for (int k = 0; k<USERBLOCK_SIZE; k++){
            if(userBlock[i][k] == 1 && (k+blockX +1) > GRID_WIDTH -1){
                return false;
            }
            if(userBlock[i][k] == 1 && gameGridData[i+blockY][k+blockX+1]==1)
                return false;
        }
    }            
    return true;
}

bool GameEngine::canRotate() {
    int tempBlock[USERBLOCK_SIZE][USERBLOCK_SIZE];

    for (int i = 0; i < USERBLOCK_SIZE; i++) {
        for (int k = 0; k < USERBLOCK_SIZE; k++) {
            tempBlock[k][USERBLOCK_SIZE - 1 - i] = userBlock[i][k];
        }
    }

    for (int i = 0; i < USERBLOCK_SIZE; i++) {
        for (int k = 0; k < USERBLOCK_SIZE; k++) {
            if (tempBlock[i][k] == 1) {
                int newX = blockX + k;
                int newY = blockY + i;

                if (newX < 0 || newX >= GRID_WIDTH || newY < 0 || newY >= GRID_HEIGHT)
                    return false;
                if (gameGridData[newY][newX] == 1)
                    return false;
            }
        }
    }

    return true;
}

bool GameEngine::isLineFilled(int y){
    for (int i = 0; i <GRID_WIDTH; i++){
        if (gameGridData[y][i] == 0) return false;
    }
    return true;
}

void GameEngine::eraseLine(int y){
    for (int i = 0; i<GRID_WIDTH; i++){
        gameGridData[y][i] = 0;
    }
}

//y좌표를 기준으로 한 칸씩 아래로 내림
void GameEngine::drop(int y){
    for (int i = y; i >=0; i--){
        for (int k = 0; k <GRID_WIDTH; k++){
            gameGridData[i][k] = (i-1) < 0? 0:  gameGridData[i-1][k];
        }
    }
}


void GameEngine::makeUserBlock(){
    blockX = GRID_WIDTH/2 - USERBLOCK_SIZE/2;
    blockY = 0;
    
    srand(time(0));

    int various = rand()%4;
    for (int i= 0; i< USERBLOCK_SIZE; i++){
        for (int k = 0; k<USERBLOCK_SIZE; k++){
            userBlock[i][k] = userBlockVarious[various][i][k];
        }
    }
}

//userblock을 gameGrid에 전사하는 함수
void GameEngine::trans(){
    for (int i =0; i<USERBLOCK_SIZE; i++){
        for (int k = 0; k<USERBLOCK_SIZE; k++){
            gameGridData[i+blockY][k+blockX] = userBlock[i][k] == 1 ? 1 : displayData[i+blockY][k+blockX];
        }
    }
    //한 줄이 가득 차 있는지 확인
    for (int i = 0; i<GRID_HEIGHT; i++){
        if(isLineFilled(i)){
            eraseLine(i);
            drop(i);
        }
    }
    
    //새로운 블록 생성
    makeUserBlock();
}

bool GameEngine::gameOverDecision(){
    for (int i = 0; i<USERBLOCK_SIZE; i++ ){
        for (int k = 0; k<USERBLOCK_SIZE; k++){
            if (userBlock[i][k] == 1 && gameGridData[i+blockY][k+blockX]==1)
            return true;
        }
    }
    return false;
}

//실제 게임 데이터를 화면에 출력할 수 있는 데이터
void GameEngine::makeDisplayData(){
    for (int i =0; i<GRID_HEIGHT; i++){
        for (int k = 0; k<GRID_WIDTH; k++){
            displayData[i][k] = gameGridData[i][k];
        }
    }

    for (int i =0; i<USERBLOCK_SIZE; i++){
        for (int k = 0; k<USERBLOCK_SIZE; k++){
            if((i+blockY) < 0 || i + blockY >= GRID_HEIGHT){
                //DO NOTHING
            }
            else if(k+blockX<0 || k+blockX >= GRID_WIDTH){
                //DO NOTHING
            }
            else {
                displayData[i + blockY][k+blockX] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[i+blockY][k+blockX];
            }
        }
    }

}
