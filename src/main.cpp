#include <raylib.h>
#include <iostream>
#include "ball.h"
#include "player.h"

using namespace std;

void DrawDashedLine(int startx, int starty, int endy, int dashLength, int spaceLength, Color color){
    for(int y = starty; y < endy; y += dashLength + spaceLength){
        DrawLine(startx, y, startx, y + dashLength, WHITE);
    }
}


//------------------------------------------------------------------------------------
// Ponto de entrada da main do programa
//------------------------------------------------------------------------------------
int main(void)
{
    // Inicialização
    //--------------------------------------------------------------------------------------
    const int screenWidth = 854;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Ace Pong");

    SetTargetFPS(60);               // Definir o jogo para rodar a 60 fps
    //--------------------------------------------------------------------------------------

    // Criação dos objetos
    Ball ball(screenWidth/2, screenHeight/2, 5, 5, 5, WHITE);
    Player playerPaddle(screenWidth - 30, screenHeight/2 - 25, 10, 10, 50, WHITE);

    // Main game loop
    while (!WindowShouldClose())    // Detecta o botão de fechar janela ou a tecla ESC
    {
        // Events
        //----------------------------------------------------------------------------------
        
        //----------------------------------------------------------------------------------

        // Update
        //----------------------------------------------------------------------------------
        ball.Update(screenWidth, screenHeight);
        playerPaddle.Update(screenHeight);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(DARKGRAY);
            DrawDashedLine(screenWidth / 2, -4, screenHeight, 14, 11, WHITE);
            DrawRectangle(10, screenHeight/2 - 30, 15, 60, WHITE);
            playerPaddle.Draw();
            ball.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha a janela e o OPEN GL
    //--------------------------------------------------------------------------------------

    return 0;
}