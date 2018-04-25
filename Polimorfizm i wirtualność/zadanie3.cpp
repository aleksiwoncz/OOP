//Napisz interfejs Polygon posiadaj¹cy publiczn¹ czysto wirtualn¹ metodê circ zwracaj¹c¹ obwód. 
//Napisz implementuj¹ce go klasy Triangle i Rectangle (o krawêdzich równoleg³ych do osi uk³adu), 
//które posiadaj¹ce informacje o odpowiednich figurach, w których ta metoda zostanie przeci¹¿ona.
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







