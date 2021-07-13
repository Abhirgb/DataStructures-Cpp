#pragma once
#include "StandardIncludes.h"

using namespace std;

class SparseMatrix
{
	int iNumOfRows = 0;
	int iNumOfColumns = 0;
	int iNumOfNonZeroElements = 0;

	vector<MatrixElement> VectorOfMatrixElement;

public:

	int GetRows();

	int GetColumns();

	int GetNoOfNonZeroElements();

	void SetRows(int i);

	void SetColumns(int j);

	void SetNoOfNonZeroElements(int num);

	SparseMatrix(int i, int j, int num);

	void Read();

	void Display();

	SparseMatrix* operator+(SparseMatrix S2);

};

