#ifndef PLAYER_H
#define PLAYER_H
#include <raylib.h>
// Construção do cabeçalho player.h.
class Player {       
    public:
        float pos_x, pos_y; // Posição da raquete do player, vertical e horizontal.
        int speed; // Velocidade da raquete.
        int width, height; // Dimensões da raquete.
        Color color; // Cor da raquete.
        int points; // Pontos do jogador

        Player(float x, float y, int s, int w, int h, Color c, int p);
    
    void Draw(); // Desenho.
    void Update(int screenHeight); // Atualização com a partir do tamanho na orientação vertical da tela.
    void IncreasePoints(); // Novo método para aumentar os pontos
    int GetPoints() const; // Novo método para obter os pontos
};

#endif