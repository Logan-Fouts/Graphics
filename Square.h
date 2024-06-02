#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
private:
    int width;
    int height;
    int center[2];

public:
    Square(int width, int height, const int center[2]);
    int getArea() const override;
    bool contains(int x, int y) const override;
};

#endif // SQUARE_H

