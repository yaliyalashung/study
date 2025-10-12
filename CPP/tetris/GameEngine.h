#ifdef __GAME_ENGINE_H__
#define __GAME_ENGINE_H__

#include "Header.h"

class GameEngine {
    public :
        enum class GameState{
            PLAYING, GAMEOVER
        };

        GameState state = GameState::PLAYING;

        int gameGridData[GRID_HEIGHT][GRID_WIDTH];
        int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE];

        int userBlockVarious[4][USERBLOCK_SIZE][USERBLOCK_SIZE];

        int blockX= 0;
        int blockY = 0;

        float elapsed = 0.0f;
        float controlCheck = 0.0f;

        void init(); //매번 불려지는 함수
        void next(float dt, char keyboardInput);
        
        void rotate();

        //블록이 아래로 내려갈 수 있는지
        bool canGoDown();

        //블록이 왼쪽으로 갈 수 있는지
        bool canGoLeft();
        
        //블록이 오른쪽으로 갈 수 있는지 
        bool canGoRight();
        bool canRotate();
        bool isLineFilled(int y);

        void eraseLine;

        //y좌표를 기준으로 한 칸씩 아래로 내림
        void drop(int y);

        
        void makeUserBlock();

        //userblock을 gameGrid에 전사하는 함수
        void trans();

        bool gameOverDecision();

        //실제 게임 데이터를 화면에 출력할 수 있는 데이터
        void makeDisplayData();

};

#endif //#define GAME_ENGINE