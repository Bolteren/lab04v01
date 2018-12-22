#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>
#include <stdio.h>
#include <conio.h>


class szMs
{
	public:
		int height;//высота
		int width;//Ўирина
};

//–јбота с файлами использу€ поточный ввод и вывод.
szMs masSizeF(char *szNameFl);
void FillingMassRand(void);
void FillingMassManual(void);
void testMass(void);
void printMass(char *szNameFl, char *massNameFl);
void editSizeF(char *szNameFl);

