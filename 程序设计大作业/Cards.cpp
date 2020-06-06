#include "Cards.h"
#include"City.h"
Cards::Cards(const string n) 
{
	srand(int(time(0)));//��ʼ�����ӣ���������������
	Node* s = new Node;
	head = s;
	head->next = nullptr;
	head->name = n;
	insertCard();
	insertCard();
	insertCard();
	insertCard();
}

void Cards::insertCard()
{
	Node* x = new Node;
	x->name = getRandName();
	x->next = head->next;
	head->next = x;
}

string Cards::find_name = "��";

void Cards::useCard()
{

	find_name = head->name;
	string s;
	static string pre_s="empty";
	if (pre_s == "�Ƹ�����") {
		if (head->name == "����")
			cityL.change_static(false);//�ı��������һ�غ���Ч
		else cityX.change_static(false);
	}
	else if (pre_s == "��") {
		if (head->name == "����")
			cityL.change_static(true);//�ı��������һ�غ���Ч
		else cityX.change_static(true);
		City::difference = 0;//������0����
	}
	cout << endl << "��������ʹ�õĿ��ƣ�";
	cin >> s;
	pre_s = s;
	(this->*card[findNumber(s)])();//���Կ����ĵ������
	deleteCard(s);
}

void Cards::deleteCard(string name)//���Ż����������һ����������֣���ôӦ����������
{
	for (Node* i = head; i != nullptr; i = i->next)
	{
		if (i->next->name == name)
		{
			Node* x = i->next;
			i->next = i->next->next;//ɾ������
			delete x;
			return;	//��ֹ����ͬ������ͬʱ��ʹ��
		}
	}
}

void Cards::showCard()
{
	cout << "������ӵ�е����ƣ�";
	for (Node* i = head->next; i != nullptr; i = i->next)
	{
		cout << i->name << " ";
	}
	cout << endl;
}
