#pragma once
#include "StdIncludes.h"

template<class T>
class BinaryTreeNode 
{
public:
	BinaryTreeNode<T>* pLeft;
	T data;
	BinaryTreeNode<T>* pRight;
	BinaryTreeNode() 
	{
		pLeft = NULL;
		pRight = NULL;
	}
	BinaryTreeNode(BinaryTreeNode<T>* left, T val, BinaryTreeNode<T>* right)
	{
		pLeft = left;
		data = val;
		pRight = right;
	}
};

template<class T>
class BinaryTree
{
private:
	BinaryTreeNode<T>* pRoot;

	void PreOrderTraversalUsingRecursion(BinaryTreeNode<T>* pBTNode);

	void InOrderTraversalUsingRecursion(BinaryTreeNode<T>* pBTNode);

	void PostOrderTraversalUsingRecursion(BinaryTreeNode<T>* pBTNode);

	int GetHeightRecursively(BinaryTreeNode<T>* pBTNode);

public:
	BinaryTree();
	~BinaryTree();

	void CreateBinaryTree();

	BinaryTreeNode<T>* GetRoot();

	//Only to use for BST
	void SetRoot(BinaryTreeNode<T>* root);

	void PreOrderTraversalUsingRecursion();

	void InOrderTraversalUsingRecursion();

	void PostOrderTraversalUsingRecursion();

	void LevelOrderTraversal();

	int GetNodeCount();

	int GetHeightRecursively();

	void PreOrderTraversalIterative();

	void InOrderTraversalIterative();

	void PostOrderTraversalIterative();
};

template<class T>
void BinaryTree<T>::PreOrderTraversalUsingRecursion(BinaryTreeNode<T>* pBTNode)
{
	if (!pBTNode)
		return;
	cout << pBTNode->data << " ";
	PreOrderTraversalUsingRecursion(pBTNode->pLeft);
	PreOrderTraversalUsingRecursion(pBTNode->pRight);
}

template<class T>
void BinaryTree<T>::InOrderTraversalUsingRecursion(BinaryTreeNode<T>* pBTNode)
{
	if (!pBTNode)
		return;
	InOrderTraversalUsingRecursion(pBTNode->pLeft);
	cout << pBTNode->data << " ";
	InOrderTraversalUsingRecursion(pBTNode->pRight);
}

template<class T>
void BinaryTree<T>::PostOrderTraversalUsingRecursion(BinaryTreeNode<T>* pBTNode)
{
	if (!pBTNode)
		return;
	PostOrderTraversalUsingRecursion(pBTNode->pLeft);
	PostOrderTraversalUsingRecursion(pBTNode->pRight);
	cout << pBTNode->data << " ";
}

template<class T>
int BinaryTree<T>::GetHeightRecursively(BinaryTreeNode<T>* pBTNode)
{
	if (!pBTNode)
		return -1;
	int iHeightOfLeftSubTree = GetHeightRecursively(pBTNode->pLeft);
	int iHeightOfRightSubTree = GetHeightRecursively(pBTNode->pRight);
	if (iHeightOfLeftSubTree >= iHeightOfRightSubTree)
		return iHeightOfLeftSubTree + 1;
	else
		return iHeightOfRightSubTree + 1;
}

template<class T>
BinaryTree<T>::BinaryTree()
{
	pRoot = NULL;
}

template<class T>
BinaryTree<T>::~BinaryTree()
{

}

template<class T>
void BinaryTree<T>::CreateBinaryTree()
{
	QueueADTUsingLL<BinaryTreeNode<T>*> BTNodePtrQueue;
	T val;
	cout << "Enter the root value: ";
	cin >> val;
	BinaryTreeNode<T>* pCurrentNode = new BinaryTreeNode<T>(NULL, val, NULL);
	pRoot = pCurrentNode;
	BTNodePtrQueue.enqueue(pCurrentNode);
	pCurrentNode = NULL;
	char ch;
	while (!BTNodePtrQueue.IsEmpty())
	{
		pCurrentNode = BTNodePtrQueue.front();
		BTNodePtrQueue.dequeue();
		cout << "Is Left Child of " << pCurrentNode->data << " Present ? (Y/y): ";
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "Enter the Left Child of " << pCurrentNode->data <<" : ";
			cin >> val;
			pCurrentNode->pLeft = new BinaryTreeNode<T>(NULL, val, NULL);
			BTNodePtrQueue.enqueue(pCurrentNode->pLeft);
		}
		cout << "Is Right Child of " << pCurrentNode->data << " Present ? (Y/y): ";
		cin >> ch;
		if (ch == 'Y' || ch == 'y')
		{
			cout << "Enter the Right Child of " << pCurrentNode->data << " : ";
			cin >> val;
			pCurrentNode->pRight = new BinaryTreeNode<T>(NULL, val, NULL);
			BTNodePtrQueue.enqueue(pCurrentNode->pRight);
		}
	}
	cout << endl;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::GetRoot()
{
	return pRoot;
}

template<class T>
void BinaryTree<T>::SetRoot(BinaryTreeNode<T>* root)
{
	pRoot = root;
}

template<class T>
void BinaryTree<T>::PreOrderTraversalUsingRecursion()
{
	cout << "Pre-Order Traversal Using Recursion: ";
	PreOrderTraversalUsingRecursion(pRoot);
	cout << endl;
}

