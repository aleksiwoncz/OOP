#include <iostream>

using namespace std;

namespace pt{
class Point{
private:
	int x;
	int y;
public:
	int getX(){
		return x;
	}
	int getY(){
		return y;
	}
	Point(int x,int y){
		this->x=x;
		this->y=y;
	}
	Point(){
		this->x=0;
		this->y=0;
	}
};
}

class Point3D : public pt::Point{
private:
	int z;
public:
	Point3D(int x, int y, int z) : pt::Point(x,y){
		this->z=z;
	}
	int getZ(){
		return z;
	}
};

class Polygon{
public:
	pt::Point *tab;
	int rozm;
public:
	Polygon(int rozm){
		this->rozm=rozm;
		tab = new pt::Point[this->rozm];
	}
	static Polygon triangle(pt::Point a, pt::Point b, pt::Point c){
		
		Polygon p = Polygon(3);
		
		p.tab[0] = a;
		p.tab[1] = b;
		p.tab[2] = c;
		
		return p;
	}
};

int main(){
	Point3D pp = Point3D(2, 3, 4);
	cout<<pp.getX()<<" "<<pp.getY()<<" "<<pp.getZ()<<endl;

	pt::Point a = pt::Point(1, 2);
	pt::Point b = pt::Point(3, 4);
	pt::Point c = pt::Point(5, 6);
	 
	Polygon w = Polygon(3);
	w.triangle(a,b,c);
	
	
	return 0;
}


