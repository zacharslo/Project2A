#ifndef GRID_CLASS
#define GRID_CLASS

/*
Grid.h
Author: Zach Sloane and Andrew Blum
Description: Used to read a matrix of words from file to search through

*/

#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>

//#include "d_matrix.h" this is going to be needed
#include "wordList.h"

using namespace std;

class grid
{
	public: 
		grid();
    	grid(const string& name);
    	vector<string> findMatches(const wordList& wordl) const;		

	private:
		void readGrid(const string& name);
		void parseLine(const string& line, int lineNum);
};

#endif
