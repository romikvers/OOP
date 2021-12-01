#include "Student.h"

int Student::counter = 0;

void Student::Init(const int kurs, Man& man)
{
	setKurs(kurs);
	setMan(man);
}
void Student::Display() const
{
	cout << endl;
	cout << " Man character : " << endl;
	man.Display();
	cout << "kurs = " << kurs << endl;
}
void Student::Read()
{
	int kurs;
	Man m;
	cout << endl;
	cout << "Man character = ? " << endl;
	m.Read();
	cout << "\tkurs = "; cin >> kurs;
	Init(kurs, m);
}
Student::Student(const string name, const int age, const int sex, const double weight, const int kurs) : man(name, age, sex, weight), kurs(kurs)
{
	Student::counter++;
}
Student::Student(const Student& s)
{
	man = s.man;
	kurs = s.kurs;
	Student::counter++;
}
Student::~Student(void)
{
	Student::counter--;
}
Student& Student::operator = (const Student& s)
{
	man = s.man;
	kurs = s.kurs;
	return *this;
}
Student::operator string () const
{
	stringstream ss;
	ss << "man = " << man << endl;
	ss << "kurs = " << kurs << endl;
	return ss.str();
}
ostream& operator << (ostream& out, const Student& s)
{
	out << string(s);
	return out;
}
istream& operator >> (istream& in, Student& s)
{
	int kurs;
	cout << endl;
	cout << "man = ? "; in >> s.man;
	cout << "spec = ? "; in >> kurs;
	s.setKurs(kurs);
	return in;
}
int Student::getCounter()
{
	return Student::counter;
}
