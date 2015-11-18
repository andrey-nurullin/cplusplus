// task01.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const string MSG_ERR_TEMPLATE = "Not enough parameters or it's incorrect. Template: findtext.exe <file name> <text to search>";
const string MSG_ERR_FILE_CANT_OPENED = "File can't be opened";
const string MSG_RESULT_TEXT_NOT_FOUND = "Text not found";

int PrintFoundResult(const vector<int> & elements)
{
	if (elements.empty())
	{
		cout << MSG_RESULT_TEXT_NOT_FOUND;
		return 1;
	}

	for (int element : elements)
	{
		cout << element << endl;
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

vector<int> FindLinesInFile(const string & fileName, const string & textToSearch, bool & error)
{
	ifstream fileIn(fileName);
	if (fileIn.is_open())
	{
		return FindLinesWithText(fileIn, textToSearch);
	}
	else
	{
		error = true;
	}
}

int main(int argc, char* argv[])
{
	if ((argc < 3) || (strlen(argv[1]) == 0) || (strlen(argv[2]) == 0))
	{
		cout << MSG_ERR_TEMPLATE << endl;
		return 1;
	}

	string fileName     = argv[1];
	string textToSearch = argv[2];

	vector<int> foundLineIndexes;
	bool error = false;
	foundLineIndexes = FindLinesInFile(fileName, textToSearch, error);

	if (error)
	{
		cout << MSG_ERR_FILE_CANT_OPENED << endl;
		return 1;
	}

	return PrintFoundResult(foundLineIndexes);
}
