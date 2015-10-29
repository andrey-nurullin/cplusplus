// solve.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const string MSG_ERR_TEMPLATE = "Not enough parameters or it's incorrect. Template: solve.exe <A> <B> <C>";
const string MSG_ERR_INCORRECT_DATA = "One of arguments is not float";
const string MSG_RESULT_NO_ROOT = "There is no real root";
const string MSG_RESULT_IS_NOT_QUADRATIC = "It is not a quadratic equation, because A=0";

struct RootsType
{
	double x1;
	double x2;
};

bool AreEqual(const double a, const double b)
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

double CalculateDiscriminant(double a, double b, double c)
{
	return b*b - 4 * a*c;
}

RootsType CalculateEquationRoots(double a, double b, double d)
{
	RootsType roots;
	roots.x1 = (-b - sqrt(d)) / (2 * a);
	roots.x2 = (-b + sqrt(d)) / (2 * a);
	return roots;
}

int SolveQuadraticEquation(double a, double b, double c)
{
	if (AreEqual(a, 0))
	{
		cout << MSG_RESULT_IS_NOT_QUADRATIC;
		return 1;
	}

	double d = CalculateDiscriminant(a, b, c);
	if (d < 0)
	{
		cout << MSG_RESULT_NO_ROOT;
		return 1;
	}

	RootsType roots = CalculateEquationRoots(a, b, d);
	cout << fixed << setprecision(4) << roots.x1;
	if (!AreEqual(d, 0))
	{
		cout << " " << roots.x2;
	}
	cout << endl;
	return 0;
}

int main(int argc, char* argv[])
{
	if ((argc < 4))
	{
		cout << MSG_ERR_TEMPLATE << endl;
		return 1;
	}

	double a = 0;
	double b = 0;
	double c = 0;

	if (StringToDouble(argv[1], a) && StringToDouble(argv[2], b) && StringToDouble(argv[3], c))
	{
		return SolveQuadraticEquation(a, b, c);
	}

	cout << MSG_ERR_INCORRECT_DATA;
	return 1;
}
