//Zadanie 3.
//Napisz klasê Subject posiadaj¹c¹ prywatne pole bêd¹ce nazw¹ przedmiotu, maksymaln¹ liczbê (?100) studentów oraz 100-elementow¹ tablicê obiektów typu Student. 
//dwie pierwsze ustawiane z konstruktora. Powinna ona mieæ logiczn¹ metodê addStudent dodaj¹c¹ studenta do przedmiotu i zwracaj¹c¹ prawdê, 
//je¿eli siê to uda³o, albo fa³sz kiedy nie ma ju¿ miejsc.
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
