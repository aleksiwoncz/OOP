//Zadanie 4.
//Napisz funkcj� distance, kt�ra przyjmie jako argumenty 
//dwa obiekty klasy Point, a nast�pnie zwr�ci odleg�o�� mi�dzy tymi punktami 
//wyra�on� za pomoc� typu float.

#include <iostream>
#include <cmath>

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
// Distance zmieniona na odleglosc z powodu bledu przy kompilacji 
float odleglosc(Point p1, Point p2){
		return sqrt(pow((p2.getX()-p1.getX()), 2) + pow((p2.getY()-p1.getY()), 2));
	}

int main(){
	
	Point p = Point(2.3, 5.6);
	Point q = Point(5.0, 7.9);
	
	cout<<"Punkt P:"<<" "<<"x = "<<p.getX()<<" "<<"y = "<<p.getY()<<endl;
	cout<<"Punkt Q:"<<" "<<"x = "<<q.getX()<<" "<<"y = "<<q.getY()<<endl;

	
	cout<<"Odleglosc wynosi: "<<odleglosc(p,q)<<endl;
	
	return 0;
	
}

