#include <raylib.h> // Inclusão para o desenvolvimento dos objetos na tela.
#include <iostream> // Biblioteca padrão do C++.
#include <cmath> // Inclusão para calcular o posicionamento da bola e das raquetes.
#include <windows.h> // Criação de janelas para o menu.
#include "ball.h" // Acesso ao cabeçalho ball.h.
#include "player.h" // Acesso ao cabeçalho player.h.
#include "bot.h" // Acesso ao cabeçalho bot.h.
#include "secondplayer.h"
using namespace std;

// Desenho da linha que divide a área do bot e do jogador.
void DrawDashedLine(int startx, int starty, int endy, int dashLength, int spaceLength, Color color){
    for(int y = starty; y < endy; y += dashLength + spaceLength){
        DrawLine(startx, y, startx, y + dashLength, WHITE);
    }
}


//------------------------------------------------------------------------------------
// Ponto de entrada da main do programa
//------------------------------------------------------------------------------------
int main(void){
    // Inicialização
    //--------------------------------------------------------------------------------------
    // Tamanho da tela:
    const int screenWidth = 854;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Ace Pong"); // Nome da janela.

    SetTargetFPS(60);               // Definir o jogo para rodar a 60 fps
    //--------------------------------------------------------------------------------------

    // Criação dos objetos
    Ball ball(screenWidth/2, screenHeight/2, 5, 5, 5, WHITE);
    Player playerPaddle(screenWidth - 30, screenHeight/2 - 25, 10, 10, 50, WHITE);
    //Secondplayer secondplayerPaddle(screenWidth - 30, screenHeight/2 - 25, 10, 10, 50, WHITE);
    Bot botPaddle(30, screenHeight/2 - 25, 10, 10, 50, WHITE);

    // Main game loop
    while (!WindowShouldClose())    // Detecta o botão de fechar janela ou a tecla ESC
    {
        // Events
        //----------------------------------------------------------------------------------
        if(CheckCollisionCircleRec(Vector2{ball.pos_x, ball.pos_y}, ball.radius, Rectangle{playerPaddle.pos_x, playerPaddle.pos_y, (float)playerPaddle.width, (float)playerPaddle.height})) {
            ball.speed_x *= -1;
            float playerCenterY = playerPaddle.pos_y + playerPaddle.height / 2;
            ball.speed_y = (ball.pos_y - playerCenterY) / (playerPaddle.height / 2) * -5;
            
            // A bola faz a trajetória reta se atingir o meio da raquete.
            if (ball.pos_y == playerCenterY) {
                ball.speed_y = 1;
            }
            ball.pos_x = playerPaddle.pos_x - ball.radius - 1;
        }

        if (CheckCollisionCircleRec(Vector2{ball.pos_x, ball.pos_y}, ball.radius, Rectangle{botPaddle.pos_x, botPaddle.pos_y, (float)botPaddle.width, (float)botPaddle.height})) {
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
       
        cout << playerPaddle.pos_y << endl;
        //----------------------------------------------------------------------------------

        // Update
        //----------------------------------------------------------------------------------
        ball.Update(screenWidth, screenHeight); // Atualização da posição da bola, seguindo os parâmetros do tamanho vertical e horizontal da tela.
        playerPaddle.Update(screenHeight); // Raquete do player é atualizada a partir da orientação vertical da bola.
        botPaddle.Update(ball.pos_y); // O bot se move a partir da posição vertical da bola.
        //secondplayerPaddle.Update(screenHeight);

        //----------------------------------------------------------------------------------

        // Desenho dos objetos:
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(DARKGRAY);
            DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, WHITE);
            DrawDashedLine(screenWidth / 2, -4, screenHeight, 14, 11, WHITE);
            botPaddle.Draw();
            playerPaddle.Draw();
            ball.Draw();
            //secondplayerPaddle.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha a janela e o OPEN GL
    //--------------------------------------------------------------------------------------

    return 0;
}