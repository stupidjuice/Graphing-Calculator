#include <raylib.h>
#include <math.h>
#pragma once

/// @brief To calculate numLines, use ceil(windowZoom + 1.0f)
void DrawHorizontalGridLines(int numLines, float linedist, float ypos, int screenWidth, float lineThickness)
{
    for(int i = 0; i < numLines; i++)
    {
        DrawLineEx({0, (float)i * linedist + fmod(ypos, linedist)}, {(float)screenWidth, (float)i * linedist + fmod(ypos, linedist)}, lineThickness, LIGHTGRAY);
    }
}

/// @brief To calculate numLines, use ceil(windowZoom * aspectRatio + 1.0f)
void DrawVerticalGridLines(int numLines, float linedist, float xpos, int screenHeight, float lineThickness)
{
    for(int i = 0; i < numLines; i++)
    {
        DrawLineEx({(float)i * linedist + fmod(xpos, linedist), 0}, {(float)i * linedist + fmod(xpos, linedist), (float)screenHeight}, lineThickness, LIGHTGRAY);
    }
}

/// @brief To calculate numLines, use ceil(windowZoom * aspectRatio + 1.0f)
void DrawXAxisLabels(float numLabels, int screenHeight, float ypos, float textOffset, int textSize, int shiftDistInBoxes, float shiftIntoScreenX, float linedist)
{
    for(int i = 0; i < numLabels; i++)
    {
        //if text is going to be render off the screen, force it to be on screen so the labels can be seen at all times
        //SORRY FOR THE IF ELSE MESS I JUST THINK ITS THE MOST UNDERSTANDABLE WAY TO DO THIS
        //I REFUSE TO USE TERNARY OPERATORS
        if(ypos + textOffset - textSize < 0)
        {
            DrawText(TextFormat("%i", i - shiftDistInBoxes), linedist * i + shiftIntoScreenX, (textSize / 2) + textOffset, textSize, BLACK);
        }
        else if (ypos + textOffset + textSize > screenHeight)
        {
            DrawText(TextFormat("%i", i - shiftDistInBoxes), linedist * i + shiftIntoScreenX, screenHeight - textSize - textOffset, textSize, BLACK);
        }
        else
        {
            DrawText(TextFormat("%i", i - shiftDistInBoxes), linedist * i + shiftIntoScreenX, ypos + textOffset, textSize, BLACK);
        }
    }
}