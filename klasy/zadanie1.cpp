//Zadanie 1.
//Napisz klasê Point posiadaj¹c¹ dwa pola prywatne typu float. Napisz akcesory do tych pól.
 
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
};

int main(){
	
	Point p;
	p.setX(5.5);
	p.setY(3.2);
	cout<<p.getX()<<" "<<p.getY()<<endl;
	
	return 0;
	
}


