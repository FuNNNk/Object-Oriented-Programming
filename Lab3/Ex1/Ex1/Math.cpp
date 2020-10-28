#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

int Math::Add(int a, int b)
{
	return a+b;
}

int Math::Add(int a, int b, int c)
{
	return a+b+c;
}

int Math::Add(double a, double b)
{
	return double(a+b);
}

int Math::Add(double a, double b, double c)
{
	return double(a+b+c);
}

int Math::Mul(int a, int b)
{
	return a*b;
}

int Math::Mul(int a, int b, int c)
{
	return a*b*c;
}

int Math::Mul(int a, double b)
{
	return a*int(b);
}

int Math::Mul(double a, double b)
{
	return double(a * b);
}

int Math::Mul(double a, double b, double c)
{
	return double(a * b * c);
}

int Math::Add(int count, ...)
{
	int* ptr = &count;
	int sum = 0;
	for (int i = 1; i <= count; i++)
	{
		sum += ptr[i];
	}
	return sum;
}

char* Math::Add(const char* text1, const char* text2)
{
	if (text1 != nullptr && text2 != nullptr) {
		char* newString = (char*)malloc(strlen(text1) + strlen(text2));
		return strcat(strcpy(newString, text1), text2);
	}
	else
	{	
		std::cout << "Exceptie";
		return nullptr;
	}
}
	
