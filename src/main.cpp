#include "raylib.h"
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <conio.h>
#include <sstream>
#include "ball.h"
#include "bot.h"
#include "player.h"
#include "secondplayer.h"

using namespace std;

void DrawDashedLine(int startx, int starty, int endy, int dashLength, int spaceLength, Color color) {
    for(int y = starty; y < endy; y += dashLength + spaceLength) {
        DrawLine(startx, y, startx, y + dashLength, WHITE);
    }
}

void DrawPoints(int screenWidth, Player player1, Secondplayer player2) {
    DrawText(TextFormat("Player 1 Points: %i", player1.GetPoints()), screenWidth - 200, 10, 20, WHITE);
    DrawText(TextFormat("Player 2 Points: %i", player2.GetPoints()), 10, 10, 20, WHITE);
}

void DrawTime(int time, int screenWidth) {
    DrawText(TextFormat("%i", time), screenWidth / 2 - 20, 20, 40, WHITE);
}

void jogo(string gameMode) {
    const int screenWidth = 854;
    const int screenHeight = 480;
    InitWindow(screenWidth, screenHeight, "Ace Pong");
    SetTargetFPS(60);  // Definir o jogo para rodar a 60 fps

    // Criação dos objetos
    Ball ball(screenWidth / 2, screenHeight / 2, 7, 7, 5, WHITE);
    Secondplayer secondplayerPaddle(30, screenHeight / 2 - 25, 10, 10, 50, WHITE, 0);
    Bot botPaddle(30, screenHeight / 2 - 25, 10, 10, 50, WHITE, 0);
    Player playerPaddle(screenWidth - 30, screenHeight / 2 - 25, 10, 10, 50, WHITE, 0);

    int startTime = GetTime();
    bool gameStarted = true;
    bool gameOver = false;
    bool paused = false; // Variável de controle de pausa
    char winner[20];

    int time = 0;
    // Main game loop
    while (!WindowShouldClose()) {
        // Verifica se a tecla P foi pressionada para alternar o estado de pausa
        if (IsKeyPressed(KEY_P)) {
            paused = !paused;
        }

        // Atualizações do jogo
        if (!paused && gameStarted) {
            time = GetTime() - startTime;

            if (CheckCollisionCircleRec(Vector2{ball.pos_x, ball.pos_y}, ball.radius, Rectangle{playerPaddle.pos_x, playerPaddle.pos_y, (float)playerPaddle.width, (float)playerPaddle.height})) {
                ball.speed_x *= -1;
                float playerCenterY = playerPaddle.pos_y + playerPaddle.height / 2;
                ball.speed_y = (ball.pos_y - playerCenterY) / (playerPaddle.height / 2) * 5;
                
                // Se a colisão for exatamente no meio da raquete, fazer a bola ir reta
                if (ball.pos_y == playerCenterY) {
                    ball.speed_y = 0;
                }
                ball.pos_x = playerPaddle.pos_x - ball.radius - 1;
            }

            if (gameMode == "secondplayer"){
                if (CheckCollisionCircleRec(Vector2{ball.pos_x, ball.pos_y}, ball.radius, Rectangle{secondplayerPaddle.pos_x, secondplayerPaddle.pos_y, (float)secondplayerPaddle.width, (float)secondplayerPaddle.height})) {
                ball.speed_x *= -1;
                float secondplayerCenterY = secondplayerPaddle.pos_y + secondplayerPaddle.height / 2;
                ball.speed_y = (ball.pos_y - secondplayerCenterY) / (secondplayerPaddle.height / 2) * 5;
                if (ball.pos_y == secondplayerCenterY) {
                    ball.speed_y = 0;
                }
                ball.pos_x = secondplayerPaddle.pos_x + secondplayerPaddle.width + ball.radius + 1;
                }
            }
            
            if (gameMode == "bot"){
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
            }
            
            // Verificação de pontos
            char point = ball.Point(screenWidth, screenHeight);
            if (point == 'l') {
                secondplayerPaddle.IncreasePoints();  // Aumenta os pontos do jogador esquerdo
            } else if (point == 'r') {
                playerPaddle.IncreasePoints();  // Aumenta os pontos do jogador direito
            }

            // Verifica se algum jogador atingiu 11 pontos
            if (playerPaddle.GetPoints() == 11 || secondplayerPaddle.GetPoints() == 11 || botPaddle.GetPoints() == 11) {
                gameOver = true;
                gameStarted = false;
                if (playerPaddle.GetPoints() == 11) {
                    snprintf(winner, sizeof(winner), "Player 1 Ganhou!");
                } else if (secondplayerPaddle.GetPoints() == 11) {
                    snprintf(winner, sizeof(winner), "Player 2 Ganhou!");
                } else {
                    snprintf(winner, sizeof(winner), "Bot Ganhou!");
                }
            }

            if (!gameOver) {
                ball.Update(screenWidth, screenHeight);
                playerPaddle.Update(screenHeight);
                if (gameMode =="secondplayer"){
                    secondplayerPaddle.Update(screenHeight);
                }
                if (gameMode == "bot"){
                    botPaddle.Update(ball.pos_y, ball.pos_x);
                }
            }
        }

        // Desenho na tela
        BeginDrawing();
            ClearBackground(DARKGRAY);

            if (paused) {
                DrawText("JOGO PAUSADO - Pressione P para continuar", screenWidth / 2 - MeasureText("JOGO PAUSADO - Pressione P para continuar", 20) / 2, screenHeight / 2 - 20, 20, GRAY);
            } else {
                if (gameOver) {
                    ClearBackground(DARKGRAY);
                    DrawText(winner, screenWidth / 2 - MeasureText(winner, 40) / 2, screenHeight / 2 - 20, 40, WHITE);
                    DrawText("Pressione a tecla ESPAÇO para sair do jogo.", screenWidth / 2 - MeasureText("Pressione a tecla ESPAÇO para sair do jogo.", 20) / 2, screenHeight / 2 + 80, 20, WHITE);

                    if(IsKeyPressed(KEY_SPACE)){
                        CloseWindow();
                        break;  // Sai do loop principal e termina o jogo
                    }
                } else {
                    DrawDashedLine(screenWidth / 2, -4, screenHeight, 14, 11, WHITE);
                    DrawTime(time, screenWidth);
                    DrawPoints(screenWidth, playerPaddle, secondplayerPaddle);
                    if (gameMode == "bot"){
                        botPaddle.Draw();
                    }
                    if (gameMode == "secondplayer"){
                        secondplayerPaddle.Draw();
                    }
                    playerPaddle.Draw();
                    ball.Draw();
                }
            }
        EndDrawing();
    }
    CloseWindow();  // Fecha a janela e o OPEN GL
}

