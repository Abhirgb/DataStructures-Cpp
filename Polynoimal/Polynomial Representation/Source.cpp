// PolynomialExpression Representation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Polynomial.h"

int main()
{
    std::cout << "Hello World!\n";
    polynomial p1(5);
    p1.Read();
    p1.Display();

    polynomial p2(4);
    p2.Read();
    p2.Display();

    polynomial p = p1 + p2;
    p.Display();

    cout << "Value of polynomial with x=2: " << p1(2) << endl;
    cout << "Value of polynomial with x=2: " << p2(2) << endl;
    cout << "Value of polynomial with x=2: " << p(2) << endl;
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
