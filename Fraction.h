#pragma once

/*
�������� ���� Fraction ��� ������ � ��������� �������. ����� �� ����
������������ ����� ������:
	� ���� ������� � ����� ���� �� ������,
	� ������� ������� � ���-������� ������� ����.
	���������� ������ � ���������� ��������:
	� ���������,
	� ��������.
	* �� ���� ���������� ��������� ����������� ����� � ����� ������� ���� � �������� ��������
*/
#include <iostream>
#include <cmath>
#include <string> // ��������� ��������, ��� ����� ����� �����
#include <sstream> // ��������� ��������, ��� ����� ����� ������

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