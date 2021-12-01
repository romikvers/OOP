#include "Student.h"


int Student::Man::counter = 0;

void Student::Man::Init(string name, int age, int sex, double weight)
{
	setName(name);
	setAge(age);
	setSex(sex);
	setWeight(weight);
}
void Student::Man::Display() const
{
	cout << "name = " << name << endl;
	cout << "age = " << age << endl;
	cout << "sex = "; 	
		if (sex == man) {
			cout << " man" << endl;
		}
		else {
			cout << " woman" << endl;
		}
	cout << "weight = " << weight << endl;
}
void Student::Man::Read()
{
	string name;
	int age, sex;
	double weight;
	cout << endl;
	cout << "\tname :"; cin >> name;
	cout << "\tage :"; cin >> age;
	cout << "\tsex(man - 1\t woman - 2) :"; cin >> sex;
	assert(sex != Student::Man::man || sex != Student::Man::woman && "_sex_");
	cout << "\tweight :"; cin >> weight;
	Init(name, age, sex, weight);
}
Student::Man::Man() : name("інкогніто"), age(0), sex(man), weight(0)
{
	Student::Man::counter++;
}
Student::Man::Man(const string name) : name(name), age(0), sex(man), weight(0)
{
	Student::Man::counter++;
}
Student::Man::Man(const int age) : name("інкогніто"), sex(man), weight(0)
{
	assert(isCorrect(age) && "Error_Age");
	Student::Man::counter++;
}
Student::Man::Man(const double weight) : name("інкогніто"), age(0), sex(man)
{
	assert(isCorrect(weight) && "Error_Weight");
	if (weight > 0)
	{
		this->weight = weight;
	}
	Student::Man::counter++;
}
Student::Man::Man(const string name, const int age, const int sex, const double weight) : name(name), age(age), sex(sex), weight(weight)
{
	Student::Man::counter++;
}
Student::Man::Man(const Student::Man& m) : name(m.name), age(m.age), sex(m.sex), weight(m.weight)
{
	Student::Man::counter++;
}
Student::Man::~Man(void)
{
	Student::Man::counter--;
}
bool Student::Man::isCorrect(const double value)
{
	if (value > 0) {
		return true;
	}
	return false;
}
Student::Man& Student::Man::operator = (const Student::Man& m)
{
	this->name = m.name;
	this->age = m.age;
	this->sex = m.sex;
	this->weight = m.weight;
	return *this;
}
Student::Man::operator string () const
{
	stringstream ss;
	ss << "name = " << name << endl;
	ss << "age = " << age << endl;
	ss << "sex = ";
		if (sex == man){
			ss << " man" << endl;
		}
		else {
			ss << " woman" << endl;
		}
	ss << "weight = " << weight << endl;
	return ss.str();
}
ostream& operator << (ostream& out, const Student::Man& m)
{
	out << string(m);
	return out;
}
istream& operator >> (istream& in, Student::Man& m)
{
	string name;
	int age, sex = 0;
	double weight;
	cout << endl;
	cout << "\tname :"; in >> name;
	cout << "\tage :"; in >> age;
	cout << "\tsex (man - 1, woman - 2) : "; in >> sex;
	assert(sex != Student::Man::man || sex != Student::Man::woman && "_sex_");
	cout << "\tweight :"; in >> weight;
	m.setName(name);
	m.setAge(age);
	m.setSex(sex);
	m.setWeight(weight);
	return in;
}
int Student::Man::getCounter()
{
	return Student::Man::counter;
}