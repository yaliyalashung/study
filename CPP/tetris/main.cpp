
#include "Header.h"
#include "GameEngine.h"
#include "Display.h"

#define INTERVAL 1.0/60.0

int displayData[GRID_HEIGHT][GRID_WIDTH] = {0, };




int main(){

    SetConsoleOutputCP(CP_UTF8);

    float prev = (float)clock() / CLOCKS_PER_SEC;
    Display* display = new Display();
    GameEngine* gameEngine = new GameEngine(); 
    gameEngine->init();

    showConsoleCursor(false);

    while (true){
        float curr = (float)clock() / CLOCKS_PER_SEC;
        float dt = curr - prev;

        if (dt < INTERVAL) continue;
        prev = curr;

        bool left = keyState('a');        
        bool right = keyState('d');
        bool down = keyState('s');
        bool rotate = keyState('w');

        if(left){
            //왼쪽으로 블록 이동
            gameEngine->next(dt, 'a');
        }
        else if(right){
            gameEngine->next(dt, 'd');
        }
        else if(down){
            gameEngine->next(dt, 's');
        }
        else if (rotate){
            gameEngine->rotate();
        }
        else{
            //그냥 떨어짐            
            gameEngine->next(dt, 0);
        }

        gameEngine->makeDisplayData();
        
        display->draw();

        if(gameEngine->state == GameEngine::GameState::GAMEOVER){
            display->draw();
            printf("GAME OVER!!! PRESS ANY KEY TO FINISH!!\n");
            system("pause");
            break;
        }

    }

    return 0;
}