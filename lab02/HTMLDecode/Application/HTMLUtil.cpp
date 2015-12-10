#include "stdafx.h"
#include "HTMLUtil.h"
#include <string>
#include <map>

using namespace std;

string HTMLDecode(const string htmlCode)
{
	string decoded = htmlCode;

	string target = "&quot;";
	string result = "\"";
	SearchAndReplace(decoded, target, result);

	return decoded;
}

void SearchAndReplace(string & inputStr, const string target, const string result)
{
	size_t searchPosition = 0;
	bool isElementFound = true;
	while (isElementFound)
	{
		searchPosition = inputStr.find(target, searchPosition);
		if (searchPosition == string::npos)
		{
			isElementFound = false;
			continue;
		}

		inputStr.replace(searchPosition, target.length(), result);
		searchPosition += result.length();
	}
}

map<string, string> GetHTMLMap()
{
	map<string, string> htmlMap;
	htmlMap["&quot"] = "\"";
	return htmlMap;	
}