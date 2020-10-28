#include <iostream>
#include "Math.h"

using namespace std;

int main() {
	cout <<"Math::Add(1, 2) = "<< Math::Add(1, 2) << endl;
	cout << "Math::Add(1, 2, 3) = " << Math::Add(1, 2, 3) << endl;
	cout << "Math::Add(1.2, 2.0) = " << Math::Add(1.2, 2.0) << endl;
	cout << "Math::Add(1.2, 2.0, 3.0) = " << Math::Add(1.2, 2.0, 3.0) << endl;

	cout << "Math::Mul(1, 2) = " << Math::Mul(1, 2) << endl;
	cout << "Math::Mul(1, 2, 3) = " << Math::Mul(1, 2, 3) << endl;
	cout << "Math::Mul(1.2, 2.0) = " << Math::Mul(1.2, 2.0) << endl;
	cout << "Math::Mul(1.2, 2.0, 3.0) = " << Math::Mul(1.2, 2.0, 3.0) << endl;
	cout << Math::Mul(int(3), double(2.5));

	cout << "Math::Add(4, 1, 2, 3, 4) = " << Math::Add(4, 1, 2, 3, 5) << endl;
	printf("Math::Add(nullptr,nullptr) = %s",Math::Add(nullptr ," nu-mi place"));
}