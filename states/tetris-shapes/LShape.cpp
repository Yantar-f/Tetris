//
// Created by Yantar on 08/12/2023.
//

#include <random>
#include "LShape.hpp"
#include "../../CommonDefinitions.hpp"
#include "../../exceptions/NoSpawnSpaceException.hpp"

LShape::LShape(bool **field, int fieldWidth, int fieldHeight) : TetrisShape(field, fieldWidth, fieldHeight) {
    std::uniform_int_distribution<int> shapeSpawnRange {0, fieldWidth - 4};
    std::minstd_rand randEngine { static_cast<unsigned int>(TIME_POINT.time_since_epoch().count()) };
    int initialPos = shapeSpawnRange(randEngine);

    tilesPoss[0].x = initialPos;
    tilesPoss[0].y = 1;

    if (field[tilesPoss[0].x][tilesPoss[0].y]) throw NoSpawnSpaceException();

    tilesPoss[1].x = ++initialPos;
    tilesPoss[1].y = 1;

    if (field[tilesPoss[1].x][tilesPoss[1].y]) throw NoSpawnSpaceException();

    tilesPoss[2].x = ++initialPos;
    tilesPoss[2].y = 1;

    if (field[tilesPoss[2].x][tilesPoss[2].y]) throw NoSpawnSpaceException();

    tilesPoss[3].x = initialPos;
    tilesPoss[3].y = 0;

    if (field[tilesPoss[3].x][tilesPoss[3].y]) throw NoSpawnSpaceException();

    for (auto tilePos : tilesPoss) field[tilePos.x][tilePos.y] = true;
}

void LShape::rotate() {
    switch (currentRotationAngle) {
        case Rotation::Rot0: {
            currentRotationAngle = Rotation::Rot90;
            break;
        }

        case Rotation::Rot90: {
            currentRotationAngle = Rotation::Rot180;
            break;
        }

        case Rotation::Rot180: {
            currentRotationAngle = Rotation::Rot270;
            break;
        }

        case Rotation::Rot270: {
            currentRotationAngle = Rotation::Rot0;
            break;
        }
    }
}
