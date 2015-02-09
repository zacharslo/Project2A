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

class wordList {
	public:
		wordList();
		wordList(const string& fileLoc);
		
		vector<string> getWordList() const;
		vector<string> getSortedWordList() const;
		
		void insertionsort();
		void quickSort(int low, int high);
		void mergesort();
	
	private:
		void readWordList(const string& fileLoc);
		vector<string> words;
		vector<string> sortedWords;
	    void swap(int word1, int word2);
};

#endif
