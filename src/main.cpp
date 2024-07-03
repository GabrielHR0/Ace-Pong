#include <raylib.h>
#include <iostream>
#include <cmath>
#include "ball.h"
#include "player.h"
#include "bot.h"
#include "secondplayer.h"
#include <sstream>

using namespace std;

void DrawDashedLine(int startx, int starty, int endy, int dashLength, int spaceLength, Color color){
    for(int y = starty; y < endy; y += dashLength + spaceLength){
        DrawLine(startx, y, startx, y + dashLength, WHITE);
    }
}


void DrawPoints(int screenWidth, Player player1, Secondplayer player2){
    DrawText(TextFormat("Player 1 Points: %i", player1.GetPoints()), screenWidth - 200, 10, 20, WHITE);
    DrawText(TextFormat("Player 2 Points: %i", player2.GetPoints()), 10, 10, 20, WHITE);

}

void DrawTime(int time, int screenWidth){
    DrawText(TextFormat("%i", time), screenWidth/2 - 20, 20, 40, WHITE);
}


//------------------------------------------------------------------------------------
// Ponto de entrada da main do programa
//------------------------------------------------------------------------------------
int main(void){
    // Inicialização
    //--------------------------------------------------------------------------------------
    const int screenWidth = 854;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Ace Pong");

    SetTargetFPS(60);               // Definir o jogo para rodar a 60 fps
    //--------------------------------------------------------------------------------------

    // Criação dos objetos
    Ball ball(screenWidth/2, screenHeight/2, 5, 5, 5, WHITE);
    Player playerPaddle(screenWidth - 30, screenHeight/2 - 25, 10, 10, 50, WHITE, 0);
    Secondplayer secondplayerPaddle(30, screenHeight/2 - 25, 10, 10, 50, WHITE, 0);
    //Bot botPaddle(30, screenHeight/2 - 25, 10, 10, 50, WHITE);

    // Main game loop
    while (!WindowShouldClose())    // Detecta o botão de fechar janela ou a tecla ESC
    {
        // Events
        //----------------------------------------------------------------------------------
        int time = GetTime();
        

        if(CheckCollisionCircleRec(Vector2{ball.pos_x, ball.pos_y}, ball.radius, Rectangle{playerPaddle.pos_x, playerPaddle.pos_y, (float)playerPaddle.width, (float)playerPaddle.height})) {
            ball.speed_x *= -1;
            float playerCenterY = playerPaddle.pos_y + playerPaddle.height / 2;
            ball.speed_y = (ball.pos_y - playerCenterY) / (playerPaddle.height / 2) * 5;
            
            // Se a colisão for exatamente no meio da raquete, fazer a bola ir reta
            if (ball.pos_y == playerCenterY) {
                ball.speed_y = 0;
            }
            ball.pos_x = playerPaddle.pos_x - ball.radius - 1;
        }
        
        if(CheckCollisionCircleRec(Vector2{ball.pos_x, ball.pos_y}, ball.radius, Rectangle{secondplayerPaddle.pos_x, secondplayerPaddle.pos_y, (float)secondplayerPaddle.width, (float)secondplayerPaddle.height})) {
             ball.speed_x *= -1;
                    float secondplayerCenterY = secondplayerPaddle.pos_y + secondplayerPaddle.height / 2;
                    ball.speed_y = (ball.pos_y - secondplayerCenterY) / (secondplayerPaddle.height / 2) * 5;
                    if (ball.pos_y == secondplayerCenterY) {
                        ball.speed_y = 0;
                    }
                    ball.pos_x = secondplayerPaddle.pos_x + secondplayerPaddle.width + ball.radius + 1;
                }

        /*if (CheckCollisionCircleRec(Vector2{ball.pos_x, ball.pos_y}, ball.radius, Rectangle{botPaddle.pos_x, botPaddle.pos_y, (float)botPaddle.width, (float)botPaddle.height})) {
            ball.speed_x *= -1;
            float botCenterY = botPaddle.pos_y + botPaddle.height / 2;
            ball.speed_y = (ball.pos_y - botCenterY) / (botPaddle.height / 2) * -5;
            
            // Se a colisão for aproximadamente no meio da raquete, fazer a bola ir reta
            if (fabs(ball.pos_y - botCenterY) < 1.0f) {
                ball.speed_y = 0;
            }
            
            // Ajusta a posição da bola para fora da raquete para evitar múltiplas detecções
            ball.pos_x = botPaddle.pos_x + botPaddle.width / 2 + ball.radius + 1;
        }

        */
        // Verificação de pontos
        char point = ball.Point(screenWidth, screenHeight);
        if (point == 'l'){
            secondplayerPaddle.IncreasePoints(); // Aumenta os pontos do jogador esquerdo
        } else if (point == 'r'){
            playerPaddle.IncreasePoints(); // Aumenta os pontos do jogador direito
        }
        cout << playerPaddle.points << endl;

        //----------------------------------------------------------------------------------

        // Update
        //----------------------------------------------------------------------------------
        ball.Update(screenWidth, screenHeight);
        
        playerPaddle.Update(screenHeight);
        //botPaddle.Update(ball.pos_y);
        secondplayerPaddle.Update(screenHeight);

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(DARKGRAY);
            DrawDashedLine(screenWidth / 2, -4, screenHeight, 14, 11, WHITE);
            DrawTime(time, screenWidth);
            DrawPoints(screenWidth, playerPaddle, secondplayerPaddle);
            //botPaddle.Draw();
            playerPaddle.Draw();
            ball.Draw();
            secondplayerPaddle.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha a janela e o OPEN GL
    //--------------------------------------------------------------------------------------

    return 0;
}