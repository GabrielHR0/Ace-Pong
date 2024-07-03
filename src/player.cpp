#include "player.h"
// Inicialização das características da raquete.
Player::Player(float x, float y,  int s, int w, int h, Color c){
    pos_x = x;
    pos_y = y;
    speed = s;
    width = w;
    height = h;
    color = c;
}
// Desenho do retângulo.
void Player::Draw(){
    DrawRectangle(pos_x, pos_y, width, height, color);
    // x position screenWidth - largura + padding | y position screenHeigth/2 - altura/2 | largura | altura | cor
}

void Player::Update(int screenHeight){
    if (IsKeyDown(KEY_UP) && pos_y > 0){ // Verificação da tecla (seta para cima).
        pos_y -= speed; // Jogador vai para cima.
    }

    if (IsKeyDown(KEY_DOWN) && pos_y < screenHeight - height){ // Verificação da tecla (seta para baixo).
        pos_y += speed; // Jogador vai para baixo.
    }
}