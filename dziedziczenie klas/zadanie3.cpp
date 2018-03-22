//Zadanie 3.
//Napisz klas� Subject posiadaj�c� prywatne pole b�d�ce nazw� przedmiotu, maksymaln� liczb� (?100) student�w oraz 100-elementow� tablic� obiekt�w typu Student. 
//dwie pierwsze ustawiane z konstruktora. Powinna ona mie� logiczn� metod� addStudent dodaj�c� studenta do przedmiotu i zwracaj�c� prawd�, 
//je�eli si� to uda�o, albo fa�sz kiedy nie ma ju� miejsc.
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

class Subject{
	string nazwa;
	int max;
	Student *tab[100];
	int obecStud = 0;
public:
	Subject(string nazwa, int max){
		this -> max = max;
		this -> nazwa = nazwa;
	}
bool addStudent(Student *a){
	if(obecStud < max){
		tab[obecStud] = a;
		obecStud++;
		return true;
	}
	else return false;
}
};

int main(){
	Student a = Student(2, "login", "haslo");
	cout<<"Semestr "<<a.getSem()<<endl;
	
	if(a.authorize("login", "haslo") == 1) cout<<"Jestes zalogowany"<<endl;
	else cout<<"Bledny login lub haslo. Sprobuj ponownie"<<endl;
	
	Subject sub1 = Subject("ASyKo", 15);
	if(sub1.addStudent(&a) == 1) cout<<"Zostales dodany do przedmiotu."<<endl;
	else cout<<"Brak wolnych miejsc. Nowe zapisy wkrotce!"<<endl;
	
	

	return 0;
	
}
