#pragma once
#include "StdIncludes.h"

//FYI below is a circular Queue for a quick and clean way to store data
template<class T>
class QueueADTUsingArray
{
	T* pQueue;
	int iFront;
	int iRear;
	int iSize;
public:
	QueueADTUsingArray();
	QueueADTUsingArray(int Size);
	~QueueADTUsingArray();

	void enqueue(T val);
	void dequeue();

	T front();
	T Rear();

	bool IsEmpty();
	bool IsFull();
	void Display();
};

template<class T>
QueueADTUsingArray<T>::QueueADTUsingArray()
{
	iSize = 10;
	pQueue = new T[iSize];
	iFront = -1;
	iRear = -1;
}

template<class T>
QueueADTUsingArray<T>::QueueADTUsingArray(int Size)
{
	iSize = Size;
	pQueue = new T[iSize];
	iFront = -1;
	iRear = -1;
}

template<class T>
QueueADTUsingArray<T>::~QueueADTUsingArray()
{
	delete pQueue;
}

template<class T>
void QueueADTUsingArray<T>::enqueue(T val)
{
	if (!IsFull())
	{
		if (iFront == -1 && iRear == -1)
			iFront++;
		iRear = (iRear + 1) % iSize;
		pQueue[iRear] = val;
	}
	else
		cout << "Queue is full" << endl;
}

template<class T>
void QueueADTUsingArray<T>::dequeue()
{
	if (!IsEmpty())
	{
		if (iFront == iRear) 
		{
			iFront = -1;
			iRear = -1;
			return;
		}
		iFront = (iFront + 1) % iSize;
	}
	else
		cout << "Queue is empty" << endl;
}

template<class T>
T QueueADTUsingArray<T>::front()
{
	if (!IsEmpty())
	{
		return pQueue[iFront];
	}
	return T{};
}

template<class T>
T QueueADTUsingArray<T>::Rear()
{
	if (!IsEmpty())
		return pQueue[iRear];
	return T();
}

template<class T>
bool QueueADTUsingArray<T>::IsEmpty()
{
	if (iFront == -1 && iRear == -1)
		return true;
	return false;
}

template<class T>
bool QueueADTUsingArray<T>::IsFull()
{
	if(((iRear+1)%iSize) == iFront)
		return true;
	return false;
}

template<class T>
void QueueADTUsingArray<T>::Display()
{
	int front = iFront;
	while (front != iRear)
	{
		cout << pQueue[front] << " ";
		front = ((front + 1) % iSize);
	}
	cout << pQueue[front] << endl;
}





//Below is the implementation of Queue using LinkedLists

template <class T>
class QueueADTUsingLL
{
	LinkedList<T> Queue;
	int iSize;
public:
	void enqueue(T val);
	void dequeue();

	T front();
	T Rear();

	bool IsEmpty();
	bool IsFull();
	void Display();
};

template<class T>
void QueueADTUsingLL<T>::enqueue(T val)
{
	Queue.Insert(val);
}

template<class T>
void QueueADTUsingLL<T>::dequeue()
{
	if (!IsEmpty())
		Queue.Delete(1);
	else
		cout << "Queue is empty" << endl;
}

template<class T>
T QueueADTUsingLL<T>::front()
{
	return Queue.GetHead()->data;
}

template<class T>
T QueueADTUsingLL<T>::Rear()
{
	return Queue.GetTail()->data;
}

template<class T>
bool QueueADTUsingLL<T>::IsEmpty()
{
	return Queue.GetHead() ? false : true;
}

template<class T>
bool QueueADTUsingLL<T>::IsFull()
{
	Node<T>* pTemp = new Node<T>();
	if (!pTemp)
		return true;
	delete pTemp;
	return false;
}

template<class T>
void QueueADTUsingLL<T>::Display()
{
	Queue.Display();
}
