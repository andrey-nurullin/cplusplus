#include "stdafx.h"
#include "HTMLUtil.h"
#include <string>
#include <map>

using namespace std;

string HTMLDecode(const string htmlCode)
{
	string decoded = htmlCode;

	StrToStrMap htmlMap = GetHTMLMap();
	for (auto it = htmlMap.cbegin(); it != htmlMap.cend(); ++it)
	{
		SearchAndReplace(decoded, (*it).first, (*it).second);
	}

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

StrToStrMap GetHTMLMap()
{
	map<string, string> htmlMap;
	htmlMap["&quot;"] = "\"";
	htmlMap["&apos;"] = "'";
	htmlMap["&lt;"]   = "<";
	htmlMap["&gt;"]   = ">";
	htmlMap["&amp;"]  = "&";
	return htmlMap;	
}