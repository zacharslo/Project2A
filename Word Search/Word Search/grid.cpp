/*
Grid.cpp
Authors: Zach Sloane and Andrew Blum

Description: Used to read a matrix of words from file to search through
*/

#ifndef GRID_FUNCTS
#define GRID_FUNCTS

#include "grid.h"

grid::grid() {
	readGrid("input15");
}

grid::grid(const string& name) {
	readGrid(name);
}

//*****************************NEEDS TO BE FINISHED***********************************
//Compiles but not sure if correct..... depends on if we make the sorted words the correct answer.
void grid::findMatches(const wordList& wordl) const{
	vector<string> matches;
	matches = wordl.getSortedWords();
	
	for (int i = 0; i < matches.size(); i++) {
		cout << matches[i];
	}
}

void grid::readGrid(const string& fileName) {
	/* this stuff is an attempt. doesn't work
    ifstream stream(fileName.c_str(), ifstream::in);{
		if(!stream.is_open()) {
			throw runtime_error("Failed to open grid file: " + fileName);
		}
	}

	string line;
	getline(stream, line);

	int rows = (line[0] - '0') * 10 + (line[1] - '0');
	int cols = (line[3] - '0') * 10 + (line[4] - '0');

	data = matrix<char>(rows, cols, '0');

	for(int cnt = 0; cnt < data.cols() && stream.good(); cnt++) {
		getline(stream, line);
		parseLine(line, c);
	}
	stream.close();
     */
}

void grid::parseLine(const string& line, int numLine) {
    /* this stuff is an attempt. doest work
    if(data.cols() * 2 - 1 != line.length()) {
        throw runtime_error("Matrix length isn't the same as line length");
	}
    
    for(int cnt = 0; cnt < data.cols() * 2 - 1; cnt++) {
        if(line[cnt] == ' ') {
            continue;
        }
        else if(line[cnt] == '\n') {
            continue;
        }
        else if(line[cnt] < 'a' || line[cnt] > 'z') {
            throw runtime_error("Entered character is not a-z:" + line[cnt]);
        }
        else  {
            data[numLine][cnt / 2] = line[cnt];
        }
    }
     */
}

#endif
