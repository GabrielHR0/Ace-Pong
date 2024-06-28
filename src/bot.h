#ifndef BOT_H
#define BOT_H
#include <raylib.h>
#include "ball.h"

// Criação do cabeçalho bot.h
class Bot {
    protected:
    void LimitMovement(){
        // Verificação da posição do bot, para que ele não ultrapasse os limites da tela. 
        if (pos_y <= 0){
            pos_y = 0; // Para a bola não sair pela parte de cima da tela.
        }if (pos_y + height >= GetScreenHeight()){
            pos_y = GetScreenHeight () - height; // Para a bola não sair pela parte de baixo da tela.
        }
        
    }
    // Criação das características do bot: velocidade, posição, cor e dimensões.
    public:
        float pos_x, pos_y;
        int speed;  
        int width, height;
        Color color;

        Bot(float x, float y, int s, int w, int h, Color c);
    
    void Draw(); // Desenho do bot.
    void Update(int ball_pos_y); // Atualização da posição do bot, dependendo da posição vertical da bola.
};

#endif