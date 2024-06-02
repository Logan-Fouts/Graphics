#include "Square.h"

Square::Square(int w, int h, const int c[2]) : width(w), height(h) {
    center[0] = c[0];
    center[1] = c[1];
}

int Square::getArea() const {
    return width * height;
}

bool Square::contains(int x, int y) const {
    int half_width = width / 2;
    int half_height = height / 2;
    int left = center[0] - half_width;
    int right = center[0] + half_width;
    int top = center[1] + half_height;
    int bottom = center[1] - half_height;
    return (x >= left && x <= right && y >= bottom && y <= top);
}

