/*
wordList.h
Authors: Zach Sloane and Andrew Blum

Description: Used to read from a text file and store a list of words as a vector
*/

#ifndef WORDLIST_CLASS
#define WORDLIST_CLASS

#include <stdlib.h>
#include <string>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

//overload << operator
ostream& operator<< (ostream& output, const vector<string>& words) {
	for (int i = 0; i < (words.size() - 1); i++) {
        output << words[i] << "\n";
	}
	output << words.back() << "\n";
    return output;
}

class wordList {
	public:
		wordList();
		wordList(const string& fileLoc);
		wordList(const vector<string>& wordl);
		void printWordList();
		
		vector<string> getWordList() const;
		
		void insertionSort();
		void quickSort(int low, int high);
		void mergeSort();
		void binarySort();
	
	private:
		void readWordList(const string& fileLoc);
		vector<string> words;
	    void swap(int word1, int word2);
};

#endif
