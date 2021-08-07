// source.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"

int main()
{
    std::cout << "Hello World!\n";
    /*BinaryTree<int> intBT;
    intBT.CreateBinaryTree();

    intBT.PreOrderTraversalUsingRecursion();

    intBT.InOrderTraversalUsingRecursion();

    intBT.PostOrderTraversalUsingRecursion();

    intBT.LevelOrderTraversal();

    intBT.PreOrderTraversalIterative();

    intBT.InOrderTraversalIterative();

    intBT.PostOrderTraversalIterative();

    cout << "Height of the Binary Tree is : " << intBT.GetHeightRecursively() << endl;

    cout << "Total No of Node's in the Binary Tree: " << intBT.GetNodeCount() << endl;*/

    /*BinarySearchTree<int> BST;
    BST.CreateBSTRecursive();
    BST.InsertUsingRecursion(2400);
    BST.PreOrderTraversal();
    BST.InOrderTraversal();
    BST.PostOrderTraversal();

    if (BST.Search(2400))
        cout << "Found 2400" << endl;
    if (BST.Search(240))
        cout << "Found 240" << endl;
    else
        cout << "Not Found" << endl;*/

    /*BinarySearchTree<int> BST1;
    BST1.CreateBSTIterative();
    BST1.InsertUsingIteration(2400);
    BST1.PreOrderTraversal();
    BST1.InOrderTraversal();
    BST1.PostOrderTraversal();

    if (BST1.Search(2400))
        cout << "Found 2400" << endl;
    if (BST1.Search(240))
        cout << "Found 240" << endl;
    else
        cout << "Not Found" << endl;*/

    /*BST.Delete(50);
    BST.InOrderTraversal();*/

    /*BST1.Delete(2400);
    BST1.InOrderTraversal();*/

    CAVLTree<int> AVLTree;
   /* AVLTree.InsertUsingRecursion(40);
    AVLTree.InsertUsingRecursion(20);
    AVLTree.InsertUsingRecursion(50);
    AVLTree.InsertUsingRecursion(10);
    AVLTree.InsertUsingRecursion(30);
    AVLTree.InsertUsingRecursion(60);
    AVLTree.InsertUsingRecursion(5);
    AVLTree.InsertUsingRecursion(25);
    AVLTree.InsertUsingRecursion(36);
    AVLTree.InsertUsingRecursion(27);*/

    AVLTree.InsertUsingRecursion(10);
    AVLTree.InsertUsingRecursion(20);
    AVLTree.InsertUsingRecursion(30);
    AVLTree.InsertUsingRecursion(25);
    AVLTree.InsertUsingRecursion(28);
    AVLTree.InsertUsingRecursion(27);
    AVLTree.InsertUsingRecursion(5);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
