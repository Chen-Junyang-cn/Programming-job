#include "Cards.h"
#include"City.h"
Cards::Cards(const string n) 
{
	srand(int(time(0)));//初始化种子，方便后续随机抽牌
	Node* s = new Node;
	head = s;
	head->next = nullptr;
	head->name = n;
	insertCard();
	insertCard();
	insertCard();
	insertCard();
	Sleep(1000);
}

void Cards::insertCard()
{
	Node* x = new Node;
	x->name = getRandName();
	x->next = head->next;
	head->next = x;
}

string Cards::find_name = "空";

void Cards::useCard()
{
	find_name = head->name;
	string s;
	static string pre_s = "empty";
	
	if (pre_s == "破釜沉舟") {
		if (head->name == "项羽")
			cityL.change_static(false);//改变兵力，后一回合生效
		else cityX.change_static(false);
		City::difference = 0;//重新置0计算
	}
	else if (pre_s == "势如破竹") {
		if (head->name == "项羽")
			cityL.change_static(true);//改变兵力，后一回合生效
		else cityX.change_static(true);
		City::difference = 0;//重新置0计算
	}
	cout << endl << "输入你想使用的卡牌：";
	cin >> s;
	int num = -1;
	while (num == -1)
	{
		for (Node* i = head->next; i != nullptr; i = i->next)
		{
			if (i->name == s) //手牌中有这张卡牌
			{
				num = findNumber(s);//寻找这张卡牌的编码
				pre_s = s;
				(this->*card[num])();//测试卡包的调用情况
				deleteCard(s);
				return;
			}
		}//遍历手牌都没有找到相应的卡牌
		cout << "没有这张卡牌，请重新选择卡牌" << endl;
		cin >> s;
	}
}

void Cards::deleteCard(string name)
{
	for (Node* i = head; i != nullptr; i = i->next)
	{
		if (i->next->name == name)//要删除的卡牌必然在手牌中，所以i不可能为nullptr，因此i->next安全
		{
			Node* x = i->next;
			i->next = i->next->next;//删除操作
			delete x;
			return;	//防止多张同名卡牌同时被使用
		}
	}
}

void Cards::showCard()
{
	cout << "你现在拥有的手牌：";
	for (Node* i = head->next; i != nullptr; i = i->next)
	{
		cout << i->name << " ";
	}
	cout << endl;
}
