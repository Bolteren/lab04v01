#include "func.hpp"

using namespace std;

void menu1(void);

int main() 
{
	setlocale(LC_ALL,"Russian");
	
	testMass();
	
	return 0;
}

void menu1(void)
{
	char szNameFile[255];
	cout << "ֲגוהטעו טלÿ פאיכא: ";
	cin >> szNameFile;
	szMs sizMas = masSizeF(szNameFile);
	cout << sizMas.height << " " << sizMas.width << endl;
}
