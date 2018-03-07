//Zadanie 2b.
//Zmodyfikuj metodê move, aby przyjmowa³a w argumencie obiekt klasy Point, 
//którego pola x, y traktowane s¹ jako sk³adowe wektora.

#include <iostream>

using namespace std;

class Point{
private:
	float x;
	float y;
public:
	void setX(float x){
		this-> x = x;
	} 
	void setY(float y){
		this-> y = y;
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
	
	Point p;
	p.setX(5.5);
	p.setY(3.2);
	p.move(p);
	cout<<p.getX()<<" "<<p.getY();
	
	return 0;
	
}

