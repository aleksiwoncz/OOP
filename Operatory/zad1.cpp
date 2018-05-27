#include <iostream>
#include <vector>

using namespace std;

struct vec3{
	float x;
	float y;
	float z;
};
 
struct vec3 operator+ (const vec3& v1, const vec3& v2){
	struct vec3 v3;
	v3.x = v1.x + v2.x;
	v3.y = v1.y + v2.y;
	v3.z = v1.z + v2.z;
	return v3;
}

struct vec3 operator- (const vec3& v1, const vec3& v2){
	struct vec3 v3;
	v3.x = v1.x - v2.x;
	v3.y = v1.y - v2.y;
	v3.z = v1.z - v2.z;
	return v3;
}

void operator+= (vec3& v1, const vec3& v2){
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
}

void operator-= (vec3& v1, const vec3& v2){
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
}

struct vec3 operator* (vec3& v1, vec3& v2){
	struct vec3 v3;
	v3.x = v1.y*v2.z - v1.z*v2.y;
	v3.y = v1.z*v2.x - v1.x*v2.z;
	v3.z = v1.x*v2.y - v1.y*v2.x;
	return v3;
}

vec3 operator* (const vec3& v, const float p){
	struct vec3 new_vec;
	new_vec.x = v.x * p;
	new_vec.y = v.y * p;
	new_vec.z = v.z * p;
	return new_vec;
}



void operator*= (vec3& v1, vec3& v2){
	struct vec3 v3;
	v3.x = v1.y*v2.z - v1.z*v2.y;
	v3.y = v1.z*v2.x - v1.x*v2.z;
	v3.z = v1.x*v2.y - v1.y*v2.x;
}

void operator*= (vec3& v, const float p){
	v.x *= p;
	v.y *= p;
	v.z *= p;
}

int main(){
	
	struct vec3 v1 = {1, 2, 3};
	struct vec3 v2 = {4, 5, 6};

	struct vec3 suma = v1 + v2;
	cout<<"Suma: "<< suma.x << " " << suma.y << " " << suma.z <<endl;
	
	v1 -= v2;
	cout<<"Roznica: "<< v1.x << " " << v1.y << " " << v1.z <<endl;

	struct vec3 iloczyn = v1 * v2;
	cout<<"Iloczyn wektorowy: "<< iloczyn.x << " " << iloczyn.y << " " << iloczyn.z <<endl;
 
	v1 *= 2;
	cout<<"Wektor pomnozony przez liczbe: "<< v1.x << " " << v1.y << " " << v1.z <<endl;

	return 0;
}
