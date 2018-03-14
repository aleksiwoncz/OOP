//Zadanie 4.
//Napisz program, kt�ry przyjmie od u�ytkownika �cie�k� do pliku oraz napis.
//Program powinien wy�wietli� liczb� wyst�pie� tego napisu w pliku.
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main(){
	
	ifstream plik("plik.txt");
	stringstream bufor;
	bufor<<plik.rdbuf();
	string tekst = bufor.str();

	string n = "heheszki";

	size_t pozycja = 0;
	int suma = 0;
	while(true){
        pozycja=tekst.find(n,pozycja);
        if(pozycja==string::npos)
            break;
        else{
            pozycja+=n.size();
            suma++;
        }
    }
	cout<<suma<<endl;
	
	return 0;
}
