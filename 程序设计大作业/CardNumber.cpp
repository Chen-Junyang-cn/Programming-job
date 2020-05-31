#include "CardNumber.h"
CardNumber::CardNumber()
{
	numberPackage[0] = "骑兵";
	numberPackage[1] = "破釜沉舟";
	numberPackage[2] = "反间计";
	numberPackage[3] = "贤者之心";
	numberPackage[4] = "养精蓄锐";
	numberPackage[5] = "战车";
	numberPackage[6] = "步兵";
	numberPackage[7] = "枪兵";
	numberPackage[8] = "弓箭手";//
	numberPackage[9] = "10";
}

int CardNumber::findNumber(string name)
{
	//int number;
	for (int i = 0; i < 10; i++)//这里的编码包暂时设置为10
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
