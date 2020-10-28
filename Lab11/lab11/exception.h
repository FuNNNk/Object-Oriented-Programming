#include <iostream>
#include <exception>
using namespace std;

class exceptie1 : public exception
{
	virtual const char* what() const throw()
	{
		return "Out of bounds";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};


class IntComparator : public Compare
{
public:
	int CompareElements(void* e1, void* e2)
	{
		int a = *(int*)e1;
		int b = *(int*)e2;
		if (a == b)
		{
			return 0;
		}
		else if (a < b)
		{
			return -1;
		}
		else {
			return 1;
		}
	}
};

template<class T>
class TComparator : public Compare
{
public:
	int CompareElements(void* e1, void* e2)
	{
		int a = *(T*)e1;
		int b = *(T*)e2;
		if (a == b)
		{
			return 0;
		}
		else if (a < b)
		{
			return -1;
		}
		else {
			return 1;
		}
	}
};

template<class T>
class ArrayIterator
{
private:
	int Current; // mai adaugati si alte date si functii necesare pentru iterator
	T** pointer;
public:
	ArrayIterator() {
		this->pointer = nullptr;
		this->Current = 0;
	}

	int GetCurrent() {
		return Current;
	}

	T** GetPointer() {
		return pointer;
	}

	ArrayIterator(T** pointer)
	{
		this->pointer = pointer;
		this->Current = 0;
	}

	ArrayIterator& operator++ () {
		ArrayIterator<T>it = *this;
		pointer++;
		return it;
	}

	ArrayIterator& operator-- () {
		ArrayIterator<T>it = *this;
		pointer--;
		return it;
	}

	bool operator==(ArrayIterator<T>& at) {
		return pointer == at.pointer;
	}

	bool operator!=(ArrayIterator<T>& p) {
		return pointer != p.pointer;
	}

	T* GetElement() {
		return pointer[0];
	}

};

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
	exceptie1 out_of_range;
public:
	Array() // Lista nu e alocata, Capacity si Size = 0
	{
		this->Capacity = 0;
		this->Size = 0;
		this->List = nullptr;
	}

	~Array() // destructor
	{
			delete this->List;
			this->Capacity=0;
			this->Size=0;	
	}

	Array(int capacity) // Lista e alocata cu 'capacity' elemente
	{
		this->Capacity = capacity;
		this->Size = 0;
		this->List = (T * *)(malloc(capacity * sizeof(T*)));
		for (int i = 0; i < capacity; i++)
			List[i] = (T*)malloc(sizeof(T));
	}

	Array(const Array<T>& otherArray) // constructor de copiere
	{
		this->List = otherArray;
	}

	T& operator[] (int index) // arunca exceptie daca index este out of range
	{
		try
		{
			if (index > this->Size)
				throw out_of_range;
		}
		catch (exception & e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}

		return List[index];
	}

	const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
	{
		*this->List[++Size] = newElem;
		return *this;
	}

	const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		try
		{
			if (index > this->Size)
				throw out_of_range;
		}
		catch (exception & e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
		//pus un for pentru a adauga elementul nou
		*this->List[index] = newElem;
	}

	const Array<T>& Insert(int index, const Array<T> otherArray) // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		try
		{
			if (index > this->Size)
				throw out_of_range;
		}
		catch (exception & e)
		{
			cout << "Exceptie: " << e.what() << endl;
		}
		//pus un for pentru a adauga elementul nou
		*this->List[index] = otherArray;
	}

	const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	{
		{
			try
			{
				if (index > this->Size)
					throw out_of_range;
			}
			catch (exception & e)
			{
				cout << "Exceptie: " << e.what() << endl;
			}
			//pus un for pentru a elimina elemente
			*this->List[index] = 0;
		}
	}

	bool operator=(const Array<T>& otherArray)
	{
		int ok = 1;
		if (this->Size > otherArray.Size || this->Size < otherArray.Size)
			return false;
		else
		{
			for (int i = 0; i < this->Size; i++)
				if (this->List[i] != otherArray.List[i])
					ok = 0;

		}
		if (ok == 1)
			return true;
		return false;
	}


	void Sort() // sorteaza folosind comparatia intre elementele din T
	{
		for (int i = 0; i < this->Size - 1; i++)
			for (int j = i + 1; j < this->Size; j++)
				if (*this->List[i] < *this->List[j])
					swap(List[i], List[j]);
	}

	void Sort(int(*compare)(const T&, const T&)) // sorteaza folosind o functie de comparatie
	{
		if (compare != nullptr)
			for (int i = 0; i < this->Size; i++)
				for (int j = i; j <= this->Size; j++)
					compare(this->List[i], this->List[j]);
	}

	void Sort(Compare* comparator) // sorteaza folosind un obiect de comparatie
	{
		for (int i = 0; i < this->Size - 1; i++)
			for (int j = i + 1; j < this->Size; j++)
				if (comparator->CompareElements((void*)this->List[i], (void*)this->List[j]) == -1)
					swap(List[i], List[j]);
	}

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int BinarySearch(const T& elem); // cauta un element folosind binary search in Array

	int BinarySearch(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind binary search si o functie de comparatie

	int BinarySearch(const T& elem, Compare* comparator)//  cauta un element folosind binary search si un comparator
	{
		int start = 0;
		int end = this->Size;
		while (start <= end)
		{
			int mid = (start + end) / 2;
			//if (*(this->List[mid]) == elem)
			int compareResult = comparator->CompareElements((void*)this->List[mid], (void*)& elem);
			if (compareResult == 0)
			{
				return mid;
			}
			if (compareResult == -1)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
		return -1;
	}

	int Find(const T& elem) // cauta un element in Array
	{
		for (int i = 0; i < Size; i++)
			if (*List[i] == elem)
				return 1;
		return 0;
	}

	int Find(const T& elem, int(*compare)(const T&, const T&));//  cauta un element folosind o functie de comparatie

	int Find(const T& elem, Compare* comparator);//  cauta un element folosind un comparator

	int GetSize() {
		return this->Size;
	}

	int GetCapacity() {
		return this->Capacity;
	}

	ArrayIterator<T> GetBeginIterator() {
		ArrayIterator<T> myIt(&List[0]);
		return myIt;
	}

	ArrayIterator<T> GetEndIterator() {
		ArrayIterator<T> myIt(&List[Size]);
		return myIt;
	}

	void PrintMyArray() {

	}
};
