#include "CardNumber.h"
CardNumber::CardNumber()
{
	numberPackage[0] = "1";
	numberPackage[1] = "Ȱ��";
	numberPackage[2] = "3";
	numberPackage[3] = "4";
	numberPackage[4] = "5";
	numberPackage[5] = "6";
	numberPackage[6] = "7";
	numberPackage[7] = "8";
	numberPackage[8] = "9";
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
