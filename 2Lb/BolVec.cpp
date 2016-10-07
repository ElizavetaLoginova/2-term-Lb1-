#include <iostream>
#include <conio.h>
#include <math.h>
#include <cstdlib>
#include "BolVec.h"


using namespace std;

//*********** BoolVector() **********************************
BoolVector::BoolVector()
{
	//randomize();
	n = rand() % 10;
	koef = new double[n + 1];
	if (!koef){ cout << "Error"; getch(); return; }
	for (int i = n; i >= 0; i--)
		koef[i] = rand() % 2;
}
//************* BoolVector(int k) *******************************
BoolVector::BoolVector(int k)
{
	n = k;
	koef = new double[n + 1];
	if (!koef){ cout << "Error"; getch(); return; }
	for (int i = n; i >= 0; i--)
		koef[i] = rand() % 10;
}
//****************** BoolVector(int k,double mas[]) ******************
BoolVector::BoolVector(int k, double mas[])
{
	n = k;
	koef = new double[n + 1];
	if (!koef){ cout << "Error"; getch(); return; }
	for (int i = n; i >= 0; i--)
		koef[i] = mas[i];
}
//*************** BoolVector(const BoolVector&ob) *********************
BoolVector::BoolVector(const BoolVector&ob)
{
	n = ob.n;
	koef = new double[n + 1];
	if (!koef){ cout << "Error"; getch(); return; }
	for (int i = 0; i <= n; i++)
		koef[i] = ob.koef[i];
}
//**************** void GiveMemory(int k) **********************
void BoolVector::GiveMemory(int k)
{
	if (koef) delete[] koef;
	koef = new double[k + 1];
	if (!koef){ cout << "Error"; getch(); return; }
}
//******************** SetBoolVector **************************
void BoolVector::SetBoolVector(int k, double *mas)
{
	n = k;
	if (koef) delete[] koef;
	koef = new double[n + 1];
	for (int i = n; i >= 0; i--)
		koef[i] = mas[i];
}
//*************** CalculateValue *****************************
void BoolVector::CalculateValue(double x = 1.0)
{
	double s;
	int i;
	for (s = koef[0], i = 1; i <= n; i++)
		s = s + koef[i] * pow(x, i);
	cout << "f(" << x << ")="; cout << s << endl;
}
//**************** BoolVector operator+(BoolVector ob) ***************
BoolVector BoolVector::operator+(BoolVector ob)
{
	int i;
	BoolVector rab;
	rab.GiveMemory(max(n, ob.GetDegree()));
	for (i = 0; i <= min(n, ob.GetDegree()); i++)
		rab.koef[i] = koef[i] + ob.GetOneCoefficient(i);
	if (n<ob.GetDegree())
	{
		for (i = min(n, ob.GetDegree()) + 1; i <= ob.GetDegree(); i++)
			rab.koef[i] = ob.GetOneCoefficient(i);
		rab.n = ob.GetDegree();
	}
	else
	{
		for (i = min(n, ob.GetDegree()) + 1; i <= n; i++) rab.koef[i] = koef[i];
		rab.n = n;
	}
	return rab;
}
//*************** BoolVector operator*(BoolVector ob) ***************
BoolVector BoolVector::operator*(BoolVector ob)
{
	int i, j, k;
	double s;
	BoolVector rab;
	rab.GiveMemory(n + ob.GetDegree());
	for (i = 0; i <= n + ob.GetDegree(); i++)
	{
		s = 0;
		for (j = 0; j <= n; j++)
		for (k = 0; k <= ob.GetDegree(); k++)
		if (j + k == i)s = s + koef[j] * ob.GetOneCoefficient(k);
		rab.koef[i] = s;
	}
	rab.n = n + ob.GetDegree();
	return rab;
}
//********** ostream& operator<<(ostream& mystream,BoolVector &ob) ******
std::ostream& operator<<(ostream& mystream, BoolVector &ob) 
{
	char c = ' '; //пропустим “+” перед первым коэффициентом
	for (int i = ob.n; i >= 0; i--)
	{
		double ai = ob.koef[i];
		if (ai == 0) continue;
		else { if (ai>0) mystream << c; mystream << ai; }
		if (i == 0) continue; else mystream << "x";
		if (i == 1) continue; else mystream << "^" << i;
		if (ai != 0)c = '+';
	}
	if (c == ' ')mystream << 0;
	mystream << endl;
	return mystream;
}
//********* istream& operator>>(istream& mystream,BoolVector &ob) *
std::istream& operator>>(istream& mystream, BoolVector &ob)
{
	int i;
	cout << "Enter Degree:";  mystream >> ob.n; cout << endl;
	for (i = ob.n; i >= 0; i--)
	{
		cout << "Enter koeff " << i << ":";  mystream >> ob.koef[i];
	}
	return mystream;
}
