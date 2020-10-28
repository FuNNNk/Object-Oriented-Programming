#pragma once
#include "Car.h"

class Circuit {
public:
	Car* cars;
	int length, carslength;
	Weather weather;
	
	Circuit();
	void AddCar(Car* car);
	void SetLength(int length);
	void SetWeather(Weather weather);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};