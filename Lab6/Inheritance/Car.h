#pragma once
#include "Weather.h"
class Car {
public:
	float fuel_capacity, fuel_consumption, maxspeed;
	char* name;
	virtual int getFuelCapacity() = 0;
	virtual int getFuelConsumption() = 0;
	virtual int getSpeed(Weather weather) = 0;
};