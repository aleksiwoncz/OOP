#include <iostream>

using namespace std;

template <class Type>
class List{
	template <class Type>
	class Node{
	public:
		Type data;
		Node<Type>* pNext;
	public:
		Node(Type data = Type(), Node<Type>* pNext = nullptr) : data(data), pNext(pNext){}
	};
public:
	List() : pHead(nullptr), size(0){}
	~List(){}
	Type& operator[] (int index){
		Node<Type>* pCurrent = pHead;
		int counter = 0;

		while (pCurrent != nullptr){
			if (counter == index){
				return pCurrent->data;
			} 
			else{
				pCurrent = pCurrent->pNext;
				counter++;
			}
		}
	}
	void push_back(Type data){
		if (pHead == nullptr){
			pHead = new Node<Type>(data);
		} else{
			Node<Type>* pCurrent = pHead;
			while (pCurrent->pNext != nullptr){
				pCurrent = pCurrent->pNext;
			}
			pCurrent->pNext = new Node<Type>(data);
		}
		size++;
	}
	int getSize() const{
		return size;
	}
	Node<Type>* begin(){
		return pHead;
	}
	Node<Type>* end(){
		return nullptr;
	}
	template <class Type>
	class Iterator{
		Node<Type>* ptr;
	public:
		Iterator(Node<Type>* ptr = nullptr): ptr(ptr){}
		Type& operator* (){
			return ptr->data;
		}
		Node<Type>* operator++ (){
			ptr = ptr->pNext;
			return ptr;
		}
		bool operator== (const Iterator& other) const{
			return (ptr == other.ptr);
		}
		bool operator!= (const Iterator& other) const{
			return !(*this == other);
		}
	};
	private:
	Node<Type>* pHead;
	int size;
};



int main() {
	List<int> lista;
	lista.push_back(1);
	lista.push_back(2);
	lista.push_back(3);
	lista.push_back(4);

	for(size_t i = 0; i<lista.getSize(); i++){
		cout<<lista[i]<<' ';
	}
	cout<<endl;

	for (List<int>::Iterator<int> it = lista.begin(); it != lista.end(); ++it){
		cout<<*it<<' ';
	}
	cout<<endl;
	
	return 0;
}
