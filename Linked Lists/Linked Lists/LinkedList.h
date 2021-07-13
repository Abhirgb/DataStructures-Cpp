#pragma once
#include "CommonIncludes.h"

template<class T>
class Node
{
public:
	Node() :data(T{}),pNext(NULL)
	{
	}

	Node(T Data, Node<T>* pTemp):data(Data),pNext(pTemp)
	{
	}

	~Node()
	{
		int i = 0;
	}

	T data;
	Node<T>* pNext;
};

template<typename T>
void RecusiveDisplay(Node<T>* pNode)
{
	if (!pNode)
		return;

	cout << pNode->data << " ";
	pNode = pNode->pNext;
	RecusiveDisplay(pNode);
}

template<typename T>
void RecursiveReverse(Node<T>* pNode)
{
	if (!pNode->pNext)
		return;
	Node<T>* pPrevious = pNode;
	pNode = pNode->pNext;
	RecursiveReverse(pNode);
	pNode->pNext = pPrevious;
}

template<class T>
class LinkedList
{
	Node<T>* pHead;
	Node<T>* pTail;
public:
	LinkedList();
	LinkedList(T* Node, int dataArrayLength);

	~LinkedList();

	void Insert(T data);

	Node<T>* GetHead();

	Node<T>* GetTail();

	//defining this to set tail so that list will be looped
	//and then use IsLoop() to determine it
	//only for testing purpose
	void SetTailNext(Node<T>* pNode);

	void Display();

	void rDisplay();

	int GetNodeCountInLL();

	int SumOfNodeValues();
	int RSumOfNodeValues();

	T GetMax();
	T RGetMax();

	T GetMin();
	T RGetMin();

	Node<T>* LinearSearch(T data);

	bool InsertAt(int index, T data);

	bool SortedInsert(T data);

	bool Delete(int position);

	void Reverse();
	void rReverse();

	void ConcatinateLL(LinkedList<T> &LL);

	void Merge(LinkedList<T>& First, LinkedList<T>& Second);

	bool IsLoop();
};

template<class T>
LinkedList<T>::LinkedList()
{
	pHead = NULL;
	pTail = NULL;
}

template<class T>
LinkedList<T>::LinkedList(T* data, int dataArrayLength)
{ 
	for (int i = 0; i < dataArrayLength; i++)
		Insert(data[i]);
}

template<class T>
LinkedList<T>::~LinkedList()
{
	Node<T>* pTemp = pHead;
	while (pTemp)
	{
		pHead = pTemp->pNext;
		delete pTemp;
		pTemp = pHead;
	}
	pTail = NULL;
}

template<class T>
void LinkedList<T>::Insert(T data)
{
	if (!pHead)
	{
		pHead = new Node<T>(data,NULL);
		pTail = pHead;
		return;
	}
	pTail->pNext = new Node<T>(data,NULL);
	pTail = pTail->pNext;
}

template<class T>
Node<T>* LinkedList<T>::GetHead()
{
	return pHead;
}

template<class T>
Node<T>* LinkedList<T>::GetTail()
{
	return pTail;
}

template<class T>
void LinkedList<T>::SetTailNext(Node<T>* pNode)
{
	pTail->pNext = pNode;
}

template<class T>
void LinkedList<T>::Display()
{
	Node<T>* pTemp = pHead;
	cout << "data in the list :- ";
	while (pTemp)
	{
		cout << pTemp->data << " ";
		pTemp = pTemp->pNext;
	}
	cout << endl;
}

template<class T>
void LinkedList<T>::rDisplay()
{
	if (!pHead)
		return;
	RecusiveDisplay(pHead);
	cout << endl;
}

template<class T>
int LinkedList<T>::GetNodeCountInLL()
{
	Node<T>* pTemp = pHead;
	int Count = 0;
	while (pTemp)
	{
		Count++;
		pTemp = pTemp->pNext;
	}
	return Count;
}

template<class T>
int LinkedList<T>::SumOfNodeValues()
{
	Node<T>* pTemp = pHead;
	int sum = 0;
	while (pTemp)
	{
		sum += pTemp->data;
		pTemp = pTemp->pNext;
	}
	return sum;
}

template<class T>
int LinkedList<T>::RSumOfNodeValues()
{
	static Node<T>* pTemp = pHead;
	if (!pTemp)
		return 0;
	int data = pTemp->data;
	pTemp = pTemp->pNext;
	return data + RSumOfNodeValues();
}

template<class T>
T LinkedList<T>::GetMax()
{
	T max = pHead->data;
	Node<T>* pTemp = pHead;
	while (pTemp)
	{
		if (pTemp->data > max)
			max = pTemp->data;
		pTemp = pTemp->pNext;
	}
	return max;
}

template<class T>
T LinkedList<T>::RGetMax()
{
	static Node<T>* pTemp = pHead;
	if (pTemp == pTail)
		return pTail->data;
	T data = pTemp->data;
	pTemp = pTemp->pNext;
	T max = RGetMax();
	return (data > max ? data : max);
}

template<class T>
T LinkedList<T>::GetMin()
{
	T min = pHead->data;
	Node<T>* pTemp = pHead;
	while (pTemp)
	{
		if (pTemp->data < min)
			min = pTemp->data;
		pTemp = pTemp->pNext;
	}
	return min;
}

template<class T>
T LinkedList<T>::RGetMin()
{
	static Node<T>* pTemp = pHead;
	if (pTemp == pTail)
		return pTail->data;
	T data = pTemp->data;
	pTemp = pTemp->pNext;
	T min = RGetMin();
	return (data < min ? data : min);
}

