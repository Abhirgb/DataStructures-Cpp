#include "SparseMatrixUsingLinkedList.h"

SparseMatrixWithLL::SparseMatrixWithLL(): iRows(0), iColumns(0), iNumOfNonZeros(0)
{
}

SparseMatrixWithLL::SparseMatrixWithLL(int rows, int columns, int nonzeros):iRows(rows), iColumns(columns), iNumOfNonZeros(nonzeros)
{
	Create();
}

void SparseMatrixWithLL::SetRows(int rows)
{
	iRows = rows;
}

void SparseMatrixWithLL::SetColumns(int cols)
{
	iColumns = cols;
}

void SparseMatrixWithLL::SetNumOfNonZeros(int nums)
{
	iNumOfNonZeros = nums;
}

void SparseMatrixWithLL::Create()
{
	m_pSparseMatrixLL = new LinkedList<Element>[iRows];
	cout << "Enter row , column and non zero element... for " << iNumOfNonZeros << " elements" << endl;
	for (int i = 0; i < iRows; i++)
	{
		bool bSameRow = true;
		while (bSameRow)
		{
			cout << "\n" << "is there a next element in "<< i <<" row? Y/y or N/n :- ";
			char ch;
			cin >> ch;
			if (ch == 'N' || ch == 'n')
			{
				bSameRow = false;
				continue;
			}
			Element element;
			cout << "Enter column data of " << i << " row :- ";
			cin >> element.iColumn >> element.iElement;
			m_pSparseMatrixLL[i].Insert(element);
		}
	}
}

void SparseMatrixWithLL::Display()
{
	int k = 0;
	for (int i = 0; i < iRows; i++)
	{
		Node<Element>* pNode = m_pSparseMatrixLL[i].GetHead();
		for (int j = 0; j < iColumns; j++)
		{
			if (pNode)
			{
				if (j == pNode->data.iColumn)
				{
					cout << pNode->data.iElement << " ";
					pNode = pNode->pNext;
				}
				else
					cout << "0 ";
			}
			else
			{
				cout << "0 ";
			}
		}
		cout << "\n";
	}
}

ostream& operator<<(ostream& os, const Element& ref)
{
	// TODO: insert return statement here
	os << ref.iElement;
	return os;
}
