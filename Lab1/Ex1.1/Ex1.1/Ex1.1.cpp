#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;

int myAtoi(char c[100]) {
	int numar = 0;
	for (int i = 0; c[i] != '\n' && c[i] != '\0'; i++)
	{
		numar = numar * 10 + c[i] - '0';
	}
	return numar;
}

int main()
{
	int s = 0,i,numar;
	char c[100];
	FILE* pfile;

	pfile = fopen("in.txt", "r");
	if (pfile != NULL)
	{
		while (fgets(c, 512, pfile) != NULL)
		{
			
			numar = myAtoi(c);
			s += numar;
		}
	}
	printf("Rezultatul e: %d", s);
	return 0;
}
