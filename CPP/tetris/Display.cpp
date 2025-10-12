#include "Display.h"


void Display::draw(){
    for (int i = 0; i <GRID_HEIGHT; i++){
        for (int k = 0; k <GRID_WIDTH; k++){
            drawPosition(k, i, displayData[i][k]==1);
        }
    }
}