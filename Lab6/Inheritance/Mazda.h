#pragma once
#include "Car.h"
class Mazda :public Car {
public:
	Mazda();
	int getFuelCapacity();
	int getFuelConsumption();
	int getSpeed(Weather weather);
};