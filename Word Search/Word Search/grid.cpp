/*
Grid.cpp
Authors: Andrew Blum and Zach Sloane

Description: Used to read a matrix of words from file to search through
*/

#ifndef GRID_FUNCTS
#define GRID_FUNCTS

#include "grid.h"

grid::grid(const string& name) {
	readGrid(name);
}

//I think it works now. Still needs to be tested though.
void grid::findMatches(const vector<string>& wordl) const{
	vector<string> match;
	string word;
	char character;
	bool wordfound;
	int dir = 0; // direction of word from first letter; (based off numpad) 1 = left-down (-,-), 2 = down (0,-), 3 = right-down (+,-), 4 = left (-,0), 6 = right (+,0), 7 = left-up (-,+), 8 = up (0,+), 9 = right up (+,+)
	
	//Finds words in grid matrix and appends found words to the end of the match vector
	for(int r = 0; r < (rows - 1); r++) {
		for(int c = 0; c < (columns - 1); c++) {
			for(int i = 0; i < (wordl.size() - 1); i++) {
				word = wordl[i];
				character = word[0];
				if(character == mygrid[r][c]) {
					wordfound = followWord(dir, r, c, word, 1);
				}
				if(wordfound) {
					match.push_back(word);
				}
			}
		}
	}
	
	//Makes a new word list of the matching words and prints the list out
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
	
	//opensgrid file
	ifstream gridfile;
	gridfile.open(fileName.c_str());
	
	//parses grid file
	if(gridfile.is_open()) {
		//gets the first line of the file (to get the row and column numbers)
		getline(gridfile, line);
		//separates the numbers and enters them into rows and columns in the grid class
		for(int i = 0; i < (line.length()); i++) {
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
		}
		columns = atoi(getNumber.c_str());
		
		//sizes the grid matrix to the correct size
		mygrid.resize(rows, columns);
		n = 0;
		
		//populates the grid in the grid class from the grid in the file
		while(n < rows) {
			if(!gridfile.good()) {
				break;
			}
			for(int i = 0; i < columns; i++) {
				character = gridfile.get();
				if(character != ' ' && character != '\n') {
					mygrid[n][i] = character;			
				}
				if(character == ' ' || character == '\n') {
					i--;
				}
			}
			n++;
		}
	}
	//closes the grid file
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

//helper function to find words in grid, once the first letter of a word is found, it checks to see if the rest of the word follows in any direction. If it is, then the true is returned
bool grid::followWord(const int& dir, const int& r, const int& c, const string& word, const int& character) const {
	int output;
	int newR;
	int newC;
	int newChar = (character + 1);
	if(character >= (word.length() - 1)) {
		return false;
	}
	switch(dir) {
		case 0:
			output = followWord(1, r, c, word, character);
			output = followWord(2, r, c, word, character);
			output = followWord(3, r, c, word, character);
			output = followWord(4, r, c, word, character);
			output = followWord(6, r, c, word, character);
			output = followWord(7, r, c, word, character);
			output = followWord(8, r, c, word, character);
			output = followWord(9, r, c, word, character);
			break;
		case 1:
			newR = r - character;
			newC = c - character;
			if(newR < 0) {
				newR += rows;
			}
			if(newC < 0) {
				newC += columns;
			}
			break;
		case 2:
			newR = r;
			newC = c - character;
			if(newC < 0) {
				newC += columns;
			}
			break;
		case 3:
			newR = r + character;
			newC = c - character;
			if(newR > (rows - 1)) {
				newR -= rows;
			}
			if(newC < 0) {
				newC += columns;
			}
			break;
		case 4:
			newR = r - character;
			newC = c;
			if(newR < 0) {
				newR += rows;
			}
			break;
		case 6:
			newR = r + character;
			newC = c;
			if(newR > (rows - 1)) {
				newR -= rows;
			}
			break;
		case 7:
			newR = r - character;
			newC = c + character;
			if(newR < 0) {
				newR += rows;
			}
			if(newC > (columns - 1)) {
				newC -= columns;
			}
			break;
		case 8:
			newR = r;
			newC = c + character;
			if(newC > (columns - 1)) {
				newC -= columns;
			}
			break;
		case 9:
			newR = r + character;
			newC = c + character;
			if(newR > (rows - 1)) {
				newR -= rows;
			}
			if(newC > (columns - 1)) {
				newC -= columns;
			}
			break;
		default:
			output = followWord(0, r, c, word, character);
	}
	if(word[character] == mygrid[newR][newC]) {
		if(character == (word.length() - 1)) {
			return true;
		}
		if(character < (word.length() - 1)) {
			output = followWord(dir, newR, newC, word, newChar);
		}
	}
	if(word[character] != mygrid[newR][newC]) {
		return false;
	}
	return output;
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
