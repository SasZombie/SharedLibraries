#include <iostream>
#include <raylib.h>
#include <dlfcn.h>

typedef void (*function)(int x, int y);

int main()
{
    const char *so_file = "./libshared.so";
    void *handle = dlopen(so_file, RTLD_LAZY);

    function drawingRect = (function)dlsym(handle, "drawRec");
    InitWindow(600, 800, "Test");
    SetTargetFPS(60);


    while (!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(BLACK);

        if (IsKeyPressed(KEY_R))
        {
            dlclose(handle);
            handle = dlopen(so_file, RTLD_LAZY);
            drawingRect = (function)dlsym(handle, "drawRec");
        }
 

        EndDrawing();
    }

    CloseWindow();
}
