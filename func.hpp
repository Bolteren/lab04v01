#include <iostream>
#include <fstream>
#include <windows.h>
#include <ctime>

class szMs
{
	public:
		int height;//������
		int width;//������
};
szMs masSizeF(char *szNameFl);
void FillingMassRand(void);
void FillingMassManual(void);
void testMass(void);
void printMass(char *szNameFl, char *massNameFl);
void editSizeF(char *szNameFl);
