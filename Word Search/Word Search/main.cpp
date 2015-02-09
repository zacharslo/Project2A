/*
main.cpp
Author: Zach Sloane and Andrew Blum
Description: Word search

 */

#include "grid.cpp"
//#include "grid.c"
#include "wordList.cpp"
//#include "wordList.c"
#include <string>

using namespace std;

void findMatches(const wordList& wordl, const grid& grid1);
void search(const int alg);
//void testSearch();

int main() {
	
	search(0);
	search(1);
	search(2);
	search(3);
	
//	cout << TotalTime;
	
	return 0;
}

void findMatches(const wordList& wordl, const grid& grid1) {
	grid1.findMatches(wordl);
}

void search(const int alg) {
	string fileLoc;
	cout << "Enter the file name of the grid you would like to use (including it's location): ";
	cin >> fileLoc;
	grid grid1 = grid(fileLoc);
	wordList wordl = wordList();
	
	if(alg == 0) {
		
//		cout << CPUtime;
	}
	if(alg == 1) {
		
//		cout << CPUtime;
	}
	if(alg == 2) {
		
//		cout << CPUtime;
	}
	if(alg == 3) {
		
//		cout << CPUtime;
	}
}
/*
void testSearch() {
	string name;

	cout << "Enter the name of the file: ";
	cin >> name;

	grid grid1 = grid(name);
	wordList wordl = wordList();

	findMatches(wordl, grid1);
}*/
