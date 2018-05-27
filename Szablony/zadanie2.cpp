#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename Typ>

Typ *fun(Typ *a, Typ *b)
{	
	Typ *min = a;
	for(a; a < b; a++){
		if(*min > *a) min = a;
	}	
	return min;
}


template<> string *fun(string *a, string *b) 
{
	for(a; a < b; a++){
		transform(*a->begin(), *a->end(), *a->begin(), ::tolower);
	}
	string *min = a;
	for(a; a < b; a++){
		if(*min > *a) min = a;
		return min;
	}	
	return min;
}

int main()
{	
	string tab[3];
	tab[0] = "ala";
	tab[1] = "MA";
	tab[2] = "Smoka";
	
	
	string *min = fun<string>(tab, (tab + 3));
	cout<< *min <<endl;
	
	return 0;
}
