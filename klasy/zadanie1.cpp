//Zadanie 1.
//Napisz klas� Point posiadaj�c� dwa pola prywatne typu float. Napisz akcesory do tych p�l.
 
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


