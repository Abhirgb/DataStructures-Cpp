#include "Matrices.h"

Matrices::Matrices():pDiagonalMatrix(NULL),m_bIsDiagonal(false)
{
}

Matrices::Matrices(MatrixType eType, int row, int col)
{
	switch (eType)
	{
	case MatrixType::DIAGONAL_MATRIX:
		pDiagonalMatrix = new int[row];
		m_bIsDiagonal = true;
		break;
	default:
		pDiagonalMatrix = NULL;
		m_bIsDiagonal = false;
		break;
	}
}

Matrices::~Matrices()
{
	delete[] pDiagonalMatrix;
}

void Matrices::SetAt(int i, int j, int Value)
{
	if (m_bIsDiagonal)
	{
		if (i == j)
			pDiagonalMatrix[i] = Value;
	}

}

int Matrices::GetAt(int i, int j)
{
	if (m_bIsDiagonal)
	{
		if (i == j)
			return pDiagonalMatrix[i - 1];
		else
			return 0;
	}
	return 0;
}
