/*
	���������� ���� Cursor. ���� first � ���� ������� �����, �������������
	���������� �������; ���� second � ���� ������� �����, ����������� ����������
	�������. ���������� ����� changeX( ) � ���� ������������� ���������� �������, ��
	����� changeY( ) � ���� ����������� ���������� �������. ������ ����� ���������
	����� �� ��� ������.
*/


#include "Project_1_class.h"
#include <iostream>

using namespace std;

void Cursor::Expansion()
{
	cout << "width  :"; cin >> Gor;
	cout << "height :"; cin >> Ver;
}
void Print_Space()
{
	for (int s = 0; s < 10; s++)
	{
		cout << " ";
	}
}
void Cursor::change_X_Y(const int Gor, const int Ver_pix, const int x, const int y)
{
	for (int i = 1; i <= Gor; i++) {
		if (x == i && y == Ver_pix){
			cout << "@";
		}
		else
			cout << ".";
	}
}
void Cursor::�heck()
{
	Print_Space();  /// //  ������ �� ����
	if (x > 0 && x <= Gor - 2 && y > 0 && y <= Ver)
		cout << "����� ������ �� �����!" << endl;
	else
		cout << "����� �� ������ �� �����!" << endl;
}
void Cursor::Print_Monitor()
{
	cout << endl << endl;
	Print_Space();  /// //  ������ ������ �� ����
	for (int i = 0; i < Gor; i++) {
		cout << "_";
	}
	cout << endl;
	for (int j = 1; j <= Ver; j++) {
		Print_Space();   /// //  ������ ������ �� ����
		cout << "(";
		change_X_Y(Gor - 2, j, x, y);    // ������� �� �����
		cout << ")" << endl;
	}
	Print_Space();   ///  //  ������ ������ �� ����
	for (int i = 0; i < Gor; i++) {
		cout << "_";
	}
	cout << endl << endl;
	�heck();    // �������� �� ��������� �� �����
	cout << endl;
}
bool Cursor::Init(int first, int second)
{
	if (first >= 0 && second >= 0)
	{
		x = first;
		y = second;
		return true;
	}
	else {
		x = 0;
		y = 0;
		return false;
	}
}
void Cursor::Display() const
{
	Print_Space();
	cout << "x = " << x << " y = " << y << endl;
}
void Cursor::Read()
{
	int first,   // ������
		second;   // �������
	  do
	  {
		cout << "x :";
		cin >> first;
		cout << "y :";
		cin >> second;
	  }while (!Init(first, second));
}