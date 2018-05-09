#include <iostream>
#include <vector>
#include <algorithm>
//Napisz klasê Point posiadaj¹c¹ dwa pola zmiennoprzecinkowe typu float. Utwórz wektor obiektów takiego typu, 
//a nastêpnie posortuj go wed³ug jednego z pól obiektu klasy Point, a potem nastêpnego.
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

bool compX(Point a, Point b){
	return a.getX() < b.getX();
}
bool compY(Point a, Point b){
	return a.getY() < b.getY();

}

int main(){
	Point p1(3,7);
	Point p2(1,9);
	
	vector<Point> v;
	v.push_back(p1);
	v.push_back(p2);
	
	sort(v.begin(), v.end(), compX);
	for(int i = 0; i < v.size(); i++){
		cout << v[i].getX() << endl;
	}
	
	sort(v.begin(), v.end(), compY);
	for(int i = 0; i < v.size(); i++){
		cout << v[i].getY() << endl;
	}
	
	return 0;
}
