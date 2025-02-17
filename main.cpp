#include <iostream>
#include <raylib.h>
#include <dlfcn.h>

typedef void (*function)();

int main()
{
    const char* so_file = "./libmylibrary.so";
    void* handle = dlopen(so_file, RTLD_LAZY);
    
    function my_function = (function) dlsym(handle, "drawRec");



    InitWindow(600, 800, "Test");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        if(IsKeyPressed(KEY_R))
        {
            dlclose(handle);
            handle = dlopen(so_file, RTLD_LAZY);
            my_function = (function) dlsym(handle, "drawRec");
        }

        my_function();
        EndDrawing();
    }
    
}
