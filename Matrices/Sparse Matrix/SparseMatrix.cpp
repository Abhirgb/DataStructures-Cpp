#include "SparseMatrix.h"

int SparseMatrix::GetRows()
{
	return iNumOfRows;
}

int SparseMatrix::GetColumns()
{
	return iNumOfColumns;
}

int SparseMatrix::GetNoOfNonZeroElements()
{
	return iNumOfNonZeroElements;
}

void SparseMatrix::SetRows(int i)
{
	iNumOfRows = i;
}

void SparseMatrix::SetColumns(int j)
{
	iNumOfColumns = j;
}

void SparseMatrix::SetNoOfNonZeroElements(int num)
{
	iNumOfNonZeroElements = num;
}

SparseMatrix::SparseMatrix(int i, int j, int num):iNumOfRows(i),iNumOfColumns(j),iNumOfNonZeroElements(num)
{
}

void SparseMatrix::Read()
{
	cout << "Enter row , column and non zero element... for "<< iNumOfNonZeroElements << " elements" << endl;
	for (int index = 0; index < iNumOfNonZeroElements; index++)
	{
		MatrixElement Temp;
		cin >> Temp.iRow >> Temp.iColumn >> Temp.iElement;
		Temp.iRow--;
		Temp.iColumn--;
		VectorOfMatrixElement.push_back(Temp);
	}
}

void SparseMatrix::Display()
{
	int k = 0;
	for (int i = 0; i < iNumOfRows; i++)
	{
		for (int j = 0; j < iNumOfColumns; j++)
		{
			if (k < VectorOfMatrixElement.size() && i == VectorOfMatrixElement[k].iRow && j == VectorOfMatrixElement[k].iColumn)
				cout << VectorOfMatrixElement[k++].iElement << " ";
			else
				cout << "0 ";
		}
		cout << "\n";
	}
}

//SparseMatrix* AddSparseMatrices(SparseMatrix* This, SparseMatrix* S2)
//{
//	if (This->iNumOfRows != S2->iNumOfRows || This->iNumOfColumns != S2->iNumOfColumns)
//		return NULL;
//	SparseMatrix* p = new SparseMatrix();
//	p->iNumOfRows = This->iNumOfRows;
//	p->iNumOfColumns = This->iNumOfColumns;
//	int i = 0;
//	int j = 0;
//	while (i < This->VectorOfMatrixElement.size() && j < S2->VectorOfMatrixElement.size())
//	{
//		if (This->VectorOfMatrixElement[i].iRow < S2->VectorOfMatrixElement[j].iRow)
//			p->VectorOfMatrixElement.push_back({ This->VectorOfMatrixElement[i].iRow, This->VectorOfMatrixElement[i].iColumn, This->VectorOfMatrixElement[i++].iElement });
//		else if(This->VectorOfMatrixElement[i].iRow > S2->VectorOfMatrixElement[j].iRow)
//			p->VectorOfMatrixElement.push_back({ S2->VectorOfMatrixElement[j].iRow, S2->VectorOfMatrixElement[j].iColumn, S2->VectorOfMatrixElement[j++].iElement });
//		else
//		{
//			if (This->VectorOfMatrixElement[i].iColumn < S2->VectorOfMatrixElement[j].iColumn)
//				p->VectorOfMatrixElement.push_back({ This->VectorOfMatrixElement[i].iRow, This->VectorOfMatrixElement[i].iColumn, This->VectorOfMatrixElement[i++].iElement });
//			else if (This->VectorOfMatrixElement[i].iColumn > S2->VectorOfMatrixElement[j].iColumn)
//				p->VectorOfMatrixElement.push_back({ S2->VectorOfMatrixElement[j].iRow, S2->VectorOfMatrixElement[j].iColumn, S2->VectorOfMatrixElement[j++].iElement });
//			else
//			{
//				p->VectorOfMatrixElement.push_back({ This->VectorOfMatrixElement[i].iRow, This->VectorOfMatrixElement[i].iColumn, This->VectorOfMatrixElement[i++].iElement });
//				p->VectorOfMatrixElement.back().iElement += S2->VectorOfMatrixElement[j++].iElement;
//			}
//		}
//	}
//	while (i < This->VectorOfMatrixElement.size())
//		p->VectorOfMatrixElement.push_back({ This->VectorOfMatrixElement[i].iRow, This->VectorOfMatrixElement[i].iColumn, This->VectorOfMatrixElement[i++].iElement });
//	while (j < S2->VectorOfMatrixElement.size())
//		p->VectorOfMatrixElement.push_back({ S2->VectorOfMatrixElement[j].iRow, S2->VectorOfMatrixElement[j].iColumn, S2->VectorOfMatrixElement[j++].iElement });
//	return p;
//}

SparseMatrix* SparseMatrix::operator+(SparseMatrix S2)
{
	if (this->GetRows() != S2.GetRows() || this->GetColumns() != S2.GetColumns())
		return NULL;
	SparseMatrix* p = new SparseMatrix(4,5,6);
	p->SetRows(this->GetRows());
	p->SetColumns(this->GetColumns());
	int i = 0;
	int j = 0;
	while (i < this->VectorOfMatrixElement.size() && j < S2.VectorOfMatrixElement.size())
	{
		if (this->VectorOfMatrixElement[i].iRow < S2.VectorOfMatrixElement[j].iRow)
			p->VectorOfMatrixElement.push_back(this->VectorOfMatrixElement[i++]);
		else if (this->VectorOfMatrixElement[i].iRow > S2.VectorOfMatrixElement[j].iRow)
			p->VectorOfMatrixElement.push_back(S2.VectorOfMatrixElement[j++]);
		else
		{
			if (this->VectorOfMatrixElement[i].iColumn < S2.VectorOfMatrixElement[j].iColumn)
				p->VectorOfMatrixElement.push_back(this->VectorOfMatrixElement[i++]);
			else if (this->VectorOfMatrixElement[i].iColumn > S2.VectorOfMatrixElement[j].iColumn)
				p->VectorOfMatrixElement.push_back(S2.VectorOfMatrixElement[j++]);
			else
			{
				p->VectorOfMatrixElement.push_back(this->VectorOfMatrixElement[i++]);
				p->VectorOfMatrixElement.back().iElement += S2.VectorOfMatrixElement[j++].iElement;
			}
		}
	}
	while (i < this->VectorOfMatrixElement.size())
		p->VectorOfMatrixElement.push_back(this->VectorOfMatrixElement[i++]);
	while (j < S2.VectorOfMatrixElement.size())
		p->VectorOfMatrixElement.push_back(S2.VectorOfMatrixElement[j++]);
	return p;
}
