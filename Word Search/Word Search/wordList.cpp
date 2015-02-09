/*
wordList.cpp
Authors: Zach Sloane and Andrew Blum

Description: Used to read from a text file and store a list of words as a vector
*/

#ifndef WORDLIST_FUNCTS
#define WORDLIST_FUNCTS

#include "wordList.h"

wordList::wordList() {
	readWordList("wordlist.txt");
}

wordList::wordList(const string& fileLoc) {
	readWordList(fileLoc);
}

wordList::wordList(const vector<string>& wordl) {
	words = wordl;
}

void wordList::printWordList() {
	cout << words;
}

vector<string> wordList::getWordList() const {
	return words;
}



void wordList::insertionSort() {
	for(int i = 0; i < words.size() - 1; i++) {
		
	}
}

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

void wordList::mergeSort() {
	for(int i = 0; i < words.size() - 1; i++) {
		
	}
}

void wordList::binarySort() {
	for(int i = 0; i < words.size() - 1; i++) {
		
	}
}



void wordList::readWordList(const string& fileLoc) {
//	Copy from grid function
}

void wordList::swap(int word1, int word2) {
	string tempword = words[word1];
	words[word1] = words[word2];
	words[word2] = tempword;
}

#endif
