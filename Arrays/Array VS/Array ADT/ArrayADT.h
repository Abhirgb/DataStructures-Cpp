#ifndef _ARRAY_ADT_
#define _ARRAY_ADT_

#include "StdIncludes.h"

template<class T> class ArrayADT
{

private:
	T* arr;
protected:
	int iSize;
	int iLength;

public:
	ArrayADT();
	~ArrayADT();

public:
	bool CreateNewArray(int size);
	void Display() const;

	T* GetArray();
	void SetSize(int size);
	int GetSize();
	void SetLength(int length);
	int GetLength();

	void Add(T& Value);
	bool Insert(int iIndex, T Value);
	bool Delete(int iIndex);
	int FindFirstUsingLinearSearch(T iKey);
	bool CopyRootArray(T* Dest);

	//! call this function to get the element at required index
	//! Param:	index	-	pass the index of the element to be fetched
	//! returns the element at index in the array(arr) if index is greater than iLength returns -1;
	T Get(int index);

	//! call this function to replace a value at required index with the passed value
	//! Param:	index	-	index of the element in the array to be replaced
	//! Param:	Value	-	value that has to replace the element at index
	//! return				true if successfull
	//!						false if un-successfull
	bool Set(int index, T Value);

	//! returns the maximum value in the array(arr)
	T Max();

	//! returns the minimum value in the array(arr)
	T Min();

	//! returns the sum of all the elements in the array
	T Sum();

	//! returns the avg of elements in the array
	T Average();

	//! all the elements in the array are reversed
	void Reverse();

	//! shifts all the elements 1 index left and the last element will be zero
	void LeftShift();

	//! shifts all the elements 1 index right and the first element will be 0
	void RightShift();

	//! shifts all the elements 1 index left and last element will be filled with the first element of before rotate
	void LeftRotate();

	//! shifts all the elements 1 index right  and the first element will be filled with the last element of before rotate
	void RightRotate();

	//! check's whether the array is sorted
	//! Param:	bAscending	-	true, To check if sorted in Ascending order
	//!							false, To check if sorted in Descending order
	//! return				-	true if sorted
	//!						-	false if array is not sorted
	bool IsSorted(bool bAscending = true);

	//! merge can only be performed on the sorted arrays
	//! so if arrays are not sorted this function returns false
	//! Param:	ArrayTobeMerged		-		array that is to be merged in to arr
	//! Param:	bAscending			-		true if the both array's are sorted in Ascending order
	//!										false if sorted in Descending Order
	//! return:						-		true if merged
	//!										false if not
	bool Merge(ArrayADT<T> *ArrayTobeMerged, bool bAscending = true);

	//! Param:	bOrder	-	true for Ascending order
	//!						false for descending order
	//!default is set to true
	void BubbleSort(bool bOrder = true);

	//! Param:	bOrder	-	true for Ascending order
	//!						false for descending order
	//!default is set to true
	void QuickSort(bool bOrder = true);
	
	//! call this function to fecth the zero based index of a certain value
	//! if present returns the zero based index else -1
	//! Param:	iKey		-		value of which index need to be fetched
	//!			bAscending	-		default true
	//!								true for sorting in Ascending order and fecth the index
	//!								false for sorting in descending order and fecth the index
	int BinarySearch(T iKey, bool bAscending = true);
};

template<class T>
ArrayADT<T>::ArrayADT() :arr{ NULL }, iSize(0), iLength(0)
{
}

template<class T>
ArrayADT<T>::~ArrayADT()
{
	if (arr)
		delete[] arr;
}
template<class T>
bool ArrayADT<T>::CreateNewArray(int size)
{
	arr = new T[size];
	if (arr)
		return true;
	return false;
}

