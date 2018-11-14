#include "func.hpp"

using namespace std;
/*class szMass
{
	public:
		int Length;
		int Windth;
};*/
//�������� ����� � ��������� �������
szMs masSizeF(char *szNameFl)
{
	szMs szMass;
	ifstream fileSize(szNameFl);
	if (!fileSize.is_open())
	{
		cout << "������ ���� �� ����� ���� ������!" << endl;
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
//���������� ������� ���������� ������� �� ���������
void FillingMassRand(void)
{
	char NameFlSize[255];
	cout << "������� ��� ����� ���������� ������ �������: ";
	cin >> NameFlSize;
	szMs MassSize = masSizeF(NameFlSize);
	
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
//������ ���������� �������
void FillingMassManual(void)
{
	char NameFlSize[255];
	cout << "������� ��� ����� ���������� ������ �������: ";
	cin >> NameFlSize;
	szMs MassSize = masSizeF(NameFlSize);
	char NameFl[255];
	cout << "������� ��� ����� �������: ";
	cin >> NameFl;
	ofstream FMass(NameFl);
	if(!FMass.is_open())
	{
		cout << "������ ���� ���������� ������� ��� ������!" << endl;
		system("pause");
		exit(-1);
	}
	cout << "������� �������� ������� (�� ��������� � ���������� �������� �����): ";
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
	cout << endl << "�������� ����� ���������." << endl;
	FMass.close();
}
//�������� ������� � ��� ��������
void testMass(void)
{
	char NameFlSize[255];
	cout << "������� ��� ����� ���������� ������ �������: ";
	cin >> NameFlSize;
	szMs MassSize = masSizeF(NameFlSize);
	int **mass;
	mass = new int*[MassSize.height];
	for(int counter = 0; counter < MassSize.height; counter++)//�������� �������.
	{
		mass[counter] = new int[MassSize.width];
	}
	
	
	
	for(int counter = 0; counter < MassSize.height; counter++)//������� ������.
	{
		delete[]mass[counter];
		mass[counter] = NULL;
	}
	delete[]mass;
	mass = NULL;
}
