#include "calc.h"
#include <iostream>
#include <cmath>

// Константы числовых кнопок калькулятора
#define ID_BUTTON_ZERO  10
#define ID_BUTTON_ONE   11
#define ID_BUTTON_TWO   12
#define ID_BUTTON_THREE 13
#define ID_BUTTON_FOUR  14
#define ID_BUTTON_FIVE  15
#define ID_BUTTON_SIX   16
#define ID_BUTTON_SEVEN 17
#define ID_BUTTON_EIGHT 18
#define ID_BUTTON_NINE  19

// Константы числовых операций и дополнительных кнопок
#define ID_BUTTON_ADDITION       20
#define ID_BUTTON_SUBTRACTION    21
#define ID_BUTTON_MULTIPLICATION 22
#define ID_BUTTON_DIVISION       23
#define ID_BUTTON_EQUAL          24
#define ID_BUTTON_CE 			 25
#define ID_BUTTON_C 			 26
#define ID_BUTTON_DOT            27
// Создадим поле для изменений
CalcEdit   *edit_1;
// Создадим указатели кнопок клавиатуры
CalcButton *button_0,   *button_1,   *button_2,
		   *button_3,   *button_4,   *button_5,
		   *button_6,   *button_7,   *button_8,
		   *button_9,   *button_C,   *button_CE,
		   *button_add, *button_sub, *button_mul,
		   *button_div, *button_eq,  *button_dot;
double a, b;
char operation = '0';
char rezultString[100];
char* number;

