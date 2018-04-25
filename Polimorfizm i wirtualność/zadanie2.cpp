//Napisz klasê abstrakcyjn¹ RegularPolyhedron modeluj¹c¹ bry³ê posiadaj¹c¹ wielok¹t foremny w podstawie. Ma ona posiadaæ:
//prywatne, zmiennoprzecinkowe zmienne okreœlaj¹ce d³ugoœæ boku podstawy, pole postawy, wysokoœæ bry³y oraz prywatn¹, 
//ca³kowit¹ zmienn¹ okreœlaj¹c¹ iloœæ boków postawy,
//publiczny konstruktor, przyjmuj¹cy w argumentach trzy wartoœci – d³ugoœæ boku, iloœæ boków i wysokoœæ, dodatkowo obliczaj¹cy wartoœæ pola postawy,
//chronione gettery do pola podstawy i wysokoœci,
//publiczn¹, czysto wirtualn¹, bezargumentow¹ metodê volume zwracaj¹c¹ wartoœæ zmiennoprzecinkow¹.
//Napisz dziedzicz¹ce po niej publicznie dwie klasy: RegularPrism i RegularPyramid. Pierwsza z nich ma implementowaæ metodê volume,
// tak aby zwraca³a objêtoœæ graniastos³upa foremnego, druga – ostros³upa foremnego. Umieœæ wszystkie trzy klasy w przestrzeni nazw o nazwie poly.
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
