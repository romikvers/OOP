#pragma once
#include <string>

using namespace std;

class Circle
{
private:
	int x, y;  // ���������� ������ ����
	double R;
public:
	bool set_check_X(int value);
	bool set_check_Y(int value);
	bool set_check_Radius(double value);
	double get_Area();
	double get_Long();
	bool Init(int gor, int ver, double radius);
	void Read();
	void Display() const;
};
