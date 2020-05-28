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

void CardPackage::test2()//saber
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
void CardPackage::test1()
{
	cout << "选择你要鼓舞的城池：" << endl;
	City* temp = &findCity();//使用指针，修改那个目标城市数据
	cout << "test function 1";
	(*temp).adjustTroops(1.2);//兵力变为原来的1.2倍
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