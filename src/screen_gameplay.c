/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
Vector2 playerPos = {0,0};
Vector2 playerVel = {0,0};
float incSpeed = 0.1f;
float velocityCap = 3.0f;
//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!
    // Player movement
    if(IsKeyDown(KEY_D)){
      playerVel.x -= incSpeed;
      playerPos.x -= playerVel.x;
    }
    if(IsKeyDown(KEY_A)){
      playerVel.x += incSpeed;
      playerPos.x -= playerVel.x;
    }
    if(IsKeyDown(KEY_S)){
      playerVel.y += incSpeed;
      playerPos.y += playerVel.y;
    }
    if(IsKeyDown(KEY_W)){
      playerVel.y -= incSpeed;
      playerPos.y += playerVel.y;
    }
    if(playerVel.x >= velocityCap){
      playerVel.x = velocityCap;
    }
    if(playerVel.y >= velocityCap){
      playerVel.y = velocityCap;
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    DrawRectangleV(playerPos, (Vector2){32,64}, RED);
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
