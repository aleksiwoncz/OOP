//Napisz funkcjê, która przyjmie sta³¹ referencjê na wektor obiektów klasy Point oraz dwa obiekty tej klasy stanowi¹ce
//lewy górny i prawy dolny punkt prostok¹ta. Funkcja powinna zwróciæ wektor punktów z wektora wejœciowego, które mieszcz¹ siê w podanym prostok¹cie.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point{
	float x, y;
public:
	Point(float x, float y){
		this->x = x;
		this->y = y; 
	}
	float getX(){
		return x;
	}	
	float getY(){
		return y;
	}
};

vector<Point> fun(vector<Point>& v, Point p1, Point p2){
	vector<Point> vC;
	for(int i = 0; i < v.size(); i++){
		bool a = v[i].getX() >= p1.getX();
		bool b = v[i].getX() <= p2.getX();
		bool c = v[i].getY() <= p1.getY();
		bool d = v[i].getY() >= p2.getY();
		if(a && b && c && d){
			vC.push_back(v[i]);
		}
	}
	return vC;
}

int main(){
	vector<Point> v;
	v.push_back(Point(2.4, 7.0));
	v.push_back(Point(3.1, 3.5));
	v.push_back(Point(0.5, 2.5));
	v.push_back(Point(11, 3.5));
	v.push_back(Point(2, 5));

	vector<Point> result = fun(v, Point(2.0, 7.0), Point(5.0, 3.0));
	
	for(int i = 0; i < result.size(); i++){
		cout<< result[i].getX()<<" "<< result[i].getY()<<endl;
	}
	
	return 0;
}
