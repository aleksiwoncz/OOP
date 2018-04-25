//Napisz klas� abstrakcyjn� RegularPolyhedron modeluj�c� bry�� posiadaj�c� wielok�t foremny w podstawie. Ma ona posiada�:
//prywatne, zmiennoprzecinkowe zmienne okre�laj�ce d�ugo�� boku podstawy, pole postawy, wysoko�� bry�y oraz prywatn�, 
//ca�kowit� zmienn� okre�laj�c� ilo�� bok�w postawy,
//publiczny konstruktor, przyjmuj�cy w argumentach trzy warto�ci � d�ugo�� boku, ilo�� bok�w i wysoko��, dodatkowo obliczaj�cy warto�� pola postawy,
//chronione gettery do pola podstawy i wysoko�ci,
//publiczn�, czysto wirtualn�, bezargumentow� metod� volume zwracaj�c� warto�� zmiennoprzecinkow�.
//Napisz dziedzicz�ce po niej publicznie dwie klasy: RegularPrism i RegularPyramid. Pierwsza z nich ma implementowa� metod� volume,
// tak aby zwraca�a obj�to�� graniastos�upa foremnego, druga � ostros�upa foremnego. Umie�� wszystkie trzy klasy w przestrzeni nazw o nazwie poly.
#include <iostream>
#include <cmath>

using namespace std;

namespace poly{

class RegularPolyhedron{
	float dlg_boku;
	float pole_podstawy;
	float H;
	int ile_bokow;
public:
	RegularPolyhedron(float dlg_boku, int ile_bokow, float H){
		this->ile_bokow = ile_bokow;
		this->dlg_boku = dlg_boku;
		this->H = H;
		this->pole_podstawy = 1./4*ile_bokow*dlg_boku*dlg_boku*1/tan(M_PI/ile_bokow);
	}
	virtual float volume() = 0;
protected:
	float getPole(){
		return pole_podstawy;
	}
	float getH(){
		return H;
	}
};

class RegularPrism : public RegularPolyhedron{
public:
	RegularPrism(float dlg_boku, int ile_bokow, float H) : RegularPolyhedron(dlg_boku, ile_bokow, H){}
	virtual float volume(){
		return getPole() * getH();
	}	
};

class RegularPyramid : public RegularPolyhedron{
public:
	RegularPyramid(float dlg_boku, int ile_bokow, float H) : RegularPolyhedron(dlg_boku, ile_bokow, H){}
	virtual float volume(){
		return getPole() * getH() * (1./3);
	}	
};

}

int main(){
	
    poly::RegularPolyhedron *tab[4];

    tab[0]=new poly::RegularPrism(3,3,2);
    tab[1]=new poly::RegularPyramid(2,3,8);
    tab[2]=new poly::RegularPrism(3,4,4);
    tab[3]=new poly::RegularPyramid(3,3,5);
    
    for(int i=0;i<4;i++)
        cout<<tab[i]->volume()<<endl;

	return 0;
}
