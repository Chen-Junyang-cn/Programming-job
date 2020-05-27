#include "City.h"
City::City(const string s)
{
	troops = 1000;
	belong = s;
	distance = 3;
}
void City::fight()
{
	cout << "选择你要出兵的城池" << endl;	//选择城池阶段
	City* c1 = &CardPackage::findCity();
	while (c1->belong != belong)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		c1 = &CardPackage::findCity();
	}
	cout << "选择军队目标的城池（选择己方城池可屯兵）" << endl;
	City* c2 = &CardPackage::findCity();//使用卡包中寻找城市的功能
	/*while (c1->distance < c2->distance) //攻击距离不够
	{
		cout << "你的军队无法直接到达该城池，请重新选择" << endl;
		c2 = &CardPackage::findCity();
	}*/
	int c1Num = selectTroops();	//选择出兵数量阶段
	while (c1Num >= c1->troops)
	{
		cout << "你的兵力不足，请重新选择" << endl;
		c1Num = selectTroops();
	}
	c1->troops -= c1Num;
	if (c1->belong == c2->belong) // 战斗判定阶段
	{
		cout << "你已选择屯兵，战斗回合结束" << endl;
		if (c1 == c2)//屯兵于当前城池，兵力不会变动
			return;
		c2->troops += c1Num;
	}
	if (c1Num > c2->troops)	//c1兵力占优
	{
		c2->belong = belong;//c2被占领
		c2->troops -= c1Num;
		c1->distance++;		//占领城池，攻击距离增加
		c2->distance++;		//c2被占领
	}
	else if (c1->troops == c2->troops)//兵力相同
	{
		c2->belong = "中立";		//城池中立
		c2->troops = 0;
	}
	else
	{
		c2->troops -= c1Num;
	}
}

void City::show()
{
	cout << "城池剩余兵力：" << troops << "城池的归属：" << belong << endl;
}

void City::adjustTroops(double ratio)
{
	troops *= ratio;
}

string City::checkBelong()
{
	return belong;
}

int City::selectTroops()
{
	cout << "选择派出军队的数量" << endl;
	int num = 0;
	cin >> num;
	return num;
}

bool City::judge()
{
	if (troops > 0)
		return true;
	return false;
}

int City::changeTroops(bool flag, int change)
{
	if (flag == 0) {
		troops -= change;
	}
	else troops += change;
	return troops;
}