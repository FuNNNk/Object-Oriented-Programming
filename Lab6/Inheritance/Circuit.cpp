#include "Circuit.h"
#include <iostream>

using namespace std;

Circuit::Circuit()
{
	this->cars = (Car*)malloc(sizeof(Car)*6);
	this->length = 0;
	this->carslength = 0;
	this->weather = Sunny;
}

void Circuit::AddCar(Car* car)
{	
	this->cars[this->carslength++] = *car;
	cout << "Masina inscrisa cu numarul " << this->carslength << " inscrisa in concurs este: " <<  this->cars[carslength -1].name << "\n";
}

void Circuit::SetLength(int length)
{
	this->length = length;
	cout << "Lungimea cursei este de: " << this->length << " km\n\n";
}

void Circuit::SetWeather(Weather weather)
{
	this->weather = weather;
	if (weather == 0)
		cout << "Vremea se anunta a fi: insorita\n\n";
	else if (weather == 1)
		cout << "Vremea se anunta a fi : ploioasa\n\n";
	else cout << "Se anunta zapada\n\n";
}

void Circuit::Race()
{
	cout << "Se pregatesc masinile de start \n\n";
	for (int i = 0; i < carslength; i++) {
		this->cars[i].maxspeed = this->cars[i].getSpeed(this->weather);
	}
	cout << "Cursa a inceput\n";

}

void Circuit::ShowFinalRanks()
{
	float time[6];
	Car* aux2;

	for (int i = 0; i < carslength; i++) {
		time[i] = this->length * 60 / this->cars[i].getSpeed(this->weather);
	}

	for (int i = 0; i < carslength-1; i++) {
		for (int j = i+1; j < carslength; j++) {
			if (time[i] < time[j]) {
				int aux = time[i];
				time[i] = time[j];
				time[j] = aux;

				aux2 =	&cars[i];
				cars[i] = cars[j];
				cars[j] = *aux2;
			}
		}
	}

	for (int i = 0; i < carslength; i++) {
		cout << "Masina " << this->cars[i].name << " a terminat traseul in: " << time[i];
	}
}

void Circuit::ShowWhoDidNotFinish()
{
	for (int i = 0; i < carslength; i++) {
		if ( cars[i].fuel_capacity < 60)
			cout << "Nu a reusit sa termine cursa masina " << cars[i].name << endl;
	}
}
