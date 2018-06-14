#include <iostream>

using namespace std;

struct Point{
	float x;
	float y;
};

class Points{
	int size;
	Point *tab;
	friend class PointsOperations;
	friend Point* closestToTheCenter(Points &p);
public:
	Points(int size){
		this->size = size;
		tab = new Point[size];
		for(int i = 0; i<size; i++){
			tab[i].x = i+1;
			tab[i].y = i+2;
		}
	}
	~Points(){
		delete [] tab;
	}
	friend ostream & operator << (ostream & wyjscie, const Points & tablica){
		for(int i = 0; i<tablica.size; i++){
			wyjscie<<"x: "<<tablica.tab[i].x<<" y: "<<tablica.tab[i].y<<endl;
		}
		return wyjscie;
	}
	
};

class PointsOperations{
public:
	PointsOperations(){}
	Point *closestToTheCenter(Points &p){
		float x = 0;
		float y = 0;		
		float xc = 0;
		float yc = 0;
		
		for (int i = 0; i<p.size; i++){
			x += p.tab[i].x;
			y += p.tab[i].y;
		}

		xc = x / p.size;
		yc = y / p.size;

		Point pCenter = {xc,yc};

		return &pCenter;
	}
};

int main(){
	Points tab(7);
	PointsOperations po;
	Point* pCenter = po.closestToTheCenter(tab);
	
	cout<<"x: "<<pCenter->x<<" y: "<<pCenter->y<<endl;
	
	return 0;
}
