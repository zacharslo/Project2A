/*
main.cpp
Author: Zach Sloane and Andrew Blum
Description: Word search

 */

#include "grid.cpp"
#include "wordList.cpp"
#include <string>

using namespace std;

void findMatches(wordList&, grid&);
void testSearch();


int main(int argc, char** argv)
{
	testSearch();
	return 0;
}

void findMatches(wordList& wordl, grid& grid1)
{
	vector<string> matches = grid1.findMatches(wordl);
	cout << "Found matches: \n";

	for (int cnt = 0; cnt < matches.size(); cnt++)
	{
		cout << matches[cnt];
	}
}
void testSearch()
{
	string name;

	cout << "Enter the name of the file: ";
	cin >> name;

	grid grid1 = grid(name);
	wordList wordl = wordList();

	findMatches(wordl, grid1);
}
