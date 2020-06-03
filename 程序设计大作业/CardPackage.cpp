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

void CardPackage::saber()//saber
{
	cout << "ѡ����Ҫ�����ĳǳ�" << endl;	//ѡ��ǳؽ׶�
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp = &findCity();
	}
	cout << "ѡ����ֵĳǳ�" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "����")attack_name = "����";
	else attack_name = "����";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "�ǵз��ǳأ�������ѡ��" << endl;
		temp_attack = &findCity();
	}
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
	cout << "ѡ����Ҫ�����ĳǳ�" << endl;	//ѡ��ǳؽ׶�
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp = &findCity();
	}
	cout << "ѡ����ֵĳǳ�" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "����")attack_name = "����";
	else attack_name = "����";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp_attack = &findCity();
	}
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
	cout << "ѡ����Ҫ�����ĳǳ�" << endl;	//ѡ��ǳؽ׶�
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp = &findCity();
	}
	cout << "ѡ����ֵĳǳ�" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "����")attack_name = "����";
	else attack_name = "����";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp_attack = &findCity();
	}
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
		if (i == nullptr) {
			cout << temp_attack->checkBelong() << "�޴���" << endl;
			cout << "���������룺" << endl;
			CardPackage::discord();//����ִ�к���
		}
	temp->show();
}
void CardPackage::sage_model()//����֮��
{
	cout << "ѡ����Ҫ�����ĳǳ�" << endl;	//ѡ��ǳؽ׶�
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp = &findCity();
	}
	cout << "ѡ����ֵĳǳ�" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "����")attack_name = "����";
	else attack_name = "����";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp_attack = &findCity();
	}
	if (temp->checkBelong() == "����") {
		cardsL.insertCard(); cardsL.insertCard();//������뿨��
	}
	else { cardsX.insertCard(); cardsX.insertCard(); }
	temp->show();
}
void CardPackage::recuperate()//��������
{
	cout << "ѡ����Ҫ�����ĳǳ�" << endl;	//ѡ��ǳؽ׶�
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp = &findCity();
	}
	cout << "ѡ����ֵĳǳ�" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "����")attack_name = "����";
	else attack_name = "����";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp_attack = &findCity();
	}
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
		record[k] = strength[rand() % j]; cout << record[k]<<"  "; 
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
	cout << "ѡ����Ҫ�����ĳǳ�" << endl;	//ѡ��ǳؽ׶�
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp = &findCity();
	}
	cout << "ѡ����ֵĳǳ�" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "����")attack_name = "����";
	else attack_name = "����";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp_attack = &findCity();
	}
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if (temp->checkBelong() == "����") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	Node* i; int j;
	for (i = Ctemp_attack->findhead(), j = 0; i != nullptr; i = i->next, j+=100) {}
	City change( j);//cards�����Է���������//�������趨
	*temp += change;
	cout << temp->checkBelong() << "������ǿ��" <<  j << endl;
	temp->show();
}
void CardPackage::infantry()//����
{
	cout << "ѡ����Ҫ�����ĳǳ�" << endl;	//ѡ��ǳؽ׶�
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp = &findCity();
	}
	cout << "ѡ����ֵĳǳ�" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "����")attack_name = "����";
	else attack_name = "����";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp_attack = &findCity();
	}
	City change(1200);
	*temp += change;
	cout << temp->checkBelong() << "������ǿ��1200" << endl;
	temp->show();
}
void CardPackage::spearman()//ǹ��/���޻غ��趨��ս������
{
	cout << "ѡ����Ҫ�����ĳǳ�" << endl;	//ѡ��ǳؽ׶�
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp = &findCity();
	}
	cout << "ѡ����ֵĳǳ�" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "����")attack_name = "����";
	else attack_name = "����";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp_attack = &findCity();
	}
	City change(700);
	*temp += change;
	cout << temp->checkBelong() << "������ǿ��700" << endl;
	temp->show();
}
void CardPackage::archer()//������
{
	cout << "ѡ����Ҫ�����ĳǳ�" << endl;	//ѡ��ǳؽ׶�
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp = &findCity();
	}
	cout << "ѡ����ֵĳǳ�" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "����")
		attack_name = "����";
	else 
		attack_name = "����";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp_attack = &findCity();
	}
	City* M = &cityMid;
	int n = 1000;
	if (M->checkBelong() == temp->checkBelong()) {
		n += 700;
	}
	else if(M->checkBelong() == temp_attack->checkBelong()) n -= 300;
	City change(n);
	*temp += change;
	cout << temp->checkBelong() << "������ǿ��" <<n<< endl;
	temp->show();
}
void CardPackage::feint() //�𹥣�������������ʲô�ã�
{
	cout << "ѡ����Ҫ�����ĳǳ�" << endl;	//ѡ��ǳؽ׶�
	City* temp = &findCity();
	while (temp->checkBelong() != Cards::find_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp = &findCity();
	}
	cout << "ѡ����ֵĳǳ�" << endl;
	City* temp_attack = &findCity();
	string attack_name;
	if (Cards::find_name == "����")attack_name = "����";
	else attack_name = "����";
	while (temp_attack->checkBelong() != attack_name)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		temp_attack = &findCity();
	}
	Cards* Ctemp = &cardsL;
	Cards* Ctemp_attack = &cardsX;
	if (temp->checkBelong() == "����") {
		Ctemp = &cardsX;
		Ctemp_attack = &cardsL;
	}
	temp->show();
}

void CardPackage::strike()//ͻϮ��ͨ���ı乥������ֱ�ӹ���������
{
	cout << "�����ڷ���ͻϮ���˴�ͻϮ���ӹ������룩" << endl;
	if (Cards::find_name == "����")//������ƽ׶�
	{
		cityL.adjustDistance();//�ı����
		cityL.fight();//ֱ�ӹ���
		cityL.adjustDistance();//����ָ�
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