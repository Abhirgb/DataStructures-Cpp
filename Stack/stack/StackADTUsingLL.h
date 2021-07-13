#pragma once

#include "StandardIncludes.h"
#include "D:\udemy courses\Udemy Data Strutures and algorithms\Linked Lists\Linked Lists\LinkedList.h"


template<class T>
class StackADTUsingLL
{
	LinkedList<T> top;
public:
	StackADTUsingLL();

	~StackADTUsingLL();

	void Push(T data);

	void Pop();

	T Top();

	T Peek(int index);

	bool IsEmpty();

	bool IsFull();
};

template<class T>
StackADTUsingLL<T>::StackADTUsingLL()
{
}

template<class T>
StackADTUsingLL<T>::~StackADTUsingLL()
{
}

template<class T>
void StackADTUsingLL<T>::Push(T data)
{
	if (!top.InsertAt(0, data))
		cout << "Stack OverFlow" << endl;
}

template<class T>
void StackADTUsingLL<T>::Pop()
{
	if (!top.Delete(1))
		cout << "Stack UnderFlow" << endl;
}

template<class T>
T StackADTUsingLL<T>::Top()
{
	if(!IsEmpty())
		return top.GetHead()->data;
	return T{};
}

template<class T>
T StackADTUsingLL<T>::Peek(int index)
{
	Node<T>* pTemp = top.GetHead();
	int i = 1;
	while (pTemp && i != index)
	{
		pTemp = pTemp->pNext;
		i++;
	}
	if (pTemp)
		return pTemp->data;
	return T{};
}

template<class T>
bool StackADTUsingLL<T>::IsEmpty()
{
	if(top.GetHead())
		return false;
	return true;
}

template<class T>
bool StackADTUsingLL<T>::IsFull()
{
	Node<T>* pTemp = new Node<T>();
	if (!pTemp)
		return true;
	delete pTemp;
	return false;
}
