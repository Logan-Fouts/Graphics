#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
private:
    int radius;
    int center[2];

public:
    Circle(int radius, const int center[2]);
    int getArea() const override;
    bool contains(int x, int y) const override;
};

#endif // CIRCLE_H
