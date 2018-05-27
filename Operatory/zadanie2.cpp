//Zdefiniuj klasê Person posiadaj¹c¹ prywatne pola: nazwê (string), 
//wiek (int) oraz wektor wskaŸników na obiekty klasy Person - dzieci tej osoby. 
//Klasa powinna za pomoc¹ operatora mniejszoœci ustalaæ porz¹dek wed³ug wieku, 
//a je¿eli jest on równy, wed³ug nazwy korzystaj¹c z porównania stringów. 
//Zdefiniuj operator <<= przyjmuj¹cy jako argument wskaŸnik na osobê. 
//Osoba ta powinna zostaæ dodana do wektora dzieci, chyba, ¿e ju¿ siê tam znajduje. 
//Napisz operator [] przyjmuj¹cy jako argument liczbê ca³kowit¹ - indeks dziecka, 
//zwracaj¹cy referencjê na dziecko we wskazanej komórce wektora.
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
