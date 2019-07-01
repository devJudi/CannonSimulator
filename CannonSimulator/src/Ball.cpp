#include "Ball.h"

Ball::Ball(int radius, materials material, int points)
    :CircleShape(radius, points)
{
    speed = 0;
    weight = 1;
    mod = 0.5;
    this->setOrigin((radius*2)/2, (radius*2)/2);
    ballMaterial = material;

    switch (material)
    {
    case wooden:
        {
            this->setFillColor(sf::Color(220, 100, 0, 240));
            break;
        }
    case rubber:
        {
            this->setFillColor(sf::Color(220, 20, 100, 220));
            break;
        }
    case metal:
        {
            this->setFillColor(sf::Color(100, 100, 100, 255));
            break;
        }
    case aether:
        {
            this->setFillColor(sf::Color(255, 255, 10, 255));
            break;
        }
    case pulsar:
        {
            this->setFillColor(sf::Color(10, 10, 10, 255));
            this->setOutlineThickness(-1);
            this->setOutlineColor(sf::Color::White);
            break;
        }
    }

}

Ball::~Ball()
{
    //dtor
}

void Ball::doGravity(int floorPosition)
{
    if(this->getPosition().y+this->getRadius()>=floorPosition)
    {
        this->setPosition(this->getPosition().x, floorPosition-this->getRadius());
        if(speed>3)
        {
            if(ballMaterial==wooden)
                speed/=-2;
            else if(ballMaterial==rubber)
                speed/=-1.4;
            else if(ballMaterial==metal)
                speed/=-4;
            else if(ballMaterial==aether)
                speed/=-1.1;
            else if(ballMaterial==pulsar)
                this->move(0, 1);

            this->move(0, -1);
        }
        else
        {
            speed = 0;
        }
    }
    else
    {
        speed+=1;
        this->move(0, mod*(speed*weight));
    }
}
