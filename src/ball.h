#ifndef BALL_H // Verifica se BALL_H não está definida
#define BALL_H // Define BALL_H
#include <raylib.h>
#include <iostream>
#include <string>
using namespace std;

// Criação da classe bola, contendo todas as características dela.
class Ball {
    public:
        float pos_x, pos_y; // Posição da bola, horizontal e vertical.
        int speed_x, speed_y;// Velocidade da bola, horizontal e vertical.
        int radius; // Tamanho da bola.
        Color color; // Cor da bola.

        Ball(float x, float y, int sx, int sy, int r, Color c);
        
        void Draw(); // Desenha a bola na tela.
        void Update(int screenWidth, int screenHeight); // Atualiza a posiçao da bola, dentro dos limites da tela.
        void Reset(int screenWidth, int screenHeight); // Posição da bola é resetada para o centro da tela.
        void ResetSpeed(string side); // Ajuste da velocidade da bola.
        char Point(int screenWidth, int screenHeight); // Verifica se foi ponto de algum jogador ou bot;
};

#endif // BALL_H
