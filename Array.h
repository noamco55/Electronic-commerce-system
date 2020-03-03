#ifndef __Array_H
#define __Array_H

#include"System.h"


class Product;

/*
T should have:
1- operator=     --> for using assignment and 'add'
2- operator <<   --> for printing with cout
3- default c'tor --> for creating the array
*/

template<class T>
class Array
{

private:
	int physicalSize, logicalSize;
	char delimiter;
	T* arr;

public:
	Array(int size = 10, char delimiter = ' ');
	//Array(const Array& other);
	//~Array();

	const Array& operator=(const Array& other);
	const Array& operator+=(const T& newVal);
	T* getArr() const;
	void setArr(vector<Product*> arrProducts);

	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		for (int i = 0; i < arr.logicalSize; i++)
			os << arr.arr[i] << arr.delimiter;
		return os;
	}

};




#endif // !__Array_H

template<class T>
inline Array<T>::Array(int size, char delimiter)
{
	physicalSize = size;
	logicalSize = 0;
	this->delimiter = delimiter;
	arr = new T[physicalSize];
}

/*template<class T>
inline Array<T>::Array(const Array & other)
{
	*this = other;
}*/

/*template<class T>
inline Array<T>::~Array()
{
	delete[]arr;
}*/

template<class T>
inline const Array<T> & Array<T>::operator=(const Array<T> & other)
{
	if (this != &other)
	{
		//delete[]arr;
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;
		delimiter = other.delimiter;
		arr = new T[physicalSize];
		for (int i = 0; i < logicalSize; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template<class T>
inline const Array<T> & Array<T>::operator+=(const T & newVal)
{
	if (logicalSize < physicalSize)
		arr[logicalSize++] = newVal;
	else
	{
		physicalSize *= 2;
		Array<T> temp(physicalSize);
		temp = *this;
		*this = temp;
		arr[logicalSize++] = newVal;
	}
	return *this;



}

template<class T>
inline T * Array<T>::getArr()  const
{
	return arr;
}

template<class T>
inline void Array<T>::setArr(vector<Product*> arrProducts)
{
	this->arr = arrProducts;
}