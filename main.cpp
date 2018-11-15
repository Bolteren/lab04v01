#include "func.hpp"

using namespace std;

void menu1(void);
void menu2(void);
void menu3(void);


int main() 
{
	setlocale(LC_ALL,"Russian");
	srand(time(NULL));
	menu3();
	
	return 0;
}

void menu1(void)
{
	char szNameFile[255];
	cout << "¬ведите им€ файла: ";
	cin >> szNameFile;
	szMs sizMas = masSizeF(szNameFile);
	cout << sizMas.height << " " << sizMas.width << endl;
}

void menu2(void)
{
	char szNameFile[255], fileNameMass[255];
	cout << "¬ведите файл размера: ";
	cin >>szNameFile;
	cout << "¬ведите название файла с данными: ";
	cin >> fileNameMass;
	printMass(szNameFile, fileNameMass);
}
void menu3(void)
{
	cout << "¬ведите им€ файла с размером массива: ";
	char nameFile[255];
	cin >> nameFile;
	editSizeF(nameFile);
}
