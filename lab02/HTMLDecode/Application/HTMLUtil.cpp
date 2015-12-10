#include "stdafx.h"
#include "HTMLUtil.h"
#include <string>
#include <map>

using namespace std;

string HTMLDecode(const string htmlCode)
{
	string decoded = htmlCode;

	size_t searchPosition = 0;
	bool isElementFound = true;
	while (isElementFound) 
	{
		searchPosition = decoded.find("&quot;", searchPosition);
		if (searchPosition == string::npos)
		{
			isElementFound = false;
			continue;
		}

		decoded.replace(searchPosition, 6, "\"");

		searchPosition += 1;
	}

	return decoded;
}

map<string, string> GetHTMLMap()
{
	map<string, string> htmlMap;
	htmlMap["&quot"] = "\"";
	return htmlMap;	
}