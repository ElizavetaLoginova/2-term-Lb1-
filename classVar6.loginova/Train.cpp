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
char* Train::GetcarDestination()
{
	return carDestination;
}

void Train::TrainNumber(char* s)
{
	strcpy(trainNumber, s);
}
char* Train::GetTrainNumber()
{
	return trainNumber;
}

void Train::DepartureTime(char* s)
{
	strcpy(departureTime, s);
}
char* Train::GetdepartureTime()
{
	return departureTime;
}

void Train::NumberOfCommonPlaces(char* s)
{
	strcpy(numCommon, s);
}
char* Train::GetNumberOfCommonPlaces()
{
	return numCommon;
}

void Train::NumOfCompartment(char* s)
{
	strcpy(numCompartment, s);
}
char* Train::GetNumOfCompartmen()
{
	return numCompartment;
}

void Train::SecondClasSeats(char* s)
{
	strcpy(secondClass, s);
}
char* Train::GetSecondClasSeats()
{
	return secondClass;
}

void Train::SetTrain(char* s1, char* s2, char* s3, char* s4, char* s5, char* s6)
{
	Destination(s1);
	TrainNumber(s2);
	DepartureTime(s3);
	NumberOfCommonPlaces(s4);
	NumOfCompartment(s5);
	SecondClasSeats(s6);
}

void Train::DisplayTrain()
{
	cout << endl << "The destination - " << carDestination << ", Train number - " << trainNumber << ", \t";
	cout.precision(3);
	cout << "  \t" << departureTime << ", Number of common seats - " << numCommon;
	cout << ", Number of compartment seats - " << numCompartment << ", The number of second-class seats - " << secondClass;

}

