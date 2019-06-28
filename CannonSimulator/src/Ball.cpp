#include "Ball.h"

Ball::Ball(int radius, int points, int red, int green, int blue, int alpha)
:CircleShape(radius, points)
{
    speed = 0;
    weight = 1;
    mod = 0.5;
    this->setOrigin((radius*2)/2, (radius*2)/2);
}

Ball::~Ball()
{
    //dtor
}

void Ball::doGravity(int floorPosition)
{
    if(this->getPosition().y+this->getRadius()>=floorPosition)
    {
        speed = 0;
        this->setPosition(this->getPosition().x, floorPosition-this->getRadius());
    }
    else
    {
        speed+=1;
        this->move(0, mod*(speed*weight));
    }
}
