/*

 Author: Yannis STEFANELLI

 Creation Date: 10-10-2023 20:56:33

 Description :

*/

#include <vector>
#include <iostream>
#include <cmath>
#include "../include/header.h"

namespace wf {
/*  {x} {a c}                     {xa + yc}
    {y} {b d} --> x*ab + y*cd --> {xb + yd}
*/
    void vectorMultMatrix(std::vector<float> &vector, const std::vector<float> &matrix) {
        float result0 = vector[0] * matrix[0] + vector[1] * matrix[1] + vector[2] * matrix[2] + vector[3] * matrix[3];
        float result1 = vector[0] * matrix[4] + vector[1] * matrix[5] + vector[2] * matrix[6] + vector[3] * matrix[7];
        float result2 = vector[0] * matrix[8] + vector[1] * matrix[9] + vector[2] * matrix[10] + vector[3] * matrix[11];
        float result3 = vector[0] * matrix[12] + vector[1] * matrix[13] + vector[2] * matrix[14] + vector[3] * matrix[15];

        vector[0] = result0;
        vector[1] = result1;
        vector[2] = result2;
        vector[3] = result3;
    }
    
    std::vector<float> matrixMultMatrix(const std::vector<float> &matrixA, const std::vector<float> &matrixB) {

        std::vector<float> resultMatrix(16, 0.0f);

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    resultMatrix[i * 4 + j] += matrixA[i * 4 + k] * matrixB[k * 4 + j];
                }
            }
        }

        return resultMatrix;
    }

    void rotate(std::vector<float>& matrix, const sf::Vector3f& angles) {
        if (matrix.size() != 16) {
            return;
        }

        // Convert degrees to radians
        float angleX = angles.x * M_PI / 180.0f;
        float angleY = angles.y * M_PI / 180.0f;
        float angleZ = angles.z * M_PI / 180.0f;

        float cosX = cos(angleX);
        float sinX = sin(angleX);
        float cosY = cos(angleY);
        float sinY = sin(angleY);
        float cosZ = cos(angleZ);
        float sinZ = sin(angleZ);

        // Create a single rotation matrix that combines all three rotations
        std::vector<float> rotationMatrix(16, 0.0f);
        rotationMatrix[0] = cosY * cosZ;
        rotationMatrix[1] = -cosX * sinZ + sinX * sinY * cosZ;
        rotationMatrix[2] = sinX * sinZ + cosX * sinY * cosZ;
        rotationMatrix[4] = cosY * sinZ;
        rotationMatrix[5] = cosX * cosZ + sinX * sinY * sinZ;
        rotationMatrix[6] = -sinX * cosZ + cosX * sinY * sinZ;
        rotationMatrix[8] = -sinY;
        rotationMatrix[9] = sinX * cosY;
        rotationMatrix[10] = cosX * cosY;
        rotationMatrix[15] = 1.0f;

        // Multiply the original matrix by the rotation matrix
        matrix = matrixMultMatrix(matrix, rotationMatrix);
    }

    void translate(std::vector<float>& matrix, const sf::Vector3f& direction) {

        std::vector<float> transMatrix{ 
            1, 0, 0, direction.x,
            0, 1, 0, direction.y,
            0, 0, 1, direction.z,
            0, 0, 0, 1
        };
        
        matrix = matrixMultMatrix(matrix, transMatrix);
    } 

}
