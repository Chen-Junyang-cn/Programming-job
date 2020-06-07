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
	numberPackage[8] = "弓箭手";
	numberPackage[9] = "势如破竹";
	numberPackage[10] = "突袭";
}

int CardNumber::findNumber(string name)
{
	for (int i = 0; i <= 10; i++)//卡牌共11张
	{
		if (name == numberPackage[i])
		{
			return i;
		}
	}
	return -1;	//没有找到相应的卡牌
}

string CardNumber::getRandName()
{
	int ran = rand() % 11;
	return numberPackage[ran];
}
