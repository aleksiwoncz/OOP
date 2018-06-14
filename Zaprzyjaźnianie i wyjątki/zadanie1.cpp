#include <iostream>

using namespace std;

struct Point{
	float x;
	float y;
	friend istream & operator >> (istream & strm, Point & p);
};

istream & operator >> (istream & strm, Point & p){
	strm>>p.x>>p.y;
	return strm;
}

int main(){
	Point p;
	cin>>p;
	cout<<"x: "<<p.x<<" y: "<<p.y<<endl;
	
	return 0;
}
