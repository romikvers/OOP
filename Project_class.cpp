#include "Project_class.h"
#include <iostream>
#define PI 3.14

using namespace std;

bool Circle::set_check_X(int value)
{
	if (value > 0)
	{
		x = value;
		return true;
	}
	else
	{
		x = 0;
		return false;
	}
}
bool Circle::set_check_Y(int value)
{
	if (value > 0)
	{
		y = value;
		return true;
	}
	else
	{
		y = 0;
		return false;
	}
}
bool Circle::set_check_Radius(double value)
{
	if (value > 0)
	{
		R = value;
		return true;
	}
	else
	{
		R = 0;
		return false;
	}
}
bool Circle::Init(int gor, int ver, double radius)
{
	return set_check_X(gor) && set_check_Y(ver) && set_check_Radius(radius);
}
void Circle::Read()
{
	int x, y;
	double R;
	do
	{
		cout << " x = "; cin >> x;
		cout << " y = "; cin >> y;
		cout << " Radius = "; cin >> R;
	} while (!Init(x, y, R));
}
void Circle::Display() const
{
	cout << " x = " << x << " y = " << y << " Radius = " << R << endl;
}
double Circle::get_Area()
{
	double S = pow(R, 2) * PI;
	return S;
}
double Circle::get_Long()
{
	double l = R * PI;
	return l;
}