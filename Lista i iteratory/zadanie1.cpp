#include <iostream>

using namespace std;

template <typename T>
class Array{
    unsigned int m_size;
    T *arr;
public:
    Array(int size){
    	this->m_size=size;
    	this->arr=new T[size];
	}
    ~Array(){
    	delete [] arr;
	}
    int size(){
    	return m_size;
	}
    T& operator[](int index){
    	return arr[index];
	}
	T* begin(){
        return arr;
    }
    T* end(){
        return arr+m_size-1;
    }
	
class Iterator{
	T* ptr;
public:
    Iterator(T* ptr){
        this->ptr=ptr;
    }
	T& operator* (){
		return *ptr;
	}
	T* operator-> (){
		return ptr;
	}
	T* operator++ (){
		return ptr++;
	}
	T* operator-- (){
		return ptr--;
	}
	bool operator== (const Iterator& it) const {
		return (ptr == it.ptr);
	}
	bool operator!= (const Iterator& it) const {
		return !(*this == it);
	}
};
};

int main(){

	Array<int> arr(3);

	for(int i = 0; i < arr.size(); i++){
		arr[i] = i + 5;
	}

	Array<int>::Iterator it = arr.begin();
 	cout<<*(++it)<<endl;
 	cout<<*(++it)<<endl;
 	
 	cout<<*(--it)<<endl;
 	
	return 0;
}



