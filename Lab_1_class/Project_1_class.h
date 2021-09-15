#pragma once

class Cursor
{
	private:
		unsigned int Gor,   //  горизонталь
			     Ver,   //   вертикаль
		         x,   // позиція точки по горизонталі
			     y;   // позиція точки по вертикалі
	public:
		void Expansion();
		void Print_Monitor();
		void change_X_Y(const int Gor, const int Ver_pix, const int x, const int y);
		void Сheck();
		bool Init(int x, int y);
		void Display() const;
		void Read();
};

