#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <vector>
#include "Ball.h"

extern sf::Sound soundWooden;
extern sf::Sound soundRubber;
extern sf::Sound soundMetal;
extern sf::Sound soundAether;
extern sf::Sound soundPulsar;
extern sf::Sound soundCannonFire;

extern sf::Text textBasicXPosition;
extern sf::Text textCurrentXPosition;
extern sf::Text textBasicYPosition;
extern sf::Text textCurrentYPosition;
extern sf::Text textBasicPreviousXPosition;
extern sf::Text textCurrentPreviousXPosition;
extern sf::Text textBasicPreviousYPosition;
extern sf::Text textCurrentPreviousYPosition;

extern sf::RectangleShape shapeCannonFire;

extern bool shouldCannonFireBeVisible;
extern float cannonPower;
extern float cannonPowerMod;
extern float cannonAngle;

class MainWindow : public sf::RenderWindow
{
    public:
        MainWindow(int x, int y, std::string name, int fps = 60);
        virtual ~MainWindow();
        sf::View view;
        bool shouldWatchBack;

        void handleEvent(sf::Event event, std::vector <Ball> &balls, int &numberOfBalls, materials &materialType);

    protected:

    private:
};

#endif // MAINWINDOW_H
