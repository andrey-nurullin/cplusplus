
#include "stdafx.h"
#include "VectorProcess.h"

int SummOfElements(const vector<int> & numbers)
{
	int summ = 0;
	for (int number : numbers)
	{
		summ += number;
	}

	return summ;
}