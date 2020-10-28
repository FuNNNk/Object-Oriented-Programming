#include "Circuit.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"

int main()
{
	Circuit c;
	c.SetLength(100);
	c.SetWeather(Weather::Snow);
	c.AddCar(new Dacia());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());
	c.Race();
	c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit
	c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
	return 0;
}