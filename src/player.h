#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>
<<<<<<< HEAD

class Player {
    public:
        float pos_x, pos_y;
        int speed;
        int width, height;
        Color color;

        Player(float x, float y, int s, int w, int h, Color c);
    
    void Draw();
    void Update(int screenHeight);
=======
// Construção do cabeçalho player.h.
class Player {       
    public:
        float pos_x, pos_y; // Posição da raquete do player, vertical e horizontal.
        int speed; // Velocidade da raquete.
        int width, height; // Dimensões da raquete.
        Color color; // Cor da raquete.

        Player(float x, float y, int s, int w, int h, Color c);
    
    void Draw(); // Desenho.
    void Update(int screenHeight); // Atualização com a partir do tamanho na orientação vertical da tela.
>>>>>>> 32bd9eb53c21aa3403371fb1055a2bac4d155454
};

#endif