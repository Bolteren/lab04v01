#include "func.hpp"
/*class szMass
{
	public:
		int Length;
		int Windth;
};*/


szMs masSizeF(char *szNameFl)
{
	setlocale(LC_ALL,"Russian");
	szMs szMass;
	std::ifstream fileSize(szNameFl);
	if (!fileSize.is_open())
	{
		std::cout << "Данный файл не может быть открыт!" << std::endl;
		exit(-1);
	}
	else
	{
		fileSize >> szMass.height >> szMass.width;
		fileSize.close();
		return szMass;
	}
}
