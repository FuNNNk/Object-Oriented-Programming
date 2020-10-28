#pragma once
#include "Car.h"
class Ford :public Car {
public:
	Ford();
	int getFuelCapacity();
	int getFuelConsumption();
	int getSpeed(Weather weather);
};