#include "Polynomial.h"

polynomial::polynomial() :iNumberOfTerms(0), PolynomialExpression({})
{
}

polynomial::polynomial(int num):iNumberOfTerms(num)
{
}

void polynomial::Read()
{
	cout << "Enter the Coefficient, Exponent for all " << iNumberOfTerms << "to store the polynomial." << endl;
	for (int i = 0; i < iNumberOfTerms; i++)
	{
		cout << "term no: " << i + 1 << endl;
		PolynomialTerm PolyTerm;
		cin >> PolyTerm.iCoefficient >> PolyTerm.iExpo;
		PolynomialExpression.push_back(PolyTerm);
	}
}

void polynomial::Display()
{
	for (int i = 0; i < PolynomialExpression.size(); i++)
	{
		cout << PolynomialExpression[i].iCoefficient << "x" << PolynomialExpression[i].iExpo << "+";
	}
	cout << "\n" << endl;
}

int polynomial::operator()(int Xval)
{
	int Val = 0;
	for (int i = 0; i < PolynomialExpression.size(); i++)
	{
		Val += (PolynomialExpression[i].iCoefficient * (int)pow(Xval, PolynomialExpression[i].iExpo));
	}
	return Val;
}

polynomial polynomial::operator+(polynomial p2)
{
	polynomial p;
	int i = 0;
	int j = 0;
	while (i < this->PolynomialExpression.size() && j < p2.PolynomialExpression.size())
	{
		if (this->PolynomialExpression[i].iExpo > p2.PolynomialExpression[j].iExpo)
			p.PolynomialExpression.push_back(this->PolynomialExpression[i++]);
		else if (this->PolynomialExpression[i].iExpo < p2.PolynomialExpression[j].iExpo)
			p.PolynomialExpression.push_back(p2.PolynomialExpression[j++]);
		else
			p.PolynomialExpression.push_back({ (this->PolynomialExpression[i++].iCoefficient + p2.PolynomialExpression[j].iCoefficient),p2.PolynomialExpression[j++].iExpo });
	}
	while (i < this->PolynomialExpression.size())
		p.PolynomialExpression.push_back(this->PolynomialExpression[i++]);
	while (j < p2.PolynomialExpression.size())
		p.PolynomialExpression.push_back(p2.PolynomialExpression[j++]);
	
	return p;
}
