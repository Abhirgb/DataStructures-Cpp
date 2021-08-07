#pragma once
#include "StdIncludes.h"
#include "BinaryTree.h"

template<typename T>
class BinarySearchTree
{
	BinaryTree<T> BTree;
	BinaryTreeNode<T>* rDelete(BinaryTreeNode<T>* pBSTNode, const T& val);
	BinaryTreeNode<T>* InsertUsingRecursion(BinaryTreeNode<T>* pBSTNode, const T& val);
public:
	BinarySearchTree();
	~BinarySearchTree();

	void CreateBSTRecursive();

	void CreateBSTIterative();

	void InsertUsingRecursion(const T& val);

	void InsertUsingIteration(const T& val);

	void PreOrderTraversal();
	
	void InOrderTraversal();

	void PostOrderTraversal();

	BinaryTreeNode<T>* Search(const T& val);

	bool Delete(T val);

	BinaryTreeNode<T>* DeleteUsingRecursion(const T& val);
};

template<typename T>
BinaryTreeNode<T>* BinarySearchTree<T>::rDelete(BinaryTreeNode<T>* pBSTNode, const T& val)
{
	if (!pBSTNode)
		return NULL;
	if (!pBSTNode->pLeft && !pBSTNode->pRight)
	{
		//if the value we are searching to delete is not present in the BST 
		//it should not return NULL instead return the leaf node only
		//so that tree's leaf node won't be altered 
		if (pBSTNode->data != val)
			return pBSTNode;

		if (BTree.GetRoot() == pBSTNode)
			BTree.SetRoot(NULL);
		delete pBSTNode;
		return NULL;
	}
	if (val < pBSTNode->data)
		pBSTNode->pLeft = rDelete(pBSTNode->pLeft, val);
	else if (val > pBSTNode->data)
		pBSTNode->pRight = rDelete(pBSTNode->pRight, val);
	else
	{
		BinaryTreeNode<T>* pTemp = pBSTNode;
		if (pTemp->pLeft)
		{
			pTemp = pTemp->pLeft;
			while (pTemp->pRight)
				pTemp = pTemp->pRight;
			pBSTNode->data = pTemp->data;
			pBSTNode->pLeft = rDelete(pBSTNode->pLeft, pTemp->data);
		}
		else
		{
			pTemp = pTemp->pRight;
			while (pTemp->pLeft)
				pTemp = pTemp->pLeft;
			pBSTNode->data = pTemp->data;
			pBSTNode->pRight = rDelete(pBSTNode->pRight, pTemp->data);
		}
	}
	return pBSTNode;
}

template<typename T>
BinaryTreeNode<T>* BinarySearchTree<T>::InsertUsingRecursion(BinaryTreeNode<T>* pBSTNode, const T& val)
{
	if (NULL == pBSTNode)
	{
		pBSTNode = new BinaryTreeNode<T>(NULL, val, NULL);
		return pBSTNode;
	}
	if (val < pBSTNode->data)
		pBSTNode->pLeft = InsertUsingRecursion(pBSTNode->pLeft, val);
	else
		pBSTNode->pRight = InsertUsingRecursion(pBSTNode->pRight, val);
	return pBSTNode;
}

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{

}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree()
{

}

template<typename T>
void BinarySearchTree<T>::CreateBSTRecursive()
{
	cout << "Enter the BST Root value: ";
	T val;
	cin >> val;
	BinaryTreeNode<T>* pRoot = BTree.GetRoot();
	pRoot = new BinaryTreeNode<T>(NULL, val, NULL);
	BTree.SetRoot(pRoot);
	cout << "Does the BST end here?(Y/y - N/n) : ";
	char ch;
	cin >> ch;
	while (ch == 'n' || ch == 'N')
	{
		cout << "Enter the BSTNode value: ";
		cin >> val;
		InsertUsingRecursion(pRoot, val);
		cout << "Does the BST end here(Y/y - N/n) ? : ";
		cin >> ch;
	}
}

