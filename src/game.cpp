#include "raylib.h"

#if defined(PLATFORM_WEB)
    #include <emscripten/emscripten.h>
#endif

static const int screenWidth = 800;
static const int screenHeight = 450;

static void UpdateDrawFrame(void);

int main(void)
{
    InitWindow(screenWidth, screenHeight, "BoomHeadshot");

    InitAudioDevice();

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 60, 1);
#else
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Hello World", screenWidth / 2, screenHeight / 2, 32, BLACK);
        EndDrawing();
    }
#endif

    CloseAudioDevice();

    CloseWindow();

    return 0;
}