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
		// �������� ��������� � ����������� params
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
				// ������� ���������� �����
				if(fgetc(f)=='\n') size++;
			}
			fclose(f);
			// �������������� ��������� ������������ size
			mas = new params[size];
			mas1 = new params*[size];
			mas2 = new params*[size];
			// ������� ������� ��� �����, �������� h
			buff = (char*)malloc(h);
		}

		void zapolnenie()
		{
			f = fopen("KrMas.csv", "r+");
			while(!feof(f))
			{
				// ���������� �������� � ����� 
				fread(buff, 1, h, f);
			}	
			fclose(f);	
			int n = 0, s = 0, k = 0;
			// ���������� �������� � buff_of, ���� �� ����� �� ����� �������. 
			for(int i = 0;i<strlen(buff);i++)
			{
				switch(buff[i])
				{
					case ';':
						{
							if (n==0) 
							{
								// 1 ��������� ��������� ���������� X
								mas[k].x = atof(buff_of);
							} 
							else 
							{
								// 2 ��������� ��������� ���������� Y
								mas[k].y = atof(buff_of);
							}
							// �������� �������� ������
							memset( buff_of, 0, sizeof(buff_of) );
							n++;
							s=0;
							break;
						}
					case '\n':
						{
							// ����� �������� ����� ������ � ������ ������� ������ ������, �� �������� ���������
							mas[k].rad = atof(buff_of);
							// �������� �������� ������ � �������� ��������
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
				// ��������� ���������� �� ����� ��� ������ ���������
				mas[i].centr = sqrt(mas[i].x*mas[i].x + mas[i].y*mas[i].y);
				// �������� �� ��� ���������� ��������� ���������
				mas1[i] = &mas[i];
				mas2[i] = &mas[i];
			}
		}
		
		void showStruct(params *s)
		{
			printf("X:\t\t|  Y:\t\t|  ������:\t|  �� ������:\n");
			for(int i = 0; i<size; i++)
				printf("%lf\t|  %lf\t|  %lf\t|  %lf\n", s[i].x, s[i].y, s[i].rad, s[i].centr);
		}
		
		void showStruct(params **s)
		{
			printf("X:\t\t|  Y:\t\t|  ������:\t|  �� ������:\n");
			for(int i = 0; i<size; i++)
				printf("%lf\t|  %lf\t|  %lf\t|  %lf\n", s[i]->x, s[i]->y, s[i]->rad, s[i]->centr);
		}
		
		void showMass() 
		{
			printf("�������� ������:\n");
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
			// ��������� ���������, � ����������� �� ��������� �����.
			// mas1 - �� �����������, mas2 - �� ��������
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
			printf("\n�� �����������:\n");
			showStruct(mas1);
			printf("\n�� ��������:\n");
			showStruct(mas2);	
		}
		// ���������� ������, ��� ������� ������
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
		printf("������� 1 ��� ���������� �� X.\n");
		printf("������� 2 ��� ���������� �� Y.\n");
		printf("������� 3 ��� ���������� �� �������.\n");
		printf("������� 4 ��� ���������� �� ���������� �� ������.\n");
		printf("������� 5 ��� ���������� ������ ���������.\n");
		scanf("%d", &menu);
		// �������� ������ ������
		Native obj;
		// �������� �� �����
		obj.zapolnenie();
		switch(menu)
		{
			case 1:
				{
					printf("���������� �� X\n\n");
					// ��������� ������
					obj.showMass();
					// ������� ���������� 1 
					obj.sort(1);
					system("PAUSE");
					break;
				}
			case 2:
				{
					printf("���������� �� Y\n\n");
					// ��������� ������
					obj.showMass();
					// ������� ���������� 2 
					obj.sort(2);
					system("PAUSE");
					break;
				}
			case 3:
				{
					printf("���������� �� �������\n\n");
					// ��������� ������
					obj.showMass();
					// ������� ���������� 3 
					obj.sort(3);
					system("PAUSE");
					break;
				}
			case 4:
				{
					printf("���������� �� ���������� �� ������ ��������� �� ������ ����������\n\n");
					// ��������� ������	
					obj.showMass();
					// ������� ���������� 4 
					obj.sort(4);
					system("PAUSE");
					break;
				}
			case 5:
				break;
			default:
				{
					printf("������ ������������ ����� ����.\n");
					system("PAUSE");
				}
		}
	}
	while(menu!=5);
	return 0;
}
