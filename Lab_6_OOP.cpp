/*
Створити клас Матриця, який у закритій частині містить поля:
• вказівник на вказівник на float,
• кількість рядків та
• стовпців.
Визначити методи:
• встановлення та
• виведення елементів матриці,
• пошуку мінімального та
• максимального елементів,
• суми елементів матриці
*/

#include "Matrix.h"
#include <iomanip>

int main()
{
    Matrix a(2, 3), b(2, 1);
    a.Init_Random();  // ініціалізує рандомно
    cout << "Matrix a :\n"; a.Read_Matrix(); cout << endl;
    cout << "Matrix b :\n"; cout << endl;
    cin >> b;   
    cout << endl << b << endl;
    cout << "++Matrix :\n" << ++b;
    cout << "Matrix-- :\n" << b--;
    cout << "Matrix++ :\n" << b++;
    cout << "Matrix :\n" << b;
    cout << "--Matrix :\n" << --b;
    cout << "Matrix :\n" << b;
    Matrix d = a;
    cout << setw(15) << "Max. elem :" << a.Max_elem() << endl;
    cout << setw(15) << "Max. elem :" << a.Min_elem() << endl;
    cout << setw(15) << "Add Matrix :\n"; a.Add(d, b);
    Matrix c;
    c.SetCol(3);
    c.SetRow(2);
    c.Expansion_Matrix(c.GetCol(), c.GetRow());
    cout << "Matrix c:" << endl; cout << c;
    return 0;
}