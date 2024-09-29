#include <raylib-cpp.hpp>

#include <memory>

#include "text.hpp"

#if defined(PLATFORM_WEB)
#include <emscripten/emscripten.h>
#endif

int screenWidth = 800;
int screenHeight = 450;

void UpdateDrawFrame(void);     // Update and Draw one frame

int main()
{
    std::unique_ptr<raylib::Window> window = std::make_unique<raylib::Window>(screenWidth, screenHeight, "Boom Headsht");

#if defined(PLATFORM_WEB)
    emscripten_set_main_loop(UpdateDrawFrame, 0, 1);
#else
    SetTargetFPS(60);

    const BH::Text text("Hello World!", screenWidth / 2, screenHeight / 2, 32);

    while (!window->ShouldClose())
    {
        window->BeginDrawing();

        window->ClearBackground(RAYWHITE);

        text.DrawCenter();

        window->EndDrawing();
    }
#endif

    return 0;
}