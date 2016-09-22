#ifndef Train_h
#define Train_h

const int N = 20;
const int M = 5;

class Train
{
public:
	Train();
	~Train();
	void SetTrain(char*, char*, char*, char*, char*, char*);
	void Destination(char*);
	void TrainNumber(char*);
	void DepartureTime(char*);
	void NumberOfCommonPlaces(char*);
	void NumOfCompartment(char*);
	void SecondClasSeats(char*);
	char* GetcarDestination();
	char* GetTrainNumber();
	char* GetdepartureTime();
	char* GetNumberOfCommonPlaces();
	char* GetNumOfCompartmen();
	char* GetSecondClasSeats();
	void DisplayTrain();
private:
	char carDestination[N], trainNumber[N], departureTime[N], numCommon[N], numCompartment[N], secondClass[N];
};

#endif
