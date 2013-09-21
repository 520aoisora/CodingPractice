#include <iostream>

#include "Question6.h"

using namespace std;

namespace Q6
{
	bool areEqualArray2(int matrix1[2][2], int matrix2[2][2])
	{
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				if(matrix1[i][j] != matrix2[i][j])
					return false;

		return true;
	}

	void rotate2(int matrix[2][2], int N)
	{
		for(int row = 0; row < (N / 2); row++)
		{
			for(int column = 0; column < ((N+1) / 2); column++)
			{
				int temp = matrix[row][column];
				matrix[row][column] = matrix[row][N-1-column];
				matrix[row][N-1-column] = matrix[N-1-row][N-1-column];
				matrix[N-1-row][N-1-column] = matrix[N-1-row][column];
				matrix[N-1-row][column] = temp;
			}
		}
	}

	void run()
	{
		int matrix1[2][2] = {{1,2},
							 {3,4}};

		int resultMatrix1[2][2] = {{2,4},
								   {1,3}};

		rotate2(matrix1,2);

		cout << "Test 1: ";
		if(areEqualArray2(matrix1, resultMatrix1))
			cout << "OK";
		else
			cout << "Fail";

		cout << "." << endl;

		return;
	}
}