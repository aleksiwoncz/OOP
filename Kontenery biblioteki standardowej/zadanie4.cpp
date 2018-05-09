////Napisz funkcjê, która w argumencie otrzyma dwa wektory liczb ca³kowitych, a zwróci wektor, w którym bêd¹ znajdowaæ siê 
////liczby z obu tych wektorów, posortowane rosn¹co, bez powtórzeñ.
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> fun(vector<int> v1, vector<int> v2){
	
	v1.insert(v1.end(), v2.begin(), v2.end());

	sort(v1.begin(), v1.end());

	for(int i = 1; i < v1.size(); i++){
		if (v1[i] == v1[i - 1]){
			v1.erase(v1.begin() + i);
			i--;
		}
	}

	return v1;
}

int main(){
	
	vector<int> v1;
	v1.push_back(7);
	v1.push_back(2);
	v1.push_back(3);
	
	vector<int> v2;
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(6);
	
	vector<int> result;
	result = fun(v1, v2);
	for(int i = 0; i < result.size(); i++){
		cout << result[i] << endl;
	}
	
	return 0;
}

