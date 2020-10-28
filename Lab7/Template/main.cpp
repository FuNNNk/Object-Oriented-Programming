#include<iostream>

float operator"" _Kelvin(unsigned long long x) {
	return (x - 273.15);
}

float operator"" _Fahrenheit(unsigned long long x) {
	return ((x - 32) / 1.8);
}

int main() {
	float a = 300_Kelvin;
	float b = 120_Fahrenheit;
	std::cout << a << "  " << (300.00 - 273.15) << std::endl;
	std::cout << b << "  " << ((120 - 32) / 1.8) << std::endl;
	return 0;
}