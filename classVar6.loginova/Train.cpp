#include <iostream>
#include <string.h>
#include "Train.h"

using namespace std;

Train::Train(){}

Train::~Train(){}

void Train::Destination(char* s)
{
	strcpy(carDestination, s);
}

void Train::TrainNumber(char* s)
{
	strcpy(trainNumber, s);
}

void Train::DepartureTime(char* s)
{
	strcpy(departureTime, s);
}


char* Train::GetcarDestination()
{
	return carDestination;
}

char* Train::GetTrainNumber()
{
	return trainNumber;
}

char* Train::GetdepartureTime()
{
	return departureTime;
}



void Train::SetTrain(char* s1, char* s2, char* s3)
{
	Destination(s1);
	TrainNumber(s2);
	DepartureTime(s3);

}

void Train::DisplayTrain()
{
	cout << endl << "The destination - " << carDestination << " Train number - " << trainNumber << ", \t";
	cout.precision(3);
	cout << "  , \t" << departureTime << ".";

}
