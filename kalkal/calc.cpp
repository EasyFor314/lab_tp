#include "calc.h"
#include <cstring>

CalcEdit::CalcEdit()
{
	Edit = NULL;
	str  = NULL;
	lenght = 0;
}
// �������� ���� ����� 
CalcEdit::CalcEdit(HWND parent, HINSTANCE hInst, int x, int y, int width, int height)
{
	Edit = CreateWindowEx(0, "EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY | ES_RIGHT,
        	x, // ���������� �
			y, // ���������� y
			width, // ������
			height, // ������
			parent, NULL, hInst, NULL);
	
/*	str = new char[2];
	str[0] = '0';
	str[1] = '\0';
	lenght = 1;*/
	str = NULL;
	lenght = 0;
}
// ���������� ����� � ����
void CalcEdit::SetText(const char* s)
{
	// ������� ����
	delete[] this->str;
	lenght = strlen(s);
	// �������� ��������� ��������  S
	str = new char[lenght + 1];
	for (ui i(0); i < lenght; i++)
		str[i] = s[i];
	str[lenght] = '\0';
	// ���������� �������� str � ����
	SetWindowText(Edit, str);
}
// �������� ����� �� ����
char* CalcEdit::GetText() 
{
	return str;
}
// �������� ������ � ����� ����
void CalcEdit::AddSymbol(const char *symbol)
{
	// �������� ������� �������� ���� � ����� ������
	char* str_copy = new char[lenght];
	for (ui i(0); i < lenght; i++)
		str_copy[i] = str[i];
	// ������� ������
	delete[] this->str;
	lenght = lenght + 1;
	str = new char[lenght+1];
	// �������� ���� =  ����� ������ + ������
	for (ui i(0); i < lenght-1; i++)
		str[i] = str_copy[i];
	str[lenght-1] = symbol[0];
	str[lenght]   = '\0';
	delete[] str_copy;
	// ���������� �������� str � ����
	SetWindowText(Edit, str);
}
// �������� ���� �����
void CalcEdit::Clear()
{
	// ������� ������
	delete[] this->str;
	str = NULL;
	lenght = 0;
	// ���������� �������� str � ����
	SetWindowText(Edit, str);
}
// ���������� - ������� ������.
CalcEdit::~CalcEdit()
{
	delete[] str;
}



CalcButton::CalcButton()
{
	Button = NULL;
	ID = 0;
}

CalcButton::CalcButton(HWND parent, HINSTANCE hInst, char* name, unsigned short id, int x, int y, int width, int height)
{
	ID = id;
	// �������� ������ �� ���������� ���������.
	Button = CreateWindowEx(0, "BUTTON", name, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        		x, // ���������� �
				y, // ���������� y
				width, // ������
				height, // ������
				parent, (HMENU)id, hInst, NULL);
}


CalcButton::~CalcButton()
{
}
