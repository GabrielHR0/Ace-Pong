#include "ball.h"

<<<<<<< HEAD
Ball::Ball(float x, float y, int sx, int sy, int r, Color c){
    pos_x = x;
    pos_y = y;
    speed_x = sx;
    speed_y = sy;
    radius = r;
    color = c;
}

void Ball::Draw() {
    DrawCircle(pos_x, pos_y, radius, color);
}

void Ball::Update(int screenWidth, int screenHeight){
    pos_x += speed_x;
    pos_y += speed_y;

    if(pos_y <= radius){
        speed_y *= -1;
        pos_y = radius;
    }
    if(pos_y >= screenHeight - radius){
        speed_y *= -1;
        pos_y = screenHeight - radius;
    }

    if(pos_x >= screenWidth - radius){
        Reset(screenWidth, screenHeight);
        ResetSpeed("right");
    }
    if(pos_x <= radius){
        Reset(screenWidth, screenHeight);
        ResetSpeed("left");
    }
}

void Ball::ResetSpeed(string side){
    if (side == "left"){
        speed_y = -5;
        }
    if (side == "right"){
        speed_y = 5;
    }
}

void Ball::Reset(int screenWidth, int screenHeight){
    pos_x = screenWidth/2;
    pos_y = screenHeight/2;
    
}

=======
// Inicialização dos parâmetros para a classe da bola.
Ball::Ball(float x, float y, int sx, int sy, int r, Color c){
    pos_x = x; // Posição horizontal da bola.
    pos_y = y; // Posição vertical da bola.
    speed_x = sx; // Velocidade horizontal da bola.
    speed_y = sy; // Velocidade vertical da bola.
    radius = r; // Raio da bola.
    color = c; // Cor da bola.
}

void Ball::Draw() { // Função que desenha a bola na tela.
    DrawCircle(pos_x, pos_y, radius, color);
}

void Ball::Update(int screenWidth, int screenHeight){ 

    // Atualização da posição da bola na tela, junto com o aumento da velocidade.
    pos_x += speed_x;
    pos_y += speed_y;

    // Verifica se a bola atingiu o topo ou o fundo da tela, invertendo sua posição para que não ultrapasse da tela:
    if(pos_y <= radius){
        speed_y *= -1;
        pos_y = radius;
    }
    if(pos_y >= screenHeight - radius){
        speed_y *= -1;
        pos_y = screenHeight - radius;
    }

    // Verifica se a bola ultrapassou a tela para direita ou esquerda, resetando sua posição no centro da tela.
    if(pos_x >= screenWidth - radius){
        Reset(screenWidth, screenHeight);
        ResetSpeed("right");
    }
    if(pos_x <= radius){
        Reset(screenWidth, screenHeight);
        ResetSpeed("left");
    }
}

void Ball::ResetSpeed(string side){
    if (side == "left"){
        speed_y = -5;
        }
    if (side == "right"){
        speed_y = 5;
    }
}

void Ball::Reset(int screenWidth, int screenHeight){ // Reposiciona a bola.
    pos_x = screenWidth/2;
    pos_y = screenHeight/2;
    
}
>>>>>>> 32bd9eb53c21aa3403371fb1055a2bac4d155454
