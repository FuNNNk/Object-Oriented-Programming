#include "Ford.h"

Ford::Ford()
{
	this->name = (char*)"Ford Fusion II 2018";
	this->fuel_capacity = 68;
	this->fuel_consumption = 11.7;
	this->maxspeed = 200;
}

int Ford::getFuelCapacity() {
	return this->fuel_capacity;
}

int Ford::getFuelConsumption() {
	return this->fuel_consumption;
}

int Ford::getSpeed(Weather weather)
{
	if (weather == Weather::Rainy)
		this->maxspeed = this->maxspeed - 20;
	if (weather == Weather::Snow)
		this->maxspeed = this->maxspeed - 40;
	return this->maxspeed;

}

