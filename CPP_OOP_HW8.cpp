#include <iostream>
#include "Source.h"

int main()
{
	//Task 1 ===============================================================================================
	std::cout << "Task 1:\n";
	int numerator = 10;
	double denominator = 18;
	try
	{
		if (denominator == 0) throw std::overflow_error("Division by zero");
		std::cout << numerator << " / " << denominator << " = " << div(numerator, denominator);
	}
	catch (std::overflow_error)
	{
		std::cout << "Division by zero!";
	}

	//Task 2 ===============================================================================================
	std::cout << "\n\nTask 2:\n";
	Bar* bar = new Bar();
	int n = 0;
	try
	{
		bool nNotZero = true;
		while (nNotZero)
		{
			std::cout << "Enter n: ";
			std::cin >> n;
			if (n != 0)
			{
				bar->set(n);
			}
			else nNotZero = false;
		}
	}
	catch (Ex &e)
	{
		std::cout << "Exception thrown, code " << e.getX();
	}
	delete bar;

	//Task 3 ===============================================================================================


	std::cout << "\nTask 3:\n";
	int fieldSize = 10;
	Robot* robot = new Robot(fieldSize);

	while (true)
	{
		robot->printCoordinates();
		robot->move();
	}
	delete robot;

}

