#include "CardPackage.h"
#include "City.h"
#include "Cards.h"
CardPackage::CardPackage()
{
	card[0] = &CardPackage::saber;
	card[1] = &CardPackage::beatback;
	card[2] = &CardPackage::discord;
	card[3] = &CardPackage::sage_model;
	card[4] = &CardPackage::recuperate;
	card[5] = &CardPackage::chariot;
	card[6] = &CardPackage::infantry;
	card[7] = &CardPackage::spearman;
	card[8] = &CardPackage::archer;
	card[9] = &CardPackage::feint;
	card[10] = &CardPackage::strike;
}

void CardPackage::saber()//骑兵
{
	cout << "选择你要出卡的城池" << endl;	//选择城池阶段
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp = &findCity();
	}
	cout << "选择对手的城池" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "刘邦")attack_name = "项羽";
	else attack_name = "刘邦";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "非敌方城池，请重新选择" << endl;
		temp_attack = &findCity();
	}
	City injure(500);//伤害临时
	City change(400);//兵力变化临时
	*temp_attack -= injure;
	cout << temp->checkBelong() << "使用'骑兵'对" << temp_attack->checkBelong();
	cout << "造成了500点伤害" << endl;
	*temp += change;
	temp->show();
}
void CardPackage::beatback()//破釜沉舟
{
	cout << "选择你要出卡的城池" << endl;	//选择城池阶段
	City* temp = &findCity();//选择己方城池阶段
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp = &findCity();
	}
	City* temp_attack;//选择对方城池阶段
	if (temp->checkBelong() == "刘邦")temp_attack = &cityX;
	else temp_attack = &cityL;
	double record = temp->army();//记录改变前兵力值
	if (temp->checkBelong() == "刘邦") {//根据双方兵力进行判断是否增强兵力
		temp_attack->army() > temp->army() ? temp->adjustTroops(1.5) : temp->adjustTroops(1);
		temp_attack->army() > 2 * temp->army() ? temp->adjustTroops(1.2) : temp->adjustTroops(1);
	}
	else temp_attack->army() > temp->army() ? temp->adjustTroops(1.7) : temp->adjustTroops(1);
	temp_attack->army() > 2 * temp->army() ? temp->adjustTroops(1.4) : temp->adjustTroops(1);
	if (temp->army() - record)cout << temp->checkBelong() << "使用‘破釜沉舟’" << "在本回合兵力增强了" << temp->army() - record << endl;
	else {
		cout << temp->checkBelong() << "使用‘破釜沉舟’" << "兵力无变化";
		cout << "，该回合后兵力减少一半" << endl;
	}
		temp->show();
}
void CardPackage::discord()//反间计
{
	cout << "选择你要出卡的城池" << endl;	//选择城池阶段
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp = &findCity();
	}
	cout << "选择对手的城池" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "刘邦")attack_name = "项羽";
	else attack_name = "刘邦";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp_attack = &findCity();
	}
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if(temp->checkBelong()=="项羽") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	string seize; Node* i; int j;
	cout << Ctemp_attack->findhead()->name << endl;
	cout << temp_attack->checkBelong() << "的卡牌有：";
	Cards::find_name = temp_attack->checkBelong();
	for (i = Ctemp_attack->findhead()->next, j = 0; i != nullptr; i = i->next, j++) {//对手卡牌展示
		cout << i->name << "  ";//对方卡牌名字
	}
	cout << "请输入要入手的（对方）卡牌" << endl;
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
	if (i == nullptr) {
		cout << temp_attack->checkBelong() << "无此牌" << endl;
		cout << "请重新输入：" << endl;
		CardPackage::discord();//重新执行函数
	}
	cout << temp->checkBelong() << "得到" << temp_attack->checkBelong() << "卡牌" << seize << endl;
	temp->show();
}
void CardPackage::sage_model()//贤者之心
{
	cout << "选择你要出卡的城池" << endl;	//选择城池阶段
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp = &findCity();
	}
	if (temp->checkBelong() == "刘邦") {
		cardsL.insertCard(); cardsL.insertCard();//随机插入卡牌
	}
	else { cardsX.insertCard(); cardsX.insertCard(); }
	temp->show();
}
void CardPackage::recuperate()//养精蓄锐
{
	cout << "选择你要出卡的城池" << endl;	//选择城池阶段
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp = &findCity();
	}
	cout << "选择对手的城池" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "刘邦")attack_name = "项羽";
	else attack_name = "刘邦";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp_attack = &findCity();
	}
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if (temp->checkBelong() == "项羽") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	Node* i; int j; string strength[10], record[3];
	for (i = Ctemp->findhead()->next, j = 0; i != nullptr; i = i->next, j++) {
		strength[j] = i->name;
	}//己方卡牌组合成数组
	for (int k = 0; k < 3; k++) { 
		record[k] = strength[rand() % j]; cout << record[k]<<"  "; 
	}//随机抽选三张卡牌
	cout << endl;
	cout << "请选择卡牌（步兵、骑兵、战车加成较大）：" << endl;
	string select;//选择的卡牌
	while (1) {
		cin >> select;
		for (i = Ctemp->findhead()->next, j = 0; i != nullptr; i = i->next, j++) //依据选择的卡牌进行兵力的增强
		{
			if (i->name == select) {
				if (select == "骑兵" || select == "战车" || select == "步兵") {
					City change(1500);
					*temp += change;
					cout << temp->checkBelong() << "使用‘养精蓄锐’使兵力增强了1500" << endl;
					temp->show();
					return;
				}
				else {
					City change(500);
					*temp += change;
					cout << temp->checkBelong() << "使用‘养精蓄锐’使兵力增强了500" << endl;
					temp->show();
					return;
				}
			}
		}
		if (i == nullptr) {
			cout << temp->checkBelong() << "无此卡牌，请重新输入：";
			continue;
		}
		
	}
}
void CardPackage::chariot()//战车//群攻
{
	cout << "选择你要出卡的城池" << endl;	//选择城池阶段
	City* temp = &findCity();//选择己方城池阶段
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp = &findCity();
	}
	cout << "选择对手的城池" << endl;//选择对方城池阶段
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "刘邦")attack_name = "项羽";
	else attack_name = "刘邦";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp_attack = &findCity();
	}
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if (temp->checkBelong() == "项羽") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	Node* i; int j;
	for (i = Ctemp_attack->findhead(), j = 0; i != nullptr; i = i->next, j+=100) {}//检索对方卡牌类链表，依据对方卡牌数增加己方战力，减少对方战力
	City change_add( j/2);//cards检索对方卡牌数量//攻击力设定
	*temp += change_add;
	cout << temp->checkBelong() << "兵力增强了" <<  j/2 << endl;
	City change_minus(j);
	*temp_attack -= change_minus;
	cout << temp_attack->checkBelong() << "兵力减少了" << j << endl;
	temp->show();
}
void CardPackage::infantry()//步兵
{
	cout << "选择你要出卡的城池" << endl;	//选择城池阶段
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp = &findCity();
	}
	City change(1200);
	*temp += change;
	cout << temp->checkBelong() << "兵力增强了1200" << endl;
	temp->show();
}
void CardPackage::spearman()//枪兵，每使用一次，增强战力逐渐增加
{
	cout << "选择你要出卡的城池" << endl;	//选择城池阶段
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp = &findCity();
	}
	cout << "选择对手的城池" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "刘邦")attack_name = "项羽";
	else attack_name = "刘邦";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp_attack = &findCity();
	}
	static int time = 0;
    while(time<5)time++;
	double mor = 1000.0 + time * 100.0;
	City change(mor);
	*temp += change;
	cout << temp->checkBelong() << "兵力增强了" << mor << endl;
	temp->show();
}
void CardPackage::archer()//弓箭手,守城时额外战力加成
{
	cout << "选择你要出卡的城池" << endl;	//选择城池阶段
	City* temp = &findCity();//己方城池判定阶段
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp = &findCity();
	}
	City* temp_attack;//选择对方城池阶段
	if (temp->checkBelong() == "刘邦")temp_attack = &cityX;
	else temp_attack = &cityL;
	if (temp->checkBelong() == "刘邦")temp_attack = &cityX;
	else temp_attack = &cityL;
	City* M = &cityMid;
	int n = 1000;
	if (M->checkBelong() == temp->checkBelong()) {
		n += 700;
	}
	else if(M->checkBelong() == temp_attack->checkBelong()) n -= 300;
	City change(n);
	*temp += change;
	cout << temp->checkBelong() << "使用‘弓箭手’使兵力增强了" <<n<< endl;
	temp->show();
}
void CardPackage::feint() //势如破竹
{
	cout << "选择你要出卡的城池" << endl;	//选择城池阶段
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp = &findCity();
	}
	cout << "选择对手的城池" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "刘邦")attack_name = "项羽";
	else attack_name = "刘邦";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "该城池不归属你，请重新选择" << endl;
		temp_attack = &findCity();
	}
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if (temp->checkBelong() == "项羽") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	cout << temp->checkBelong() << "使用‘势如破竹’在该回合免伤40%" << endl;
	temp->show();
}

void CardPackage::strike()//突袭，通过改变攻击距离直接攻击其主城
{
	cout << "你正在发动突袭（此次突袭无视攻击距离）" << endl;
	if (Cards::find_name == "刘邦")//刘邦出牌阶段
	{
		cityL.adjustDistance();//改变距离
		cityL.fight();//直接攻击
		cityL.adjustDistance();//距离恢复
	}
	else
	{
		cityX.adjustDistance();
		cityX.fight();
		cityX.adjustDistance();
	}
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