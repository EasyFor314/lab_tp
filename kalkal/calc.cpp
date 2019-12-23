#include "calc.h"
#include <cstring>

CalcEdit::CalcEdit()
{
	Edit = NULL;
	str  = NULL;
	lenght = 0;
}
// Создание поля ввода 
CalcEdit::CalcEdit(HWND parent, HINSTANCE hInst, int x, int y, int width, int height)
{
	Edit = CreateWindowEx(0, "EDIT", "", WS_VISIBLE | WS_CHILD | WS_BORDER | ES_READONLY | ES_RIGHT,
        	x, // координата х
			y, // координата y
			width, // ширина
			height, // высота
			parent, NULL, hInst, NULL);
	
/*	str = new char[2];
	str[0] = '0';
	str[1] = '\0';
	lenght = 1;*/
	str = NULL;
	lenght = 0;
}
// Установить текст в поле
void CalcEdit::SetText(const char* s)
{
	// Очистим поле
	delete[] this->str;
	lenght = strlen(s);
	// Заполним полученно строкойм  S
	str = new char[lenght + 1];
	for (ui i(0); i < lenght; i++)
		str[i] = s[i];
	str[lenght] = '\0';
	// установить значения str у поля
	SetWindowText(Edit, str);
}
// Получить текст из поля
char* CalcEdit::GetText() 
{
	return str;
}
// Добавить символ в конец поля
void CalcEdit::AddSymbol(const char *symbol)
{
	// Сохраним текущее значения поля в копию строки
	char* str_copy = new char[lenght];
	for (ui i(0); i < lenght; i++)
		str_copy[i] = str[i];
	// очистим строку
	delete[] this->str;
	lenght = lenght + 1;
	str = new char[lenght+1];
	// Заполним поле =  копию строки + символ
	for (ui i(0); i < lenght-1; i++)
		str[i] = str_copy[i];
	str[lenght-1] = symbol[0];
	str[lenght]   = '\0';
	delete[] str_copy;
	// установить значения str у поля
	SetWindowText(Edit, str);
}
// Очистить поле ввода
void CalcEdit::Clear()
{
	// Обнулим строку
	delete[] this->str;
	str = NULL;
	lenght = 0;
	// установить значения str у поля
	SetWindowText(Edit, str);
}
// Деструктор - очищает память.
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
	// Создадим кнопку по полученным значениям.
	Button = CreateWindowEx(0, "BUTTON", name, WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        		x, // координата х
				y, // координата y
				width, // ширина
				height, // высота
				parent, (HMENU)id, hInst, NULL);
}


CalcButton::~CalcButton()
{
}
