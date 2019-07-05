#ifndef BALL_H
#define BALL_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

extern sf::Sound soundWooden;
extern sf::Sound soundRubber;
extern sf::Sound soundMetal;
extern sf::Sound soundAether;
extern sf::Sound soundPulsar;
extern sf::Sound soundCannonFire;

enum materials
{
    wooden = 0,
    rubber = 1,
    metal = 2,
    aether = 3,
    pulsar = 4
};

class Ball : public sf::CircleShape
{
    public:
        Ball(int radius, materials material, int points = 30);
        virtual ~Ball();
        void doGravity(int floorPosition);
        bool isBallTouchingGround(int floorPosition);
        bool isBallStoped(int floorPosition);
        bool willBallBeOutOfFloor;

        float speedY;
        float speedX;
        float weight;
        float maxSpeedY;
        float accelerationY;
        float bounciness;
        materials ballMaterial;

    protected:

    private:
};



#endif // BALL_H
