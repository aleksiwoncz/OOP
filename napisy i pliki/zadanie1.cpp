//Zadanie 1.
//Napisz program, kt�ry przyjmie od u�ytkownika napis i zapisze go w obiekcie klasy string.
//Wy�wietl najwcze�niejsz� i najp�niejsza liter� alfabetu, kt�ra znajduje si� w tym napisie.
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	
	string napis;
	cout<<"Podaj napis: ";
	getline(cin,napis);
	transform(napis.begin(), napis.end(), napis.begin(), ::tolower);
	
	napis.c_str();
	int i = 0;
	
	char min = napis[0];
	for(i=0; i<napis.size();i++){
	if( napis[i]> min ){
		min = napis[i];
		i++;
		
	}
}
	cout<<"min to "<<min<<endl;
	
	char max = napis[0] ;
	for(i=0; i<napis.size();i++){
	if( napis[i] < max ){
		max = napis[i];
		i++;
		
	}
}
	cout<<"max to "<<max<<endl;
	
	return 0;
}
