#include <raylib.h>
#include <iostream>
#include <math.h>

int main(void)
{
    //random vars i need
    float g_epsilon = 0.001f;
    float linedisty = 0.0f;
    float linedistx = 0.0f;

    //graphics options
    float lineThickness = 2;

    //control options
    float scrollSensitivity = 0.5f;

    //window
    float windowZoom = 20.0f;
    Vector2 windowPos = { 0.0f, 0.0f };

    const int screenWidth = 800;
    const int screenHeight = 450;
    const float aspectRatio = (float)screenWidth / (float)screenHeight;

    //initialization
    InitWindow(screenWidth, screenHeight, "Graphing Calculator");

    SetTargetFPS(60);

    //main loop
    while (!WindowShouldClose())
    {
        //variable updates
        windowZoom -= GetMouseWheelMove();
        if(windowZoom < g_epsilon)
        {
            windowZoom = g_epsilon;
        }

        /*-----*/ BeginDrawing(); /*-----*/

        ClearBackground(WHITE);

        //draw
        //horizontal lines
        linedisty = screenHeight / windowZoom;
        for(int i = 0; i < ceilf(windowZoom + 1.0f); i++)
        {
            DrawLineEx({0, (float)i * linedisty}, {screenWidth, (float)i * linedisty}, lineThickness, GRAY);
        }

        //vertical lines
        linedistx = screenHeight / windowZoom;
        for(int i = 0; i < ceilf(windowZoom * aspectRatio + 1.0f); i++)
        {
            DrawLineEx({(float)i * linedistx, 0}, {(float)i * linedistx, screenHeight}, lineThickness, GRAY);
        }
        

        /*-----*/ EndDrawing(); /*-----*/
    }

    //deinitialization
    CloseWindow();

    return 0;
}
