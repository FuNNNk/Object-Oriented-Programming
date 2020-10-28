#include "Mercedes.h"

Mercedes::Mercedes()
{
	this->name = (char*)"Mercedes-Benz E-Class";
	this->fuel_capacity = 66;
	this->fuel_consumption = 8.8;
	this->maxspeed = 250;
}

int Mercedes::getFuelCapacity() {
	return this->fuel_capacity;
}

int Mercedes::getFuelConsumption() {
	return this->fuel_consumption;
}

int Mercedes::getSpeed(Weather weather)
{
	if (weather == Weather::Rainy)
		this->maxspeed = this->maxspeed - 20;
	if (weather == Weather::Snow)
		this->maxspeed = this->maxspeed - 40;
	return this->maxspeed;

}
