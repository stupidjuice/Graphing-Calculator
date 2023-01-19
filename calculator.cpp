#include <raylib.h>
#include <iostream>
#include <math.h>
#include "graphdrawer.hpp"

int main(void)
{
    //random vars i need
    float g_epsilon = 0.001f;
    float linedist = 0.0f;
    int shiftDistInBoxes = 0.0f;
    float shiftIntoScreenX = 0.0f;
    float shiftIntoScreenY = 0.0f;;

    //graphics options
    float lineThickness = 2;
    float textOffset = 4;
    int textSize = 14;

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
        if (IsKeyDown(KEY_W)) windowPos.y += 2.0f;
        if (IsKeyDown(KEY_S)) windowPos.y -= 2.0f;
        if (IsKeyDown(KEY_A)) windowPos.x += 2.0f;
        if (IsKeyDown(KEY_D)) windowPos.x -= 2.0f;

        windowZoom -= GetMouseWheelMove() * scrollSensitivity;
        
        if(windowZoom < g_epsilon)
        {
            windowZoom = g_epsilon;
        }

        /*-----*/ BeginDrawing(); /*-----*/

        ClearBackground(WHITE);

        //draw
        linedist = screenHeight / windowZoom;

        //grid lines
        DrawHorizontalGridLines(ceil(windowZoom + 1.0f), linedist, windowPos.y, screenWidth, lineThickness);
        DrawVerticalGridLines(ceil(windowZoom * aspectRatio + 1.0f), linedist, windowPos.x, screenHeight, lineThickness);

        //draw labels
        //x axis lables
        shiftDistInBoxes = ceil(windowPos.x / linedist);
        shiftIntoScreenX = windowPos.x - shiftDistInBoxes * linedist + textOffset;
        DrawXAxisLabels(ceil(windowZoom * aspectRatio + 1.0f), screenHeight, windowPos.y, textOffset, textSize, shiftDistInBoxes, shiftIntoScreenX, linedist);

        //y axis labels
        shiftDistInBoxes = ceil(windowPos.y / linedist);
        shiftIntoScreenY = windowPos.y - shiftDistInBoxes * linedist + textOffset;

        //axis lines
        DrawLineEx({windowPos.x, 0}, {windowPos.x, screenHeight}, lineThickness, BLACK);
        DrawLineEx({0, windowPos.y}, {screenWidth, windowPos.y}, lineThickness, BLACK);
        
        /*-----*/ EndDrawing(); /*-----*/
    }

    //deinitialization
    CloseWindow();

    return 0;
}