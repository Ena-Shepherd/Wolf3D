/*

 Author: Yannis STEFANELLI

 Creation Date: 10-10-2023 20:22:37

 Description :

*/

#include "../include/header.h"
#include <cmath>

using namespace sf;

void drawPyramid(RenderWindow &window, std::vector<float> &matrix) {
    // Create an array for the vertices of the pyramid
    int vertexCount = 15; // 1 point per vertex and 4 additional points for interpolation
    sf::VertexArray vertices(sf::TriangleStrip, vertexCount);

    // Define the 3D coordinates of the pyramid's vertices
    std::vector<std::vector<float>> vertexPositions(5, std::vector<float>(4));
    float ntr = 10, mtm = 10;
    vertexPositions[0] = {0, 100, 0, 1};     // Apex
    vertexPositions[1] = {-50, 0, -50, 1}; // Base vertex 1
    vertexPositions[2] = {50, 0, -50, 1};  // Base vertex 2
    vertexPositions[3] = {50, 0, 50, 1};   // Base vertex 3
    vertexPositions[4] = {-50, 0, 50, 1};  // Base vertex 4

    // Apply the matrix transformation to the vertex positions
    for (size_t i = 0; i < 5; ++i) {
        wf::vectorMultMatrix(vertexPositions[i], matrix);
    }

    // Define the triangles for the pyramid faces
    int triangles[] = {
        0, 1, 2,  // Front face
        0, 2, 3,  // Right face
        0, 3, 4,  // Back face
        0, 4, 1,  // Left face
        1, 2, 3,  // Bottom face
        1, 3, 4,  // Bottom face
    };

    // Define different colors for each vertex
    sf::Color colors[] = {
        sf::Color::Red, sf::Color::Green, sf::Color::Blue,
        sf::Color::Yellow, sf::Color::Cyan, sf::Color::Magenta
    };

    // Apply the rotation to the vertices
    for (size_t i = 0; i < 5; ++i) wf::rotate(matrix, Vector3f(0, .5, .5));
    
    static bool toggle[3] = {0, 0, 0};
    
    if (matrix[3] > window.getSize().x)
        toggle[0] = true;
    if (matrix[3] == 0)
        toggle[0] = false;

    if (matrix[11] > window.getSize().y)
        toggle[1] = true;
    if (matrix[11] == 0)
        toggle[1] = false;

    ntr *= (toggle[0] ? -1 : 1);
    mtm *= (toggle[1] ? -1 : 1);

    wf::translate(matrix, Vector3f(ntr, 0, mtm));

    // Update the vertex positions and colors in the array
    for (size_t i = 0; i < 15; ++i) {
        vertices[i].position = sf::Vector2f(vertexPositions[triangles[i]][0], vertexPositions[triangles[i]][2]);
        vertices[i].color = colors[i / 3]; // Use colors in groups of 3 for the triangles
    }

    // Draw the pyramid
    window.draw(vertices);
}
