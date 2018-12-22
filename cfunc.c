#include "cfunc.h"

/*---------------------------------------------------------
//������ � ������� ��� ������������� ������� �����, ������.
---------------------------------------------------------*/


/*-----------------------------------------
������� �
-----------------------------------------*/


//�������� ����� � ��������� �������
szMs cMasSizeF(char *szNameFl)
{
	szMs szMass;
	FILE *sf;
	if( (sf = fopen(szNameFl, "r")) == NULL)
	{
		printf("ERROR!!! �� ������� ������� ����!\n");
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


//���������� ������� ���������� ������� �� ���������
void CFillingMassRand(void)
{
	char NameFlSize[255];
	cout << "������� ��� ����� ���������� ������ �������: ";
	cin >> NameFlSize;
	szMs MassSize = cmasSizeF(NameFlSize);
	
	char NameFl[255];
	cout << "������� ��� ����� �������: ";
	cin >> NameFl;
	cout << "������� ������������, � ����� ����������� �������� ���������: ";
	int rMax = 0, rMin = 0;
	cin >> rMax >> rMin;
	
	
	ofstream FMass(NameFl);
	if(!FMass.is_open())
	{
		cout << "������ ���� ���������� ������� ��� ������!" << endl;
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
	cout << "���� ������." << endl;
	FMass.close();
}
