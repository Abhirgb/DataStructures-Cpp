#pragma once
#include "BinarySearchTree.h"

template<typename T>
class AVLTreeNode
{
public:

	AVLTreeNode<T>* pLeft;
	T data;
	AVLTreeNode<T>* pRight;
	int iHeight;
	AVLTreeNode()
	{
		pLeft = NULL;
		pRight = NULL;
		iHeight = 0;
	}
	AVLTreeNode(AVLTreeNode<T>* left, T val, AVLTreeNode<T>* right)
	{
		pLeft = left;
		data = val;
		pRight = right;
		iHeight = 0;
	}
};

template<typename T>
class CAVLTree
{
	AVLTreeNode<T>* pRoot;
	AVLTreeNode<T>* InsertUsingRecursion(AVLTreeNode<T>* pNode, T val);
public:
	CAVLTree();
	~CAVLTree();

	void InsertUsingRecursion(T val);

	int GetHeight(AVLTreeNode<T>* pNode);

	int BalanceFactor(AVLTreeNode<T>* pNode);

	AVLTreeNode<T>* LLRotation(AVLTreeNode<T>* pNode);
	AVLTreeNode<T>* RRRotation(AVLTreeNode<T>* pNode);
	AVLTreeNode<T>* LRRotation(AVLTreeNode<T>* pNode);
	AVLTreeNode<T>* RLRotation(AVLTreeNode<T>* pNode);
};

template<typename T>
AVLTreeNode<T>* CAVLTree<T>::InsertUsingRecursion(AVLTreeNode<T>* pNode, T val)
{
	if (NULL == pNode)
	{
		pNode = new AVLTreeNode<T>(NULL, val, NULL);
		return pNode;
	}
	if (val < pNode->data)
		pNode->pLeft = InsertUsingRecursion(pNode->pLeft, val);
	else
		pNode->pRight = InsertUsingRecursion(pNode->pRight, val);

	pNode->iHeight = GetHeight(pNode);

	int iBF = BalanceFactor(pNode);
	if (iBF == 2)
	{
		int iBFLeft = BalanceFactor(pNode->pLeft);
		if (iBFLeft == 1)
			return RRRotation(pNode);
		else
			return LRRotation(pNode);
	}
	else if (iBF == -2)
	{
		int iBFRight = BalanceFactor(pNode->pRight);
		if (iBFRight == -1)
			return LLRotation(pNode);
		else
			return RLRotation(pNode);
	}
	return pNode;
}

template<typename T>
CAVLTree<T>::CAVLTree()
{
	pRoot = NULL;
}

template<typename T>
CAVLTree<T>::~CAVLTree()
{
}

template<typename T>
void CAVLTree<T>::InsertUsingRecursion(T val)
{
	if (!pRoot)
		pRoot = InsertUsingRecursion(pRoot, val);
	else
		InsertUsingRecursion(pRoot, val);
}

template<typename T>
int CAVLTree<T>::GetHeight(AVLTreeNode<T>* pNode)
{
	if (!pNode)
		return 0;
	if (!pNode->pLeft && !pNode->pRight)
		return 0;

	int iLHeight = (pNode->pLeft) ? pNode->pLeft->iHeight : 0;
	int iRHeight = (pNode->pRight) ? pNode->pRight->iHeight : 0;

	if (iLHeight > iRHeight)
		return iLHeight+1;
	return iRHeight+1;
}

template<typename T>
int CAVLTree<T>::BalanceFactor(AVLTreeNode<T>* pNode)
{
	int iLHeight = (pNode && pNode->pLeft) ? pNode->pLeft->iHeight+1 : 0;
	int iRHeight = (pNode && pNode->pRight) ? pNode->pRight->iHeight+1 : 0;

	return iLHeight - iRHeight;
}

template<typename T>
AVLTreeNode<T>* CAVLTree<T>::LLRotation(AVLTreeNode<T>* pNode)
{
	AVLTreeNode<T>* pRightNode = pNode->pRight;

	pNode->pRight = pRightNode->pLeft;
	pRightNode->pLeft = pNode;

	pNode->iHeight = GetHeight(pNode);
	pRightNode->iHeight = GetHeight(pRightNode);

	if (pNode == pRoot)
		pRoot = pRightNode;

	return pRightNode;
}

template<typename T>
AVLTreeNode<T>* CAVLTree<T>::RRRotation(AVLTreeNode<T>* pNode)
{
	AVLTreeNode<T>*  pLeftNode = pNode->pLeft;
	AVLTreeNode<T>* pLeftNodeRight = pLeftNode->pRight;

	pLeftNode->pRight = pNode;
	pNode->pLeft = pLeftNodeRight;

	pNode->iHeight = GetHeight(pNode);
	pLeftNode->iHeight = GetHeight(pLeftNode);
	
	if (pRoot == pNode)
		pRoot = pLeftNode;

	return pLeftNode;
}

template<typename T>
AVLTreeNode<T>* CAVLTree<T>::LRRotation(AVLTreeNode<T>* pNode)
{
	AVLTreeNode<T>* pLeftNode = pNode->pLeft;
	AVLTreeNode<T>* pLeftNodeRight = pLeftNode->pRight;

	pLeftNode->pRight = pLeftNodeRight->pLeft;
	pNode->pLeft = pLeftNodeRight->pRight;
	pLeftNodeRight->pLeft = pLeftNode;
	pLeftNodeRight->pRight = pNode;

	pNode->iHeight = GetHeight(pNode);
	pLeftNode->iHeight = GetHeight(pLeftNode);
	pLeftNodeRight->iHeight = GetHeight(pLeftNodeRight);

	if (pNode == pRoot)
		pRoot = pLeftNodeRight;

	return pLeftNodeRight;
}

template<typename T>
AVLTreeNode<T>* CAVLTree<T>::RLRotation(AVLTreeNode<T>* pNode)
{
	AVLTreeNode<T>* pRightNode = pNode->pRight;
	AVLTreeNode<T>* pRightNodeLeft = pRightNode->pLeft;

	pRightNode->pLeft = pRightNodeLeft->pRight;
	pNode->pRight = pRightNodeLeft->pLeft;
	pRightNodeLeft->pLeft = pNode;
	pRightNodeLeft->pRight = pRightNode;

	pNode->iHeight = GetHeight(pNode);
	pRightNode->iHeight = GetHeight(pRightNode);
	pRightNodeLeft->iHeight = GetHeight(pRightNodeLeft);

	if (pNode == pRoot)
		pRoot = pRightNodeLeft;

	return pRightNodeLeft;
}
