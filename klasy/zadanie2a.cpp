//Zadanie 2a.
//Do klasy Point dopisz metodê move, która przyjmie dwa argumenty typu float - x i y, 
//która przesunie punkt o zadany wektor.

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
	void move(float x, float y){
		this->x+=x;
		this->y+=y;
	}
};

int main(){
	
	Point p;
	p.setX(5.5);
	p.setY(3.2);
	p.move(1.5, 2.7);
	cout<<p.getX()<<" "<<p.getY();
	
	return 0;
	
}


