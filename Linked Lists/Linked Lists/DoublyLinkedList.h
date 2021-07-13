#pragma once

#include "CommonIncludes.h"

template<class T>
class node
{
public:
	node<T>* pPrevious;
	T data;
	node<T>* pNext;

	node();
	node(node<T>* prev, T data, node<T>* next);

};

template<class T>
node<T>::node()
{
	pPrevious = NULL;
	data = {};
	pNext = NULL;
}

template<class T>
node<T>::node(node<T>* prev, T data, node<T>* next)
{
	pPrevious = prev;
	this->data = data;
	pNext = next;
}

template<class T>
class DoublyLinkedList
{
	node<T>* pHead;
	node<T>* pTail;
public:
	DoublyLinkedList();
	DoublyLinkedList(T* array, int length);

	void Insert(T data);

	void Display();

	int GetCount();

	bool InsertAt(int Position, T data);

	bool DeleteAt(int Position);

	void Reverse();
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	pHead = NULL;
	pTail = NULL;
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(T* array, int length)
{
	for (int i = 0; i < length; i++)
	{
		Insert(array[i]);
	}
}

template<class T>
void DoublyLinkedList<T>::Insert(T data)
{
	node<T>* pNewNode = new node<T>(NULL, data, NULL);
	if (!pHead)
	{
		pHead = pNewNode;
		pTail = pHead;
	}
	else
	{
		pTail->pNext = pNewNode;
		pNewNode->pPrevious = pTail;
		pTail = pNewNode;
	}
}

template<class T>
void DoublyLinkedList<T>::Display()
{
	node<T>* pTemp = pHead;
	while (pTemp){
		cout << pTemp->data << " ";
		pTemp = pTemp->pNext;
	}
	cout << endl;
}

template<class T>
int DoublyLinkedList<T>::GetCount()
{
	int Count = 0;
	node<T>* pTemp = pHead;
	while (pTemp)
	{
		Count++;
		pTemp = pTemp->pNext;
	}
	return Count;
}

template<class T>
bool DoublyLinkedList<T>::InsertAt(int Position, T data)
{
	if (Position < 0 || Position > GetCount())
		return false;
	node<T>* pTemp = pHead;
	node<T>* pNewNode = new node<T>(NULL, data, NULL);
	if (!pHead)
	{
		pHead = pNewNode;
		return true;
	}
	if (Position == 0)
	{
		pNewNode->pNext = pHead;
		pHead->pPrevious = pNewNode;
		pHead = pNewNode;
		return true;
	}
	for (int i = 1; i < Position; i++)
	{
		pTemp = pTemp->pNext;
	}
	pNewNode->pNext = pTemp->pNext;
	pNewNode->pPrevious = pTemp;
	pTemp->pNext = pNewNode;
	if (pNewNode->pNext)
		pNewNode->pNext->pPrevious = pNewNode;
	return true;
}

template<class T>
bool DoublyLinkedList<T>::DeleteAt(int Position)
{
	if (Position < 0 || Position > GetCount())
		return false;
	if (!pHead)
		return false;
	node<T>* pTemp = pHead;
	for (int i = 1; i < Position; i++)
	{
		pTemp = pTemp->pNext;
	}
	if (pTemp == pHead)
	{
		pTemp = pHead->pNext;
		delete pHead;
		pHead = pTemp;
		if(pHead)pHead->pPrevious = NULL;
		return true;
	}
	pTemp->pPrevious->pNext = pTemp->pNext;
	if (pTemp->pNext)
		pTemp->pNext->pPrevious = pTemp->pPrevious;
	delete pTemp;
	return true;
}

template<class T>
void DoublyLinkedList<T>::Reverse()
{
	if (!pHead || !pHead->pNext)
		return;
	node<T>* pTemp = pHead;
	while (pTemp)
	{
		node<T>* pNext = pTemp->pNext;
		pTemp->pNext = pTemp->pPrevious;
		pTemp->pPrevious = pNext;
		pTemp = pNext;
	}
	pTemp = pHead;
	pHead = pTail;
	pTail = pTemp;
}
