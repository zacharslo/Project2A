/*
wordList.h
Author: Zach Sloane and Andrew Blum
Description: Used to read from a text file and store a list of words as a vector

*/

// idk about this #define WORDLIST_CLASS

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

class wordList
{
public:
	wordList();
	wordList(const string& name);

private:
	vector<string> words;
	void quickSort(int low, int high);
    void swap(int word1, int word2);
};

#endif
