#include "TetrisShape.hpp"
#include "ZShape.hpp"
#include "LShape.hpp"
#include "IShape.hpp"
#include "BShape.hpp"

TetrisShape TetrisShape::createShape(ShapeType shapeType) {
    switch (shapeType) {
        case ShapeType::ZShape: {
            return ZShape();
        }

        case ShapeType::LShape: {
            return LShape();
        }

        case ShapeType::IShape: {
            return IShape();
        }

        case ShapeType::BShape: {
            return BShape();
        }
    }
}
