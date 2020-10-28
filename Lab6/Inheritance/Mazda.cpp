#include "Mazda.h"

Mazda::Mazda()
{
	this->name = (char*)"Mazda6";
	this->fuel_capacity = 62;
	this->fuel_consumption = 9.0;
	this->maxspeed = 240;
}

int Mazda::getFuelCapacity() {
	return this->fuel_capacity;
}

int Mazda::getFuelConsumption() {
	return this->fuel_consumption;
}

int Mazda::getSpeed(Weather weather)
{
	if (weather == Weather::Rainy)
		this->maxspeed = this->maxspeed - 20;
	if (weather == Weather::Snow)
		this->maxspeed = this->maxspeed - 40;
	return this->maxspeed;

}
