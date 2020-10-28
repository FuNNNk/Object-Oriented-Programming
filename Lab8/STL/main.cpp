#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>
#include <queue>
	
using namespace std;

class CompareModule {
	int operator()(string v1, string v2){
	}
};


int main() {
	string line;
	FILE* file;
	char* buffer;
	map<string, int> Counter;
	map<string, int>::iterator it;
	priority_queue<int> pq;

	//file
	file =fopen("exemplu.txt","r");
	if (file == NULL) {
		cout << "Eroare";
	}

	fseek(file, 0, SEEK_END);
	int lSize = ftell(file);
	rewind(file);
	buffer = (char*)malloc(sizeof(char) * lSize);

	fread(buffer, 1, lSize, file);
	line.append(buffer);
	cout << line;
	

	int count1 = 0;
	int count2 = line.find_first_of(",. /") - 0;
	while (line.end == false) {
		line.append(line.substr(count1, count2));
		count1 = count2 + 1;
	}


	// map
	if (Counter.find(line) == Counter.cend()) {
		Counter[line] = 0;
	}
	else {
		Counter[line]++;
	}

		
	// priority queue
	for (it = Counter.begin(); it != Counter.end(); it++) {
		pq.push(it->second);
	}


	// print
	for (it = Counter.begin(); it != Counter.end(); it++) {
		while (pq.empty() == false) {
			if (pq.top() == it->second) {
				pq.pop();
				cout << it->first<<" -> "<<it->second;
			}
		}
	}

}
