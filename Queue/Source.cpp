// This file contains the 'main' function. Program execution begins and ends there.
//

#include "QueueADT.h"


int main()
{
    std::cout << "Hello World!\n";
    QueueADTUsingArray<int> QueueArray(7);
    QueueArray.enqueue(0);
    QueueArray.enqueue(1);
    QueueArray.enqueue(2);
    QueueArray.enqueue(3);
    QueueArray.enqueue(4);
    QueueArray.enqueue(5);
    QueueArray.enqueue(6);
    QueueArray.enqueue(7);
    QueueArray.dequeue();
    QueueArray.enqueue(7);
    //QueueArray.Display();
    while (!QueueArray.IsEmpty())
    {
        cout << QueueArray.front() << " ";
        QueueArray.dequeue();
    }
    cout << endl;

    QueueADTUsingLL<int> QueueLL;
    QueueLL.enqueue(0);
    QueueLL.enqueue(1);
    QueueLL.enqueue(2);
    QueueLL.enqueue(3);
    QueueLL.enqueue(4);
    QueueLL.enqueue(5);
    QueueLL.enqueue(6);
    QueueLL.enqueue(7);

    /*while (!QueueLL.IsEmpty())
    {
        cout << QueueLL.front() << " ";
        QueueLL.dequeue();
    }
    cout << endl;*/
    QueueLL.Display();

    QueueLL.dequeue();
    cout << endl;
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
