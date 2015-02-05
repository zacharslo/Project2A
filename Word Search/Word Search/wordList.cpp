#ifndef WORDLIST_FUNCTS
#define WORDLIST_FUNCTS

/*
wordList.cpp
Authors: Zach Sloane and Andrew Blum

Description: Used to read from a text file and store a list of words as a vector

*/

#include "wordList.h"

wordList::wordList()
{

}

void wordList::quickSort(int low, int high)
{
	if(high - low <= 1)
		return;

	string pivot = words[high - 1];
	int split = low;

	for(int i = low; i < (high - 1); i++)
	{
		if(words[i].compare(pivot) < 0)
		{
			swap(i,split);
			split++;
		}
	}

	swap(high - 1, split);

	quickSort(low, split);
	quickSort(split + 1, high);
}

void wordList::swap(int word1, int word2)
{
	string tempword = words[word1];
	words[word1] = words[word2];
	words[word2] = tempword;
}

#endif
