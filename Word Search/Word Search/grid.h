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

#include "d_matrix.h" //Has a warning, because it #includes "d_except.h" which contains the strstream library. This library is out of date and therefore a warning message appears telling us that it "may be removed without further notice at a future date". Ignore this warning message for now.

using namespace std;

class grid {
	public:
    	grid(const string& name);
    	void findMatches(const vector<string>& wordl) const;
		

	private:
		void readGrid(const string& name);
		void parseLine(const string& line, int lineNum);
};

#endif
