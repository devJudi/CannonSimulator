#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.h"

class MainWindow : public sf::RenderWindow
{
    public:
        MainWindow(int x, int y, std::string name, int fps = 60);
        virtual ~MainWindow();

        void handleEvent(sf::Event event, std::vector <Ball> &balls, int &numberOfBalls, materials &materialType);

    protected:

    private:
};

#endif // MAINWINDOW_H
