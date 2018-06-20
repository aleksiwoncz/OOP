#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void resetVec(vector<int> &v, int a, int b){
	replace_if(v.begin(), v.end(), [b, a](int c)->bool {return !(c>=a && c<=b);}, 0);
}

int main(){
	vector<int> v;
	for(int i=0; i<10; i++){
       		v.push_back(i*i);
    	}

	resetVec(v, 3, 7);
	for(int i=0; i<10; i++){
		cout<<v[i]<<endl;
    	}
    
    return 0;
}
