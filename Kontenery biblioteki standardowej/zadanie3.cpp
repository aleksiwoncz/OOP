//Napisz funkcjê, która przyjmie jako argumenty dwa iteratory do listy napisów. Funkcja powinna wyœwietliæ napisy znajduj¹ce siê miêdzy tymi iteratorami.
#include <iostream>
#include <list>
#include <iterator>
#include <string>

using namespace std;

void fun(list<string> ::iterator it1, list<string> ::iterator it2){
	for(it1; it1 != it2; it1++){
		cout<< *it1 <<endl;
	}	
}

int main(){
	
	list<string> List;
	for(int i = 0; i < 5; i++){
		List.push_back("programowanie");
	}
	
	list<string> ::iterator it1 = List.begin();
	list<string> ::iterator it2 = List.end();
	advance(it1, 2);
	
	fun(it1, it2);
	
	return 0;
}
