#include "func.hpp"

using namespace std;
/*class szMass
{
	public:
		int Length;
		int Windth;
};*/
//Открытие файла с размерами массива
szMs masSizeF(char *szNameFl)
{
	szMs szMass;
	ifstream fileSize(szNameFl);
	if (!fileSize.is_open())
	{
		cout << "Данный файл не может быть открыт!" << endl;
		system("pause");
		exit(-1);
	}
	else
	{
		fileSize >> szMass.height >> szMass.width;
		fileSize.close();
		return szMass;
	}
}
//Заполнение массива случайными числами из диапазона
void FillingMassRand(void)
{
	char NameFlSize[255];
	cout << "Введите имя файла содержащее размер массива: ";
	cin >> NameFlSize;
	szMs MassSize = masSizeF(NameFlSize);
	
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
//Ручное заполнение массива
void FillingMassManual(void)
{
	char NameFlSize[255];
	cout << "Введите имя файла содержащее размер массива: ";
	cin >> NameFlSize;
	szMs MassSize = masSizeF(NameFlSize);
	char NameFl[255];
	cout << "Введите имя файла массива: ";
	cin >> NameFl;
	ofstream FMass(NameFl);
	if(!FMass.is_open())
	{
		cout << "Данный фаил невозможно открыть для записи!" << endl;
		system("pause");
		exit(-1);
	}
	cout << "Вводите элементы массива (до сообщения о завершении создания файла): ";
	for(int counter = 0; counter < MassSize.height; counter ++)
	{
		for(int cntr = 0; cntr < MassSize.width; cntr++)
		{
			int temp;
			cin >> temp;
			FMass << temp << "\t";
		}
		FMass << endl;
	}
	cout << endl << "Создание файла завершено." << endl;
	FMass.close();
}
//открытие массива и его проверка
void testMass(void)
{
	char NameFlSize[255];
	cout << "Введите имя файла содержащее размер массива: ";
	cin >> NameFlSize;
	szMs MassSize = masSizeF(NameFlSize);
	int **mass;
	mass = new int*[MassSize.height];
	for(int counter = 0; counter < MassSize.height; counter++)//создание массива.
	{
		mass[counter] = new int[MassSize.width];
	}
	
	
	
	for(int counter = 0; counter < MassSize.height; counter++)//очистка памяти.
	{
		delete[]mass[counter];
		mass[counter] = NULL;
	}
	delete[]mass;
	mass = NULL;
}
