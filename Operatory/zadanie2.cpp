//Zdefiniuj klas� Person posiadaj�c� prywatne pola: nazw� (string), 
//wiek (int) oraz wektor wska�nik�w na obiekty klasy Person - dzieci tej osoby. 
//Klasa powinna za pomoc� operatora mniejszo�ci ustala� porz�dek wed�ug wieku, 
//a je�eli jest on r�wny, wed�ug nazwy korzystaj�c z por�wnania string�w. 
//Zdefiniuj operator <<= przyjmuj�cy jako argument wska�nik na osob�. 
//Osoba ta powinna zosta� dodana do wektora dzieci, chyba, �e ju� si� tam znajduje. 
//Napisz operator [] przyjmuj�cy jako argument liczb� ca�kowit� - indeks dziecka, 
//zwracaj�cy referencj� na dziecko we wskazanej kom�rce wektora.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Person{
	string nazwa;
	int wiek;
	vector<Person*> dzieci;
public:
	Person(string nazwa, int wiek){
		this->nazwa = nazwa;
		this->wiek = wiek;
	}
	
	bool operator< (Person dziecko){
		if(this->wiek <= dziecko.wiek || this->wiek >= dziecko.wiek)
			return this->wiek < dziecko.wiek;
		
		else
			return this->nazwa < dziecko.nazwa;
		
	}
	void operator<<= (Person* dziecko){
		if(find(dzieci.begin(), dzieci.end(), dziecko) == dzieci.end())
			dzieci.push_back(dziecko);
		
	}
	Person* operator[] (int indeks){
		if(indeks > dzieci.size())
			return 0;
		else
			return dzieci[indeks];
		
	}
	string getNazwa(){
		return nazwa;
	}
	void sortuj(){
		sort(dzieci.begin(), dzieci.end());
	}
	
	~Person(){}
	
};

int main(){
	
	Person a = Person("Magda", 4);
	Person b = Person("Piotr", 5);
	Person c = Person("Ola", 3);
	
	
	a<<=(&b);
	a<<=(&c);
	
	cout<<a[1]->getNazwa()<<endl;	
	
	return 0;
	
}
