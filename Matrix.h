#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Matrix
{
	float** m;
	int Row_Col;
public:
	Matrix();
	Matrix(const int);
	Matrix(Matrix&);
	void Set_Row_Col(const int row_col) {
		this->Row_Col = row_col;
	}
	int Get_Row_Col() {
		return this->Row_Col;
	}
	void Rewrite();
	void Init_Random();
	float Write_number();
	float Drob_value();
	void Read_Matrix();
	const float Max_elem() const;
	const float Min_elem() const;
	void Skaliar(const double);
	operator string () const;
	friend bool operator > (const Matrix&, const Matrix& b);
	friend bool operator < (const Matrix&, const Matrix& b);
	friend bool operator <= (const Matrix&, const Matrix& b);
	friend bool operator >= (const Matrix&, const Matrix& b);
	friend bool operator == (const Matrix&, const Matrix& b);
	friend istream& operator >> (istream& in, Matrix& b);
	friend ostream& operator << (ostream& out, const Matrix& b);
};

