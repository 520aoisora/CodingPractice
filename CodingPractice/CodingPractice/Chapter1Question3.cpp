#include <iostream>
#include <algorithm>

#include "Question3.h"

using namespace std;

namespace Q3
{
	bool isPermutation(string str1, string str2)
	{
		int strLength1 = str1.length();
		int strLength2 = str2.length();

		if(strLength1 != strLength2)
			return false;

		int counter1[256], counter2[256];

		for(int i = 0; i < strLength1; i++)
		{
			counter1[str1[i]]++;
			counter2[str2[i]]++;
		}

		for(int i = 0; i < 256; i++)
		{
			if(counter1[i] != counter2[i])
				return false;
		}

		return true;
	}
	
	bool isPermutation_Sort(std::string str1, std::string str2)
	{
		int strLength1 = str1.length();
		int strLength2 = str2.length();

		if(strLength1 != strLength2)
			return false;

		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());

		for(int i = 0; i < strLength1; i++)
		{
			if(str1[i] != str2[i])
				return false;
		}

		return true;
	}

	void run()
	{
		string str1[3];
		str1[0] = "abcdefgh";
		str1[1] = "abcdefgh";
		str1[2] = "abcdefgh";

		string str2[3];
		str2[0] = "hgfedcba";
		str2[1] = "hgfedcb";
		str2[2] = "hgfedcbb";

		for(int i = 0; i < 3; i++)
		{
			cout << "str1: " << str1[i] << " is ";

			if(!isPermutation_Sort(str1[i],str2[i]))
				cout << "not ";

			cout << "the permutation of str2: " << str2[i] << endl;
		}

		return;
	}
}