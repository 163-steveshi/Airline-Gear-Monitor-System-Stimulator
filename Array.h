
#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "defs.h"

using namespace std;

template <class T>
class Array {

	template <class V>
  	friend ostream& operator<<(ostream&, const Array<V>&);
	public:
		//constructor
		Array();
				
		//destructor
		~Array();
		
		//other
		void add(T);
		int getSize() const;
		bool isFull() const;
		const T& operator[](int index) const;

	private:
		int size;
		T* elements;
	
};

//constructor
template <class T>
Array<T>::Array(){
	elements = new T[MAX_ARR];
	size = 0;
}

//destructor
template <class T>
Array<T>::~Array(){
	delete [] elements;
}

//overload add for adding any data type
template <class T>
void Array<T>::add(T t){
	if (size >= MAX_ARR)   return;
  	elements[size++] = t;
}

//overide get funtion for easier
template <class T>
const T& Array<T>::operator[](int index) const{
	
	//first check index if index is invalid exits
	if (index < 0 || index >=size){
    	cout<< "Array index out of bounds"<<endl;
    	exit(1);
  }
  return elements[index];
}

//overide isFull for any data type
template <class T>
bool Array<T>::isFull() const{
	return size >= MAX_ARR;
}
//overide getSize for any data type
template <class T>
int Array<T>::getSize() const{
	return size;
}

//overload ostream that can print any data type
//notice the pointer will print memory address rather than actual value
template <class T>
ostream& operator<<(ostream& os, const Array<T>& list)
{
  

 for(int i = 0; i < list.getSize(); i++) {
    os<<list[i]<<endl<<endl;
  }
  return os;
}


#endif