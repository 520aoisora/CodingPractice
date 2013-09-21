#include <iostream>

#include "Question1.h"

using namespace std;

namespace C1Q1
{
	bool allUniqueCharacters(string iStr)
	{
		int len = iStr.size();
		if(len == 0)
			return false;

		int characterSet[300];
		for(int i = 0; i < len; i++)
		{
			if(characterSet[(int)iStr[i]] == 1)
			{
				return false;
			}
			else
			{
				characterSet[(int)iStr[i]] = 1;
			}
		}

		return true;
	}

	void run()
	{
		string str[10];
		str[0] = "";
		str[1] = "abc123";
		str[2] = "aab123";
		str[3] = ",.abc123";
		str[4] = ",abc123,";
		str[5] = ",a c1 3";
		str[6] = "12345678901234567890";
		str[7] = "12345678901234567890";
		str[8] = "12345678901234567890";
		str[9] = "12345678901234567890";

		for(int i = 0; i < 10; i++)
		{
			cout << "All characters in string: " << str[i] << "are ";

			if(!allUniqueCharacters(str[i]))
				cout << "not ";

			cout << "unique." << endl;
		}
	
		return;
	}
}