template<class T>
void BinaryTree<T>::InOrderTraversalUsingRecursion()
{
	cout << "In-Order Traversal Using Recursion: ";
	InOrderTraversalUsingRecursion(pRoot);
	cout << endl;
}

template<class T>
void BinaryTree<T>::PostOrderTraversalUsingRecursion()
{
	cout << "Post-Order Traversal Using Recursion: ";
	PostOrderTraversalUsingRecursion(pRoot);
	cout << endl;
}

template<class T>
void BinaryTree<T>::LevelOrderTraversal()
{
	QueueADTUsingLL<BinaryTreeNode<T>*> BTNodePtrQueue;
	BTNodePtrQueue.enqueue(pRoot);
	BinaryTreeNode<T>* pTemp = NULL;
	cout << "Level-Order Traversal: ";
	while (!BTNodePtrQueue.IsEmpty())
	{
		pTemp = BTNodePtrQueue.front();
		if (pTemp->pLeft)
			BTNodePtrQueue.enqueue(pTemp->pLeft);
		if(pTemp->pRight)
			BTNodePtrQueue.enqueue(pTemp->pRight);
		cout << pTemp->data << " ";
		BTNodePtrQueue.dequeue();
	}
	cout << endl;
}

template<class T>
int BinaryTree<T>::GetNodeCount()
{
	StackADTUsingLL<BinaryTreeNode<T>*> BTNodePtrStack;
	BinaryTreeNode<T>* pBTNode = pRoot;
	int iNodeCount = 0;
	while (pBTNode || !BTNodePtrStack.IsEmpty())
	{
		if (pBTNode)
		{
			//Getting Node Count Using PreOrder Traversal Method
			//iNodeCount++;
			BTNodePtrStack.Push(pBTNode);
			pBTNode = pBTNode->pLeft;
		}
		else
		{
			//pBTNode = BTNodePtrStack.Top();
			//BTNodePtrStack.Pop();
			////Getting Node Count Using InOrder Traversal Method
			////iNodeCount++;
			//pBTNode = pBTNode->pRight;

			//Getting Node Count Using PostOrder Traversal Method
			BinaryTreeNode<T>* pTempNode = (BTNodePtrStack.Top())->pRight;
			if (!pTempNode)
			{
				pTempNode = BTNodePtrStack.Top();
				BTNodePtrStack.Pop();
				iNodeCount++;
				while (!BTNodePtrStack.IsEmpty() && (BTNodePtrStack.Top())->pRight == pTempNode)
				{
					pTempNode = BTNodePtrStack.Top();
					BTNodePtrStack.Pop();
					iNodeCount++;
				}
			}
			else
			{
				pBTNode = pTempNode;
			}
		}
	}
	return iNodeCount;
}

template<class T>
int BinaryTree<T>::GetHeightRecursively()
{
	return GetHeightRecursively(pRoot);
}

template<class T>
void BinaryTree<T>::PreOrderTraversalIterative()
{
	StackADTUsingLL<BinaryTreeNode<T>*> BTNodePtrStack;
	BinaryTreeNode<T>* pBTNode = pRoot;
	cout << "Pre-Order Traversal Iterative: ";
	while (pBTNode || !BTNodePtrStack.IsEmpty())
	{
		if (pBTNode)
		{
			cout << pBTNode->data << " ";
			BTNodePtrStack.Push(pBTNode);
			pBTNode = pBTNode->pLeft;
		}
		else
		{
			pBTNode = BTNodePtrStack.Top();
			BTNodePtrStack.Pop();
			pBTNode = pBTNode->pRight;
		}
	}
	cout << endl;
}

template<class T>
void BinaryTree<T>::InOrderTraversalIterative()
{
	StackADTUsingLL<BinaryTreeNode<T>*> BTNodePtrStack;
	BinaryTreeNode<T>* pBTNode = pRoot;
	cout << "In-Order Traversal Iterative: ";
	while (pBTNode || !BTNodePtrStack.IsEmpty())
	{
		if (pBTNode)
		{
			BTNodePtrStack.Push(pBTNode);
			pBTNode = pBTNode->pLeft;
		}
		else
		{
			pBTNode = BTNodePtrStack.Top();
			BTNodePtrStack.Pop();
			cout << pBTNode->data << " ";
			pBTNode = pBTNode->pRight;
		}
	}
	cout << endl;
}

template<class T>
void BinaryTree<T>::PostOrderTraversalIterative()
{
	StackADTUsingLL<BinaryTreeNode<T>*> BTNodePtrStack;
	BinaryTreeNode<T>* pBTNode = pRoot;
	cout << "Post-Order Traversal Iterative: ";
	while (pBTNode || !BTNodePtrStack.IsEmpty()) {
		if (pBTNode) 
		{
			BTNodePtrStack.Push(pBTNode);
			pBTNode = pBTNode->pLeft;
		}
		else
		{
			BinaryTreeNode<T>* pTemp = BTNodePtrStack.Top();
			if (!pTemp->pRight)
			{
				cout << pTemp->data << " ";
				BTNodePtrStack.Pop();
				while (!BTNodePtrStack.IsEmpty() && (BTNodePtrStack.Top())->pRight == pTemp)
				{
					pTemp = BTNodePtrStack.Top();
					BTNodePtrStack.Pop();
					cout << pTemp->data << " ";
				}
			}
			else
			{
				pBTNode = pTemp->pRight;
			}
		}
	}
	cout << endl;
}
