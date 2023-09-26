#include "shapelist.h"
#include <algorithm> 

void ShapeList::moveToFront(Shape *sp) {
    auto it = std::find(begin(), end(), sp);
    if (it != end()) {
        std::rotate(it, it + 1, end());
    } else {
        throw std::runtime_error("Shape not found in ShapeList.");
    }
}

void ShapeList::moveToBack(Shape *sp) {
    auto it = std::find(begin(), end(), sp);
    if (it != end()) {
        std::rotate(begin(), it, it + 1);
    } else {
        throw std::runtime_error("Shape not found in ShapeList.");
    }
}

void ShapeList::moveForward(Shape *sp) {
    auto it = std::find(begin(), end(), sp);
    if (it != end()) {
        if (it + 1 != end()) { // Not already at the front
            std::iter_swap(it, it + 1);
        }
    } else {
        throw std::runtime_error("Shape not found in ShapeList.");
    }
}

void ShapeList::moveBackward(Shape *sp) {
    auto it = std::find(begin(), end(), sp);
    if (it != end()) {
        if (it != begin()) { // Not already at the back
            std::iter_swap(it, it - 1);
        }
    } else {
        throw std::runtime_error("Shape not found in ShapeList.");
    }
}

void ShapeList::draw(GWindow & gw) const {
    for (Shape *shape : *this) {
        shape->draw(gw);
    }
}

Shape* ShapeList::getShapeAt(double x, double y) const {
    for (Shape *shape : *this) {
        if (shape->contains(x, y)) {
            return shape;
        }
    }
    return nullptr;
}