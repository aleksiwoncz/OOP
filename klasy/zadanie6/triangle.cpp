#include "triangle.hpp"
#include "point.hpp"
#include <cmath>

Triangle::Triangle(Point a, Point b, Point c){
    this->a = a;
    this->b = b;
    this->c = c;
}
float Triangle::perimeter(float x, float y, float z){
    return x + y + z;
}
float Triangle::area(float x, float y, float z){
    float ob = (x+y+z)/2;
    return sqrt((ob*(ob-x)*(ob-y)*(ob-z)));
}
