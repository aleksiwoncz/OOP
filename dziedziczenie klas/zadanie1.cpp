//Zadanie 1.
//Napisz klas� User posiadaj�c� prywatne pola login i password typu string. 
//Napisz konstruktor przyjmuj�cy obie warto�ci. Napisz metod� authorize, kt�ra przyjmie w argumentach 
//dwa napisy i sprawdzi, czy zgadzaj� si� z polami w klasie.
#include <iostream>

using namespace std;

class User{	
	string login;
	string password;
public:
	User(string login, string password){
		this -> login = login;
		this -> password = password;
		}
 
bool authorize(string n1, string n2){
		if(n1==login && n2==password) return true;
		else return false;
		}

};

int main(){
	User k = User("login", "haslo");
	if(k.authorize("login", "haslo") == 1) cout<<"Jestes zalogowany";
	else cout<<"Bledny login lub haslo. Sprobuj ponownie";
	
	return 0;
}



