#pragma once

class Cursor
{
	private:
		unsigned int Gor,   //  �����������
			     Ver,   //   ���������
		         x,   // ������� ����� �� ����������
			     y;   // ������� ����� �� ��������
	public:
		void Expansion();
		void Print_Monitor();
		void change_X_Y(const int Gor, const int Ver_pix, const int x, const int y);
		void �heck();
		bool Init(int x, int y);
		void Display() const;
		void Read();
};

