#include <iostream>
#include "Train.h"

using namespace std;

Train InitTrain();
Train* InitArray(int);
void DisplayArray(Train*, int);
void DisplayChoise(Train*, int, char*, int);
int Menu();


int main()
{

	while (true)
	{
	
		system("cls");
		InitTrain;
		
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
		int y=1;
		while (y)
		{
			int k = Menu();
		if (k == 4) return 0;
		if (k != 0)
		{
			char departureTag[N];
			cout << "\nEnter the tag:";
			cin >> departureTag;

			DisplayChoise(Trains, n, departureTag, k);
			system("pause");
			cout << "If you  want exit press 0 " << endl;
			cin >> y;
		}
		}
		delete[] Trains;
	
	}
	system("pause");
	return 0;
}

Train InitTrain()
{
	char carDestination[N] = "not", TrainNumber[N] = "not", departureTime[N] = "not";
	char numCommon[N] = "not", numCompartment[N] = "not", secondClass[N] = "not";
	cout << "\nEnter Destination of the train:";
	cin.ignore();
	cin.get(carDestination, N, '\n');
	cout << "Enter number of the train:";
	cin.ignore();
	cin.get(TrainNumber, N, '\n');
	cout << "Enter departureTime:";
	cin.ignore();
	cin.get(departureTime, N, '\n');

	cout << "Enter the number of common seats: ";
	cin.ignore();
	cin.get(numCommon, N, '\n');
	cout << "Enter the number of compartment seats: ";
	cin.ignore();
	cin.get(numCompartment, N, '\n');
	cout << "Enter the number of second-class seats: ";
	cin.ignore();
	cin.get(secondClass, N, '\n');


	Train trip;
	trip.SetTrain(carDestination, TrainNumber, departureTime, numCommon, numCompartment, secondClass);
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

void DisplayArray(Train* array, int n)
{
	for (int i = 0; i < n; i++)
		array[i].DisplayTrain();
	cout << endl;
}

void DisplayChoise(Train* array, int dimension, char* departureTag, int key)
{ 
	
	for (int i = 0; i < dimension; i++)
	{

		if (!strcmp(array[i].GetcarDestination(), departureTag) && key == 1)
			array[i].DisplayTrain();
		if (!strcmp(array[i].GetdepartureTime(), departureTag) && key == 2)
			array[i].DisplayTrain();
		if (!strcmp(array[i].GetNumberOfCommonPlaces(), departureTag) && key == 3)
			array[i].DisplayTrain();
	}
}

int Menu()
{
	int k;
	cout << "Enter your choise: " << endl;
	cout << " 1. By the destination: ";
	cout << " 2. By the time: ";
	cout << " 3. By the common seats: ";
	cout << " 4. Exit ";

	cin >> k;
	if (k > 4)
	{
		cout << "Invalid data! Try again.";
		return 0;
	}
	return k;
}
