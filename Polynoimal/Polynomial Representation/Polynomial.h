#pragma once

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

struct PolynomialTerm
{
	int iCoefficient;
	int iExpo;
};

class polynomial
{
	int iNumberOfTerms;
	vector<PolynomialTerm> PolynomialExpression;
public:

	polynomial();

	polynomial(int num);

	void Read();

	void Display();

	int operator()(int Xval);

	polynomial operator+(polynomial p2);

};