template<typename T>
void BinarySearchTree<T>::CreateBSTIterative()
{
	cout << "Enter the BST Root value: ";
	T val;
	cin >> val;
	BinaryTreeNode<T>* pRoot = new BinaryTreeNode<T>(NULL, val, NULL);
	BTree.SetRoot(pRoot);
	cout << "Does the BST end here?(Y/y - N/n) : ";
	char ch;
	cin >> ch;
	while (ch == 'n' || ch == 'N')
	{
		cout << "Enter the BSTNode value: ";
		cin >> val;
		InsertUsingIteration(val);
		cout << "Does the BST end here(Y/y - N/n) ? : ";
		cin >> ch;
	}
}

template<typename T>
void BinarySearchTree<T>::InsertUsingRecursion(const T& val)
{
	BinaryTreeNode<T>* pRoot = BTree.GetRoot();
	if(!pRoot)
		BTree.SetRoot(InsertUsingRecursion(pRoot, val));
	else
	{
		InsertUsingRecursion(pRoot, val);
	}
}

template<typename T>
void BinarySearchTree<T>::InsertUsingIteration(const T& val)
{
	BinaryTreeNode<T>* pRoot = BTree.GetRoot();
	if (!pRoot)
		pRoot = new BinaryTreeNode<T>(NULL, val, NULL);
	else
	{
		BinaryTreeNode<T>* pTrailingNode = NULL;
		while (pRoot)
		{
			pTrailingNode = pRoot;
			if (val == pRoot->data)
				return;
			if (val < pRoot->data)
				pRoot = pRoot->pLeft;
			else
				pRoot = pRoot->pRight;
		}
		if (val < pTrailingNode->data)
			pTrailingNode->pLeft = new BinaryTreeNode<T>(NULL, val, NULL);
		else
			pTrailingNode->pRight = new BinaryTreeNode<T>(NULL, val, NULL);
	}
}

template<typename T>
void BinarySearchTree<T>::PreOrderTraversal()
{
	BTree.PreOrderTraversalIterative();
}

template<typename T>
void BinarySearchTree<T>::InOrderTraversal()
{
	BTree.InOrderTraversalIterative();
}

template<typename T>
void BinarySearchTree<T>::PostOrderTraversal()
{
	BTree.PostOrderTraversalIterative();
}

template<typename T>
BinaryTreeNode<T>* BinarySearchTree<T>::Search(const T& val)
{
	BinaryTreeNode<T>* pRoot = BTree.GetRoot();
	while (pRoot)
	{
		if (val == pRoot->data)
			return pRoot;
		else if (val < pRoot->data)
			pRoot = pRoot->pLeft;
		else
			pRoot = pRoot->pRight;
	}
	return NULL;
}

template<typename T>
bool BinarySearchTree<T>::Delete(T val)
{
	BinaryTreeNode<T>* pNode = BTree.GetRoot();
	BinaryTreeNode<T>* pTrailingNode = NULL;
	while (pNode)
	{
		if (val < pNode->data)
		{
			pTrailingNode = pNode;
			pNode = pNode->pLeft;
		}
		else if (val > pNode->data)
		{
			pTrailingNode = pNode;
			pNode = pNode->pRight;
		}
		else
			break;
	}
	while(pNode)
	{
		if (pNode->pRight)
		{
			pTrailingNode = pNode;
			BinaryTreeNode<T>* pTemp = pNode->pRight;
			while (pTemp->pLeft)
			{
				pTrailingNode = pTemp;
				pTemp = pTemp->pLeft;
			}
			pNode->data = pTemp->data;
			pNode = pTemp;
		}
		else if (pNode->pLeft)
		{
			pTrailingNode = pNode;
			BinaryTreeNode<T>* pTemp = pNode->pLeft;
			while (pTemp->pRight)
			{
				pTrailingNode = pTemp;
				pTemp = pTemp->pRight;
			}
			pNode->data = pTemp->data;
			pNode = pTemp;
		}
		else
		{
			if (BTree.GetRoot() == pNode)
				BTree.SetRoot(NULL);
			else
			{
				if (pTrailingNode->pLeft == pNode)
					pTrailingNode->pLeft = NULL;
				else
					pTrailingNode->pRight = NULL;
			}
			delete pNode;
			pNode = NULL;
			return true;
		}
	}
	return false;
}

template<typename T>
BinaryTreeNode<T>* BinarySearchTree<T>::DeleteUsingRecursion(const T& val)
{
	return rDelete(BTree.GetRoot(), val);
}
