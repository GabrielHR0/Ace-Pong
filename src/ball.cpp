#include "ball.h"

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

    if(pos_y <= -radius){
        speed_y *= -1;
    }
    if(pos_y >= screenHeight - radius){
        speed_y *= -1;
    }

    if(pos_x >= screenWidth - radius){
        Reset(screenWidth, screenHeight);
    }
    if(pos_x <= -radius){
        Reset(screenWidth, screenHeight);
    }
}

void Ball::Ace(string side){
    //if (side == "left"){;}
    //if (side == "right"){;}
}

void Ball::Reset(int screenWidth, int screenHeight){
    pos_x = screenWidth/2;
    pos_y = screenHeight/2;
}