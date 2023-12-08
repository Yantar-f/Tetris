#include "TetrisShape.hpp"
#include "ZShape.hpp"
#include "LShape.hpp"
#include "IShape.hpp"
#include "BShape.hpp"

#include <memory>

std::unique_ptr<TetrisShape> TetrisShape::createShape(ShapeType shapeType, bool **field, int fieldWidth, int fieldHeight) {
    switch (shapeType) {
        case ShapeType::ZShape: {
            return std::make_unique<ZShape>(field, fieldWidth, fieldHeight);
        }

        case ShapeType::LShape: {
            return std::make_unique<LShape>(field, fieldWidth, fieldHeight);
        }

        case ShapeType::IShape: {
            return std::make_unique<IShape>(field, fieldWidth, fieldHeight);
        }

        case ShapeType::BShape: {
            return std::make_unique<BShape>(field, fieldWidth, fieldHeight);
        }
    }
}

TetrisShape::TetrisShape(bool **field, int fieldWidth, int fieldHeight) :
        field(field),
        fieldWidth(fieldWidth),
        fieldHeight(fieldHeight) {}

void TetrisShape::moveLeft() {
    horizontalMove(-1);
}

void TetrisShape::moveRight() {
    horizontalMove(1);
}

void TetrisShape::horizontalMove(char direction) {
    for (auto tilePos : tilesPoss) {
        sf::Vector2i comparablePos {tilePos.x + direction, tilePos.y};

        if (comparablePos.x == fieldWidth || comparablePos.x == -1) return;

        if (field[comparablePos.x][comparablePos.y]) {
            bool isSelfTile = false;
            for (sf::Vector2 selfTilePos : tilesPoss) {
                if (comparablePos == selfTilePos) isSelfTile = true;
            }
            if ( ! isSelfTile) return;
        }
    }

    for (auto tilePos : tilesPoss) {
        field[tilePos.x][tilePos.y] = false;
        tilePos.x += direction;
        field[tilePos.x][tilePos.y] = true;
    }
}

