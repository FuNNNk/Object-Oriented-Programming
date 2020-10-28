#include "Toyota.h"

Toyota::Toyota()
{
	this->name = (char*)"Toyota Camry";
	this->fuel_capacity = 55;
	this->fuel_consumption = 9.0;
	this->maxspeed = 210;
}

int Toyota::getFuelCapacity() {
	return this->fuel_capacity;
}

int Toyota::getFuelConsumption() {
	return this->fuel_consumption;
}

int Toyota::getSpeed(Weather weather)
{
	if (weather == Weather::Rainy)
		this->maxspeed = this->maxspeed - 20;
	if (weather == Weather::Snow)
		this->maxspeed = this->maxspeed - 40;
	return this->maxspeed;
}

