#include "Ball.h"

Ball::Ball(int radius, materials material, int points)
    :CircleShape(radius, points)
{
    speedY = 0;
    speedX = 20;
    weight = 1;
    mod = 0.5;
    this->setOrigin((radius*2)/2, (radius*2)/2);
    ballMaterial = material;

    switch (material)
    {
    case wooden:
        {
            this->setFillColor(sf::Color(220, 100, 0, 240));
            weight = 76.84;
            break;
        }
    case rubber:
        {
            this->setFillColor(sf::Color(220, 20, 100, 220));
            weight = 158.2;
            break;
        }
    case metal:
        {
            this->setFillColor(sf::Color(100, 100, 100, 255));
            weight = 881.4;
            break;
        }
    case aether:
        {
            this->setFillColor(sf::Color(255, 255, 10, 255));
            weight = 33.9;
            break;
        }
    case pulsar:
        {
            this->setFillColor(sf::Color(10, 10, 10, 255));
            this->setOutlineThickness(-1);
            this->setOutlineColor(sf::Color::White);
            weight = 113000;
            break;
        }
    }

    maxSpeedY = 16*weight;

}

Ball::~Ball()
{
    //dtor
}

void Ball::doGravity(int floorPosition)
{
    if(speedX>10) speedX-=0.02;
    else if(speedX>50) speedX-=0.015;
    else if(speedX>0) speedX-=0.01;

    if(this->getPosition().y+this->getRadius()>=floorPosition)
    {
        this->setPosition(this->getPosition().x, floorPosition-this->getRadius());
        if(speedY>3)
        {
            if(ballMaterial==wooden)
            {
                 speedY/=-2;
                 if(speedY*speedY>100)   woodenSound.setVolume(100);
                 else if(speedY*speedY>64)   woodenSound.setVolume(80);
                 else if(speedY*speedY>36)   woodenSound.setVolume(60);
                 else if(speedY*speedY>16)   woodenSound.setVolume(40);
                 else   woodenSound.setVolume(20);
                 woodenSound.play();
            }
            else if(ballMaterial==rubber)
            {
                speedY/=-1.4;
                if(speedY*speedY>100)   rubberSound.setVolume(100);
                else if(speedY*speedY>64)   rubberSound.setVolume(80);
                else if(speedY*speedY>36)   rubberSound.setVolume(60);
                else if(speedY*speedY>16)   rubberSound.setVolume(40);
                else   rubberSound.setVolume(20);
                rubberSound.play();
            }
            else if(ballMaterial==metal)
            {
                speedY/=-4;
                if(speedY*speedY>100)   metalSound.setVolume(100);
                else if(speedY*speedY>64)   metalSound.setVolume(80);
                else if(speedY*speedY>36)   metalSound.setVolume(60);
                else if(speedY*speedY>16)   metalSound.setVolume(40);
                else   metalSound.setVolume(20);
                metalSound.play();
            }
            else if(ballMaterial==aether)
            {
                speedY/=-1.1;
                if(speedY*speedY>100)   aetherSound.setVolume(100);
                else if(speedY*speedY>64)   aetherSound.setVolume(80);
                else if(speedY*speedY>36)   aetherSound.setVolume(60);
                else if(speedY*speedY>16)   aetherSound.setVolume(40);
                else   aetherSound.setVolume(20);
                aetherSound.play();
            }
            else if(ballMaterial==pulsar)
            {
                speedY/=-80;
                if(speedY*speedY>100)   pulsarSound.setVolume(100);
                else if(speedY*speedY>64)   pulsarSound.setVolume(80);
                else if(speedY*speedY>36)   pulsarSound.setVolume(60);
                else if(speedY*speedY>16)   pulsarSound.setVolume(40);
                else   pulsarSound.setVolume(20);
                pulsarSound.play();
            }

            this->move(0, -1);
        }
        else
        {
            speedY = 0;
            if(speedX>2)
            {
                speedX-=0.5;
                this->move(speedX, 0);
            }
        }
    }
    else
    {
        speedY+=1;
        this->move(speedX, mod*speedY);
    }
}
