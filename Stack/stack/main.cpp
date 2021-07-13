// stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "StackADTusingArray.h"
#include "StackADTUsingLL.h"
#include "map"


int main()
{
    std::cout << "Hello World!\n";


    //string strpalindrome;
    //cout << "Enter a palindrome:- ";
    //cin >> strpalindrome;
    ////StackADTUsingArray<char> chStack((int)strpalindrome.length());
    //StackADTUsingLL<char>chStack;
    //cout << (chStack.IsEmpty() ? "stack is empty" : "Stack is full") << endl;
    //for (int i = 0; i < strpalindrome.length(); i++)
    //{
    //    chStack.Push(strpalindrome[i]);
    //}
    //chStack.Push('$');
    //cout << (chStack.IsEmpty() ? "stack is empty" : "Stack is full") << endl;
    //cout << chStack.Peek(4) << endl;
    //while (!chStack.IsEmpty())
    //{
    //    cout << chStack.Top();
    //    chStack.Pop();
    //}
    //cout << endl;
    //chStack.Pop();
    //cout << chStack.Top() << endl;
    //cout << (chStack.IsEmpty() ? "stack is empty" : "Stack is full") << endl;

    string strExpression;
    cout << "Enter an Expression:- ";
    cin >> strExpression;
    //StackADTUsingLL<char> CheckBalance;
    StackADTUsingArray<char> CheckBalance((int)strExpression.length());
    for (int i = 0; i < strExpression.length(); i++)
    {
        if (strExpression[i] == '(' || strExpression[i] == '{' || strExpression[i] == '[')
            CheckBalance.Push(strExpression[i]);
        else if (strExpression[i] == ')' || strExpression[i] == '}' || strExpression[i] == ']')
        {
            char ch = CheckBalance.Top();

            if (ch == (strExpression[i] - 1) || ch == (strExpression[i] - 2))
                CheckBalance.Pop();
            else
                CheckBalance.Push(strExpression[i]);
        }
    }
    if (CheckBalance.IsEmpty())
        cout << "Expression is Balanced" << endl;
    else
        cout << "Not A Balanced Expression" << endl;

    StackADTUsingLL<char> OperatorStack;
    map<char, int> OpertrOutSideStackPrecedenceMap;
    OpertrOutSideStackPrecedenceMap['+'] = 1;
    OpertrOutSideStackPrecedenceMap['-'] = 1;
    OpertrOutSideStackPrecedenceMap['*'] = 3;
    OpertrOutSideStackPrecedenceMap['/'] = 3;
    OpertrOutSideStackPrecedenceMap['^'] = 6;
    OpertrOutSideStackPrecedenceMap['('] = 7;
    OpertrOutSideStackPrecedenceMap[')'] = 0;

    map<char, int> OpertrInSideStackPrecedenceMap;
    OpertrInSideStackPrecedenceMap['+'] = 2;
    OpertrInSideStackPrecedenceMap['-'] = 2;
    OpertrInSideStackPrecedenceMap['*'] = 4;
    OpertrInSideStackPrecedenceMap['/'] = 4;
    OpertrInSideStackPrecedenceMap['^'] = 5;
    OpertrInSideStackPrecedenceMap['('] = 0;

    string strPostFixExp;
    for (int i = 0; i < strExpression.length(); i++)
    {
        if (strExpression[i] == '+' || strExpression[i] == '-' || strExpression[i] == '*' || strExpression[i] == '/' || 
            strExpression[i] == '^' || strExpression[i] == '(' || strExpression[i] == ')')
        {
            if (OperatorStack.IsEmpty())
                OperatorStack.Push(strExpression[i]);
            else
            {
                if (OpertrInSideStackPrecedenceMap[OperatorStack.Top()] < OpertrOutSideStackPrecedenceMap[strExpression[i]])
                    OperatorStack.Push(strExpression[i]);
                else
                {
                    while (!OperatorStack.IsEmpty() && OpertrInSideStackPrecedenceMap[OperatorStack.Top()] >= OpertrOutSideStackPrecedenceMap[strExpression[i]])
                    {
                        if (OpertrInSideStackPrecedenceMap[OperatorStack.Top()] == OpertrOutSideStackPrecedenceMap[strExpression[i]])
                        {
                            OperatorStack.Pop();
                        }
                        else
                        {
                            strPostFixExp += OperatorStack.Top();
                            OperatorStack.Pop();
                        }
                    }
                    if(strExpression[i] != ')')
                        OperatorStack.Push(strExpression[i]);
                }
            }
        }
        else
        {
            strPostFixExp += strExpression[i];
        }
    }
    while (!OperatorStack.IsEmpty())
    {
        strPostFixExp += OperatorStack.Top();
        OperatorStack.Pop();
    }

    cout << "Infix: - " << strExpression << endl;
    cout << "Postfix: - " << strPostFixExp << endl;

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
