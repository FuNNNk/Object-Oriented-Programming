#include "Vector.h"
#include <iostream>

using namespace std;

int main() {
	Vector<int> vector;
	vector.push(3);
	vector.push(2);
	vector.push(5);
	vector.push(2);
	vector.push(6);
	vector.push(1);

	vector.print();
	cout << endl;

	cout<<vector.pop();
	cout << endl;

	cout<<vector.count();
	cout << endl;

	cout<<vector.firstIndexOf(2, findFunction);
	cout << endl;

	cout<<vector.get(2);
	cout << endl;

	vector.insert(3, 10);
	vector.print();
	cout << endl;

	vector.set(12, 4);
	vector.print();
	cout << endl;

	vector.sort(sort);
	vector.print();
}