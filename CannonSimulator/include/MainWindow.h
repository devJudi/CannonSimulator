#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "Ball.h"

extern sf::SoundBuffer woodenSoundBuffer;
extern sf::SoundBuffer rubberSoundBuffer;
extern sf::SoundBuffer metalSoundBuffer;
extern sf::SoundBuffer aetherSoundBuffer;
extern sf::SoundBuffer pulsarSoundBuffer;
extern sf::SoundBuffer cannonFireSoundBuffer;;

extern sf::Sound woodenSound;
extern sf::Sound rubberSound;
extern sf::Sound metalSound;
extern sf::Sound aetherSound;
extern sf::Sound pulsarSound;
extern sf::Sound cannonFireSound;

extern sf::RectangleShape cannonFire;
extern bool shouldCannonFireBeVisible;

extern float cannonPower;
extern float cannonAngle;

class MainWindow : public sf::RenderWindow
{
    public:
        MainWindow(int x, int y, std::string name, int fps = 60);
        virtual ~MainWindow();
        sf::View view;
        bool shouldWatchBack;

        void loadSounds();
        void handleEvent(sf::Event event, std::vector <Ball> &balls, int &numberOfBalls, materials &materialType);

    protected:

    private:
};

#endif // MAINWINDOW_H
