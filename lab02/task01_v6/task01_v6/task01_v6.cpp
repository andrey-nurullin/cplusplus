// task01_v6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "VectorProcessor.h"
#include <boost/chrono.hpp>
#include <iostream>
#include <iterator>

using namespace std;

void ReadVector(vector<double> & inputVector)
{
	istream_iterator<double> start(cin);
	istream_iterator<double> end;

	vector<double> vector(start, end);
	inputVector = vector;
}

void PrintVector(const vector<double> & outputVector)
{
	ostream_iterator<double> output(cout, " ");
	copy(outputVector.begin(), outputVector.end(), output);
}

void main()
{
	vector<double> numbers;
	ReadVector(numbers);
	ProcessVector(numbers);
	PrintVector(numbers);
}

