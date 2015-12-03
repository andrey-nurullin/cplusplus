// task01_v6_test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../task01_v6/VectorProcessor.h"
#include <vector>

using namespace std;

bool VerifyVectorProcessing(vector<double> inputNumbers, const vector<double> & expectedNumbers)
{
	ProcessVector(inputNumbers);
	return (inputNumbers == expectedNumbers);
}

BOOST_AUTO_TEST_SUITE(VectorProcessingTests)

	BOOST_AUTO_TEST_CASE(EmptyArrayProcess)
	{
		BOOST_CHECK(VerifyVectorProcessing({}, {}));
	}

	BOOST_AUTO_TEST_CASE(DivisionByZero)
	{
		BOOST_CHECK(VerifyVectorProcessing({ 0 }, {}));
		BOOST_CHECK(!VerifyVectorProcessing({ -4, 0 }, {}));
		BOOST_CHECK(VerifyVectorProcessing({ 4, 0 }, {}));
	}

	BOOST_AUTO_TEST_CASE(ProcessVectorCommonTests)
	{
		BOOST_CHECK(VerifyVectorProcessing({ 1 }, { 1 }));
		BOOST_CHECK(VerifyVectorProcessing({ 1, 2 }, { 2, 4 }));
		BOOST_CHECK(VerifyVectorProcessing({ 2, 1 }, { 4, 2 }));
	}

	BOOST_AUTO_TEST_CASE(ProcessVectorWithNegativeNumbers)
	{
		BOOST_CHECK(VerifyVectorProcessing({ -2, 1 }, { 1, -0.5 }));
		BOOST_CHECK(VerifyVectorProcessing({ -0.5, 1 }, { 1, -2 }));
	}

	BOOST_AUTO_TEST_CASE(VectorOutputSorted)
	{
		BOOST_CHECK(!VerifyVectorProcessing({ 2, 1 }, { 2, 4 }));
	}

BOOST_AUTO_TEST_SUITE_END()

