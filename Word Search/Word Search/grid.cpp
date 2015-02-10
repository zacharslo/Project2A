/*
Grid.cpp
Authors: Zach Sloane and Andrew Blum

Description: Used to read a matrix of words from file to search through
*/

#ifndef GRID_FUNCTS
#define GRID_FUNCTS

#include "grid.h"

grid::grid(const string& name) {
	readGrid(name);
}

//*****************************NEEDS TO BE FINISHED***********************************
void grid::findMatches(const vector<string>& wordl) const{
	vector<string> match;
	match = wordl;
	
	//Create code that finds matches in grid matrix.
	
	wordList matches(match);
	
	matches.printWordList();
}

void grid::readGrid(const string& fileName) {
	// untested, but I think it will work.
	char character;
	string line;
	string getNumber;
	bool num1read = false;
	bool num2read = false;
	int n = 0;
	
	ifstream gridfile;
	gridfile.open(fileName.c_str());
	
	if(gridfile.is_open()) {
		getline(gridfile, line);
		for(int i = 0; i < (line.length() - 1); i++) {
			if(isdigit(line[i])) {
				getNumber[n] = line[i];
				n++;
				num1read = true;
			}
			if(!isdigit(line[i]) && num1read && !num2read) {
				rows = atoi(getNumber.c_str());
				getNumber = "";
				n = 0;
			}
			if((!isdigit(line[i]) || i == (line.length() - 1)) && num1read && num2read) {
				columns = atoi(getNumber.c_str());
			}
		}
		mygrid.resize(rows, columns);
		n = 0;
		while(n < (rows - 1)) {
			if(!gridfile.good()) {
				break;
			}
			for(int i = 0; i < (columns - 1); i++) {
				character = gridfile.get();
				if(character != ' ' && character != '\n') {
					mygrid[n][i] = character;					
				}
			}
			n++;
		}
	}
	gridfile.close();
	
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
	stream.close();*/
}

/* This should no longer be needed
void grid::parseLine(const string& line, int numLine) {
    // this stuff is an attempt. doest work
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
     
}*/

#endif
