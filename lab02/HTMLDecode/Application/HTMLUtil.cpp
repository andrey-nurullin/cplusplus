#include "stdafx.h"
#include "HTMLUtil.h"
#include <string>
#include <map>

using namespace std;

string HTMLDecode(const string htmlCode)
{
	string decoded = htmlCode;

	/*StrToStrMap htmlMap = GetHTMLMap();
	for (auto it = htmlMap.cbegin(); it != htmlMap.cend(); ++it)
	{
		SearchAndReplace(decoded, (*it).first, (*it).second);
	}*/
	SearchAndReplace(decoded, "&quot;", "\"");
	SearchAndReplace(decoded, "&apos;", "'");
	SearchAndReplace(decoded, "&lt;", "<");
	SearchAndReplace(decoded, "&gt;", ">");
	SearchAndReplace(decoded, "&amp;", "&");

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
	htmlMap["&quot"] = "\"";
	return htmlMap;	
}