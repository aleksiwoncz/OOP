//Zadanie 5.
//Podziel klas� Point na plik nag��wkowy, w kt�rym znajdzie si� definicja klasy zawieraj�ca pola i
//deklaracje metod oraz plik �r�d�owy zawieraj�cy definicje metod. W g��wnym pliku �r�d�owym
//powinna pozosta� wy��cznie definicja funkcji distance oraz main.

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
