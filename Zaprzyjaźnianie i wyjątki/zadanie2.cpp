#include <iostream>

using namespace std;

struct Point{
	float x;
	float y;
};

class Points{
	int size;
	Point *tab;
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

int main(){
	Points tab(7);
	cout<<tab;
	
	return 0;
}
