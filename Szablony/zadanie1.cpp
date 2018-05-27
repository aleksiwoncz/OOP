#include <iostream>

using namespace std;

template <typename Typ>

Typ* fun (Typ *a, Typ *b)
{	Typ* min = a;
	for(a; a < b; a++){
		if(*min > *a) min = a;
	}	
	return min;
}

int main()
{	
	int tab[5];
	for(int i = 0; i < 5; i++){
		tab[i] = i * 2;
	}
	
	int *min = fun<int>(tab, (tab + 5));
	cout<< *min <<endl;
	
	return 0;
}
