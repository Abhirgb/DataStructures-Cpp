#pragma once

#include <iostream>
#include <vector>

struct MatrixElement
{
	int iRow;
	int iColumn;
	int iElement;

	MatrixElement() {
		iRow = 0;
		iColumn = 0;
		iElement = 0;
	}

	MatrixElement(int row, int col, int data) {
		iRow = row;
		iColumn = col;
		iElement = data;
	}
};
