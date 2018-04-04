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
	
	void setWiek(unsigned int wiek){
		this->wiek = wiek;
	}

	unsigned int getWiek(){
		return wiek;
	}

	bool checkPlec(){
		return plec;
	}
	~Villager(){
		cout<<"Umiera "<<*imie<<" w wieku "<<max_wiek<<" lat";
		delete this->imie;
	}
};

class Household{
	Villager **tab;
	unsigned int maxEl, currEl; 
public:
	Household(unsigned int maxEl, unsigned int initRozm){
		this->maxEl = maxEl;
		this->currEl = initRozm;
		tab = new Villager * [this->currEl];
		Villager *v;
		for(unsigned int i= 0; i < this->currEl; i++){
			tab[i] = new Villager();
		}
	}
	void nextYear(){
		for(unsigned int i= 0; i < currEl; i++){
			tab[i]->wiekPlus();
		}	
}
	bool Child(){
		if(currEl==maxEl)
			return false;

		bool kobieta = false;
		bool mezczyzna = false;
		bool czy_dziecko = false;

		for (int i = 0; i < currEl; i++){
				if((tab[i]->checkPlec() == true) && (tab[i]->getWiek() >= 18) && (tab[i]->getWiek() <= 40)){
					mezczyzna = true;
					}
				if((tab[i]->checkPlec() == false) && ((tab[i]->getWiek() >= 18) && (tab[i]->getWiek() <= 40))){
					kobieta = true;
					}	
				if(tab[i]->getWiek() < 5){
					czy_dziecko = true;
					}
		}
		if(mezczyzna == true && kobieta == true && czy_dziecko == false) 
			return true;
		else 
			return false;
	}

	void addChild(){
		if(Child() == true){
			Villager* v = new Villager();
			v->setWiek(0);
			tab[currEl] = v;
			currEl++;
		}
	}
};

int main(){
	
	srand(time(NULL));
	Household *dom = new Household(100, 10);
	dom->nextYear();
	dom->addChild();	
	
	return 0;	
}
