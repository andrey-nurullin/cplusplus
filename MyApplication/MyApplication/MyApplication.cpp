// MyApplication.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VectorProcess.h"
#include <iostream>
#include <iterator>

using namespace std;

void ReadVector(vector<int> & inputNumbers)
{
	istream_iterator<int> start(cin);
	istream_iterator<int> end;

	vector<int> tempVector(start, end);
	inputNumbers = tempVector;
}

void PrintResult(const int & number)
{
	cout << number;
}

int main()
{
	vector<int> numbers;

	ReadVector(numbers);

	PrintResult( SummOfElements(numbers) );

    return 0;
}

