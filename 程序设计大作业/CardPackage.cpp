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
	cout << "'saber'��";
	if (temp.belong == "L")cout << "����"; else cout << "����";
	cout << "�����500���˺�" << endl;
	temp.troops += 200;
	temp.show();*/
}
void CardPackage::test2()//�Ƹ�����
{
	City temp = findCity();
	City temp_attack = findCity();
	int record = temp.troops;
	if (temp.belong == "L") {
		temp.troops = temp_attack.troops > temp.troops ? temp.troops * 1.5 : temp.troops;
		temp.troops = temp_attack.troops > 2 * temp.troops ? temp.troops * 1.5 : temp.troops;
	}
	int difference = temp.troops - record;//��ֵ
	//���ٶ���һ��������¼�غ�//����һ����ֵ����һ��ϼ�ȥ
	temp.show();
}
void CardPackage::test3()//�����
{
	City temp = findCity();
	City temp_attack = findCity();

	temp.show();
}
void CardPackage::test3()//����֮��
{
	City temp = findCity();
	City temp_attack = findCity();
	if (temp.belong == "L") {
		cardsL.insertCard(); cardsL.insertCard();
	}
	else { cardsX.insertCard(); cardsX.insertCard(); }
	temp.show();
}
void CardPackage::test3()//��������
{
	City temp = findCity();
	City temp_attack = findCity();
	if (temp.belong == "L")
		cards.//����������
	else
		temp.show();
}
void CardPackage::test3()//ս��//Ⱥ��
{
	City* temp = &findCity();
	City temp_attack = findCity();
	//cards�����Է���������//�������趨
	temp.troops += 100;
	temp.show();
}
void CardPackage::test3()//����
{
	City temp = findCity();
	City temp_attack = findCity();
	temp.troops += 500;
	temp.show();
}
void CardPackage::test3()//ǹ��
{
	City temp = findCity();
	City temp_attack = findCity();
	temp.troops += 500;
	temp.show();
}
void CardPackage::test3()//����
{
	City temp = findCity();
	City temp_attack = findCity();
	temp.troops += 500;
	//fight������                                                             
	temp.show();
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