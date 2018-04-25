#include <iostream>
#include <string>
#include <sstream>
//Napisz klas� Person posiadaj�c� chronione pole name typu string. Napisz dziedzicz�c� po niej klas� Teacher, 
//kt�ra posiada prywatne pole title typu string oraz klas� Student posiadaj�ce publiczne pole semester typu int. 
//Napisz metod� ident w ka�dej z tej klas zwracaj�c� informacje o nazwie i dodatkowym parametrze w postaci napisu.
using namespace std;

template <class A>
string to_string(const A& obj){
    stringstream stri;
    stri<<obj;
    return stri.str();
}

class Person{
protected:
	string name;
public:
	Person(string name){
		this->name=name;
	}
	virtual string ident(){
		return name;
	}
};

class Teacher : public Person{
	string title;
public:
	Teacher(string name, string title) : Person(name){
		this->title = title;
	}
	virtual string ident(){
		return name + " " + title;
	}		
};

class Student : public Person{
public:
	int semestr;
	Student(string name, int semestr) : Person(name){
		this->semestr=semestr;
	}
	virtual string ident(){
		return name + " " + to_string(semestr);
	}
};

int main(){
	
	Person *tab[3];
    tab[0]=new Student("Krystyna", 2);
    tab[1]=new Teacher("Sasza", "dr");
    tab[2]=new Person("Ala");
    
	for(int i=0;i<3;i++)
        cout<<tab[i]->ident()<<endl;
		
	return 0;
		
}


