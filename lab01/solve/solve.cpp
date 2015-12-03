// solve.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

enum ErrorCode 
{
	NO_ERROR				= 0,
	ERR_TEMPLATE			= 1,
	ERR_INCORRECT_DATA		= 2,
	RESULT_NO_ROOT			= 3,
	RESULT_IS_NOT_QUADRATIC = 4
};

const string MSG_ERROR[] = {
	"No error",
	"Not enough parameters or it's incorrect. Template: solve.exe <A> <B> <C>",
	"One of arguments is not float",
	"There is no real root",
	"It is not a quadratic equation, because A=0"
};

struct RootsType
{
	double x1;
	double x2;
	int count;
};

struct QuadraticEquationResult
{
	RootsType root;
	int errorCode = 0;
};

bool AreEqual(const double & a, const double & b)
{
	return (fabs(a - b) <= DBL_EPSILON * fmax(fabs(a), fabs(b)));
}

bool StringToDouble(const char * str, double & number)
{
	char * pLastChar = nullptr;
	number = strtod(str, &pLastChar);
	bool err = ((*str == '\0') || (*pLastChar != '\0'));
	return err ? false : true;
}

double CalculateDiscriminant(const double & a, const double & b, const double & c)
{
	return b*b - 4 * a*c;
}

RootsType CalculateEquationRoots(const double & a, const double & b, const double & d)
{
	RootsType root;
	root.x1 = (-b - sqrt(d)) / (2 * a);

	if (!AreEqual(d, 0))
	{
		root.x2 = (-b + sqrt(d)) / (2 * a);
		root.count = 2;
	}
	else
	{
		root.count = 1;
	}
	
	return root;
}

int SolveQuadraticEquation(const double & a, const double & b, const double & c, QuadraticEquationResult & result)
{
	if (AreEqual(a, 0))
	{
		result.errorCode = RESULT_IS_NOT_QUADRATIC;
		return 1;
	}

	double d = CalculateDiscriminant(a, b, c);
	if (d < 0)
	{
		result.errorCode = RESULT_NO_ROOT;
		return 1;
	}

	result.root = CalculateEquationRoots(a, b, d);
	return 0;
}

void PrintResult(const QuadraticEquationResult & result)
{
	if (result.errorCode == NO_ERROR)
	{
		RootsType root = result.root;
		cout << fixed << setprecision(4) << root.x1;
		if (root.count > 1)
		{
			cout << " " << root.x2;
		}
		cout << endl;
	}
	else
	{
		cout << MSG_ERROR[result.errorCode];
	}
}

int main(int argc, char* argv[])
{
	if ((argc < 4))
	{
		cout << ERR_TEMPLATE << endl;
		return 1;
	}

	double a = 0;
	double b = 0;
	double c = 0;
	int resultCode = 0;
	QuadraticEquationResult SolveResult;

	if (StringToDouble(argv[1], a) && StringToDouble(argv[2], b) && StringToDouble(argv[3], c))
	{
		resultCode = SolveQuadraticEquation(a, b, c, SolveResult);
	}
	else
	{
		SolveResult.errorCode = ERR_INCORRECT_DATA;
	}

	PrintResult(SolveResult);

	return resultCode;
}
