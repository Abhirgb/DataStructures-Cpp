#include "ArrayADT.h"

int main()
{
	ArrayADT<int> arrADT;
	int size;
	std::cout << "Enter the size of the array: ";
	std::cin >> size;
	std::cout << "\n";

	arrADT.SetSize(size);
	arrADT.CreateNewArray(size);
	int* CurrentArray{ NULL };
	CurrentArray = (int*)arrADT.GetArray();

	int iCount;
	std::cout << "Enter no of elements to be filled in the array: ";
	std::cin >> iCount;
	std::cout << "\n";

	std::cout << "Filling the Array...\n";
	arrADT.SetLength(iCount);
	for (int i = 0; i < iCount; i++)
	{
		std::cout << "Enter a value at index " << i << " in the array: ";
		std::cin >> CurrentArray[i];
	}
	std::cout << "\n";

	arrADT.Display();
	int iNum = 100;
	arrADT.Add(iNum);
	iNum = 101;
	arrADT.Insert(0, iNum);
	iNum = 101;
	arrADT.Insert(3, iNum);
	arrADT.Display();
	arrADT.Delete(2);
	arrADT.Display();
	arrADT.Delete(3);
	arrADT.Display();
	std::cout << "Size: " << arrADT.GetSize() << ", Length: " << arrADT.GetLength() << std::endl;
	std::cout << "index of 101 is: " << arrADT.FindFirstUsingLinearSearch(101) << std::endl;

	//arrADT.BubbleSort();
	int iValueToFind = 10;
	std::cout << "index " << iValueToFind << ": " << arrADT.BinarySearch(10) << std::endl;
	std::cout << "Ascending order, ";
	arrADT.Display();

	//arrADT.BubbleSort(false);
	std::cout << "index " << iValueToFind << ": " << arrADT.BinarySearch(10,false) << std::endl;
	std::cout << "decending order, ";
	arrADT.Display();

	std::cout << "element at 2: " << arrADT.Get(2) << " ,element at 11: " << arrADT.Get(11) << std::endl;

	std::cout << "set element at index 2 with 23: " << arrADT.Set(2,23) << ", set element at 11 with 11: " << arrADT.Set(11,11) << std::endl;
	arrADT.Display();

	std::cout << "Max: " << arrADT.Max() << " ,Min: " << arrADT.Min() << " ,Sum: " << arrADT.Sum() << " ,Average: " << arrADT.Average() << std::endl;
	std::cout << "Is array sorted: " << (arrADT.IsSorted(false) ? "YES" : "No") << std::endl;
	arrADT.Display();

	arrADT.Reverse();
	arrADT.Display();

	arrADT.LeftRotate();
	arrADT.Display();

	arrADT.RightRotate();
	arrADT.Display();

	arrADT.LeftShift();
	arrADT.Display();

	arrADT.RightShift();
	arrADT.Display();

	std::cout << "Is array sorted: " << (arrADT.IsSorted(false) ? "YES" : "No" )<< std::endl;

	ArrayADT<int> ArrTobeMerged;
	for (int i = 0; i < 5; i++)
	{
		ArrTobeMerged.Add(i);
	}
	arrADT.BubbleSort(true);
	arrADT.Merge(&ArrTobeMerged);
	arrADT.Display();

	return 0;
}
