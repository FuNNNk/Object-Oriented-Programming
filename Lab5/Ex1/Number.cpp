#define _CRT_SECURE_NO_WARNINGS

#include "Number.h"
#include <iostream>

int val(char c)
{
	if (c >= '0' && c <= '9')
		return (int)c - '0';
	else
		return (int)c - 'A' + 10;
}

char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

// Utility function to reverse a string 
void strev(char* str)
{
	int len = strlen(str);
	int i;
	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

int toDecimal(char* number, int base)
{
	int len = strlen(number);
	int power = 1; // Initialize power of base 
	int num = 0;  // Initialize result 
	int i;

	// Decimal equivalent is str[len-1]*1 + 
	// str[len-1]*base + str[len-1]*(base^2) + ... 
	for (i = len - 1; i >= 0; i--)
	{
		// A digit in input number must be 
		// less than number's base 
		if (val(number[i]) >= base)
		{
			printf("Invalid Number");
			return -1;
		}

		num += val(number[i]) * power;
		power = power * base;
	}

	return num;
}

char* fromDecimal(int number, int base)
{
	char res[100];
	int index = 0;  // Initialize index of result 

	// Convert input number is given base by repeatedly 
	// dividing it by base and taking remainder 
	while (number > 0)
	{
		res[index++] = reVal(number % base);
		number /= base;
	}
	res[index] = '\0';

	// Reverse the result 
	strev(res);

	return res;
}

Number::Number(const char* value, int base)
{
	this->digitscount = 0;
	number = (char*)malloc(0);
	this->base = 0;
	if (base >= 2 && base <= 16) {
		this->base = base;
		this->digitscount = 0;
		number = (char*)malloc(strlen(value));
		for (int i = 0; i < strlen(value); i++) {
			number[i] = value[i];
			this->digitscount++;
		}
	}
}

Number::~Number()
{
	delete[] number;
}

Number::Number(const Number& obj)
{
	this->number = obj.number;
	this->base = obj.base;
	this->digitscount = obj.digitscount;
}

Number::Number(const Number&& obj)
{
}

Number& Number::operator=(const Number& obj)
{

}

//Number& Number::operator=(const char* val)
//{
//	strcpy(this->number, val);
//	return (*this);
//}

//Number& Number::operator=(int val)
//{
//	return (*this);
//}
//
//Number Number::operator+=(Number n1)
//{
//	return n1;
//
//}

Number& Number::operator--()
{
	for (int i = 0; i < this->digitscount-1; i++) {
		this->number[i] = this->number[i + 1];
	}
	return (*this);
}


Number Number::operator--(int value)
{
	Number n1(*this);
	n1.number[n1.digitscount - 1] = ' ';
	n1.digitscount--;
	return n1;
}

int Number::operator[](int value)
{
	return this->number[value];
}

bool Number::operator>(Number& n1)
{
	return (toDecimal(this->number, this->base) > toDecimal(n1.number, n1.base));
	return true;
}


void Number::SwitchBase(int newBase)
{
	fromDecimal(toDecimal(this->number, this->base), newBase);
}

void Number::Print()
{
	std::cout <<"n.base = " << this->base<<std::endl;
	std::cout <<"n.digitscount = "<< this->digitscount<<std::endl;
	std::cout << "n.number = ";
	for (int i = 0; i < this->digitscount; i++)
		std::cout << this->number[i];
	std::cout<<std::endl;
}

int Number::GetDigitsCount()
{
	return this->digitscount;
}

int Number::GetBase()
{
	return this->base;
}

Number operator+(Number n1, Number n2)
{
	int commonbase;
	if (n1.base > n2.base) {
		commonbase = n1.base;
	}
	else
	{
		commonbase = n2.base;
	}

	n1.SwitchBase(commonbase);
	n2.SwitchBase(commonbase);
	
	n1.number = (char*) ((int)n1.number + (int)n2.number);
	return n1;
}

Number operator-(Number n1, Number n2)
{
	int commonbase;
	if (n1.base > n2.base) {
		commonbase = n1.base;
	}
	else
	{
		commonbase = n2.base;
	}

	n1.SwitchBase(commonbase);
	n2.SwitchBase(commonbase);

	n1.number = (char*)((int)n1.number - (int)n2.number);
	return n1;
}