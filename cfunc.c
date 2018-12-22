#include "cfunc.h"

/*---------------------------------------------------------
//Работа с файломи без использование потоков ввода, вывода.
---------------------------------------------------------*/


/*-----------------------------------------
Функции С
-----------------------------------------*/


//Открытие файла с размерами массива
szMs cMasSizeF(char *szNameFl)
{
	szMs szMass;
	FILE *sf;
	if( (sf = fopen(szNameFl, "r")) == NULL)
	{
		printf("ERROR!!! Не удалось открыть файл!\n");
		system("pause");
		exit(-1);
	}
	else
	{
		fscanf(sf,"%d%d", &szMass.height, &szMass.width);
		fclose(sf);
		return szMass;
	}
}


//Заполнение массива случайными числами из диапазона
void CFillingMassRand(void)
{
	char NameFlSize[255];
	cout << "Введите имя файла содержащее размер массива: ";
	cin >> NameFlSize;
	szMs MassSize = cmasSizeF(NameFlSize);
	
	char NameFl[255];
	cout << "Введите имя файла массива: ";
	cin >> NameFl;
	cout << "Введите максимальное, а затем минимальное значение элементов: ";
	int rMax = 0, rMin = 0;
	cin >> rMax >> rMin;
	
	
	ofstream FMass(NameFl);
	if(!FMass.is_open())
	{
		cout << "Данный фаил невозможно открыть для записи!" << endl;
		system("pause");
		exit(-1);
	}
	
	for(int counter = 0; counter < MassSize.height; counter ++)
	{
		for(int cntr = 0; cntr < MassSize.width; cntr++)
		{
			FMass << (rMin) + rand() % ((rMax + 1) - rMin)  << "\t";
		}
		FMass << endl;
	}
	cout << "Фаил создан." << endl;
	FMass.close();
}
