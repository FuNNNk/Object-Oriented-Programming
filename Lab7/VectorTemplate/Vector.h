#pragma once
#include <stdlib.h>
template <class T>
class Vector {
public:
	T* vector;
	int sizeOfArray, numberOfElements;

	Vector();
	void push(T element);
	T pop();
	void remove(int index);
	void insert(int index, T element);
	void sort(bool(*sort)(T a, T b));
	const T& get(int index);
	void set(T vector, int index);
	int count();
	int firstIndexOf(T element, bool(*findFunction)(T a, T b));

	void print();
};

template<class T>
Vector<T>::Vector()
{
	this->sizeOfArray = sizeof(T);
	this->vector = (T*)malloc(sizeof(T) * this->sizeOfArray);
	this->numberOfElements = 0;
}

template<class T>
void Vector<T>::push(T element)
{
	if (this->numberOfElements == this->sizeOfArray) {
		this->sizeOfArray = this->sizeOfArray * 2;
		this->vector = (T*)realloc(this->vector, sizeof(T)*this->sizeOfArray);
	}
	this->vector[this->numberOfElements++] = element;
}

template<class T>
T Vector<T>::pop()
{
	return this->vector[--this->numberOfElements];
}

template<class T>
void Vector<T>::remove(int index)
{
	for (int i = index; i < this->numberOfElements - 1; i++)
		this->vector[i] = this->vector[i + 1];
}

template<class T>
void Vector<T>::insert(int index, T element)
{
	if (this->numberOfElements == this->sizeOfArray) {
		this->sizeOfArray = this->sizeOfArray * 2;
		this->vector = (T*)realloc(this->vector, this->sizeOfArray);
	}
	for (int i = numberOfElements; i > index; i--)
		this->vector[i] = this->vector[i - 1];
	vector[index] = element;
}

template<class T>
void Vector<T>::sort(bool(*sort)(T a, T b))
{
	if (sort == nullptr) {
		for (int i = 0; i < this->numberOfElements; i++) {
			for (int j = i; j < this->numberOfElements; j++) {
				if (this->vector[i] < this->vector[j]) {
					T aux = this->vector[i];
					this->vector[i] = this->vector[j];
					this->vector[j] = aux;
				}
			}
		}
	}
	else {
		for (int i = 0; i < this->numberOfElements; i++) {
			for (int j = i; j < this->numberOfElements; j++) {
				if (sort(this->vector[i], this->vector[j])) {
					T aux = this->vector[i];
					this->vector[i] = this->vector[j];
					this->vector[j] = aux;
				}
			}
		}
	}
}

template<class T>
const T& Vector<T>::get(int index)
{
	return this->vector[index];
}

template<class T>
void Vector<T>::set(T vector, int index)
{
	if (index < sizeOfArray)
		this->vector[index] = vector;
	else std::cout << "Eroare";
}

template<class T>
int Vector<T>::count()
{
	return this->numberOfElements;
}

template<class T>
int Vector<T>::firstIndexOf(T element, bool(*findFunction)(T a, T b))
{
	if (findFunction == nullptr) {
		for (int i = 0; i < this->numberOfElements; i++)
			if (element == this->vector[i])
				return i;
	}
	else {
		for (int i = 0; i < this->numberOfElements; i++)
			if (findFunction(element,this->vector[i]))
				return i;
	}
}

template<class T>
void Vector<T>::print()
{
	for (int i = 0; i < this->numberOfElements; i++)
		std::cout << this->vector[i]<< " ";
}

template <class T>
bool sort(T a, T b)
{
	return a > b;
}

template <class T>
bool findFunction(T a, T b)
{
	return a == b;
}