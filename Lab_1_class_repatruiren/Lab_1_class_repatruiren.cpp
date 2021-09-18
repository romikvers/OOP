/*
	Реалізувати клас Cursor. Поле first – ціле додатне число, горизонтальна
	координата курсору; поле second – ціле додатне число, вертикальна координата
	курсору. Реалізувати метод changeX( ) – зміну горизонтальної координати курсору, та
	метод changeY( ) – зміну вертикальної координати курсору. Методи мають перевіряти
	вихід за межі екрану.
*/


#include <iostream>
#include <windows.h>
#include "Project_1_class.h"

using namespace std;

Cursor makeCursor(double x, double y)
{
	Cursor k;
	if (!k.Init(x, y))
		cout << "Wrong arguments to Init!" << endl;
	else
		cout << "Аргументи введені коректно" << endl;
	return k;
}
int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Cursor n;
	n.Expansion();
	n.Read();
	n.Print_Monitor();
	n.Display();
	cout << endl << endl;
	
	Cursor k;
	int i;
	k.Expansion();
	k.Read();
	makeCursor(13, 15);
	k.Display();

	return 0;
}