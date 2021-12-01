/*
	Створити клас Man (людина) з полями: ім’я, вік, стать і вага. Визначити методи
	переприсвоєння імені, зміни віку і зміни ваги.
	Створити клас-контейнер Student, що має поля «людина» та «курс». Визначити
	методи пере-присвоєння та збільшення курсу.
*/

#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

class Student
{
private:
	int kurs;
	static int counter;     //  лічильник, який рахує кількість викликів класу Student
public:
	class Man
	{
	private:
		string name;
		int age;
		int sex;   // стать
		double weight;    //   вага
		static int counter;    //  лічильник, який рахує кількість викликів класу Man
	public:
		static enum who { man = 1, woman };
		string getName() const { return name; }
		int getAge() const { return age; }
		string getSex() const {
			stringstream ss;
			if (sex == man) {
				ss << "man" << endl;
				return ss.str();
			}
			else {
				ss << "woman" << endl;
				return ss.str();
			}
		}
		double getWeight() const { return weight; }
		void setName(string name) { this->name = name; }
		void setAge(int age) { this->age = age; }
		void setSex(int sex) { this->sex = sex; }
		void setWeight(double weight) { this->weight = weight; }
		void Init(string name, int age, int sex, double weight);
		void Display() const;
		void Read();
		Man();
		Man(const string name);
		Man(const int age);
		//Man(const string sex);
		Man(const double weight);
		Man(const string name, const int age, const int sex, const double weight);
		Man(const Man& m);
		~Man(void);
		bool isCorrect(const double value);
		Man& operator = (const Man& m);
		friend ostream& operator << (ostream& out, const Man& m);
		friend istream& operator >> (istream& in, Man& m);
		operator string () const;
		static int getCounter();
	};
	int getKurs() const { return kurs; }
	Man getMan() const { return man; }
	void setKurs(int kurs) { this->kurs = kurs; }
	void setMan(Man man) { this->man = man; }
	void Init(const int kurs, Man& man);
	void Display() const;
	void Read();
	Student(const string name = "інкогніто", const int age = 0, const int sex = Student::Man::man, const double weight = 0,  const int kurs = 0);
	Student(const Student& s);
	~Student(void);
	Student& operator = (const Student& s);
	friend ostream& operator << (ostream& out, const Student& s);
	friend istream& operator >> (istream& in, Student& s);
	operator string () const;
	static int getCounter();
private:
	Man man;
};