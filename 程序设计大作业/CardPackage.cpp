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
	City* temp = &findCity();
	City* temp_attack = &findCity();
	City injure(500);//伤害临时
	City change(400);//兵力变化临时
	*temp_attack -= injure;
	cout << temp->checkBelong() << "使用'saber'对" << temp_attack->checkBelong();
	cout << "造成了500点伤害" << endl;
	*temp += change;
	temp->show();
}
void CardPackage::test2()//破釜沉舟
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	double record = temp->army();
	if (temp->checkBelong() == "刘邦") temp->adjustTroops(1.5);
	else temp_attack->adjustTroops(2);
	temp_attack->army() > temp->army() ? temp->adjustTroops(1.5) : temp->adjustTroops(1);
	temp_attack->army() > 2 * temp->army() ? temp->adjustTroops(1.2) : temp->adjustTroops(1);
	int difference = temp->army() - record;//差值
	//需再定义一个变量记录回合//返回一个差值再下一会合减去
	temp->show();
}
void CardPackage::test3()//反间计
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if(temp->checkBelong()=="项羽") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	string seize; Node* i; int j;
	cout << Ctemp_attack->findhead() << "的卡牌有：";
	for (i = Ctemp_attack->findhead(), j = 0; i != nullptr; i = i->next, j++) {//对手卡牌展示
		cout << i->name << "  ";//对方卡牌名字
	}
		cout << "请输入要入手的（对方）卡牌";
		cin >> seize;
		for (i = Ctemp_attack->findhead(); i != nullptr; i = i->next)//反间抢夺卡牌
		{
			if (i->next->name == seize)
			{
				Node* d = i->next;
				i->next = i->next->next;//对方删除卡牌
				delete d;
				Node* x = new Node;
				x->name = seize;
				x->next = Ctemp->findhead()->next;//己方插入卡牌
				Ctemp->findhead()->next = x;//好像不是左值，如果不行必须另设函数
				break;
			}
		}
		if (i->next == nullptr) {
			cout << temp_attack->checkBelong() << "无此牌" << endl;
			cout << "请重新输入：" << endl;
			CardPackage::test3();//重新执行函数
		}
	temp->show();
}
void CardPackage::test4()//贤者之心
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	if (temp->checkBelong() == "刘邦") {
		cardsL.insertCard(); cardsL.insertCard();//随机插入卡牌
	}
	else { cardsX.insertCard(); cardsX.insertCard(); }
	temp->show();
}
void CardPackage::test5()//养精蓄锐
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if (temp->checkBelong() == "项羽") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	Node* i; int j; string strength[10], record[3];
	for (i = Ctemp->findhead(), j = 0; i != nullptr; i = i->next, j++) {
		strength[j] = i->name;
	}//己方卡牌组合成数组
	for (int k = 0; k < 3; k++) { 
		record[3] = strength[rand() % j]; cout << record[k]<<"  "; 
	}//随机抽选三张卡牌
	cout << endl;
	cout << "请选择卡牌（步兵、骑兵、战车加成较大）：" << endl;
	string select;//选择的卡牌
	cin >> select;
	for (i = Ctemp->findhead(), j = 0; i != nullptr; i = i->next, j++) //依据选择的卡牌进行兵力的增强
	{
		if (i->next->name == select) {
			if (select == "saber" || select == "chariot" || select == "infantry") {
				City change(1500);
				*temp += change;
				cout << temp->checkBelong() << "兵力增强了1500" << endl;
			}
			else {
				City change(500);
				*temp += change;
				cout << temp->checkBelong() << "兵力增强了500" << endl;
			}
		}
	}
	if (i == nullptr) {
		cout << temp->checkBelong() << "无此卡牌，请重新输入：";
		CardPackage::test5();
	}
	temp->show();
}
void CardPackage::test3()//战车//群攻
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if (temp->checkBelong() == "项羽") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	Node* i; int j;
	for (i = Ctemp_attack->findhead(), j = 0; i != nullptr; i = i->next, j++) {}
	City change(100 * j);//cards检索对方卡牌数量//攻击力设定
	*temp -= change;
	cout << temp->checkBelong() << "兵力增强了" << 100 * j << endl;
	temp->show();
}
void CardPackage::test3()//步兵
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	City change(1200);
	*temp += change;
	cout << temp->checkBelong() << "兵力增强了1200" << endl;
	temp->show();
}
void CardPackage::test3()//枪兵/暂无回合设定，战力减少
{
	City *temp = &findCity();
	City *temp_attack = &findCity();
	City change(700);
	*temp += change;
	cout << temp->checkBelong() << "兵力增强了700" << endl;
	temp->show();
}
void CardPackage::test3()//弓箭手
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	City* M = &findCity();
	int n = 1000;
	if (M->checkBelong() == temp->checkBelong()) {
		n += 700;
	}
	else n -= 300;
	City change(n);
	*temp += change;
	cout << temp->checkBelong() << "兵力增强了" <<n<< endl;
	temp->show();
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