#pragma once
#include "Car.h"
class Dacia:public Car {
public:
	Dacia();
	int getFuelCapacity();
	int getFuelConsumption();
	int getSpeed(Weather weather);
};