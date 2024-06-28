#include "bot.h"
#include "ball.h"

Bot::Bot(float x, float y,  int s, int w, int h, Color c){
    pos_x = x;
    pos_y = y;
    speed = s;
    width = w;
    height = h;
    color = c;
}

void Bot::Draw(){
    DrawRectangle(pos_x, pos_y, width, height, color);
    // x position screenWidth - largura + padding | y position screenHeigth/2 - altura/2 | largura | altura | cor
}

void Bot::Update(int ball_y){
     if (pos_y + height/2 > ball_y){
        pos_y = pos_y - speed;
    }
    if (pos_y + height/2 <= ball_y){
        pos_y = pos_y + speed;
    }    
    LimitMovement();
};
