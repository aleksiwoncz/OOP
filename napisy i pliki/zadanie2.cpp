//Zadanie 2.
//Napisz program, kt�ry pobierze od u�ytkownika trzy napisy. Pierwszy z nich powinien zawiera� wyrazy - 
//ci�gi znak�w oddzielone pojedyncz� spacj�, drugi i trzeci pojedynczy wyraz. 
//Je�eli w pierwszym napisie znajduje si� wyraz z drugiego napisu, powinien on zosta� zast�piony wyrazem z trzeciego napisu.
// Po wykonaniu operacji zmieniony pierwszy napis nale�y wy�wietli�.
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	
	string n1;
	string n2;
	string n3;
	
	cout<<"Podaj napis: "<<endl;
	getline(cin,n1);
	cout<<"Podaj pierwszy wyraz: "<<endl;
	getline(cin,n2);
	cout<<"Podaj drugi wyraz: "<<endl;
	getline(cin,n3);
	
	size_t pozycja = n1.find(n2);
	int dlg = n2.size();
	if(pozycja!=string::npos){
		n1.replace(pozycja, dlg, n3);
	}
	cout<<n1<<endl;
	
	return 0;
}

