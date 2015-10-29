// lab01-2015.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef char Matrix100x100[100][100];

const string MSG_ERR_TEMPLATE = "Error. Template for launching: labyrinth.exe <file_matrix>";
const string MSG_ERR_OPEN_FILE = "Error. File can't be opened.";

bool PopulateLabyrint(ifstream & file, Matrix100x100 & labyrintMap)
{

	if (file.is_open())
	{
		int lineIndex = 0;
		string line;
		while (getline(file, line))
		{
			memcpy(labyrintMap[lineIndex], line.c_str(), 100);

			//char chararr[100];
			//labyrintMap[lineIndex] = chararr;

		}
	}
	else
	{
		cout << MSG_ERR_OPEN_FILE << endl;
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if ((argc < 2) || (strlen(argv[1]) == 0))
	{
		cout << MSG_ERR_TEMPLATE << endl;
		return 1;
	}

	string inputFileName = argv[1];
	Matrix100x100 labyrint;
	ifstream inputFile(inputFileName);

	memcpy(labyrint[0], inputFileName.c_str(), 100);
	/*
	if (!(PopulateLabyrint(inputFile, labyrint)))
	{
	return 1;
	}
	*/
	cout << labyrint[0] << endl;

	return 0;
}
