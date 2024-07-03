#ifndef BALL_H // Verifica se BALL_H não está definida
#define BALL_H // Define BALL_H
#include <raylib.h>
#include <iostream>
#include <string>
using namespace std;

<<<<<<< HEAD

class Ball {
    public:
        float pos_x, pos_y;
        int speed_x, speed_y;
        int radius;
        Color color;

        Ball(float x, float y, int sx, int xy, int r, Color c);

        void Draw();
        void Update(int screenWidth, int screenHeight);
        void Reset(int screenWidth, int screenHeight);
        void ResetSpeed(string side);
=======
// Criação da classe bola, contendo todas as características dela.
class Ball {
    public:
        float pos_x, pos_y; // Posição da bola, horizontal e vertical.
        int speed_x, speed_y;// Velocidade da bola, horizontal e vertical.
        int radius; // Tamanho da bola.
        Color color; // Cor da bola.

        Ball(float x, float y, int sx, int xy, int r, Color c);
        
        void Draw(); // Desenha a bola na tela.
        void Update(int screenWidth, int screenHeight); // Atualiza a posiçao da bola, dentro dos limites da tela.
        void Reset(int screenWidth, int screenHeight); // Posição da bola é resetada para o centro da tela.
        void ResetSpeed(string side); // Ajuste da velocidade da bola.
>>>>>>> 32bd9eb53c21aa3403371fb1055a2bac4d155454
};

#endif // BALL_H
