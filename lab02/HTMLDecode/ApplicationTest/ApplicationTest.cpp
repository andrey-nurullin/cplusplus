// ApplicationTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../Application/HTMLUtil.h"
#include <string>

using namespace std;

bool VerifyHTMLDecoding(const string encodedString, const string expectedString)
{
	string decoded = HTMLDecode(encodedString);
	return decoded == expectedString;
}

BOOST_AUTO_TEST_SUITE(ApplicationTests)

	BOOST_AUTO_TEST_CASE(EmptyString)
	{
		BOOST_CHECK(VerifyHTMLDecoding("",""));
	}

	BOOST_AUTO_TEST_CASE(SimpleElementReplace)
	{
		BOOST_CHECK(VerifyHTMLDecoding("&quot;", "\""));
		BOOST_CHECK(VerifyHTMLDecoding("  &quot;  ", "  \"  "));
		BOOST_CHECK(VerifyHTMLDecoding("abcde&quot;fg", "abcde\"fg"));
	}

BOOST_AUTO_TEST_SUITE_END()