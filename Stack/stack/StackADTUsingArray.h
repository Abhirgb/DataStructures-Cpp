#pragma once
#include "StandardIncludes.h"


template <class T>
class StackADTUsingArray
{
	T* pStack;
	int iTop;
	int iSize;
public:
	StackADTUsingArray();

	StackADTUsingArray(int Size);

	~StackADTUsingArray();

	void Push(T data);

	void Pop();

	T Top();

	T Peek(int index);

	bool IsEmpty();

	bool IsFull();

	int Size();

};

template<class T>
StackADTUsingArray<T>::StackADTUsingArray()
{
	pStack = NULL;
	iSize = 5;
	iTop = -1;
}

template<class T>
StackADTUsingArray<T>::StackADTUsingArray(int Size)
{
	iSize = Size;
	pStack = new T[Size];
	iTop = -1;
}

template<class T>
inline StackADTUsingArray<T>::~StackADTUsingArray()
{
	delete pStack;
}

template<class T>
void StackADTUsingArray<T>::Push(T data)
{
	if (iTop == iSize - 1)
	{
		cout << "Stack OverFlow" << endl;
		return;
	}
	iTop++;
	pStack[iTop] = data;
}

template<class T>
void StackADTUsingArray<T>::Pop()
{
	if (iTop == -1)
	{
		cout << "Stack UnderFlow" << endl;
	}
	else
	{
		T Temp = pStack[iTop];
		iTop--;
	}
}

template<class T>
T StackADTUsingArray<T>::Top()
{
	if (iTop == -1)
		return T{};
	return pStack[iTop];
}

template<class T>
T StackADTUsingArray<T>::Peek(int index)
{
	if (iTop - (index - 1) < 0 || index < 0)
	{
		cout << "Invalid Index" << endl;
		return T{};
	}
	return pStack[(iTop - (index - 1))];
}

template<class T>
bool StackADTUsingArray<T>::IsEmpty()
{
	if(iTop == -1)
		return true;
	return false;
}

template<class T>
bool StackADTUsingArray<T>::IsFull()
{
	if(iTop == iSize - 1)
		return true;
	return false;
}

template<class T>
int StackADTUsingArray<T>::Size()
{
	return iTop+1;
}