template<class T>
Node<T>* LinkedList<T>::LinearSearch(T data)
{
	Node<T>* pTemp = pHead;
	while (pTemp)
	{
		if (pTemp->data == data)
			return pTemp;
		pTemp = pTemp->pNext;
	}
	return NULL;
}

template<class T>
bool LinkedList<T>::InsertAt(int index, T data)
{
	if (index < 0)
		return false;
	Node<T>* pTemp = pHead;
	for (int i = 1; i < index; i++)
	{
		pTemp = pTemp->pNext;
		if (!pTemp)
			return false;
	}
	Node<T>* pNewNode = new Node<T>(data, NULL);
	if (!pNewNode)
		return false;
	if (index == 0)
	{
		pNewNode->pNext = pHead;
		pHead = pNewNode;
		if (!pHead->pNext)
			pTail = pHead;
		return true;
	}
	pNewNode->pNext = pTemp->pNext;
	pTemp->pNext = pNewNode;
	if (!pNewNode->pNext)
		pTail = pNewNode;
	return true;
}

template<class T>
bool LinkedList<T>::SortedInsert(T data)
{
	Node<T>* pNewNode = new Node<T>(data, NULL);
	if (!pHead)
	{
		pHead = pNewNode;
		pTail = pHead;
		return true;
	}
	else
	{
		Node<T>* pTemp = pHead;
		while (pTemp->pNext && data > pTemp->data && data > pTemp->pNext->data)
		{
			pTemp = pTemp->pNext;
		}
		if (pTemp == pHead && pTemp->data > data)
		{
			pNewNode->pNext = pHead;
			pHead = pNewNode;
			return true;
		}
		pNewNode->pNext = pTemp->pNext;
		pTemp->pNext = pNewNode;
		if (!pNewNode->pNext)
			pTail = pNewNode;
		return true;
	}
}

template <class T>
bool LinkedList<T>::Delete(int position)
{
	if (position < 1)
		return false;
	Node<T>* pCurrentNode = pHead;
	for (int i = 1; i < position - 1 && pCurrentNode; i++)
		pCurrentNode = pCurrentNode->pNext;
	if (pCurrentNode)
	{
		if (position == 1)
		{
			if (pCurrentNode == pTail)
				pTail = NULL;
			pHead = pCurrentNode->pNext;
			delete pCurrentNode;
			pCurrentNode = NULL;
			return true;
		}
		Node<T>* pNextNode = pCurrentNode->pNext;
		pCurrentNode->pNext = pNextNode->pNext;
		if (pTail == pNextNode)
			pTail = pCurrentNode;
		delete pNextNode;
		pNextNode = NULL;
		return true;
	}
	return false;
}

template <class T>
void LinkedList<T>::Reverse()
{
	Node<T>* PDupHead = NULL;
	Node<T>* pTemp = pHead;
	Node<T>* pDupTemp = NULL;
	while (pTemp)
	{
		if (!PDupHead)
		{
			PDupHead = pHead;
			pTail = pHead;
			pTemp = pTemp->pNext;
			PDupHead->pNext = NULL;
			continue;
		}
		pDupTemp = pTemp;
		pTemp = pTemp->pNext;
		pDupTemp->pNext = PDupHead;
		PDupHead = pDupTemp;
	}
	pHead = PDupHead;
}

template<class T>
void LinkedList<T>::rReverse()
{
	if (!pHead)
		return;
	RecursiveReverse(pHead);
	pHead->pNext = NULL;
	Node<T>* pTemp = pHead;
	pHead = pTail;
	pTail = pTemp;
}

template<class T>
void LinkedList<T>::ConcatinateLL(LinkedList<T> &LL)
{
	this->pTail->pNext = LL.GetHead();
	this->pTail = LL.GetTail();
	LL.pHead = NULL;
	LL.pTail = NULL;
}

template<class T>
void LinkedList<T>::Merge(LinkedList<T> &First, LinkedList<T> &Second)
{
	Node<T>* pFirst = First.GetHead();
	Node<T>* pSecond = Second.GetHead();
	Node<T>* pTemp = NULL;

	while (pFirst && pSecond)
	{
		if (pFirst->data <= pSecond->data)
		{
			if (!this->pHead)
			{
				this->pHead = pFirst;
				pTemp = this->pHead;
			}
			else
			{
				pTemp->pNext = pFirst;
				pTemp = pTemp->pNext;
			}
			pFirst = pFirst->pNext;
		}
		else
		{
			if (!this->pHead)
			{
				this->pHead = pSecond;
				pTemp = this->pHead;
			}
			else
			{
				pTemp->pNext = pSecond;
				pTemp = pTemp->pNext;
			}
			pSecond = pSecond->pNext;
		}
		pTemp->pNext = NULL;
	}
	if (pFirst)
	{
		pTemp->pNext = pFirst;
		this->pTail = First.pTail;
	}
	else if (pSecond)
	{
		pTemp->pNext = pSecond;
		this->pTail = Second.pTail;
	}
	else
	{
		this->pTail = pTemp;
	}
	pTail = pTemp;
	First.pHead = NULL;
	Second.pHead = NULL;
}

template<class T>
bool LinkedList<T>::IsLoop() 
{
	if (!pHead || !pHead->pNext)
		return false;

	Node<T>* P1 = NULL;
	Node<T>* P2 = pHead;
	if(pHead->pNext)
		P1 = pHead->pNext;
	
	while (P1 && P2 && P1 != P2)
	{
		P1 = (P1->pNext ? (P1->pNext->pNext ? P1->pNext->pNext : NULL) : NULL);
		P2 = (P2->pNext ? P2->pNext : NULL);
	}
	if (P1 == P2)
		return true;
	else
		return false;
}