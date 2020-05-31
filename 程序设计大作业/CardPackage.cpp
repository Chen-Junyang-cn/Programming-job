#include "CardPackage.h"
#include "City.h"

CardPackage::CardPackage()
{
	test[0] = &CardPackage::saber;
	test[1] = &CardPackage::beatback;
	test[2] = &CardPackage::discord;
	test[3] = &CardPackage::sage_model;
	test[4] = &CardPackage::recuperate;
	test[5] = &CardPackage::chariot;
	test[6] = &CardPackage::infantry;
	test[7] = &CardPackage::spearman;
	test[8] = &CardPackage::archer;
	test[9] = &CardPackage::test10;
}

void CardPackage::saber()//saber
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	City injure(500);//�˺���ʱ
	City change(400);//�����仯��ʱ
	*temp_attack -= injure;
	cout << temp->checkBelong() << "ʹ��'saber'��" << temp_attack->checkBelong();
	cout << "�����500���˺�" << endl;
	*temp += change;
	temp->show();
}
void CardPackage::beatback()//�Ƹ�����
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	double record = temp->army();
	if (temp->checkBelong() == "����") {
		temp_attack->army() > temp->army() ? temp->adjustTroops(1.5) : temp->adjustTroops(1);
		temp_attack->army() > 2 * temp->army() ? temp->adjustTroops(1.2) : temp->adjustTroops(1);
	}
	else temp_attack->army() > temp->army() ? temp->adjustTroops(1.7) : temp->adjustTroops(1);
	temp_attack->army() > 2 * temp->army() ? temp->adjustTroops(1.4) : temp->adjustTroops(1);
	double difference = temp->army() - record;//��ֵ
	//���ٶ���һ��������¼�غ�//����һ����ֵ����һ��ϼ�ȥ
	temp->show();
}
void CardPackage::discord()//�����
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if(temp->checkBelong()=="����") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	string seize; Node* i; int j;
	cout << temp->checkBelong() << "�Ŀ����У�";
	for (i = Ctemp_attack->findhead(), j = 0; i != nullptr; i = i->next, j++) {//���ֿ���չʾ
		cout << i->name << "  ";//�Է���������
	}
	cout << "������Ҫ���ֵģ��Է�������" << endl;
	cin >> seize;
		for (i = Ctemp_attack->findhead(); i != nullptr; i = i->next)//�������Ῠ��
		{
			if (i->next->name == seize)
			{
				Node* d = i->next;
				i->next = i->next->next;//�Է�ɾ������
				delete d;
				Node* x = new Node;
				x->name = seize;
				x->next = Ctemp->findhead()->next;//�������뿨��
				Ctemp->findhead()->next = x;//��������ֵ��������б������躯��
				break;
			}
		}
		if (i->next == nullptr) {
			cout << temp_attack->checkBelong() << "�޴���" << endl;
			cout << "���������룺" << endl;
			CardPackage::discord();//����ִ�к���
		}
	temp->show();
}
void CardPackage::sage_model()//����֮��
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	if (temp->checkBelong() == "����") {
		cardsL.insertCard(); cardsL.insertCard();//������뿨��
	}
	else { cardsX.insertCard(); cardsX.insertCard(); }
	temp->show();
}
void CardPackage::recuperate()//��������
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if (temp->checkBelong() == "����") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	Node* i; int j; string strength[10], record[3];
	for (i = Ctemp->findhead(), j = 0; i != nullptr; i = i->next, j++) {
		strength[j] = i->name;
	}//����������ϳ�����
	for (int k = 0; k < 3; k++) { 
		record[3] = strength[rand() % j]; cout << record[k]<<"  "; 
	}//�����ѡ���ſ���
	cout << endl;
	cout << "��ѡ���ƣ������������ս���ӳɽϴ󣩣�" << endl;
	string select;//ѡ��Ŀ���
	cin >> select;
	for (i = Ctemp->findhead(), j = 0; i != nullptr; i = i->next, j++) //����ѡ��Ŀ��ƽ��б�������ǿ
	{
		if (i->next->name == select) {
			if (select == "saber" || select == "chariot" || select == "infantry") {
				City change(1500);
				*temp += change;
				cout << temp->checkBelong() << "������ǿ��1500" << endl;
			}
			else {
				City change(500);
				*temp += change;
				cout << temp->checkBelong() << "������ǿ��500" << endl;
			}
		}
	}
	if (i == nullptr) {
		cout << temp->checkBelong() << "�޴˿��ƣ����������룺";
		CardPackage::recuperate();
	}
	temp->show();
}
void CardPackage::chariot()//ս��//Ⱥ��
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if (temp->checkBelong() == "����") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	Node* i; int j;
	for (i = Ctemp_attack->findhead(), j = 0; i != nullptr; i = i->next, j++) {}
	City change(100 * j);//cards�����Է���������//�������趨
	*temp += change;
	cout << temp->checkBelong() << "������ǿ��" << 100 * j << endl;
	temp->show();
}
void CardPackage::infantry()//����
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	City change(1200);
	*temp += change;
	cout << temp->checkBelong() << "������ǿ��1200" << endl;
	temp->show();
}
void CardPackage::spearman()//ǹ��/���޻غ��趨��ս������
{
	City *temp = &findCity();
	City *temp_attack = &findCity();
	City change(700);
	*temp += change;
	cout << temp->checkBelong() << "������ǿ��700" << endl;
	temp->show();
}
void CardPackage::archer()//������
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	City* M = &cityMid;
	int n = 1000;
	if (M->checkBelong() == temp->checkBelong()) {
		n += 700;
	}
	else n -= 300;
	City change(n);
	*temp += change;
	cout << temp->checkBelong() << "������ǿ��" <<n<< endl;
	temp->show();
}
void CardPackage::test10() 
{
	City* temp = &findCity();
	City* temp_attack = &findCity();
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if (temp->checkBelong() == "����") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	temp->show();
}


City& CardPackage::findCity()
{
	string target;
	cin >> target;
	if (target == "����")
	{
		return cityL;
	}
	else if (target == "����")
	{
		return cityX;
	}
	return cityMid;
}
