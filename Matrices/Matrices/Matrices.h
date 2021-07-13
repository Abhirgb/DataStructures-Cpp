#pragma once
#include<iostream>

using namespace std;

enum class MatrixType
{
	DIAGONAL_MATRIX = 0,
	LOWER_TRIANGULAR_MATRIX
};

class Matrices
{
public:
	Matrices();
	Matrices(MatrixType eType, int row, int col);
	~Matrices();

private:
	int* pDiagonalMatrix;
	bool m_bIsDiagonal;

public:
	void SetAt(int i, int j, int Value);
	int GetAt(int i, int j);

};