#pragma once
class Number
{
	int base, digitscount;
	char* number;
	// add data members
public:
	Number(const char* value, int base); // where base is between 2 and 16 //done
	Number();
	~Number(); //done

	// friend operators + -
	friend Number operator+(Number n1, Number n2);
	friend Number operator-(Number n1, Number n2);

	//copy and move constructors
	Number(const Number& obj);
	Number(const Number&& obj);
	Number& operator=(const Number& obj);
	Number& operator=(int val);
	Number& operator=(const char* val);

	//other operations
	Number operator+=(Number n1);

	//post pre fix --
	Number& operator--();
	Number operator--(int value);

	//index
	int operator[](int value); //done
	
	//relational
	bool operator>(Number& n1);

	char* transformbasetobase(char* number, int basen1, int basen2);
	void SwitchBase(int newBase);
	void Print(); //done
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};