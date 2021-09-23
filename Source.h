#pragma once

#include <stdexcept>
#include <vector>

//Task 1 =============================================

template <typename T1, typename T2>
auto div(T1 numerator, T2 denominator)
{
	return numerator / denominator;
}

//Task 2 =============================================

class Ex
{
private:
	double x;
public:
	Ex(double input)
		: x(input) {}

	double getX()
	{
		return x;
	}
};

class Bar
{
private:
	double y;
public:
	Bar()
		: y(0) {}
	void set(double a)
	{
		if (y + a > 100)
		{
			throw Ex(a * y);
		}
		else y = a;
	}
	double getY()
	{
		return y;
	}
};

//Task 3 =============================================
class Cell
{
private:
	int x, y;
	bool containsRobot = false;
public: 
	Cell(int inputX, int inputY)
		: x(inputX), y(inputY){}

	int getX()
	{
		return x;
	}

	int getY()
	{
		return y;
	}

	void setX(int input)
	{
		x = input;
	}

	void setY(int input)
	{
		y = input;
	}
};

class Robot
{
private:
	int fieldSize;
	Cell currentCell;
public:
	Robot(int inputSize)
		: fieldSize(inputSize), currentCell(0,0){}

	void move()
	{
		std::string axis, direction;
		try
		{
			std::cout << "Choose movement axis (x, y):";
			std::cin >> axis;
			if (axis != "x" && axis != "y") throw IllegalCommand();

			std::cout << "Choose movement direction (+, -):";
			std::cin >> direction;
			if (direction != "+" && direction != "-") throw IllegalCommand();
		}
		catch (IllegalCommand)
		{
		}

		int newCoord = 0;

		if (axis == "x" && direction == "+")
		{
			try
			{
				newCoord = currentCell.getX() + 1;
				if (newCoord >= fieldSize)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setX(newCoord);
				}
			}
			catch (OffTheField &e)
			{
				e.printDetails();
			}
		}

		if (axis == "x" && direction == "-")
		{
			try
			{
				newCoord = currentCell.getX() - 1;
				if (newCoord < 0)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setX(newCoord);
				}
			}
			catch (OffTheField& e)
			{
				e.printDetails();
			}
		}

		if (axis == "y" && direction == "+")
		{
			try
			{
				newCoord = currentCell.getY() + 1;
				if (newCoord >= fieldSize)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setY(newCoord);
				}
			}
			catch (OffTheField& e)
			{
				e.printDetails();
			}
		}

		if (axis == "y" && direction == "-")
		{
			try
			{
				newCoord = currentCell.getY() - 1;
				if (newCoord < 0)
				{
					throw OffTheField(this, axis, direction);
				}
				else
				{
					currentCell.setY(newCoord);
					//return true;
				}
			}
			catch (OffTheField& e)
			{
				e.printDetails();
				//return false;
			}
		}
	}

	int getCoordX()
	{
		return currentCell.getX();
	}

	int getCoordY()
	{
		return currentCell.getY();
	}

	void printCoordinates()
	{
		std::cout << "Current coordinates (x, y): (" << currentCell.getX()+1 << "," << currentCell.getY()+1 << ")\n";
	}

	class IllegalCommand
	{
	public:
		IllegalCommand()
		{
			system("cls");
			std::cout << "Incorrect command! Choose correct axis and direction.\n";
		}
	};

	class OffTheField
	{
	private:
		Robot* robotPtr;
		std::string axis, direction;
	public:
		OffTheField(Robot* robot, std::string inputAxis, std::string inputDirection)
			: robotPtr(robot), axis(inputAxis), direction(inputDirection) {}
		void printDetails() const
		{
			std::cout << "\nIncorrect input, Robot will be off the field!\nInitial coordinates (x, y): (" << robotPtr->getCoordX()+1 << "," << robotPtr->getCoordY()+1 << ")\n";
			std::cout << "Movement axis: " << axis << ", movement direction: " << direction << "\n";
		}
	};
};

