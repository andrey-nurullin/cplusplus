// Application.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HTMLUtil.h"
#include <string>
#include <iostream>

using namespace std;

const string MSG_ERR_TEMPLATE = "Not enough parameters or it's incorrect. Template: application.exe <input string>";

void ReadString(string & str)
{
	cin >> str;
}

void PrintString(const string str)
{
	cout << str << endl;
}

int main()
{
	string inputStr;
	
	ReadString(inputStr);
	string htmlCode = HTMLDecode(inputStr);
	PrintString(htmlCode);

	return 0;
}

