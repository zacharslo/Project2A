/*
main.cpp
Authors: Andrew Blum and Zach Sloane

Description: Word search
*/

#include "grid.cpp"
//#include "grid.c"
#include "wordList.cpp"
//#include "wordList.c"
#include <string>
#include <time.h>

using namespace std;

void findMatches(const wordList& wordl, const grid& grid1);
void search(const int alg);

int main() {
	int sort;
	cout << "What type of sorting would you like to use?\nEnter \"0\" to use Insertion Sort.\nEnter \"1\" to use Quick Sort.\nEnter \"2\" to use Merge Sort.\n\nWhat is your pick? ";
	cin >> sort;
	if(sort == 3) {
		cout << "Each sorting method will be used. Notice, this is for testing purposes only.\nThere will be some repeats.\n\n";
//		search(0);
		search(1);
//		search(2);
		return 0;
	}
	if(sort < 0 || sort > 2) {
		cout << "You have enterred an improper value, Quick Sort will be used.\n\n";
		sort = 1;
	}
	search(sort);
	
	return 0;
}

//finds words in the grid entered in the search function.
void findMatches(const grid& grid1, const vector<string>& wordl) {
	grid1.findMatches(wordl);
}

//Sorts the word list and then finds words in the user-entered grid.
void search(const int alg) {
	clock_t CPUtimeStart1;
	CPUtimeStart1 = clock();
	string fileName;
	cout << "Enter the file name of the grid you would like to use: ";
	cin >> fileName;
	grid grid1 = grid(fileName);
	wordList wordl = wordList();
	
	//Keeps track of the time it takes to run sort and find match
	clock_t CPUtimeStart2;
	CPUtimeStart2 = clock();
	clock_t CPUtimeSort;
	clock_t CPUtimeSearch;
	clock_t Totaltime;
	
	//uses a sort based off of user input.
	if(alg == 0) {
		wordl.insertionSort();
		cout << "\nSorted using Insertion Sort.\n";
	}
	if(alg == 1) {
		wordl.quickSort(0, wordl.getWordList().size() - 1);
		cout << "\nSorted using Quick Sort.\n";
	}
	if(alg == 2) {
		wordl.mergeSort();
		cout << "\nSorted using Merge Sort.\n";
	}
	//save how long it took to sort
	CPUtimeSort = clock();
	
	cout << "Words found in your grid:\n";
//	findMatches(grid1, wordl.getWordList());
	
	CPUtimeSearch = clock();
	
	cout << "\nThe time it took to sort the word list: " << difftime(CPUtimeSort, CPUtimeStart2);
	cout << "\nThe time it took to search the grid for the words in the word list: " << difftime(CPUtimeSearch, CPUtimeSort) << "\n";
	cout << "\nThe total time it took to sort the word list and to search the grid for\n  the words in the word list: " << difftime(CPUtimeSearch, CPUtimeStart2) << "\n";
	cout << "\nThe total time it took run this program: " << difftime(CPUtimeSearch, CPUtimeStart1) << "\n";
	
}
