#include <iostream>
#include <cmath>
#include "triangle.hpp"
#include "point.hpp"

using namespace std;

float odleglosc(Point p1, Point p2){
		return sqrt(pow((p2.getX()-p1.getX()), 2) + pow((p2.getY()-p1.getY()), 2));
	}

int main(){

	Point p = Point(0.0, 0.0);
	Point q = Point(1.0, 4.0);
	Point r = Point(5.0, 2.0);

	cout<<"Punkt P:"<<" "<<"x = "<<p.getX()<<" "<<"y = "<<p.getY()<<endl;
	cout<<"Punkt Q:"<<" "<<"x = "<<q.getX()<<" "<<"y = "<<q.getY()<<endl;
    cout<<"Punkt R:"<<" "<<"x = "<<r.getX()<<" "<<"y = "<<r.getY()<<endl;

    Triangle t(p, q, r);
    float x = odleglosc(p,q);
    float y = odleglosc(q,r);
    float z = odleglosc(p,r);

    cout<<"Obwod trojkata PQR = "<< t.perimeter(x, y, z)<<endl;
    cout<<"Pole trojkata PQR = "<<t.area(x, y, z)<<endl;

	return 0;

}
