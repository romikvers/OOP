#include "Matrix.h"
#include <sstream>
#define NDEBUG	
#include <cassert>

Matrix::Matrix()
{
	Row_Col = 1;
	m = new float* [this->Row_Col];
	for (int i = 0; i < Row_Col; i++)
	{
		m[i] = new float[Row_Col];
	}
	for (int i = 0; i < this->Row_Col; i++)
	{
		for (int k = 0; k < this->Row_Col; k++)
		{
			m[i][k] = 0;
		}
	}
}
Matrix::Matrix(const int Row_Col)
{
	this->Row_Col = Row_Col < 1 ? 1 : Row_Col;
	m = new float* [this->Row_Col];
	for (int i = 0; i < Row_Col; i++)
	{
		m[i] = new float[Row_Col];
	}
	for (int i = 0; i < this->Row_Col; i++)
	{
		for (int k = 0; k < this->Row_Col; k++)
		{
			m[i][k] = 0;
		}
	}
}
Matrix::Matrix(Matrix& a)
{
	this->Row_Col = a.Row_Col;

	m = new float* [this->Row_Col];

	for (int i = 0; i < Row_Col; i++)
	{
		m[i] = new float[Row_Col];
	}
	for (int i = 0; i < this->Row_Col; i++)
	{
		for (int k = 0; k < this->Row_Col; k++)
		{
			this->m[i][k] = a.m[i][k];
		}
	}
}
float Matrix::Write_number()
{
	float a = (0 + rand() % 10) - Drob_value();
	return a;
}
float Matrix::Drob_value()
{
	stringstream ss;   // записує/зчитує так само як із файла
	float k = 1 + rand() % 10;
	ss << "0." << k << endl;
	ss >> k;  // 0. ...
	return k;
}
void Matrix::Init_Random()
{
	for (int i = 0; i < this->Row_Col; i++)
	{
		for (int k = 0; k < this->Row_Col; k++)
		{
			m[i][k] = Write_number();
			//cin >> m[i][k];
		}
	}
}
void Matrix::Read_Matrix()
{
	cout << "Matrix : {" << endl;
	for (int i = 0; i < this->Row_Col; i++)
	{
		for (int k = 0; k < this->Row_Col; k++)
		{
			cout << m[i][k] << "\t";
		}
		cout << endl;
	}
	cout << " }" << endl;
}
const float Matrix::Max_elem() const
{
	float max = 0;
	for (int i = 0; i < this->Row_Col; i++) {
		for (int k = 0; k < this->Row_Col; k++) {
			if (i == 0 && k == 0) {
				max = m[i][k];
			}
			else {
				if (m[i][k] > max) {
					max = m[i][k];
				}
			}
		}
	}
	return max;
}
const float Matrix::Min_elem() const
{
	float min = 0;
	for (int i = 0; i < this->Row_Col; i++) {
		for (int k = 0; k < this->Row_Col; k++) {
			if (i == 0 && k == 0) {
				min = m[i][k];
			}
			else {
				if (m[i][k] < min) {
					min = m[i][k];
				}
			}
		}
	}
	return min;
}
void Matrix::Rewrite()
{
	m = new float* [Row_Col];
	for (int i = 0; i < Row_Col; i++)
	{
		m[i] = new float[Row_Col];
	}
	for (int i = 0; i < Row_Col; i++)
	{
		for (int k = 0; k < Row_Col; k++)
		{
			m[i][k] = 0;
		}
	}
}
void Matrix::Skaliar(const double value)
{
	for (int i = 0; i < Row_Col; i++)
	{
		for (int j = 0; j < Row_Col; j++)
		{
			m[i][j] *= value;
		}
	}
}
bool operator > (const Matrix& a, const Matrix& b)
{
	int count_a = 0, count_b = 0;
	assert(a.Row_Col != b.Row_Col && "Не рівна кількість елементів");
	for (int i = 0; i < a.Row_Col; i++)
	{
		for (int k = 0; k < a.Row_Col; k++)
		{
			if (a.m[i][k] > b.m[i][k]) {
				count_a++;
			}
			else {
				count_b++;
			}
		}
	}
	if (count_a > count_b)
	{
		return true;
	}
	return false;
}
bool operator < (const Matrix& a, const Matrix& b)
{
	int count_a = 0, count_b = 0;
	assert(a.Row_Col == b.Row_Col && "Не рівна кількість елементів");
	for (int i = 0; i < a.Row_Col; i++)
	{
		for (int k = 0; k < a.Row_Col; k++)
		{
			if (a.m[i][k] < b.m[i][k]) {
				count_b++;
			}
			else {
				count_a++;
			}
		}
	}
	if (count_a < count_b)
	{
		return true;
	}
	return false;
}
bool operator <= (const Matrix& a, const Matrix& b)
{
	if (a < b || a == b)
	{
		return true;
	}
	return false;
}
bool operator >= (const Matrix& a, const Matrix& b)
{
	if (a > b || a == b)
	{
		return true;
	}
	return false;
}
bool operator == (const Matrix& a, const Matrix& b)
{
	assert(a.Row_Col != b.Row_Col && "Не рівна кількість елементів");
	for (int i = 0; i < a.Row_Col; i++)
	{
		for (int k = 0; k < a.Row_Col; k++)
		{
			if (a.m[i][k] != b.m[i][k]) {
				return false;
			}
		}
	}
	return true;
}
Matrix::operator string () const
{
	stringstream ss;
	for (int i = 0; i < Row_Col; i++)
	{
		for (int k = 0; k < Row_Col; k++)
		{
			ss << m[i][k] << "\t";
		}
		ss << "\n";
	}
	return ss.str();
}
istream& operator >> (istream& in, Matrix& b)
{
	for (int i = 0; i < b.Row_Col; i++)
	{
		for (int k = 0; k < b.Row_Col; k++)
		{
			cout << "Value :"; in >> b.m[i][k];
		}
	}
	return in;
}
ostream& operator << (ostream& out, const Matrix& b)
{
	out << string(b);
	return out;
}