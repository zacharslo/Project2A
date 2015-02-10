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
#include <time.h>

using namespace std;

void findMatches(const wordList& wordl, const grid& grid1);
void search(const int alg);
//void testSearch();

int main() {
	int sort;
	cout << "What type of sorting would you like to use?\nEnter \"0\" to use Insertion Sort.\nEnter \"1\" to use Quick Sort.\nEnter \"2\" to use Merge Sort.\n\nWhat is your pick? ";
	cin >> sort;
	if(sort < 0 || sort > 2) {
		cout << "You have enterred an improper value, Quick Sort will be used.\n\n";
		sort = 1;
	}
	search(sort);
	
	return 0;
}

void findMatches(const grid& grid1, const vector<string>& wordl) {
	grid1.findMatches(wordl);
}

void search(const int alg) {
	string fileName;
	cout << "Enter the file name of the grid you would like to use: ";
	cin >> fileName;
	grid grid1 = grid(fileName);
	wordList wordl = wordList();
	
	time_t CPUtimeStart;
	CPUtimeStart = time(NULL);
	time_t CPUtimeSort;
	time_t CPUtimeSearch;
	time_t Totaltime;
	
	
	if(alg == 0) {
		wordl.insertionSort();
		cout << "Sorted using Insertion Sort.\n";
	}
	if(alg == 1) {
		wordl.quickSort(0, wordl.getWordList().size() - 1);
		cout << "Sorted using Quick Sort.\n";
	}
	if(alg == 2) {
		wordl.mergeSort();
		cout << "Sorted using Merge Sort.\n";
	}
	
	CPUtimeSort = time(NULL);
	
	cout << "Matches found:\n";
	
	findMatches(grid1, wordl.getWordList());
	
	CPUtimeSearch = time(NULL);
	
	cout << "The time it took to sort the word list: " << difftime(CPUtimeSort, CPUtimeStart);
	
	cout << "\nThe time it took to search the grid for the words in the word list: " << difftime(CPUtimeSearch, CPUtimeSort);
	
	cout << "\nThe total time it took to sort the word list and to search the grid for the words in the word list: " << difftime(CPUtimeSearch, CPUtimeStart) << "\n\n";
}
