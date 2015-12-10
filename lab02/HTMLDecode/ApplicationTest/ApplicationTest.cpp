// ApplicationTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Application/HTMLUtil.h"
#include <string>

using namespace std;

bool VerifyHTMLDecoding(string encodedString, string expectedString)
{
	string decoded = HTMLDecode(encodedString);
	return decoded == expectedString;
}

BOOST_AUTO_TEST_SUITE(ApplicationTests)

	BOOST_AUTO_TEST_CASE(CheckIsBoostEnabled)
	{
		BOOST_CHECK(2*2 == 4);
	}

	BOOST_AUTO_TEST_CASE(EmptyString)
	{
		BOOST_CHECK(VerifyHTMLDecoding("",""));
	}

BOOST_AUTO_TEST_SUITE_END()