// Инициализируем кнопки
void Init_Buttons(HWND &hwnd, HINSTANCE &hInstance)
{
	
	button_dot = new CalcButton(hwnd, hInstance, ".",  ID_BUTTON_DOT,            0,   327,  65, 45);		
	button_0   = new CalcButton(hwnd, hInstance, "0",  ID_BUTTON_ZERO,           65,  327, 130, 45);
	button_eq  = new CalcButton(hwnd, hInstance, "=",  ID_BUTTON_EQUAL,          195, 282,  65, 90);
	button_7   = new CalcButton(hwnd, hInstance, "7",  ID_BUTTON_SEVEN,          0,   282,  65, 45);
	button_8   = new CalcButton(hwnd, hInstance, "8",  ID_BUTTON_EIGHT,          65,  282,  65, 45);		
	button_9   = new CalcButton(hwnd, hInstance, "9",  ID_BUTTON_NINE,           130, 282,  65, 45);	
	button_4   = new CalcButton(hwnd, hInstance, "4",  ID_BUTTON_FOUR,           0,   237,  65, 45);	
	button_5   = new CalcButton(hwnd, hInstance, "5",  ID_BUTTON_FIVE,           65,  237,  65, 45);	
	button_6   = new CalcButton(hwnd, hInstance, "6",  ID_BUTTON_SIX,            130, 237,  65, 45);	
	button_sub = new CalcButton(hwnd, hInstance, "-",  ID_BUTTON_SUBTRACTION,    195, 237,  65, 45);	
	button_1   = new CalcButton(hwnd, hInstance, "1",  ID_BUTTON_ONE,            0,   192,  65, 45);	
	button_2   = new CalcButton(hwnd, hInstance, "2",  ID_BUTTON_TWO,            65,  192,  65, 45);	
	button_3   = new CalcButton(hwnd, hInstance, "3",  ID_BUTTON_THREE,          130, 192,  65, 45);	
	button_add = new CalcButton(hwnd, hInstance, "+",  ID_BUTTON_ADDITION,       195, 192,  65, 45);	
	button_C   = new CalcButton(hwnd, hInstance, "C",  ID_BUTTON_C,              0,   147,  65, 45);	
	button_CE  = new CalcButton(hwnd, hInstance, "CE", ID_BUTTON_CE,             65,  147,  65, 45);	
	button_mul = new CalcButton(hwnd, hInstance, "*",  ID_BUTTON_MULTIPLICATION, 130, 147,  65, 45);	
	button_div = new CalcButton(hwnd, hInstance, "/",  ID_BUTTON_DIVISION,       195, 147,  65, 45);			
}
// Событие нажатия на кнопку 
void On_ButtonClick(unsigned short indent)
{
	// Получим значения из поля
	number = edit_1->GetText();
	static bool InputDot = false;
	static bool InputRezult = false;
	switch(indent)
	{
		case ID_BUTTON_ZERO: {
			if(InputRezult){
				operation = '0';
				InputRezult = false;
			}
			// Добавим символ 0 в поле для ввода
			if(number[0] != '0' && !InputDot)
				edit_1->AddSymbol("0");
			else if(InputDot)
				edit_1->AddSymbol("0");
			break;
		}
		
		case ID_BUTTON_ONE: {
			if(InputRezult){
				operation = '0';
				InputRezult = false;
			}
			// Добавим символ 1 в поле для ввода
			if(number[0] == '0' && !InputDot){
				edit_1->Clear();
				edit_1->AddSymbol("1");
			}
			else 
				edit_1->AddSymbol("1");
			break;
		}
		
		case ID_BUTTON_TWO: {
			if(InputRezult){
				operation = '0';
				InputRezult = false;
			}
			// Добавим символ 2 в поле для ввода
			if(number[0] == '0' && !InputDot){
				edit_1->Clear();
				edit_1->AddSymbol("2");
			}
			else
				edit_1->AddSymbol("2");
			break;
		}
		
		case ID_BUTTON_THREE: {
			if(InputRezult){
				operation = '0';
				InputRezult = false;
			}
			// Добавим символ 3 в поле для ввода
			if(number[0] == '0' && !InputDot){
				edit_1->Clear();
				edit_1->AddSymbol("3");
			}
			else
				edit_1->AddSymbol("3");
			break;
		}
		
		case ID_BUTTON_FOUR: {
			if(InputRezult){
				operation = '0';
				InputRezult = false;
			}
			// Добавим символ 4 в поле для ввода
			if(number[0] == '0' && !InputDot){
				edit_1->Clear();
				edit_1->AddSymbol("4");
			}
			else
				edit_1->AddSymbol("4");
			break;
		}
		
		case ID_BUTTON_FIVE: {
			if(InputRezult){
				operation = '0';
				InputRezult = false;
			}
			// Добавим символ 5 в поле для ввода
			if(number[0] == '0' && !InputDot){
				edit_1->Clear();
				edit_1->AddSymbol("5");
			}
			else
				edit_1->AddSymbol("5");
			break;
		}
		
		case ID_BUTTON_SIX: {
			if(InputRezult){
				operation = '0';
				InputRezult = false;
			}
			// Добавим символ 6 в поле для ввода
			if(number[0] == '0' && !InputDot){
				edit_1->Clear();
				edit_1->AddSymbol("6");
			}
			else
				edit_1->AddSymbol("6");
			break;
		}
		
		case ID_BUTTON_SEVEN: {
			if(InputRezult){
				operation = '0';
				InputRezult = false;
			}
			// Добавим символ 7 в поле для ввода
			if(number[0] == '0' && !InputDot){
				edit_1->Clear();
				edit_1->AddSymbol("7");
			}
			else
				edit_1->AddSymbol("7");
			break;
		}
		
		case ID_BUTTON_EIGHT: {
			if(InputRezult){
				operation = '0';
				InputRezult = false;
			}
			// Добавим символ 8 в поле для ввода
			if(number[0] == '0' && !InputDot){
				edit_1->Clear();
				edit_1->AddSymbol("8");
			}
			else
				edit_1->AddSymbol("8");
			break;
		}
		
		case ID_BUTTON_NINE: {
			if(InputRezult){
				operation = '0';
				InputRezult = false;
			}
			// Добавим символ 9 в поле для ввода
			if(number[0] == '0' && !InputDot){
				edit_1->Clear();
				edit_1->AddSymbol("9");
			}
			else
				edit_1->AddSymbol("9");
			break;
		}
		
		case ID_BUTTON_DOT: {
			// Добавим символ точки в поле для ввода, если он не был нажат ранее.
			if(!InputDot) {
				edit_1->AddSymbol(".");
				InputDot = true;
			}
			break;
		}
		
		case ID_BUTTON_C: {
			// Очистим поле для ввода и заполним 0
			edit_1->Clear();
			edit_1->AddSymbol("0");
			// Сбросим операцию и флаг наличия точки
			operation = '0';
			InputDot = false;
			break;
		}
		
		case ID_BUTTON_ADDITION: {
		
			if(operation == '0') {
				// Сохраним значение из поля ввода в переменную 
				a = atof(edit_1->GetText());				
				b = a;
				// Очистим поле для ввода, заполним 0 и сбросим флаги 
				edit_1->Clear();
				InputDot = false;
				edit_1->AddSymbol("0");
			}
			// Сохраним операцию
			operation = '+';
			break;
		}
		
		case ID_BUTTON_SUBTRACTION: {
			if(operation == '0') {
				a = atof(edit_1->GetText());
				b = a;
				edit_1->Clear();
				InputDot = false;
				edit_1->AddSymbol("0");
			}
			operation = '-';
			break;
		}
		
		case ID_BUTTON_MULTIPLICATION: {
			if(operation == '0') {
				a = atof(edit_1->GetText());
				b = a;
				edit_1->Clear();
				InputDot = false;
				edit_1->AddSymbol("0");
			}
			operation = '*';
			break;
		}
		
		case ID_BUTTON_DIVISION: {
			if(operation == '0') {
				a = atof(edit_1->GetText());
				b = a;
				edit_1->Clear();
				InputDot = false;
				edit_1->AddSymbol("0");
			}
			operation = '/';
			break;
		}
		// Кнопка равно
		case ID_BUTTON_EQUAL: {
			
			static double rezult;
			double fractpart, intpart;
			b = atof(edit_1->GetText());
			// Рассчеты в зависимости от выбранной операции
			switch(operation)
			{
				case '+': {
					rezult = a + b;
					break;
				}
				
				case '-': {
					rezult = a - b;
					break;
				}
				
				case '*': {
					rezult = a * b;
					break;
				}
				
				case '/': {
					rezult = a / b;
					break;
				}
			}
 
  			fractpart = modf(rezult , &intpart); // отделить дробную часть от целой
			if(fractpart == 0)
				sprintf(rezultString, "%.0f", rezult);
			else
				sprintf(rezultString, "%f", rezult);
			// Устанавливаем текст для поля ввода
		 	edit_1->SetText(rezultString);
		 	// Сбрасываем флаги
			InputDot = false;
			InputRezult = true;


			break;
		}

	}
}
// Удаление кнопок
void DeleteButtons()
{
	delete button_0;   
	delete button_1;   
	delete button_2;
	delete button_3;   
	delete button_4;   
	delete button_5;	   
	delete button_6;	   
	delete button_7;	      
	delete button_8;	   
	delete button_9;
	delete button_C;
	delete button_CE;
	delete button_add;
	delete button_sub;
	delete button_mul;
	delete button_div;
	delete button_eq;
	delete button_dot;
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	HFONT hFont;
	
	switch(Message) {
		case WM_CREATE: {

			break;
		}
		
		case WM_COMMAND: {
			// При нажатии на кнопку вызываем событие нажатия на кнопку
			On_ButtonClick(LOWORD(wParam));
			break;
		}
		
		case WM_DESTROY: {
			// При закрытие окна вызываем удаление кнопок
			DeleteButtons();
			PostQuitMessage(0);
			break;
		}
		
		
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

// Стандартсная инициализация окна WIN-API
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; 
	HWND hwnd; 
	MSG Msg; 

	
	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; 
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	
	
	wc.hbrBackground = (HBRUSH)(COLOR_HIGHLIGHTTEXT+1);
	wc.lpszClassName = "WindowClass";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); 
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); 

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	// Создаем окно 
	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","Calculator", WS_VISIBLE|WS_MINIMIZEBOX|WS_OVERLAPPED|WS_SYSMENU,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		270, /* width */
		405, /* height */
		NULL,NULL,hInstance,NULL);
	
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}
	// Создаем поле ввода
	edit_1 = new CalcEdit(hwnd, hInstance, 10, 50, 240, 21);
	edit_1->AddSymbol("0");
	// Создаем все кнопки
	Init_Buttons(hwnd, hInstance);

	while(GetMessage(&Msg, NULL, 0, 0) > 0) {  
		TranslateMessage(&Msg); 
		DispatchMessage(&Msg); 
	}
	
	return Msg.wParam;
}
