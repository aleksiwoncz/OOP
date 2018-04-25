//Napisz interfejs Polygon posiadaj�cy publiczn� czysto wirtualn� metod� circ zwracaj�c� obw�d. 
//Napisz implementuj�ce go klasy Triangle i Rectangle (o kraw�dzich r�wnoleg�ych do osi uk�adu), 
//kt�re posiadaj�ce informacje o odpowiednich figurach, w kt�rych ta metoda zostanie przeci��ona.
#include <iostream>

using namespace std;

class Polygon{
public:
	virtual float circ() = 0;		
};

class Triangle : public Polygon{
	int x;
	int y;
	int z;
public:
	Triangle(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
	}
	float circ(){
		return x + y + z;
	}	
};

class Rectangle : public Polygon{
	int x;
	int y;
public:
	Rectangle(float x, float y){
		this->x = x;
		this->y = y;
	}
	float circ(){
	return 2 * x + 2 * y;
	}	
};

int main(){
	
	Polygon *wsk[3];
	wsk[0] = new Rectangle(2, 7);
	wsk[1] = new Triangle(3, 2, 1);
	wsk[2] = new Triangle(9, 3, 7);

	  for(int i=0; i<3; i++)
        cout<<wsk[i]->circ()<<endl;
		
	return 0;
}







