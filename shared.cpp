#include <iostream>
#include <raylib.h>

extern "C"
{
    void drawRec( int x, int y)
    {
        DrawRectangle(x, y, 100, 100, WHITE);
    }
}
