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

	BOOST_AUTO_TEST_CASE(QuotSimpleElementReplace)
	{
		BOOST_CHECK(VerifyHTMLDecoding("&quot;", "\""));
		BOOST_CHECK(VerifyHTMLDecoding("  &quot;  ", "  \"  "));
		BOOST_CHECK(VerifyHTMLDecoding("abcde&quot;fg", "abcde\"fg"));
	}

	BOOST_AUTO_TEST_CASE(AposSimpleElementReplace)
	{
		BOOST_CHECK(VerifyHTMLDecoding("&apos;", "'"));
		BOOST_CHECK(VerifyHTMLDecoding("  &apos;  ", "  '  "));
		BOOST_CHECK(VerifyHTMLDecoding("abcde&apos;fg", "abcde'fg"));
	}

	BOOST_AUTO_TEST_CASE(LtSimpleElementReplace)
	{
		BOOST_CHECK(VerifyHTMLDecoding("&lt;", "<"));
		BOOST_CHECK(VerifyHTMLDecoding("  &lt;  ", "  <  "));
		BOOST_CHECK(VerifyHTMLDecoding("abcde&lt;fg", "abcde<fg"));
	}

	BOOST_AUTO_TEST_CASE(GtSimpleElementReplace)
	{
		BOOST_CHECK(VerifyHTMLDecoding("&gt;", ">"));
		BOOST_CHECK(VerifyHTMLDecoding("  &gt;  ", "  >  "));
		BOOST_CHECK(VerifyHTMLDecoding("abcde&gt;fg", "abcde>fg"));
	}

	BOOST_AUTO_TEST_CASE(AmpSimpleElementReplace)
	{
		BOOST_CHECK(VerifyHTMLDecoding("&amp;", "&"));
		BOOST_CHECK(VerifyHTMLDecoding("&amp;amp;", "&amp;"));
		BOOST_CHECK(VerifyHTMLDecoding("  &amp;  ", "  &  "));
		BOOST_CHECK(VerifyHTMLDecoding("abcde&amp;fg", "abcde&fg"));
	}

	BOOST_AUTO_TEST_CASE(RandomElementsCountReplace)
	{
		BOOST_CHECK(VerifyHTMLDecoding("&quot;&apos;&lt;&gt;&amp;", "\"'<>&"));
		BOOST_CHECK(VerifyHTMLDecoding("hello&quot;world cd<&lt;", "hello\"world cd<<"));
		BOOST_CHECK(VerifyHTMLDecoding("&lt;&lt;hello&quot;world cd<&lt;The End&gt;&gt;", "<<hello\"world cd<<The End>>"));
	}

BOOST_AUTO_TEST_SUITE_END()