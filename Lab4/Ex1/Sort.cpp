#include "Sort.h"
#include <stdlib.h>
#include <iostream>

Sort::Sort(int min, int max)
{
	contor = 0;
	this->p = &contor;
	for (int i = min; i < max; i++) {
		int numar = rand() % (max-min) + min;
		p[contor] = numar;
		contor++;
	}
}

/*Sort::Sort(int* p)
{
}

Sort::Sort(int array[], int count)
{
}

Sort::Sort(const char* string)
{
}*/


void Sort::InsertSort(bool reverse)
{
}

void Sort::QuickSort(bool reverse)
{
}

void Sort::BubbleSort(bool reverse)
{
}

void Sort::Print()
{
	for (int i = 0; i < contor; i++) {
		std::cout << this->p[i];
	}
}

int Sort::GetElementsCount()
{
	return 0;
}

int Sort::GetElementFromIndex(int index)
{
	return 0;
}
