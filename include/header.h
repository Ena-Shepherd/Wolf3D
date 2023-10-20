#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <vector>
#include <iostream>

using namespace sf;

void drawPyramid(RenderWindow &window, std::vector<float> &matrix);
namespace wf {

    void vectorMultMatrix(std::vector<float>& vector, const std::vector<float>& matrix);
    std::vector<float> matrixMultMatrix(const std::vector<float> &matrixA, const std::vector<float> &matrixB);
    void rotate(std::vector<float>& matrix, const sf::Vector3f& coordinates);
    void translate(std::vector<float>& matrix, const sf::Vector3f& direction);

}