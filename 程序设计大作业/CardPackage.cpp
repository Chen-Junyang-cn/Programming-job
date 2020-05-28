#include "CardPackage.h"
#include "City.h"

CardPackage::CardPackage()
{
	test[0] = &CardPackage::test1;
	test[1] = &CardPackage::test2;
	test[2] = &CardPackage::test3;
	test[3] = &CardPackage::test4;
	test[4] = &CardPackage::test5;
	test[5] = &CardPackage::test6;
	test[6] = &CardPackage::test7;
	test[7] = &CardPackage::test8;
	test[8] = &CardPackage::test9;
	test[9] = &CardPackage::test10;
}

void CardPackage::test1()//saber
{
	City *temp=&findCity();
	City *temp_attack = &findCity();
	/*temp_attack->changeTroops(bool )
	cout << "'saber'对";
	if (temp.belong == "L")cout << "刘邦"; else cout << "项羽";
	cout << "造成了500点伤害" << endl;
	temp.troops += 200;
	temp.show();*/
}
void CardPackage::test2()//破釜沉舟
{
	City temp = findCity();
	City temp_attack = findCity();
	int record = temp.troops;
	if (temp.belong == "L") {
		temp.troops = temp_attack.troops > temp.troops ? temp.troops * 1.5 : temp.troops;
		temp.troops = temp_attack.troops > 2 * temp.troops ? temp.troops * 1.5 : temp.troops;
	}
	int difference = temp.troops - record;//差值
	//需再定义一个变量记录回合//返回一个差值再下一会合减去
	temp.show();
}
void CardPackage::test3()//反间计
{
	City temp = findCity();
	City temp_attack = findCity();

	temp.show();
}
void CardPackage::test3()//贤者之心
{
	City temp = findCity();
	City temp_attack = findCity();
	if (temp.belong == "L") {
		cardsL.insertCard(); cardsL.insertCard();
	}
	else { cardsX.insertCard(); cardsX.insertCard(); }
	temp.show();
}
void CardPackage::test3()//养精蓄锐
{
	City temp = findCity();
	City temp_attack = findCity();
	if (temp.belong == "L")
		cards.//访问类链表
	else
		temp.show();
}
void CardPackage::test3()//战车//群攻
{
	City* temp = &findCity();
	City temp_attack = findCity();
	//cards检索对方卡牌数量//攻击力设定
	temp.troops += 100;
	temp.show();
}
void CardPackage::test3()//步兵
{
	City temp = findCity();
	City temp_attack = findCity();
	temp.troops += 500;
	temp.show();
}
void CardPackage::test3()//枪兵
{
	City temp = findCity();
	City temp_attack = findCity();
	temp.troops += 500;
	temp.show();
}
void CardPackage::test3()//陷阱
{
	City temp = findCity();
	City temp_attack = findCity();
	temp.troops += 500;
	//fight函数内                                                             
	temp.show();
}

City& CardPackage::findCity()
{
	string target;
	cin >> target;
	if (target == "刘邦")
	{
		return cityL;
	}
	else if (target == "项羽")
	{
		return cityX;
	}
	return cityMid;
}