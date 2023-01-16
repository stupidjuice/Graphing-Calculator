#include <raylib.h>
#include <iostream>
#include <math.h>

int main(void)
{
    //random vars i need
    float g_epsilon = 0.001f;
    float linedist = 0.0f;

    //graphics options
    float lineThickness = 2;

    //control options
    float scrollSensitivity = 0.5f;

    //window
    const int screenWidth = 800;
    const int screenHeight = 450;
    const float aspectRatio = (float)screenWidth / (float)screenHeight;

    float windowZoom = 10.0f;
    Vector2 windowPos = { (float)screenWidth / 2, (float)screenHeight / 2 };

    //initialization
    InitWindow(screenWidth, screenHeight, "Graphing Calculator");

    SetTargetFPS(60);

    //main loop
    while (!WindowShouldClose())
    {
        //variable updates
        if (IsKeyDown(KEY_UP)) windowPos.y += 2.0f;
        if (IsKeyDown(KEY_DOWN)) windowPos.y -= 2.0f;

        windowZoom -= GetMouseWheelMove() * scrollSensitivity;
        
        if(windowZoom < g_epsilon)
        {
            windowZoom = g_epsilon;
        }

        /*-----*/ BeginDrawing(); /*-----*/

        ClearBackground(WHITE);

        //draw
        //horizontal grid lines
        linedist = screenHeight / windowZoom;
        for(int i = 0; i < ceilf(windowZoom + 1.0f); i++)
        {
            DrawLineEx({0, (float)i * linedist + fmod(windowPos.y, screenHeight / windowZoom)}, {screenWidth, (float)i * linedist + fmod(windowPos.y, screenHeight / windowZoom)}, lineThickness, LIGHTGRAY);
        }

        //vertical grid lines
        for(int i = 0; i < ceilf(windowZoom * aspectRatio + 1.0f); i++)
        {
            DrawLineEx({(float)i * linedist + fmod(windowPos.x, screenHeight / windowZoom), 0}, {(float)i * linedist + fmod(windowPos.x, screenHeight / windowZoom), screenHeight}, lineThickness, LIGHTGRAY);
        }
        //axis lines
        DrawLineEx({windowPos.x, 0}, {windowPos.x, screenHeight}, lineThickness, BLACK);
        DrawLineEx({0, windowPos.y}, {screenWidth, windowPos.y}, lineThickness, BLACK);
        
        /*-----*/ EndDrawing(); /*-----*/
    }

    //deinitialization
    CloseWindow();

    return 0;
}
