#include "player.h"
<<<<<<< HEAD

=======
// Inicialização das características da raquete.
>>>>>>> 32bd9eb53c21aa3403371fb1055a2bac4d155454
Player::Player(float x, float y,  int s, int w, int h, Color c){
    pos_x = x;
    pos_y = y;
    speed = s;
    width = w;
    height = h;
    color = c;
}
<<<<<<< HEAD

=======
// Desenho do retângulo.
>>>>>>> 32bd9eb53c21aa3403371fb1055a2bac4d155454
void Player::Draw(){
    DrawRectangle(pos_x, pos_y, width, height, color);
    // x position screenWidth - largura + padding | y position screenHeigth/2 - altura/2 | largura | altura | cor
}

void Player::Update(int screenHeight){
<<<<<<< HEAD
    if (IsKeyDown(KEY_UP) && pos_y > 0){
        pos_y -= speed;
    }

    if (IsKeyDown(KEY_DOWN) && pos_y < screenHeight - height){
        pos_y += speed;
=======
    if (IsKeyDown(KEY_UP) && pos_y > 0){ // Verificação da tecla (seta para cima).
        pos_y -= speed; // Jogador vai para cima.
    }

    if (IsKeyDown(KEY_DOWN) && pos_y < screenHeight - height){ // Verificação da tecla (seta para baixo).
        pos_y += speed; // Jogador vai para baixo.
>>>>>>> 32bd9eb53c21aa3403371fb1055a2bac4d155454
    }
}