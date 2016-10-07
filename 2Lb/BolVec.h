#ifndef BolVec_h
#define BolVec_h
#include <ostream>


class BoolVector 
{
private:
	int n;
	double *koef;
public:
	BoolVector(); //конструкторы
	BoolVector(int k);
	BoolVector(int k, double *mas);
	BoolVector(const BoolVector&ob); //конструктор копирования
	~BoolVector(){ delete[]koef; }
	void GiveMemory(int k);
	void SetBoolVector(int k, double *mas);
	void SetDegree(int k){ n = k; }; //установить степень
	void CalculateValue(double x);  //вычислить значение
	int GetDegree(){ return n; };   //получить степень
	double GetOneCoefficient(int i){ return(koef[i]); };
	BoolVector operator+(BoolVector ob); //перегрузка операторов
	BoolVector operator*(BoolVector ob);
	double& operator[](int i){ return(koef[i]); }//перегрузка []
	BoolVector& operator = (const BoolVector p)
	{
		if (&p == this) return *this;
		if (koef) delete[] koef;
		n = p.n;
		koef = new double[p.n + 1];
		for (int i = 0; i <= p.n; i++)
			koef[i] = p.koef[i];
		return *this;
	}
	friend ostream& operator<<(const ostream& mystream,const BoolVector &ob) ;
	friend istream& operator>>(istream& mystream, BoolVector &ob);
	int min(int n, int m)
	{
		return (n<m) ? n : m;
	}
	int max(int n, int m)
	{
		return (n>m) ? n : m;
	}
};

#endif
