#include "Circle.h"
#include <cmath>

Circle::Circle(int r, const int c[2]) : radius(r) {
    center[0] = c[0];
    center[1] = c[1];
}

int Circle::getArea() const {
    return static_cast<int>(M_PI * radius * radius);
}

bool Circle::contains(int x, int y) const {
    int center_x = center[0];
    int center_y = center[1];
    int dx = x - center_x;
    int dy = y - center_y;
    int distance_squared = dx * dx + dy * dy;
    return distance_squared <= radius * radius;
}

