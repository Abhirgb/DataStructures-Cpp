
#include "LinkedList.h"
#include "DoublyLinkedList.h"

int main()
{
    std::cout << "Hello World!\n";
    /*int A[] = { -3,-5,-2,7,-1,-15,0};
    LinkedList<int> List(A, 7);
    List.rDisplay();
    cout << endl;
    cout << "Total Nodes in the Linked List:- " << List.GetNodeCountInLL() << endl;
    cout << "Sum of Node Values in the Linked List:- " << List.RSumOfNodeValues() << endl;
    cout << "Max Node Value in the Linked List:- " << List.RGetMax() << endl;
    cout << "Min Node Value in the Linked List:- " << List.RGetMin() << endl;
    int key = 0;
    cout << "Node of " << key << " in the Linked List:- " << List.LinearSearch(key) << endl;
    key = 1;
    cout << "Node of " << key << " in the Linked List:- " << List.LinearSearch(key) << endl;
    List.Display();
    int pos = 7;
    int data = 200;
    List.InsertAt(pos, data);
    List.Display();
    pos = 1;
    data = 300;
    List.InsertAt(pos, data);
    List.Display();
    LinkedList<char>Listchar;
    Listchar.Insert('A');
    Listchar.Insert('B');
    Listchar.Insert('H');
    Listchar.Insert('I');
    Listchar.InsertAt(0, 'I');
    Listchar.InsertAt(0, 'A');
    Listchar.InsertAt(0, 'S');
    Listchar.Display();*/
    
    /*LinkedList<int> List3;
    List3.SortedInsert(10);
    List3.Display();
    List3.SortedInsert(5);
    List3.Display();
    List3.SortedInsert(20);
    List3.SortedInsert(30);
    List3.SortedInsert(70);
    List3.SortedInsert(-1);
    List3.SortedInsert(40);
    List3.SortedInsert(50);
    List3.SortedInsert(15);
    List3.SortedInsert(35);
    List3.SortedInsert(80);
    List3.SortedInsert(6);
    List3.SortedInsert(0);
    List3.Display();
    List3.Delete(1);
    List3.Display();
    List3.Delete(15);
    List3.Display();
    List3.Delete(3);
    List3.Delete(4);
    List3.Display();

    List3.rReverse();
    List3.Display();
    LinkedList<int> test;
    test.Display();
    test.SortedInsert(2021);
    test.Display();
    test.SortedInsert(2020);
    test.Display();
    test.rReverse();
    test.Display();
    test.ConcatinateLL(List3);
    test.Display();
    List3.Display();*/

    /*int A[] = {-10,20,30,40,50,60,70};
    LinkedList<int> List1(A, 7);
    int B[] = { -1,2,30,38,43,47,61};
    LinkedList<int> List2(B, 7);

    LinkedList<int> List3;
    List3.Merge(List1, List2);
    List3.Display();
    List1.Display();
    List2.Display();
    cout << "List3 is " << (List3.IsLoop() ? "a loop" : "Linear") << endl;
    List3.SetTailNext(List3.GetHead()->pNext);
    cout << "List3 is " << (List3.IsLoop() ? "a loop" : "Linear") << endl;
    List3.GetTail()->pNext = NULL;*/

    /*LinkedList<int> List4(A, 7);
    LinkedList<int> List5(B, 7);
    LinkedList<int> List6;
    List6.Merge(List5, List4);
    List6.Display();
    List4.Display();
    List5.Display();*/

    int A[] = { -10,20,30,40,50,60,70 };
    DoublyLinkedList<int> DLL(A, 7);
    DLL.Display();
    cout << "Size Of Doubly Linked List :- " << DLL.GetCount() << endl;
    DLL.InsertAt(0, -5);
    DLL.Display();
    DLL.InsertAt(8, 80);
    DLL.Display();
    DLL.InsertAt(2, 15);
    DLL.Display();
    cout << "Size Of Doubly Linked List :- " << DLL.GetCount() << endl;
    DLL.DeleteAt(1);
    DLL.Display();
    DLL.DeleteAt(9);
    DLL.Display();
    DLL.DeleteAt(2);
    DLL.Display();
    cout << "Size Of Doubly Linked List :- " << DLL.GetCount() << endl;
    DLL.Reverse();
    DLL.Display();
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
