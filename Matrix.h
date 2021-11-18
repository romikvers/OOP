#pragma once
#include <iostream>

using namespace std;

class Matrix
{
	float** m;
	int Row, Col;   //  Row - рядок, Col - стовпець
public:
	int GetRow() const { return Row; }
	unsigned GetCol() const { return Col; }
	void SetRow(int Row) { this->Row = Row; };
	void SetCol(int Col) { this->Col = Col; };
	Matrix();
	Matrix(const int R, const int C);
	Matrix(Matrix& a);
	Matrix& operator ++ ();
	Matrix& operator -- ();
	Matrix operator ++ (int);
	Matrix operator -- (int);
	operator string() const;
	void Init_Random();
	float Write_number();
	float Drob_value();
	void Read_Matrix();
	const float Max_elem() const;
	const float Min_elem() const;
	void Add(Matrix&, Matrix&);
	void Expansion_Matrix(const int, const int);
	friend ostream& operator <<(ostream&, const Matrix&);
	friend istream& operator >>(istream&, Matrix&);

};

