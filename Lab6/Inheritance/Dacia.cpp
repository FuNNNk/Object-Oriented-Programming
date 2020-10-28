#include "Dacia.h"
#include <iostream>

Dacia::Dacia()
{
	this->name = (char*)"Dacia Logan";
	this->fuel_capacity = 50;
	this->fuel_consumption = 3.6;
	this->maxspeed = 179;
}

int Dacia::getFuelCapacity() {
	return this->fuel_capacity;
}

int Dacia::getFuelConsumption() {
	return this->fuel_consumption;
}

int Dacia::getSpeed(Weather weather)
{
	if (weather == Weather::Rainy)
		this->maxspeed = this->maxspeed - 20;
	if (weather == Weather::Snow)
		this->maxspeed = this->maxspeed - 40;
	return this->maxspeed;
}
