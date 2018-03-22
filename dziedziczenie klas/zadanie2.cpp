//Zadanie 2.
//Napisz klas� Student, kt�ra dziedziczy publicznie po klasie User, kt�rej prywatne pola nale�y zmieni� na chronione. 
//Student powinien mie� dodatkowe pole okre�laj�ce semestr ustawiane z poziomu konstruktora.
#include <iostream>

using namespace std;

class User{
protected:
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

class Student:public User{
	int semestr;
public:
	Student(int semestr, string log, string passwd)
	:User(log, passwd){
		this -> semestr = semestr;
	}
	int getSem(){
		return semestr;
	}
	
};

int main(){
	Student a = Student(2, "login", "haslo");
	cout<<"Semestr "<<a.getSem()<<endl;
	
	if(a.authorize("login", "haslo") == 1) cout<<"Jestes zalogowany";
	else cout<<"Bledny login lub haslo. Sprobuj ponownie";

	return 0;
	
}

