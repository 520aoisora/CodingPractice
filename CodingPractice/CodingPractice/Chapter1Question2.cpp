#include <iostream>

#include "Question2.h"

using namespace std;

namespace Q2
{
	void swap(char *begin, char *end)
	{
		char tmp = *begin;
		*begin = *end;
		*end = tmp;
	}

	void reverse(char *str)
	{
		char *begin = str;
		char *end = str;

		while(*end != NULL)
			end++;
		end--;

		for(; begin < end; begin++, end--)
			swap(begin, end);
	}

	void run()
	{
		char str[] = "hello";

		char *str1 = str;

		reverse(str1);

		cout << str1 << endl;

		return;
	}
}