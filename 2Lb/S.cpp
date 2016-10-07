#include <iostream>
#include <conio.h>
#include <math.h>
#include "BolVec.h"

using namespace std;


//******************** MAIN ****************************
int main(int argc, char* argv[])
{
	const int m = 3;
	BoolVector f, g, masp[m], *p1, s;
	int n = 5, i;
	double K[6] = { 1.0, 3.2, 0.0, 4.1, 0.0, 1.1 };
	p1 = new BoolVector(n, K);
	cout << *p1;
	p1->CalculateValue(2.0);
	cin >> f;
	cout << " f(x)= ";  cout << f;
	cout << " g(x)= "; cout << g;
	s = f + g;
	cout << "f(x)+g(x) = "; cout << s;
	s = f*g;
	cout << " f(x)*g(x) = ";  cout << s;
	s = masp[0]; cout << masp[0];
	for (i = 1; i<m; i++)
	{
		s = s + masp[i]; cout << masp[i];
	}
	cout << "Summa: ";  cout << s;
	while (!kbhit());
	delete p1;
	return 0;
}
