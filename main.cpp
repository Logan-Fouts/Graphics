#include "Square.h"
#include "Circle.h"
#include <iostream>
#include <vector>
using namespace std;

void renderImage(int image_width, int image_height, const vector<Shape*>& shapes);

int main() {
    int square_center[2] = {100, 100};
    Square square(100, 100, square_center);

    int circle_center[2] = {800, 800};
    Circle circle(50, circle_center);

    int image_width = 3840;
    int image_height = 2160;

    vector<Shape*> shapes;
    shapes.push_back(&square);
    shapes.push_back(&circle);

    renderImage(image_width, image_height, shapes);

    return 0;
}

void renderImage(int image_width, int image_height, const vector<Shape*>& shapes) {
    cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            bool isInside = false;
            for (const auto& shape : shapes) {
                if (shape->contains(i, j)) {
                    isInside = true;
                    break;
                }
            }

            auto r = isInside ? 0.0 : (double(i) / (image_width - 1));
            auto g = isInside ? 0.0 : (double(j) / (image_height - 1));
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}

