#include "point.hpp"
#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle{
private:
    Point a;
    Point b;
    Point c;
public:
    Triangle(Point a, Point b, Point c);
    float perimeter(float x, float y, float z);
    float area(float x, float y, float z);
};

#endif // TRIANGLE_H

