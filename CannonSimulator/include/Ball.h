#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

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

        int speed;
        int weight;
        float mod;
        materials ballMaterial;

    protected:

    private:
};



#endif // BALL_H
