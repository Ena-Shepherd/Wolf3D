
#include "../include/header.h"

#include <SFML/OpenGL.hpp>

using namespace sf;

int main(int ac, char** av)
{
    RenderWindow window(VideoMode(1920, 1080), "Wolf3D", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    //std::vector<float> vect{2, 2, 1, 1}; // Exemple de vecteur

    // Matrices fonctionnent comme suit : échelle = \, rotation = 3x3, translation = |
    std::vector<float> matrix{  1, 0, 0, 0,
                                0, 1, 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1};

    // Appliquer la transformation de la matrice au vecteur

    while (window.isOpen()) {

        Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                return EXIT_SUCCESS;
            else if (event.type == sf::Event::Resized)
            {
                // adjust the viewport when the window is resized
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        window.clear(Color::Black);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //dra

        drawPyramid(window, matrix);

        window.display();
    }

    return 0;
}