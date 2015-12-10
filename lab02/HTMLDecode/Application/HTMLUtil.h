#pragma once

#include <string>
#include <map>
typedef std::map<std::string, std::string> StrToStrMap;

std::string HTMLDecode(const std::string inputString);
void SearchAndReplace(std::string & inputStr, const std::string target, const std::string result);
StrToStrMap GetHTMLMap();