void instrucoes() {
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    while (!WindowShouldClose() && !IsKeyPressed(KEY_SPACE)) {
        BeginDrawing();
            ClearBackground(GRAY);
            DrawText("INSTRUÇÕES:", screenWidth / 2 - MeasureText("INSTRUÇÕES:", 30) / 2, 50, 30, WHITE);
            DrawText("1 - NÃO DEIXE O OPONENTE PONTUAR", 50, 100, 20, WHITE);
            DrawText("2 - CONTROLE UTILIZANDO AS SETAS DE CIMA E BAIXO OU O W/S", 50, 130, 20, WHITE);
            DrawText("3 - COMPLETE 11 PONTOS PRIMEIRO DO QUE O ADVERSÁRIO", 50, 160, 20, WHITE);
            DrawText("4 - USE A TECLA P PARA PAUSAR O JOGO", 50, 190, 20, WHITE);
            DrawText("5 - DIVIRTA-SE!", 50, 210, 20, WHITE);
            DrawText("Pressione a tecla ESPAÇO para retornar ao MENU.", 50, 290, 20, WHITE);
        EndDrawing();
    }
}

void menu(){
    const int screenWidth = 854;
    const int screenHeight = 480;
    InitWindow(screenWidth, screenHeight, "ACE PONG MENU");
    Rectangle player1Button = { screenWidth / 2 - 150, 180, 300, 50 };
    Rectangle botButton = { screenWidth / 2 - 150, 240, 300, 50 };
    Rectangle instructionsButton = { screenWidth / 2 - 150, 300, 300, 50 };
    Rectangle exitButton = { screenWidth / 2 - 150, 360, 300, 50 };
    SetTargetFPS(60);

    
    while (!WindowShouldClose()) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            Vector2 mousePoint = GetMousePosition();

            if (CheckCollisionPointRec(mousePoint, player1Button)) {
                jogo("secondplayer");
            }
            if (CheckCollisionPointRec(mousePoint, botButton)) {
                jogo("bot");
            }
            if (CheckCollisionPointRec(mousePoint, instructionsButton)) {
                instrucoes();
            }
            if (CheckCollisionPointRec(mousePoint, exitButton)) {
                CloseWindow();
                break;
            }
        }

        // Draw
        BeginDrawing();
            ClearBackground(GRAY);

            DrawText("ACE PONG!", screenWidth / 2 - MeasureText("ACE PONG!", 30) / 1.25, 80, 50, BLACK);

            DrawRectangleRec(player1Button, BLACK);
            DrawRectangleRec(botButton, BLACK);
            DrawRectangleRec(instructionsButton, BLACK);
            DrawRectangleRec(exitButton, BLACK);
            
            DrawText("JOGAR - 2 PLAYERS", player1Button.x + 45, player1Button.y + 15, 20, WHITE);
            DrawText("JOGAR - 1 PLAYER", botButton.x + 50, botButton.y + 15, 20, WHITE);
            DrawText("INSTRUÇÕES", instructionsButton.x + 75, instructionsButton.y + 15, 20, WHITE);
            DrawText("SAIR", exitButton.x + 120, exitButton.y + 15, 20, WHITE);
        EndDrawing();
    }

    CloseWindow();
}

int main(void) {
    menu();
    return 0;
}
