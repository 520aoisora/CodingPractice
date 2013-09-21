#include <iostream>

#include "Question7.h"

using namespace std;

namespace Q7
{
	bool areEqualArray3(int matrix1[3][3], int matrix2[3][3])
	{
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				if(matrix1[i][j] != matrix2[i][j])
					return false;

		return true;
	}

	void repaintArray(int matrix[3][3])
	{
		int rows[3], columns[3];
		fill_n(rows, 3, 1);
		fill_n(columns, 3, 1);

		for(int row = 0; row < 3; row++)
		{
			for(int column = 0; column < 3; column++)
			{
				if(matrix[row][column] == 0)
				{
					rows[row] = 0;
					columns[column] = 0;
				}
			}
		}

		for(int row = 0; row < 3; row++)
			if(rows[row] == 0)
				for(int column = 0; column < 3; column++)
					matrix[row][column] = 0;

		for(int column = 0; column < 3; column++)
			if(columns[column] == 0)
				for(int row = 0; row < 3; row++)
					matrix[row][column] = 0;
	}

	void run()
	{
		//int test[2][2][2];

		//int test1[2][2] = {{1,2},{3,4}};
		//int test2[2][2] = {{5,6},{7,8}};

		//memcpy(test[0], test1, 16);
		//memcpy(test[1], test2, 16);

		//for(int i = 0; i < 2; i++)
		//	for(int j = 0; j < 2; j++)
		//		for(int k = 0; k < 2; k++)
		//			cout << test[i][j][k];
		//cout << endl;

		int matrix[4][3][3] = {{{1,1,1},
								{1,1,1},
								{1,1,1}},

							   {{0,1,1},
								{1,1,1},
								{1,1,1}},

							   {{1,1,1},
								{1,0,1},
								{1,1,1}},

							   {{1,1,1},
								{1,1,0},
								{1,0,1}}};

		int resultMatrix[4][3][3] = {{{1,1,1},
									  {1,1,1},
									  {1,1,1}},

									 {{0,0,0},
									  {0,1,1},
									  {0,1,1}},

									 {{1,0,1},
									  {0,0,0},
									  {1,0,1}},

									 {{1,0,0},
									  {0,0,0},
									  {0,0,0}}};

		for(int i = 0; i < 4; i++)
		{
			repaintArray(matrix[i]);

			cout << "Test " << i << ": ";
			if(areEqualArray3(matrix[i], resultMatrix[i]))
				cout << "OK";
			else
				cout << "Fail";

			cout << "." << endl;
		}
		return;
	}
}