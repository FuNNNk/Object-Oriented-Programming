#include <iostream>
#include "Canvas.h"

int main() {
	Canvas canvas = Canvas(20,20);
	canvas.DrawCircle(4, 4, 2, 'x');
	std::cout << "Canvas \n";
	canvas.Print();
	canvas.Clear();
	canvas.FillCircle(4, 4, 2, 'x');
	std::cout << "Canvas \n";
	canvas.Print();
	canvas.Clear();
	canvas.DrawRect(1, 1, 6, 6, 'x');
	std::cout << "Canvas \n";
	canvas.Print();
	canvas.Clear();
	canvas.FillRect(1,1,6,6, 'x');
	std::cout << "Canvas \n";
	canvas.Print();
	canvas.Clear();
	canvas.SetPoint(2, 2, 'x');
	std::cout << "Canvas \n";
	canvas.Print();
	canvas.Clear();
	canvas.DrawLine(3, 2, 15, 5, 'x');
	std::cout << "Canvas \n";
	canvas.Print();
	canvas.Clear();
	std::cout << "Canvas \n";
	canvas.Print();
}