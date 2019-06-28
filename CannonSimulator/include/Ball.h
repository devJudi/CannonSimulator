#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>


class Ball : public sf::CircleShape
{
    public:
        Ball(int radius, int points = 30, int red = 100, int green = 100, int blue = 100, int alpha = 100);
        virtual ~Ball();
        void doGravity(int floorPosition);

        int speed;
        int weight;
        float mod;

    protected:

    private:
};

#endif // BALL_H
