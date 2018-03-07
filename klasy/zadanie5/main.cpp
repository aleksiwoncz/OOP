//Zadanie 5.
//Podziel klasê Point na plik nag³ówkowy, w którym znajdzie siê definicja klasy zawieraj¹ca pola i
//deklaracje metod oraz plik Ÿród³owy zawieraj¹cy definicje metod. W g³ównym pliku Ÿród³owym
//powinna pozostaæ wy³¹cznie definicja funkcji distance oraz main.

#include <iostream>
#include <cmath>
#include "zadanie5.hpp"

using namespace std;

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
