#ifndef BALL_H
#define BALL_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

extern sf::SoundBuffer woodenSoundBuffer;
extern sf::SoundBuffer rubberSoundBuffer;
extern sf::SoundBuffer metalSoundBuffer;
extern sf::SoundBuffer aetherSoundBuffer;
extern sf::SoundBuffer pulsarSoundBuffer;

extern sf::Sound woodenSound;
extern sf::Sound rubberSound;
extern sf::Sound metalSound;
extern sf::Sound aetherSound;
extern sf::Sound pulsarSound;

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

        float speedY;
        float speedX;
        float weight;
        float mod;
        float maxSpeedY;
        materials ballMaterial;

    protected:

    private:
};



#endif // BALL_H
