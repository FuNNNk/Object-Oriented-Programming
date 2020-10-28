#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::Init() {
	count = 0;
}

bool NumberList::Add(int x) {
	numbers[count++] = x;
	if (count >= 10)
		return false;
	return true;
}

void NumberList::Sort() {
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < i; j++) {
			if (numbers[i] < numbers[j]) {
				int aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
		}
	}
}

void NumberList::Print() {
	for (int i = 0; i < count; i++)
		cout << numbers[i] << " ";
}