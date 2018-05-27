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
	int getRozmiar(){
		return dzieci.size();
	}
	~Person(){}
	
};

class Family{
	Person *osoba;
public:
	Family(Person *osoba){
		this->osoba = osoba;
	}
	bool operator() (Person *p){
		if(osoba == p) return true;
	
		for(int i = 0; i < osoba->getRozmiar(); i++){
			if(p == (*osoba)[i]) return true;
		}

		return false;

	}
	~Family(){}
	
	
};

int main(){
	
	Person a = Person("Magda", 4);
	Person b = Person("Piotr", 5);
	Person c = Person("Ola", 3);

	a<<=&b;
	a<<=&c;
	
    cout<<Family(&a)(&c)<<endl;	
	
	return 0;
	
}
