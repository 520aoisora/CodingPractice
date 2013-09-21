#include <iostream>

#include "Question4.h"

using namespace std;

namespace Q4
{
	bool replaceSpace(string& str, int realLength)
	{
		if(realLength <= 0)
			return false;

		int spaceCounter = 0;
		for(int i = 0; i < realLength; i++)
		{
			if(str[i] == ' ')
				spaceCounter++;
		}

		if(spaceCounter == 0)
			return true;

		int newLength = realLength + 2 * spaceCounter;
		int writeBeginAt = newLength - 1;

		for(int i = realLength - 1; i >= 0; i--)
		{
			if(str[i] != ' ')
				str[writeBeginAt--] = str[i];
			else
			{
				str[writeBeginAt--] = '0';
				str[writeBeginAt--] = '2';
				str[writeBeginAt--] = '%';
			}
		}

		return true;
	}

	void run()
	{
		string str[3];
		str[0] = "abcdefgh";
		str[1] = " bcdefgh  ";
		str[2] = "ab defgh  ";

		int realLength[3];
		realLength[0] = 8;
		realLength[1] = 8;
		realLength[2] = 8;

		string resultStr[3];
		resultStr[0] = "abcdefgh";
		resultStr[1] = "%20bcdefgh";
		resultStr[2] = "ab%20defgh";


		for(int i = 0; i < 3; i++)
		{
			cout << "Test " << i << ": ";
			if(replaceSpace(str[i], realLength[i]) && (str[i].compare(resultStr[i]) == 0))
				cout << "OK";
			else
				cout << "Fail";

			cout << "." << endl;
		}

		return;
	}
}