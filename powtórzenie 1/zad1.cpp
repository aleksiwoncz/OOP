#include <iostream>

using namespace std;

class Polygon{
public:
	struct Point{
		float x;
		float y;
	};
private:
	Point **tab;
	int count;
	int size;	
public:
	Polygon(){
		size = 4;
		count = 0;
		tab = new Point * [4];
	}
	Polygon(int p){
		size = (p%4>0) ? (p-p%4+4) : p;
	  	tab = new Point*[size];
	}
	int getSize(){
		return size;
	}
	int getCount(){
		return count;
	}		
	Polygon(Polygon &cpy){
		size = cpy.getSize();
		count = cpy.getCount();
		tab = new Point *[size];
		Point *acpy;
		for(int i = 0; i<count; i++){
			tab[i] = new Point();
			acpy = cpy.getPoint(i);
			tab[i]->x = acpy->x;
			tab[i]->y = acpy->y;
		}
		cout<<"KOPIA"<<endl;
	}
	~Polygon(){
		for(int i = 0; i < count; i++)
			delete tab[i];
		delete tab;
	}
	void addPoint(Point point){
		Point **points = tab;
		size+=4;
		tab = new Point * [size];
		for(int i = 0; i < count; i++)
			tab[i] = points[i];
		delete points; 
	}
	Point *getPoint(int index){
		return tab[index];
	}
};

int main(){
	
	Polygon *pol = new Polygon();
	cout<<pol->getSize()<<endl;
	Polygon::Point p;
	p.x = 2;
	p.y = 3;
	pol->addPoint(p);
	cout<<pol->getPoint(0)<<endl;
	
	return 0;	
}
