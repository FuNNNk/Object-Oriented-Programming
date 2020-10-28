#pragma once
class Sort
{
	// add data members
	int* p;
	int contor;
public:
	// add constuctors
	Sort(int min, int max);
/*	Sort(int *p);
	Sort(int array[], int count);
	Sort(const char* string);
	*/
	void InsertSort(bool reverse = false);
	void QuickSort(bool reverse = false);
	void BubbleSort(bool reverse = false);
	void Print();
	int  GetElementsCount();
	int  GetElementFromIndex(int index);
};