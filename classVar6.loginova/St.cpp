#include <iostream>
#include "Train.h"

using namespace std;

Train InitTrain();
Train* InitArray(int);
void DisplayArray(Train*, int);
void EnterArray(int*, int);
void DisplayChoise(Train*, int, char*);
int Menu();


int main()
{
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true)
	{
		int Key = Menu();
		if (Key == Exit)
			return 0;
		system("cls");
		switch (Key)
		{
		case Init:
			InitTrain;
			break;
		default:
			cout << "\nIncorrect input! Try again!";
		}

		int n;
		cout << "\n Enter the number of Trains:";
		cin >> n;
		system("cls");
		Train* Trains = InitArray(n);
		if (!Trains)
		{
			cout << "\nDynamic array doesn't exist!\n";
			system("pause");
			return 0;
		}
		cout << "\nThe list of Trains:\n";
		DisplayArray(Trains, n);
		char departureTimeTag[N];
		cout << "\nEnter the departure time:";
		cin >> departureTimeTag;



		DisplayChoise(Trains, n, departureTimeTag);
		cout << "\n\nThe sorting list of Trains: \n";

		delete[] Trains;
	}
	system("pause");
	return 0;
}

Train InitTrain()
{
	char carDestination[N] = "not", TrainNumber[N] = "not", departureTime[N] = "not";
	cout << "\nEnter Destination of the train:";
	cin.ignore();
	cin.get(carDestination, N, '\n');
	cout << "Enter number of the train:";
	cin.ignore();
	cin.get(TrainNumber, N, '\n');
	cout << "Enter departureTime:";
	cin.ignore();
	cin.get(departureTime, N, '\n');


	Train trip;
	trip.SetTrain(carDestination, TrainNumber, departureTime);
	return trip;
}

Train* InitArray(int n)
{
	Train* array = new Train[n];
	if (!array)
		return NULL;
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter the information about " << (i + 1) << " Train\n";
		array[i] = InitTrain();
	}
	return array;
}

void EnterArray(int* array, int n)
{
	for (int i = 0; i < M; i++)
	{
		cout << "enter A[" << (i + 1) << "] = ";
		cin >> array[i];
	}
}


void DisplayArray(Train* array, int n)
{
	for (int i = 0; i < n; i++)
		array[i].DisplayTrain();
	cout << endl;
}

void DisplayChoise(Train* array, int dimension, char* departureTimeTag)
{
	for (int i = 0; i < dimension; i++)
	if (!strcmp(array[i].GetdepartureTime(), departureTimeTag)) 
		array[i].DisplayTrain();
}
int Menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations:"
		"\n 1 - Init the list of trains"
		"\n 2 - List of trains coming to the specified destination : "
		"\n 3 - VIEWING OF CONTENTS OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO AND"
		"\n 5 - CHANGE THE ELEMENT"
		"\n 6 - REMOVE THE ELEMENT"
		"\n 7 - SORTING THE ELEMENT"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}