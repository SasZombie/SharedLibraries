#include <iostream>
#include <raylib.h>

extern "C" {
    void drawRec() {
        DrawRectangle(0, 0, 100, 100, ORANGE);
    }
}
