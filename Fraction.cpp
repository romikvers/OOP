#include "Fraction.h"

void Fraction::Read()
{
	Fraction a, b;
	a.setX(3);
	cout << "x.y : " << a.getX();
	a.setY(44);
	cout << "." << a.getY() << endl;
	cout << "--------------------" << endl;
	b.setX(9);
	cout << "x.y : " << b.getX();
	b.setY(454);
	cout << "." << b.getY() << endl;
	cout << "--------------------" << endl;

	cout << " Plus : " << Plus(a, b) << endl;

	cout << " Multiplate : " << Multiplate(a, b) << endl;
}
double Fraction::Plus(Fraction a, Fraction b)
{
	stringstream myString;

	myString << a.x << "." << a.y << " " << b.x << "." << b.y;

	double first = 0, second = 0;

	myString >> first >> second;

	return first + second;
}
double Fraction::Multiplate(Fraction a, Fraction b)
{
	stringstream myString;

	myString << a.x << "." << a.y << " " << b.x << "." << b.y;

	double first = 0, second = 0;

	myString >> first >> second;

	return first * second;
}