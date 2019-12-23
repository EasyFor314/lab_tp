#include <iostream>
#include <cstdlib>
#include <string.h>
#include <math.h>

using namespace std;

class Native
{
	private:
		int  size;
		long h;
		char *buff, buff_of[20];
		FILE *f;
		// Создадим структуру с псевдонимом params
		typedef struct
		{
			double x;
			double y;
			double rad;
			double centr;
		} params;
		params *mas, **mas1, **mas2, *buff1;
	public:
		Native()
		{
			size = 0;
			f = fopen("KrMas.csv", "r+");
			while(!feof(f))
			{
				h = ftell(f);
				// Считаем количество строк
				if(fgetc(f)=='\n') size++;
			}
			fclose(f);
			// Инициализируем структуры размерностью size
			mas = new params[size];
			mas1 = new params*[size];
			mas2 = new params*[size];
			// Выделим паммять под буфер, размером h
			buff = (char*)malloc(h);
		}

		void zapolnenie()
		{
			f = fopen("KrMas.csv", "r+");
			while(!feof(f))
			{
				// Записываем значения в буфер 
				fread(buff, 1, h, f);
			}	
			fclose(f);	
			int n = 0, s = 0, k = 0;
			// Записываем значения в buff_of, пока не дошли до конца строчки. 
			for(int i = 0;i<strlen(buff);i++)
			{
				switch(buff[i])
				{
					case ';':
						{
							if (n==0) 
							{
								// 1 элементом храниться координата X
								mas[k].x = atof(buff_of);
							} 
							else 
							{
								// 2 элементом храниться координата Y
								mas[k].y = atof(buff_of);
							}
							// Обнуляем значения буфера
							memset( buff_of, 0, sizeof(buff_of) );
							n++;
							s=0;
							break;
						}
					case '\n':
						{
							// Когда достигли конца строки в буфере остался только Радиус, он хранится последний
							mas[k].rad = atof(buff_of);
							// Обнуляем значения буфера и счетчики значений
							memset( buff_of, 0, sizeof(buff_of) );
							n=0;
							s=0;
							k++;
							break;
						}
					default:
						{
							buff_of[s] = buff[i];
							s++;
						}
				}
			}
			for(int i = 0; i<size; i++) 
			{
				// Вычисляем расстояние до центр для каждой структуры
				mas[i].centr = sqrt(mas[i].x*mas[i].x + mas[i].y*mas[i].y);
				// Копируем их для сортировки упрощения сортироки
				mas1[i] = &mas[i];
				mas2[i] = &mas[i];
			}
		}
		
		void showStruct(params *s)
		{
			printf("X:\t\t|  Y:\t\t|  Радиус:\t|  До центра:\n");
			for(int i = 0; i<size; i++)
				printf("%lf\t|  %lf\t|  %lf\t|  %lf\n", s[i].x, s[i].y, s[i].rad, s[i].centr);
		}
		
		void showStruct(params **s)
		{
			printf("X:\t\t|  Y:\t\t|  Радиус:\t|  До центра:\n");
			for(int i = 0; i<size; i++)
				printf("%lf\t|  %lf\t|  %lf\t|  %lf\n", s[i]->x, s[i]->y, s[i]->rad, s[i]->centr);
		}
		
		void showMass() 
		{
			printf("Исходный массив:\n");
			showStruct(mas);
		}
		
		void swap(params *&massiv1, params *&massiv2)
		{
			buff1 = massiv1;
			massiv1 = massiv2;
			massiv2 = buff1;
		}
		
		void sort(int pr)
		{
			// Сортируем пузырьком, в зависимости от выбранной цифры.
			// mas1 - по возрастания, mas2 - по убыванию
			switch(pr)
			{
				case 1:
					{
						for(int i = 0; i<size; i++)
							for(int j = 0; j<size-1; j++)
							{
								if(mas1[j]->x>mas1[j+1]->x) swap(mas1[j], mas1[j+1]);
								if(mas2[j]->x<mas2[j+1]->x) swap(mas2[j], mas2[j+1]);
							}
						break;
					}
				case 2:
					{
						for(int i = 0; i<size; i++)
							for(int j = 0; j<size-1; j++)
							{
								if(mas1[j]->y>mas1[j+1]->y) swap(mas1[j], mas1[j+1]);
								if(mas2[j]->y<mas2[j+1]->y) swap(mas2[j], mas2[j+1]);
							}	
						break;
					}
				case 3:
					{
						for(int i = 0; i<size; i++)
							for(int j = 0; j<size-1; j++)
							{
								if(mas1[j]->rad>mas1[j+1]->rad) swap(mas1[j], mas1[j+1]);
								if(mas2[j]->rad<mas2[j+1]->rad) swap(mas2[j], mas2[j+1]);
							}
						break;
					}
				case 4:
					{
						for(int i = 0; i<size; i++)
							for(int j = 0; j<size-1; j++)
							{
								if(mas1[j]->centr>mas1[j+1]->centr) swap(mas1[j], mas1[j+1]);
								if(mas2[j]->centr<mas2[j+1]->centr) swap(mas2[j], mas2[j+1]);
							}
						break;
					}
			}
			printf("\nПО ВОЗРОСТАНИЮ:\n");
			showStruct(mas1);
			printf("\nПО УБЫВАНИЮ:\n");
			showStruct(mas2);	
		}
		// Деструктор класса, для очистки памяти
		~Native()
		{
			delete [] mas;
			delete [] mas1;
			delete [] mas2;
			free(buff);
		}
};

int main(int argc, char** argv) {
	
	setlocale(0,"Rus");
	
	int menu;
	do
	{
		system("cls");
		printf("Введите 1 для сортировки по X.\n");
		printf("Введите 2 для сортировки по Y.\n");
		printf("Введите 3 для сортировки по радиусу.\n");
		printf("Введите 4 для сортировки по расстоянию от центра.\n");
		printf("Введите 5 для завершения работы программы.\n");
		scanf("%d", &menu);
		// Создадим объект класса
		Native obj;
		// Заполним из файла
		obj.zapolnenie();
		switch(menu)
		{
			case 1:
				{
					printf("Сортировка по X\n\n");
					// Отобразим массив
					obj.showMass();
					// Вызовем сортировку 1 
					obj.sort(1);
					system("PAUSE");
					break;
				}
			case 2:
				{
					printf("Сортировка по Y\n\n");
					// Отобразим массив
					obj.showMass();
					// Вызовем сортировку 2 
					obj.sort(2);
					system("PAUSE");
					break;
				}
			case 3:
				{
					printf("Сортировка по радиусу\n\n");
					// Отобразим массив
					obj.showMass();
					// Вызовем сортировку 3 
					obj.sort(3);
					system("PAUSE");
					break;
				}
			case 4:
				{
					printf("Сортировка по расстоянию от начала координат до центра окружности\n\n");
					// Отобразим массив	
					obj.showMass();
					// Вызовем сортировку 4 
					obj.sort(4);
					system("PAUSE");
					break;
				}
			case 5:
				break;
			default:
				{
					printf("Выбран неправильный пункт меню.\n");
					system("PAUSE");
				}
		}
	}
	while(menu!=5);
	return 0;
}
