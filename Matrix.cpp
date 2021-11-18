#include "Matrix.h"
#include <sstream>

Matrix::Matrix()
{
	Row = 0, Col = 0;
	m = new float* [this->Row];
	for (int i = 0; i < Row; i++)
	{
		m[i] = new float[Col];
	}
	for (int i = 0; i < this->Row; i++)
	{
		for (int k = 0; k < this->Col; k++)
		{
			m[i][k] = 0;
		}
	}
}
Matrix::Matrix(const int R, const int C)
{
	this->Row = R < 1 ? 1 : R;
	this->Col = C < 1 ? 1 : C;
	m = new float* [this->Row];
	for (int i = 0; i < Row; i++)
	{
		m[i] = new float[Col];
	}
	for (int i = 0; i < this->Row; i++)
	{
		for (int k = 0; k < this->Col; k++)
		{
			m[i][k] = 0;
		}
	}
}
Matrix::Matrix(Matrix& a)
{
	this->Row = a.Row;
	this->Col = a.Col;
	m = new float* [this->Row];
	for (int i = 0; i < Row; i++)
	{
		m[i] = new float[Col];
	}
	for (int i = 0; i < this->Row; i++)
	{
		for (int k = 0; k < this->Col; k++)
		{
			this->m[i][k] = a.m[i][k];
		}
	}
}
Matrix& Matrix::operator ++()
{
	for (int i = 0; i < this->Row; i++)
	{
		for (int k = 0; k < this->Col; k++)
		{
			m[i][k]++;
		}
	}
	return *this;
}
Matrix& Matrix::operator --()
{
	for (int i = 0; i < this->Row; i++)
	{
		for (int k = 0; k < this->Col; k++)
		{
			m[i][k]--;
		}
	}
	return *this;
}
Matrix Matrix::operator ++(int)
{
	Matrix tmp = *this;
	
	++* this;

	return tmp;
}
Matrix Matrix::operator --(int)
{
	Matrix tmp = *this;
	
	--* this;
	
	return tmp;
}

float Matrix::Write_number()   // рандомно складає дійсне число
{
	float a = (0 + rand() % 10) - Drob_value();
	return a;
}
float Matrix::Drob_value()   // складає дробову чатину
{
	stringstream ss;   // записує/зчитує так само як із файлу
	float k = 1 + rand() % 10;
	ss << "0." << k << endl;
	ss >> k;  // 0. ...
	return k;
}
void Matrix::Init_Random()
{
	for (int i = 0; i < this->Row; i++)
	{
		for (int k = 0; k < this->Col; k++)
		{
			m[i][k] = Write_number();
		}
	}
}
void Matrix::Read_Matrix()
{
	for (int i = 0; i < this->Row; i++)
	{
		for (int k = 0; k < this->Col; k++)
		{
			cout << m[i][k] << "\t";
		}
		cout << endl;
	}
}
const float Matrix::Max_elem() const
{
	float max = 0;
	for (int i = 0; i < this->Row; i++) {
		for (int k = 0; k < this->Col; k++) {
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
	for (int i = 0; i < this->Row; i++) {
		for (int k = 0; k < this->Col; k++) {
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
void Matrix::Add(Matrix& a, Matrix& b)
{
	int R = 0, C =0;
	if (a.Row < b.Row)
	{
		R = b.Row;
	} else {
		R = a.Row;
	}
	if (a.Col < b.Col)
	{
		C = b.Col;
	} else {
		C = a.Col;
	}
	Matrix tmp(R, C);
	for (int i = 0; i < a.Row; i++)
	{
		for (int k = 0; k < a.Col; k++)
		{
			tmp.m[i][k] = a.m[i][k];
		}
	}
	for (int i = 0; i < b.Row; i++)
	{
		for (int k = 0; k < b.Col; k++)
		{
			tmp.m[i][k] += b.m[i][k];
		}
	}
	tmp.Read_Matrix();
}
void Matrix::Expansion_Matrix(const int Row, const int Col)
{
	delete[] m;
	m = new float* [this->Row];
	for (int i = 0; i < Row; i++)
	{
		m[i] = new float[Col];
	}
	for (int i = 0; i < this->Row; i++)
	{
		for (int k = 0; k < this->Col; k++)
		{
			this->m[i][k] = Write_number();
		}
	}
}
Matrix::operator string() const
{
	stringstream sout;
	for (int i = 0; i < this->Row; i++)
	{
		for (int k = 0; k < this->Col; k++)
		{
			sout << m[i][k] << "\t";
		}
		sout << endl;
	}
	return sout.str();
}
ostream& operator <<(ostream& out, const Matrix& a)
{
	out << string(a) << endl;
	return out;
}
istream& operator >>(istream& in, Matrix& a)
{
	for (int i = 0; i < a.Row; i++)
	{
		for (int k = 0; k < a.Col; k++)
		{
			cout << "elem :"; cin >> a.m[i][k];
		}
	}
	return in;
}
