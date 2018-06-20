#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
    float x;
	float y;
};

void sortVec(vector<Point> &v){
	sort(v.begin(), v.end(), [](Point a, Point b)->bool{return a.x<b.x;});

}

int main(){
	
	vector<Point> v;
    for(int i=0; i<5; i++){
        v.push_back({i+i, i*i});
    }
    
    cout<<"Przed sortowaniem"<<endl;
    for(int i=0; i<5; i++){
 		cout<< v[i].x <<" "<< v[i].y <<endl;    
	}
       
    cout<<"Po sortowaniu"<<endl;
    sortVec(v);
    for(int i=0; i<5; i++){
 		cout<< v[i].x <<" "<< v[i].y <<endl;    
	}  
	
	return 0;
}
