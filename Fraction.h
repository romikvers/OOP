#pragma once

/*
—творити клас Fraction дл€ роботи з дробовими числами. „исло маЇ бути
представлене двома пол€ми:
	Х ц≥ла частина Ц довге ц≥ле ≥з знаком,
	Х дробова частина Ц без-знакове коротке ц≥ле.
	–еал≥зувати методи Ц арифметичн≥ операц≥њ:
	Х додаванн€,
	Х множенн€.
	* маЇ бути реал≥зована можлив≥сть опрацюванн€ чисел з р≥зною к≥льк≥стю цифр в дробових частинах
*/
#include <iostream>
#include <cmath>
#include <string> // п≥дключаЇмо б≥бл≥отеку, €ка описуЇ л≥терн≥ р€дки
#include <sstream> // п≥дключаЇмо б≥бл≥отеку, €ка описуЇ л≥терн≥ потоки

using namespace std;

class Fraction
{
private:
	long int x;
	int y;
public:
	void Read();
	void setX(double value)
	{
		x = value;
	}
	void setY(double value)
	{
		y = value;
	}
	double getX() const
	{
		return x;
	}
	double getY() const
	{
		return y;
	}
	double Plus(Fraction a, Fraction b);

	double Multiplate(Fraction a, Fraction b);
};