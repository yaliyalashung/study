#ifdef __DISPLAY_H__
#define __DISPLAY_H__

#include "Header.h"

class Display{
    public:
        void draw();
        extern int Display::displayData[GRID_HEIGHT][GRID_WIDTH];
};

#endif