#include "stdafx.h"
#include "vectorProcessor.h"
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool AreEqual(const double & a, const double & b)
{
	return (fabs(a - b) <= DBL_EPSILON * fmax(fabs(a), fabs(b)));
}

bool ProcessVector(vector<double> & numbers)
{
	if (numbers.empty())
	{
		return false;
	}

	double minElement = *min_element(numbers.begin(), numbers.end());
	if (AreEqual(minElement, 0))
	{
		return false;
	}

	double maxElement = *max_element(numbers.begin(), numbers.end());

	transform(numbers.begin(), numbers.end(),
		numbers.begin(), [minElement, maxElement](double item) {
			return (item * maxElement) / minElement;
	});

	sort(numbers.begin(), numbers.end());
	return true;
}