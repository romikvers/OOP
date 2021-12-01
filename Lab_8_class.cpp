/*
    Створити клас Man (людина) з полями: ім’я, вік, стать і вага. Визначити методи 
    переприсвоєння імені, зміни віку і зміни ваги.
    Створити клас-контейнер Student, що має поля «людина» та «курс». Визначити 
    методи пере-присвоєння та збільшення курсу.
*/
#include "Student.h"
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Student s1;
    cout << "Student №" << Student::getCounter() << endl;
    s1.Display();
    cout << "--------------------------------------------------------" << endl;
    Student::Man m1("Oleh", 19, Student::Man::man, 73);
    cout << "People №" << Student::Man::getCounter() << ", data :" << endl;
    m1.Display();
    cout << endl;
    m1.setName("Maria");
    m1.setAge(10);
    m1.setSex(Student::Man::woman);
    m1.setWeight(67);
    cout << m1 << endl;
    cout << "Input character :" << endl; cin >> m1;
    cout << "People №" << Student::Man::getCounter() << " data : \n\tname :" << m1.getName() << "\n\tage :" << m1.getAge() << endl;
    cout << "\tsex :" << m1.getSex() << "\n\t weight :" << m1.getWeight() << endl;
    cout << "--------------------------------------------------------" << endl;

    cout << "Student №" << Student::getCounter() << endl;
    Student s2("Roman", 18, Student::Man::man, 73, 2);
    s2.Display();
    s2.Read();
    s2 = s1;
    cout << "--------------------------------------------------------" << endl;

    Student::Man m2("Sergo");
    cout << "People №" << Student::Man::getCounter() << ", data :" << endl;
    cout << "\tName :" << m2.getName() << endl;
    m2 = m1;
    m2.setName("Sergo");
    cout << "data :\n" << m2;
    cout << "--------------------------------------------------------" << endl;
    {
        Student s4("Mia", 19, Student::Man::woman, 73, 2);
        cout << "getMan :\n" << s4.getMan() << endl;
        cout << "Student local : " << Student::getCounter() << endl;
        cout << "Student::Man local : " << Student::Man::getCounter() << endl;
        Student::Man m1;
        cout << "Student::Man local +1 : " << Student::Man::getCounter() << endl;
    }
    return 0;
}