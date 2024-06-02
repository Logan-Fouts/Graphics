#include "Square.h"
#include "Circle.h"
#include <fstream> 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void renderImage(int image_width, int image_height, const vector<Shape*>& shapes, ostream& out) {
    out << "P3\n" << image_width << ' ' << image_height << "\n255\n";

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

            out << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
}

void runAnimation(int image_width, int image_height) {
    for (int i = 0; i < 10; i++) {
      int circle_center[2] = {100 * i + 100, 100 * i + 100};
      Circle circle(50, circle_center);

      vector<Shape*> shapes;
      shapes.push_back(&circle);

      string file = "animation" + to_string(i) + ".ppm";
      ofstream outFile(file);
      if (!outFile) {
        cerr << "Error opening file for writing" << endl;
        return;
      }
      renderImage(image_width, image_height, shapes, outFile);
      outFile.close();
    }
}


void runRender(int image_width, int image_height) {
    int square_center[2] = {100, 100};
    Square square(100, 100, square_center);

    int circle_center[2] = {800, 600};
    Circle circle(200, circle_center);


    vector<Shape*> shapes;
    shapes.push_back(&square);
    shapes.push_back(&circle);

    string file = "render.ppm";
    ofstream outFile(file);
    if (!outFile) {
      cerr << "Error opening file for writing" << endl;
      return;
    }
    renderImage(image_width, image_height, shapes, outFile);
}

int main() {
    int image_width = 1920;
    int image_height = 1080;
    
    // Animation
    // runAnimation(image_width, image_height);
    
    // Simple Render
    runRender(image_width, image_height);

    return 0;
}
