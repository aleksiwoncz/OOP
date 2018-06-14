#include <iostream>
#include <stdexcept> 

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
	Point operator [] (int index){
	try{
		if(index >= size){
			throw out_of_range("Out of range error \n");
		}
		return tab[index];
	}
	catch(out_of_range outofrange){
		cout<<outofrange.what();
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

	cout<<"Podaj indeks ";
	int index;
	cin>>index;

	cout<<"Punkt o indeksie: "<<index<<endl;
	cout<<"x: "<<tab[index].x<<" y: "<<tab[index].y<<endl;

	return 0;
}
