#pragma once
#include "StandardIncludes.h"
#include "D:\udemy courses\Udemy Data Strutures and algorithms\Linked Lists\Linked Lists\LinkedList.h"

struct Element {
	int iColumn;
	int iElement;
};

class SparseMatrixWithLL
{
	LinkedList<Element>* m_pSparseMatrixLL;
	int iRows;
	int iColumns;
	int iNumOfNonZeros;
public:
	SparseMatrixWithLL();
	SparseMatrixWithLL(int rows, int columns, int nonzeros);
	void SetRows(int rows);
	void SetColumns(int cols);
	void SetNumOfNonZeros(int nums);

	//! Set No of rows and columns of the matrix along with the num of Non Zeros before calling this function
	//! if not set sparse matrix won't be created
	//! This function asks you to enter the matrix elements with their row and column indicies alon with data at that location
	void Create();

	//
	void Display();

	friend ostream& operator<<(ostream& os, const Element& ref);
};