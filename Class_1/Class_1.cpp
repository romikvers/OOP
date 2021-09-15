// Class_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#define PI 3.14159

using namespace std;

class complex
{
    public:
        double x;
        double y;

        double modul(){
            return pow(x * x + y * y, 0.5);
        }
        double argument() {
            return atan2(y, x) * 180 / PI;
        }
        void shcow_complex() {
            if (y >= 0)
                cout << x << " + " << y << "*i" << endl << endl;
            else
                cout << x << y << "i" << endl;
        }
};
int main()
{
    complex chislo;
    chislo.x = 3.5;
    chislo.y = -1.432;
    chislo.shcow_complex();
           chislo.shcow_complex();

   cout << "Modul' chisla=" << chislo.modul();
   
   cout << endl << "Argument chisla=" << chislo.argument() << endl;
   
   system("pause");

   return 0;
}