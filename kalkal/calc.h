#ifndef CALC_H
#define CALC_H

#include <windows.h>

typedef unsigned int ui;
// Класс поля ввода
class CalcEdit {
private:
	HWND Edit;
	char* str;
	ui lenght;
public:
	CalcEdit();
	CalcEdit(HWND parent, HINSTANCE hInst, int x, int y, int width, int height);
	
	void  SetText(const char *s);
	char* GetText();
	void  AddSymbol(const char *symbol);
	void  Clear();	
	
	~CalcEdit();
};
// Класс кнопок ввода
class CalcButton {
private:
	HWND Button;
	unsigned short ID;	
public:
	CalcButton();
	CalcButton(HWND parent, HINSTANCE hInst, char *name, unsigned short id, int x, int y, int width, int height);
	
	~CalcButton();	
};

#endif
