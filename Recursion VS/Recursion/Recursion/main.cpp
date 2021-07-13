#include "iostream"
#include <algorithm>
#include <vector>

using namespace std;

int sum = 0;
//Using a global variable in recursion
void FindSum(int n)
{
	if (n != 0)
	{
		FindSum(n - 1);
		sum = sum + n;
	}
}

// Finding sum using static varible in recursion
int FindSumUsingStaicVariable(int n)
{
	static int iSum = 0;
	if (n != 0)
	{
		iSum += n;
		FindSumUsingStaicVariable(n - 1);
	}
	return iSum;
}

int FindSumInOneStep(int n)
{
	if (n != 0)
	{
		return FindSumInOneStep(n - 1) + n;
	}
	return 0;
}

void PrintnNumbers(int n)
{
	if (n > 0)
	{
		cout << n << endl;
		PrintnNumbers(n - 1);
		////Tree Recursion Example
		//PrintnNumbers(n - 1);
	}
}

void IndirectRecursion2(int n);

void IndirectRecursion1(int n)
{
	if (n > 0)
	{
		cout << n << " ";
		IndirectRecursion2(n*2);
	}
}

void IndirectRecursion2(int n)
{
	if (n > 0)
	{
		IndirectRecursion1(n / 4);
		cout << n << " ";
	}
}

//Example of a Nested Recursion
int NestedRecursion(int n)
{
	if (n > 110)
		return n - 10;
	return NestedRecursion(NestedRecursion(n + 12));
}

//Factorial of a number using recursion

unsigned long long int Factorial(int n)
{
	if (n >= 0)
	{
		if (n == 0)
			return 1;
		else
			return Factorial(n - 1) * n;

		//if (n != 0)
		//{
		//	return Factorial(n - 1)*n;
		//}
		//return 1;
	}
	else
	{
		cout << "enter a non negative number" << endl;
		return 0;
	}
	
}

//power of a number using recursion
int pow(int m, int n)
{
	if (n != 0)
		return pow(m, n - 1) * m;
	return 1;
}
//int pow(int m, int n)
//{
//	if (n == 0)
//		return 1;
//	if (n % 2 == 0)
//		return pow(m*m, n / 2);
//	else
//		return pow(m*m, (n - 1)/2) * m;
//}

double e(int x, int n)
{
	if (n == 0)
		return 1;
	static double p = 1;
	static double f = 1;
	double r;
	r = e(x, n - 1);
	p = p * x;
	f = f * n;
	return r + (p / f);

	/*return e(x, n - 1) + (double)((pow(x,n)/Factorial(n)));*/
}

double expo(int x, int n)
{
	static double iNum = 1;
	if (n == 0)
		return iNum;
	iNum = 1 + ((x / n) * iNum);
	return expo(x, n - 1);
}

int F[1000] = {-1} ;
int fib(int n) //Oreder(2 power n) approx excesive recursion
{
	if (n <= 1)
	{
		F[n] = n;
		return n;
	}
	else
	{
		if (F[n - 2] == -1)
			fib(n - 2);
		if (F[n - 1] == -1)
			fib(n - 1);
		return fib(n - 2) + fib(n - 1);
	}
	//return fib(n - 2) + fib(n - 1);
}

int fibonacci(int n)
{
	static long long int t0 = 0;
	static long long int t1 = 0;
	static long long int fibnum = 0;
	if (n <= 1)
		return n;
	
	long long int i = fibonacci(n - 1);
	t0 = t1;
	t1 = i;
	fibnum = t0 + t1;
	return fibnum;
}

int main()
{
	/*int n = 0;
	cout << "Enter the value of n:" << endl;
	cin >> n;

	FindSum(n);
	cout << "Sum of first "<< n << " numbers: "<< sum << endl;

	cout << "Sum of first " << n << " numbers: " << FindSumInOneStep(n) << endl;

	cout << "Sum of first " << n << " numbers: " << FindSumUsingStaicVariable(n) << endl;

	cout << "List of " << n << " numbers: " << endl;
	PrintnNumbers(n);

	cout << "********************************************************" << endl;
	IndirectRecursion1(20);
	cout << " " << endl;

	cout << NestedRecursion(100) << endl;

	int m = 0;
	cout << "Enter a number to get factorial: ";
	cin >> m;
	cout << "Factorial of " << m << " : " << Factorial(m) << endl;

	int x = 0;
	int y = 0;
	cout << "Enter a base number: ";
	cin >> x;
	cout << "Enter a base power: ";
	cin >> y;
	cout << pow(x, y) << endl;*/


	/*int iPower;
	cout << "Enter the highest degree: ";
	cin >> iPower;
	cout << "Enter the number: ";
	int iNumber;
	cin >> iNumber;
	double dVal = e(iNumber, iPower);
	cout << dVal<<endl;*/

	unsigned long long int iNum;
	cout << "Enter the required Fib number: ";
	cin >> iNum;
	cout << "fib(" << iNum << "): " << fib(iNum) << endl;
	return 0;
}