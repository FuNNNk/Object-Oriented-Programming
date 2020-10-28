#pragma once
#include "Car.h"
class Mercedes :public Car {
public:
	Mercedes();
	int getFuelCapacity();
	int getFuelConsumption();
	int getSpeed(Weather weather);
};