template<class T>
void ArrayADT<T>::Display() const
{
	std::cout << "Elements of the Array: ";
	for (int i = 0; i < iLength; i++)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

template<class T> T* ArrayADT<T>::GetArray()
{
	return arr;
}

template<class T> void ArrayADT<T>::SetSize(int size)
{
	iSize = size;
}

template<class T> int ArrayADT<T>::GetSize()
{
	return iSize;
}

template<class T> void ArrayADT<T>::SetLength(int length)
{
	iLength = length;
}

template<class T> int ArrayADT<T>::GetLength()
{
	return iLength;
}

template<class T> void ArrayADT<T>::Add(T &Entry)
{
	if (iLength >= iSize)
	{
		iSize += 1;
		T* NewArr = new T[iSize];
		if (arr)
		{
			for (int i = 0; i < iLength; i++)
				NewArr[i] = arr[i];

			delete[] arr;
		}
		NewArr[iLength] = Entry;
		arr = NewArr;
	}
	else
	{
		arr[iLength] = Entry;
	}
	iLength ++;
}

template<class T>
bool ArrayADT<T>::Insert(int iIndex, T Value)
{
	if (iIndex >= iSize || iIndex < 0)
	{
		std::cout << "Index out of range to insert" << std::endl;
		return false;
	}
	if (iLength == iSize)
	{
		iSize++;
		T* NewArr = new T[iSize];
		for (int i = 0; i < iLength; i++)
		{
			NewArr[i] = arr[i];
		}
		delete[] arr;
		arr = NewArr;
	}
	int iCurrentIndex = iLength;
	do
	{
		arr[iCurrentIndex] = arr[iCurrentIndex - 1];
		iCurrentIndex--;
	} while (iCurrentIndex != iIndex);
	arr[iIndex] = Value;
	iLength++;
	return true;
}

template<class T>
bool ArrayADT<T>::Delete(int iIndex)
{
	if (iIndex >= iLength || iIndex < 0)
	{
		std::cout << "Index out of range to delete" << std::endl;
		return false;
	}
	for (int i = iIndex; i < iLength - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	iLength--;
	iSize--;
	T* NewArr = new T[iSize];
	for (int i = 0; i < iLength; i++)
	{
		NewArr[i] = arr[i];
	}
	delete[] arr;
	arr = NewArr;

	return true;
}

template<class T>
int ArrayADT<T>::FindFirstUsingLinearSearch(T iKey)
{
	for (int i = 0; i < iLength; i++)
	{
		if (iKey == arr[i])
			return i;
	}
	return -1;
}

template<class T>
bool ArrayADT<T>::CopyRootArray(T* Dest)
{
	if (arr)
		return false;
	Dest = new int[iSize];
	for (int i = 0; i < iLength; i++)
	{
		Dest[i] = arr[i];
	}
	return true;
}

template<class T>
T ArrayADT<T>::Get(int index)
{
	if (index >= iLength || index < 0)
		return -1;
	return arr[index];
}

template<class T>
bool ArrayADT<T>::Set(int index, T Value)
{
	if (index >= iSize || index < 0)
		return false;
	arr[index] = Value;
	return true;
}

template<class T>
T ArrayADT<T>::Max()
{
	T Max = arr[0];
	for (int i = 1; i < iLength; i++)
	{
		if (arr[i] > Max)
			Max = arr[i];
	}
	return Max;
}

template<class T>
T ArrayADT<T>::Min()
{
	T Min = arr[0];
	for (int i = 1; i < iLength; i++)
	{
		if (arr[i] < Min)
			Min = arr[i];
	}
	return Min;
}

template<class T>
T ArrayADT<T>::Sum()
{
	T Sum = 0;
	for (int i = 0; i < iLength; i++)
	{
		Sum += arr[i];
	}
	return Sum;
}

template<class T>
T ArrayADT<T>::Average()
{
	return (Sum() / iLength);
}

template<class T>
void ArrayADT<T>::Reverse()
{
	if (iLength > 1)
	{
		int i = 0;
		int j = iLength - 1;
		bool bReversed = false;
		while (!bReversed)
		{
			T Temp = arr[i];
			arr[i] = arr[j];
			arr[j] = Temp;
			i++;
			j--;
			if (i >= j)
				bReversed = true;
		}
	}
}

template<class T>
void ArrayADT<T>::LeftShift()
{
	if (iLength > 1)
	{
		for (int i = 0; i < iLength - 1; i++)
			arr[i] = arr[i + 1];
		arr[iLength - 1] = 0;
	}
}

template<class T>
void ArrayADT<T>::RightShift()
{
	if (iLength > 1)
	{
		for (int i = iLength - 2; i >= 0; i--)
			arr[i + 1] = arr[i];
		arr[0] = 0;
	}
}

template<class T>
void ArrayADT<T>::LeftRotate()
{
	if (iLength > 1)
	{
		T Temp = arr[0];
		LeftShift();
		arr[iLength - 1] = Temp;
	}
}

template<class T>
void ArrayADT<T>::RightRotate()
{
	if (iLength > 1)
	{
		T Temp = arr[iLength - 1];
		RightShift();
		arr[0] = Temp;
	}
}

template<class T>
bool ArrayADT<T>::IsSorted(bool bAscending)
{
	for (int i = 0; i < iLength - 1; i++)
	{
		bool bIsValid = bAscending ? (arr[i] <= arr[i + 1]) : (arr[i] >= arr[i + 1]);
		if (!bIsValid)
			return bIsValid;
	}
	return true;
}

template<class T>
bool ArrayADT<T>::Merge(ArrayADT<T> *ArrayTobeMerged, bool bAscending)
{
	if (!IsSorted(bAscending) || !ArrayTobeMerged->IsSorted(bAscending))
		return false;
	int i = 0;
	int j = 0;
	T* TempArr = new T[iSize + ArrayTobeMerged->GetSize()];
	int iIndex = 0;
	while (i < iLength && j < ArrayTobeMerged->GetLength())
	{
		bool bInsert = bAscending ? (ArrayTobeMerged->Get(j) <= this->arr[i]) : (ArrayTobeMerged->Get(j) >= this->arr[i]);
		if (bInsert)
			TempArr[iIndex++] = ArrayTobeMerged->Get(j++);
		else
			TempArr[iIndex++] = this->arr[i++];
	}
	while(i < iLength)
		TempArr[iIndex++] = this->arr[i++];
	while(j < ArrayTobeMerged->GetLength())
		TempArr[iIndex++] = ArrayTobeMerged->Get(j++);
	if (TempArr)
	{
		delete[] this->arr;
		iLength += ArrayTobeMerged->GetLength();
		iSize += ArrayTobeMerged->GetSize();
		this->arr = TempArr;
	}
	return true;
}

template<class T>
void ArrayADT<T>::BubbleSort(bool bOrder)
{
	/*std::vector<T> arrVec;
	for (int i = 0; i < iLength; i++)
		arrVec.push_back(arr[i]);
	int iCurIndex = iLength - 1;
	typename std::vector<int>::iterator it = arrVec.begin();*/ 
	bool bSorted = false;
	int iLastUnsorted = iLength - 1;
	while (!bSorted)
	{
		bSorted = true;
		for (int i = 0; i < iLastUnsorted; i++)
		{
			bool bSwapRequired = bOrder ? (arr[i] > arr[i + 1]) : (arr[i] < arr[i + 1]);
			if (bSwapRequired)
			{
				T temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				bSorted = false;
			}
		}
		iLastUnsorted--; //because after going through the whole array once the highest or smallest element will be pushed to last and we can ignore it each iteration
	}
	//while (arrVec.size() > 0)
	//{
	//	if (arrVec.size() == 1)
	//	{
	//		arr[iCurIndex] = *it;
	//		iCurIndex--;
	//		break;
	//	}

	//	bool bSwap = bOrder ? (*it > * (++it)) : (*it < *(++it));
	//	if (bSwap)
	//	{
	//		T NextValue = *it;
	//		it--;
	//		T CurrentValue = *it;
	//		*it = NextValue;
	//		it++;
	//		*it = CurrentValue;
	//	}

	//	if (it == (arrVec.end() - 1))
	//	{
	//		arr[iCurIndex] = *it;
	//		iCurIndex--;
	//		it = arrVec.begin(); //assing to begin and pop the last
	//		arrVec.pop_back();
	//	}
	//}
}

template <class T>
int ArrayADT<T>::BinarySearch(T iKey, bool bAscending)
{
	BubbleSort(bAscending);
	int iLowerState = 0;
	int iUpperState = iLength - 1;
	int index = (iLowerState + iUpperState) / 2;
	bool bCheck;
	while (iLowerState <= iUpperState)
	{
		if (iKey == arr[index])
			return index;
		bCheck = bAscending ? (iKey < arr[index]) : (iKey > arr[index]);
		if (bCheck)
			iUpperState = index - 1;
		else
			iLowerState = index + 1;
		index = (iLowerState + iUpperState) / 2;
	}
	return -1;
}

template<class T>
void ArrayADT<T>::QuickSort(bool bOrder)
{
	T* pHead = arr[0];
	T* pTail = arr[iLength - 1];
	T* pEndCase = NULL;
	bool bSwaped = false;
	while (pTail != pEndCase)
	{
		if (*pHead > * pTail)
		{
			T Temp = *pHead;
			*pHead = *pTail;
			*pTail = Temp;
			if (bSwaped)
			{
				bSwaped = false;
				pTail--;
			}
			else
			{
				bSwaped = true;
				pHead++;
			}
		}
		else
		{
			if (bSwaped)
				pHead++;
			else
				pTail--;
		}
		if (pHead == pTail)
		{
			pEndCase = pHead + 1;
			pHead = arr[0];
			pTail--;
		}
	}
}

#endif // !_ArrayADT
