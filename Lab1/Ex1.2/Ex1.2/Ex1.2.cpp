#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	char n[1000], *comparestring[100];
	char* tok;
	int i = 0;
	scanf("%[^\n]", n);
	tok = strtok(n, " ");
	while (tok != NULL) {
		comparestring[i++] = tok;
		tok = strtok(NULL, " ");
	}
	for(int j = 0; j<=i-1; j++)
		for (int k = 0; k < j; k++) {
			if (strlen(comparestring[j]) > strlen(comparestring[k])) {
				char* aux = comparestring[j];
				comparestring[j] = comparestring[k];
				comparestring[k] = aux;
			}
		}

	for (int j = 0; j <= i - 1; j++)
		cout << comparestring[j] << endl;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
