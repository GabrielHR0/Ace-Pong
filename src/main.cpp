#include <raylib.h>
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------------
// Ponto de entrada da main do programa
//------------------------------------------------------------------------------------
int main(void){
    printf ("aaaaaaa;");
    // Inicialização
    //--------------------------------------------------------------------------------------
    const int screenWidth = 854;
    const int screenHeight = 480;

    InitWindow(screenWidth, screenHeight, "Ace Pong");

    SetTargetFPS(60);               // Definir o jogo para rodar a 60 fps
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detecta o botão de fechar janela ou a tecla ESC
    {
        // Events
        //----------------------------------------------------------------------------------
        
        //----------------------------------------------------------------------------------

        // Update
        //----------------------------------------------------------------------------------
        
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(DARKGRAY);
            DrawCircle(screenWidth/2, screenHeight/2, 10, WHITE);
            DrawRectangle(10, screenHeight/2 - 30, 15, 60, WHITE);
            DrawRectangle(screenWidth - 25, screenHeight/2 - 30, 15, 60, WHITE);
            DrawLine(screenWidth/2, 0, screenWidth/2, screenHeight, WHITE);



        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Fecha a janela e o OPEN GL
    //--------------------------------------------------------------------------------------

    return 0;
}