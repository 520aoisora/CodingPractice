#include <iostream>
//#include <boost/lexical_cast.hpp>
#include <sstream>

#include "Question5.h"

using namespace std;

namespace Q5
{
	void append(std::string& newStr, char lastChar, int count)
	{
		stringstream ss1;
		ss1 << lastChar;
		newStr.append(ss1.str());

		stringstream ss2;
		ss2 << count;
		newStr.append(ss2.str());
	}

	bool compressString(string& str)
	{
		unsigned int size = str.size();
		if(size == 0)
			return false;

		char lastChar = str[0];
		int count = 0;
		string newStr = "";

		for(unsigned int i = 0; i < size; i++)
		{
			if(str[i] != lastChar)
			{
				append(newStr, lastChar, count);
				lastChar = str[i];
				count = 1;
			}
			else
				count++;
		}

		append(newStr, lastChar, count);

		if(newStr.size() < size)
			str = newStr;

		return true;
	}

	void run()
	{
		string str[3];
		str[0] = "abcdefgh";
		str[1] = "aabbccdd";
		str[2] = "aaaabbbb";

		string resultStr[3];
		resultStr[0] = "abcdefgh";
		resultStr[1] = "aabbccdd";
		resultStr[2] = "a4b4";


		for(int i = 0; i < 3; i++)
		{
			cout << "Test " << i << ": ";
			if(compressString(str[i]) && (str[i].compare(resultStr[i]) == 0))
				cout << "OK";
			else
				cout << "Fail";

			cout << "." << endl;
		}

		return;
	}
}