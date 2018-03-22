//Zadanie 4.
//Napisz metodê klasy Subject, która przyjmie indeks studenta oraz referencjê na wartoœæ logiczn¹.
//Je¿eli student o podanym indeksie znajduje siê w tablicy przedmiotu, nale¿y ustawiæ wartoœæ logiczn¹ z argumentu na true i
//zwróciæ referencjê na obiekt tego studenta. W przeciwnym razie nale¿y ustawiæ fa³sz i zwróciæ dowoln¹ wartoœæ.
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
	string indeks;
public:
	Student(int semestr, string log, string passwd, string indeks)
	:User(log, passwd){
		this -> semestr = semestr;
		this -> indeks = indeks;
	}
	int getSem(){
		return semestr;
	}
	string getInd(){
		return indeks;
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
	Student& szukaj(string indeks, bool& ref){
		for(int i = 0; i < max; i++){
			if(tab[i] -> getInd() == indeks){
				ref = true;
				return *(tab[i]);
		}
	}
        ref = false;
}
};

int main(){
	Student a = Student(2, "login", "haslo", "123456");
	cout<<"Semestr "<<a.getSem()<<endl;

	if(a.authorize("login", "haslo") == 1) cout<<"Jestes zalogowany"<<endl;
	else cout<<"Bledny login lub haslo. Sprobuj ponownie"<<endl;

	Subject sub1 = Subject("ASyKo", 15);
	if(sub1.addStudent(&a) == 1) cout<<"Zostales dodany do przedmiotu."<<endl;
	else cout<<"Brak wolnych miejsc. Nowe zapisy wkrotce!"<<endl;
	bool ref;
	cout<<sub1.szukaj("123456", ref).getInd()<<" "<<ref<<" "<<sub1.szukaj("123456", ref).authorize("login", "haslo");

	return 0;

}
