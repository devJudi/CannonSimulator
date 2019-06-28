#include "Ball.h"

Ball::Ball(int radius, int points, int red, int green, int blue, int alpha)
:CircleShape(radius, points)
{
    speed = 0;
    weight = 1;
    this->setOrigin((radius*2)/2, (radius*2)/2);
}

Ball::~Ball()
{
    //dtor
}
