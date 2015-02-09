/*
Grid.h
Authors: Zach Sloane and Andrew Blum

Description: Used to read a matrix of words from file to search through
*/

#ifndef GRID_CLASS
#define GRID_CLASS

#include <stdlib.h>
#include <string>
#include <stdexcept>
#include <fstream>
#include <iostream>
#include "wordList.cpp"

//#include "d_matrix.h" this is going to be needed

using namespace std;

class grid {
	public: 
		grid();
    	grid(const string& name);
    	void findMatches(const wordList& wordl) const;
		

	private:
		void readGrid(const string& name);
		void parseLine(const string& line, int lineNum);
};

#endif
