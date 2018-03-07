//Zadanie 3.
//Usuñ z klasy Point settery. Napisz konstruktor, który przyjmie 
//dwa argumenty typu float i ustawi ich wartoœci polom x i y.

#include <iostream>

using namespace std;

class Point{
private:
	float x;
	float y;
public:
	Point(float x, float y){
		this->x=x;
		this->y=y;
	}
	float getX(){
		return x;
	}
	float getY(){
		return y;
	}
	void move(Point p){
		x+=p.getX();
		y+=p.getY();
	}
};


int main(){
	
	Point p = Point(2.3, 5.6);
	cout<<p.getX()<<" "<<p.getY()<<endl;
	p.move(p);
	cout<<p.getX()<<" "<<p.getY();
	
	return 0;
	
}

