#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual ~Shape() = default;  // Virtual destructor for proper cleanup
    virtual int getArea() const = 0;  // Pure virtual function to calculate the area
    virtual bool contains(int x, int y) const = 0;  // Pure virtual function to check if a point is within the shape
};

#endif // SHAPE_H

