#include <iostream>
#include <Windows.h>
using namespace std;

enum Color
{
		RED = 12,
		GREEN = 10,
		BLUE = 9
};

class Shape
{
	Color color;
public:
	Color get_color() const
	{
		return this->color;
	}
	virtual ~Shape()
	{

	}
	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
};

class Square :public Shape
{
	double side;
public:
	const double get_side() const
	{
		return this->side;
	}
	double set_side(double side)
	{
		if (side <= 0)throw exception("Error: Bad square side length");
		return this->side = side;
	}
	Square(double side) :side(set_side(side))
	{
	}
	~Square()
	{
	}
	double get_area() const
	{
		return side * side;
	}
	double get_perimeter() const
	{
		return side * 4;
	}
	void draw()const
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, get_color());
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
			}
		SetConsoleTextAttribute(hConsole, 0x07);
	}
};

void main()
{
	setlocale(LC_ALL, "rus");
	Square s(4);
	cout << "Side length:" << s.get_side() << endl;
	cout << "Area:" << s.get_area() << endl;
	cout << "Perimeter:" << s.get_perimeter() << endl;
	s.draw();
}