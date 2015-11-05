// MyApplicationTests.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "../MyApplication/VectorProcess.h"
#include <vector>

using namespace std;

bool VerifySummOfElements(const vector<int> & inputNumbers, const int & expectedSum)
{
	int solvedSum = SummOfElements(inputNumbers);
	return (solvedSum == expectedSum);
}

// Создаем решение, набор тестов
BOOST_AUTO_TEST_SUITE(VectorProcessingTests)

	BOOST_AUTO_TEST_CASE(SummOfVectorElements)
	{
		BOOST_CHECK(VerifySummOfElements({}, 0));
		BOOST_CHECK(VerifySummOfElements({ 1 }, 1));
		BOOST_CHECK(VerifySummOfElements({ -1, 1 }, 0));
		BOOST_CHECK(VerifySummOfElements({ -1, 1, 100 }, 100));
	}

BOOST_AUTO_TEST_SUITE_END()

