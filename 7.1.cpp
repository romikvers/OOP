/*
Описати клас, який представляє матрицю із NнаN цілих чисел.
Реалізувати операції
• множення матриці на скаляр;
• порівняння матриць;
• обчислення норми матриць(модуль різниці максимального та мінімального
    елементів)
*/

#include <iostream>
#include "Matrix.h"
#include <iomanip>
#include <windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Matrix a(2), b(2);
    a.Init_Random();
    a.Read_Matrix();
    cout << "-----------------" << endl;
    b.Init_Random();
    b.Read_Matrix();
    cout << "-----------------" << endl;
    double value;
    cout << "Множення матриці на скаляр : "; cin >> value;
    b.Skaliar(value);
    cout << b << endl;
    cout << "-----------------" << endl;
    Matrix d = a;
    cout << setw(15) << "Max. elem :" << a.Max_elem() << endl;
    cout << setw(15) << "Max. elem :" << a.Min_elem() << endl;
    cout << "-----------------" << endl;
    Matrix tmp;
    cout << "-----------------" << endl;
    if (a.Get_Row_Col() >= b.Get_Row_Col())
    {
        tmp.Set_Row_Col(a.Get_Row_Col());
    }
    else {
        tmp.Set_Row_Col(b.Get_Row_Col());
    }
    tmp.Rewrite();
    tmp.Init_Random();
    cout << tmp << endl;
    cout << setw(15) << "Compare :" << endl;
    if (a > b)
    {
        cout << "\ta > b" << endl;
    }
    else {
        cout << "\ta <= b" << endl;
    }
    cout << "-----------------" << endl;
    if (a >= b)
    {
        cout << "\ta >= b" << endl;
    }
    else {
        cout << "\ta < b" << endl;
    }
    return 0;
}