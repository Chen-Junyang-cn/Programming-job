#include "CardNumber.h"
CardNumber::CardNumber()
{
	numberPackage[0] = "���";
	numberPackage[1] = "�Ƹ�����";
	numberPackage[2] = "�����";
	numberPackage[3] = "����֮��";
	numberPackage[4] = "��������";
	numberPackage[5] = "ս��";
	numberPackage[6] = "����";
	numberPackage[7] = "ǹ��";
	numberPackage[8] = "������";//
	numberPackage[9] = "10";
}

int CardNumber::findNumber(string name)
{
	//int number;
	for (int i = 0; i < 10; i++)//����ı������ʱ����Ϊ10
	{
		if (name == numberPackage[i])
		{
			return i;
		}
	}
	return 0;
}

string CardNumber::getRandName()
{
	int ran = rand() % 10;
	return numberPackage[ran];
}
