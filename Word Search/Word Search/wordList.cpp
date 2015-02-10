/*
wordList.cpp
Authors: Andrew Blum and Zach Sloane

Description: Used to read from a text file and store a list of words as a vector
*/

#ifndef WORDLIST_FUNCTS
#define WORDLIST_FUNCTS

#include "wordList.h"

//initiates wordlist
wordList::wordList() {
	readWordList("wordlist.txt");
}

//initiates wordlist (alowing custom wordlist file to be used)
wordList::wordList(const string& fileLoc) {
	readWordList(fileLoc);
}

//initiates wordlist (populates wordlist using a vector of strings)
wordList::wordList(const vector<string>& wordl) {
	words = wordl;
}

//prints out the words in the word list
void wordList::printWordList() {
	cout << words;
}

//returns the words in the word list
vector<string> wordList::getWordList() const {
	return words;
}


//***********************************************************Need to complete**********************************************************************
//sorts the words in the word list using the insertion sort method
void wordList::insertionSort() {
	if(words.size() > 1) {
		for(int i = 0; i < words.size() - 1; i++) {
			
		}
	}
}

//sorts the words in the word list using the quick sort method
void wordList::quickSort(int low, int high) {
	if(high - low > 1) {
		
		string pivot = words[high - 1];
		int split = low;
	
		for(int i = low; i < (high - 1); i++) {
			if(words[i].compare(pivot) < 0) {
				swap(i, split);
				split++;
			}
		}
	
		swap(high - 1, split);
	
		quickSort(low, split);
		quickSort(split + 1, high);
	}
}

//***********************************************************Need to complete**********************************************************************
//sorts the words in the word list using the merge sort method
void wordList::mergeSort() {
	if(words.size() > 1) {
		for(int i = 0; i < words.size() - 1; i++) {
			
		}
	}
}

//***********************************************************Need to complete**********************************************************************
//Conducts a binary search of the word list
void wordList::binarySearch(const int binary) {
	if(words.size() - 1 < binary) {
		
	}
}


//gets the word list from an inputted file
void wordList::readWordList(const string& fileLoc) {
	//opens word list file
	ifstream wordListFile;
	wordListFile.open(fileLoc.c_str());
	string line;
	
	//reads each line into words vector
	if(wordListFile.is_open()) {
		while(wordListFile.good()) {
			getline(wordListFile, line);
			words.push_back(line);
		}
	}
	//closes word list file
	wordListFile.close();
}

//swaps 2 words in the word list at the inputted positions (used in quick sort)
void wordList::swap(int word1, int word2) {
	string tempword = words[word1];
	words[word1] = words[word2];
	words[word2] = tempword;
}

#endif
