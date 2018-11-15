#include "func.hpp"

using namespace std;

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
//������ �������
void printMass(char *szNameFl, char *massNameFl)
{
	cout << "Hell";
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
	cout << "������� ��� ����� ����������� ������ �������: ";
	char NameFlMass[255];
	cin >> NameFlMass;
	ifstream fileMass(NameFlMass);
	if (!fileMass.is_open())
	{
		cout << "������ ���� �� ����� ���� ������!" << endl;
		system("pause");
		exit(-1);
	}
	else
	{
		for(int counter = 0; counter < MassSize.height; counter++)
		{
			for(int num = 0; num < MassSize.width; num++)
			{
				fileMass >> mass[counter][num];
			}
		}
		fileMass.close();
	}	
	
	
	int tmpRows = MassSize.width / 2, tmpCols = MassSize.height / 2, ynum = 0;
		/*�������� ���������� ������� ����� */
		/* 1 0 0 0 1     �      	1 0 0 0 0 1
		   0 1 0 1 0			0 1 0 0 1 0
		   0 0 1 0 0			0 0 1 1 0 0
		   0 0 1 0 0			0 0 1 1 0 0
		*/
	int **massNor;
	massNor = new int*[MassSize.height];
/* ���-�� ������ � �����.*/


	for(int counter = 0; counter < MassSize.height; counter++)
	{
		massNor[counter] = new int [MassSize.width];
		for (int num = 0; num < MassSize.width; num++)
		{
			massNor[counter][num] = 0;
		}
	}
/*������ �� ����        -----------------------*/

	int ctrRows = 0, ctrRowsEnd = (MassSize.width - 1), ctrCols = 0, ctrColsEnd = (MassSize.height - 1);
	//rows = MassSize.width
	//cols = MassSize.height
	
	while (1)
		{
			if(MassSize.height > 2 || MassSize.width > 3)
			{
				if (MassSize.width % 2 != 0)//��� �� ������
				{
					if ((ctrCols < MassSize.height) && (ctrRows < MassSize.width / 2))
					{
						massNor[ctrCols][ctrRows] = 1;
						massNor[ctrCols][ctrRowsEnd] = 1;
						ctrCols++;
						ctrRows++;
						ctrColsEnd--;
						ctrRowsEnd--;
					}
					else if (ctrCols < MassSize.height)
					{
						massNor[ctrCols][MassSize.width / 2] = 1;
						ctrCols++;
						if (ynum < 2)
						{
							ynum++;
						}
					}
					else break;
					}
					else// ��� ������
					{
						if ((ctrCols < MassSize.height) && (ctrRows < MassSize.width / 2))
					{
						massNor[ctrCols][ctrRows] = 1;
						massNor[ctrCols][ctrRowsEnd] = 1;
						ctrCols++;
						ctrRows++;
						ctrColsEnd--;
						ctrRowsEnd--;
					}
					else if (ctrCols < MassSize.height)
					{
						massNor[ctrCols][MassSize.width / 2] = 1;
						massNor[ctrCols][(MassSize.width / 2) - 1] = 1;
						ctrCols++;
						if (ynum < 2)
						{
							ynum++;
						}
					}
					else break;
				}
			}
				else
				{
					ynum = -1;
					break;
				}
	}
		
		for(int counter = 0; counter < MassSize.height; counter++)
		{
			for(int num = 0; num < MassSize.width; num++)
			{
				if((massNor[counter][num] == 0))
				{
					if(mass[counter][num] != 0)
					{
						if(ynum > 0) ynum++;
					}
				}
				else
				{
					if(mass[counter][num] == 0)
					{
						if(ynum > 0) ynum++;
					}
				}
			}
		}
		int summ1 = 0, summ2 = 0;
			if(ynum != 2)
			{		
				int num = 0;
				if(MassSize.height <= MassSize.width)
				{
					for(int counter = 0; counter < MassSize.height; counter++)
					{
						summ1 = summ1 + mass[counter][counter];
					}
					for(int counter = (MassSize.height - 1); counter >= 0; counter--)
					{
						summ2 = summ2 + mass[counter][num];
						num++;
					}
					cout << endl << "����� ����� �� ������� ��������� ����� " << summ1 << endl << "����� �� ������� ��������� ����� " << summ2 << endl;
				}
				else
				{
					for(int counter = 0; counter < MassSize.width; counter++)
					{
						summ1 = summ1 + mass[counter][counter];
					}
					for(int counter = (MassSize.width - 1); counter >=0; counter--)
					{
						summ2 = summ2 + mass[counter][num];
						num++;
					}
					cout << endl << "����� ����� �� ������� ��������� ����� " << summ1 << endl <<"����� �� ������� ��������� ����� " << summ2 << endl;
				}
			}
			else
			{
				cout << "����� �������� Y ��������." << endl;
			}
			system("pause");
			system("cls");
			for (int counter = 0; counter < MassSize.height; counter++)
			{
				delete[]massNor[counter];
				massNor[counter] = NULL;
			}
			delete[]massNor;
		massNor = NULL;	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	for(int counter = 0; counter < MassSize.height; counter++)//������� ������.
	{
		delete[]mass[counter];
		mass[counter] = NULL;
	}
	delete[]mass;
	mass = NULL;
}
