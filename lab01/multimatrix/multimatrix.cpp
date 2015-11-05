// multimatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

typedef double Matrix3x3[3][3];

const string MSG_ERR_TEMPLATE = "Template: multimatrix.exe <file_matrix1> <file_matrix2>";
const string MSG_ERR_OPEN_FILE = "Error. File can't be opened: ";
const string MSG_ERR_INCORRECT_DATA = "Incorrect file data format: ";

bool PopulateMatrix(const string & fileName, Matrix3x3 & matrix)
{
	ifstream fileMatrix(fileName);
	if (fileMatrix.is_open())
	{
		for (int row = 0; row < 3; ++row)
		{
			if (!(fileMatrix >> matrix[row][0] >> matrix[row][1] >> matrix[row][2]))
			{
				cout << MSG_ERR_INCORRECT_DATA << fileName << endl;
				return false;
			}
		}
	}
	else
	{
		cout << MSG_ERR_OPEN_FILE << fileName << endl;
		return false;
	}
	return true;
}

void MultiplyMatrix(const Matrix3x3 & aMatrix, const Matrix3x3 & bMatrix, Matrix3x3 & resultMatrix)
{
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			resultMatrix[row][col] = 0;
			for (int i = 0; i < 3; ++i)
			{
				resultMatrix[row][col] += aMatrix[row][i] * bMatrix[i][col];
			}
		}
	}
}

void PrintMatrix(const Matrix3x3 & matrix)
{
	for (int row = 0; row < 3; ++row)
	{
		cout << fixed << setprecision(3) << matrix[row][0] << "\t" << matrix[row][1] << "\t" << matrix[row][2] << endl;
	}
}

int main(int argc, char* argv[])
{
	if ((argc < 3) || (strlen(argv[1]) == 0) || (strlen(argv[2]) == 0))
	{
		cout << MSG_ERR_TEMPLATE << endl;
		return 1;
	}

	string fileName1 = argv[1];
	string fileName2 = argv[2];

	Matrix3x3 a, b, result;

	if (!(PopulateMatrix(fileName1, a) && PopulateMatrix(fileName2, b)))
	{
		return 1;
	}

	MultiplyMatrix(a, b, result);
	PrintMatrix(result);

	return 0;
}
