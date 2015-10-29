// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int PrintFoundResult(const vector<int> & elements)
{
	if (elements.empty())
	{
		cout << "Text not found";
		return 1;
	}

	for (auto it = elements.cbegin(); it != elements.cend(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}

vector<int> FindLinesWithText(ifstream & fileIn, string textToSearch)

{
	string line;
	int lineIndex = 0;
	vector<int> lineIndexes;
	while (getline(fileIn, line))
	{
		++lineIndex;
		int searchPosition = line.find(textToSearch);
		if (searchPosition != string::npos)
		{
			lineIndexes.push_back(lineIndex);
		}
	}
	return lineIndexes;
}

int main(int argc, char* argv[])
{
	if ((argc < 3) || (strlen(argv[1]) == 0) || (strlen(argv[2]) == 0))
	{
		cout << "Not enough parameters or it's incorrect. Template: findtext.exe <file name> <text to search>" << endl;
		return 1;
	}

	string fileName = argv[1];
	ifstream fileIn(fileName);

	if (fileIn.is_open())
	{
		vector<int> foundLineIndexes;
		string textToSearch = argv[2];

		foundLineIndexes = FindLinesWithText(fileIn, textToSearch);
		return PrintFoundResult(foundLineIndexes);
	}
	else
	{
		cout << "File can't be opened" << endl;
		return 1;
	}

	return 0;
}
