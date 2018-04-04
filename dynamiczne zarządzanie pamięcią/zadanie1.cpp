#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

string name_fem[5] = {"Krystyna", "Sasza", "Alicja", "Marta", "Anna"};
string name_mal[5] = {"Jakub", "Marek", "Antoni", "Waclaw", "Krzysztof"};
 
class Villager{
	string *imie;
	unsigned int wiek, max_wiek;
	bool plec;
public:	
	Villager(string imie, unsigned int wiek, unsigned int max_wiek, bool plec){
		this->imie = new string;
		*this->imie = imie;
		this->wiek = wiek;
		this->max_wiek = max_wiek;
		this->plec = plec;
	cout<<imie<<" lat "<<wiek<<" dozyje "<<max_wiek<<endl;
}
	Villager(){
		this->imie = new string;
		srand(time(NULL));
		plec = rand() % 2;
		max_wiek = rand() % 100 + 1;
		wiek = rand() % max_wiek;
		if(plec)
			*imie = name_mal[rand()%5];
		else 
			*imie = name_fem[rand()%5];	

   	cout<<(!plec ? "Kobieta": "Mezczyzna")<<" o imieniu "<<*imie<<" ma "<<wiek<<" lat, dozyje "<<max_wiek<<endl;
}
	void wiekPlus(){
		wiek++;
		if(wiek == max_wiek)
		delete this;
	}
	~Villager(){
		cout<<"Umiera "<<*imie<<" w wieku "<<max_wiek<<" lat"<<endl;
		delete this->imie;
	}
};

int main(){
	
	Villager *k = new Villager("Jakub", 1, 3, true);
	k->wiekPlus();
	k->wiekPlus();
	
	Villager *z = new Villager();
	
	return 0;	
}
