#include "func.hpp"

using namespace std;

int main() 
{
	setlocale(LC_ALL,"Russian");
	char szNameFile[255];
	cout << "ֲגוהטעו טלÿ פאיכא: ";
	cin >> szNameFile;
	szMs sizMas = masSizeF(szNameFile);
	cout << sizMas.height << " " << sizMas.width << endl;
	return 0;
}
