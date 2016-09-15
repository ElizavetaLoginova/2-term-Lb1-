#ifndef Train_h
#define Train_h

const int N = 20;
const int M = 5;

class Train
{
public:
	Train();
	~Train();
	void Destination(char*);
	void TrainNumber(char*);
	void DepartureTime(char*);
	void SetTrain(char*, char*, char*);
	char* GetcarDestination();
	char* GetTrainNumber();
	char* GetdepartureTime();
	void DisplayTrain();
private:
	char carDestination[N], trainNumber[N], departureTime[N];
};

#endif