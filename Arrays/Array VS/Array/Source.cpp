#include<iostream>
#include<array>
#include<iomanip>

void Print2DArray(int** p,int row,int col)
{
	std::cout << row << "*" << col << " Array\n";
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << p[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int main()
{
	int A[5] = {1,2,3,4,5};
	int* p;
	p = new int[5];
	p[0] = 6;
	p[1] = 7;
	p[2] = 8;
	p[3] = 9;
	p[4] = 10;
	std::cout << "A: ";
	for (int i = 0; i < 5; i++)
	{
		std::cout << A[i] << ",";
	}
	std::cout << "\n";
	std::cout << "p: ";
	for (int i = 0; i < 5; i++)
	{
		std::cout << p[i] << ",";
	}
	std::cout << "\n";
	int iNewSize;
	std::cout << "Enter the new size: ";
	std::cin >> iNewSize;
	int *q = new int[iNewSize];
	for (int i = 0; i < 5; i++)
		q[i] = p[i];
	delete[] p;
	p = q;
	q = NULL;
	for (int i = 5; i < iNewSize; i++)
	{
		std::cout << "Enter array value: ";
		int iVal;
		std::cin >> iVal;
		p[i] = iVal;
	}

	std::cout << "p: ";
	for (int i = 0; i < iNewSize; i++)
	{
		std::cout << *p << ",";
		p++;
	}

	//2D Array
	//Type 1 declaration
	std::cout << "\n\n";
	int Array2D[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
	std::cout << "3*4" << " Array\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << std::setw(5) << Array2D[i][j];
		}
		std::cout << "\n";
	};

	//Type 2 declaration
	std::cout << "\n\n";
	int* ArrayOfintPointers[3];
	ArrayOfintPointers[0] = new int[4];
	ArrayOfintPointers[1] = new int[4];
	ArrayOfintPointers[2] = new int[4];
	ArrayOfintPointers[0][0] = 1; ArrayOfintPointers[0][1] = 2; ArrayOfintPointers[0][2] = 3; ArrayOfintPointers[0][3] = 4;
	ArrayOfintPointers[1][0] = 5; ArrayOfintPointers[1][1] = 6; ArrayOfintPointers[1][2] = 7; ArrayOfintPointers[1][3] = 8;
	ArrayOfintPointers[2][0] = 9; ArrayOfintPointers[2][1] = 10; ArrayOfintPointers[2][2] = 11; ArrayOfintPointers[2][3] = 12;
	std::cout << "3*4" << " Array\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << std::setw(5) << ArrayOfintPointers[i][j];
		}
		std::cout << "\n";
	};

	//Type 3 declaration
	std::cout << "\n\n";
	int** DoublePointer;
	DoublePointer = ArrayOfintPointers;
	std::cout << "3*4" << " Array\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << std::setw(5) << DoublePointer[i][j];
		}
		std::cout << "\n";
	};

	int** DblPointer = new int* [3];
	DblPointer[0] = new int[4];
	DblPointer[1] = new int[4];
	DblPointer[2] = new int[4];
	std::cout << "3*4" << " Array\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			std::cout << std::setw(5) << DblPointer[i][j];
		}
		std::cout << "\n";
	};

	return 0;
}