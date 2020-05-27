#include "City.h"
City::City(const string s)
{
	troops = 1000;
	belong = s;
	distance = 3;
}
void City::fight()
{
	cout << "ѡ����Ҫ�����ĳǳ�" << endl;	//ѡ��ǳؽ׶�
	City* c1 = &CardPackage::findCity();
	while (c1->belong != belong)
	{
		cout << "�óǳز������㣬������ѡ��" << endl;
		c1 = &CardPackage::findCity();
	}
	cout << "ѡ�����Ŀ��ĳǳأ�ѡ�񼺷��ǳؿ��ͱ���" << endl;
	City* c2 = &CardPackage::findCity();//ʹ�ÿ�����Ѱ�ҳ��еĹ���
	/*while (c1->distance < c2->distance) //�������벻��
	{
		cout << "��ľ����޷�ֱ�ӵ���óǳأ�������ѡ��" << endl;
		c2 = &CardPackage::findCity();
	}*/
	int c1Num = selectTroops();	//ѡ����������׶�
	while (c1Num >= c1->troops)
	{
		cout << "��ı������㣬������ѡ��" << endl;
		c1Num = selectTroops();
	}
	c1->troops -= c1Num;
	if (c1->belong == c2->belong) // ս���ж��׶�
	{
		cout << "����ѡ���ͱ���ս���غϽ���" << endl;
		if (c1 == c2)//�ͱ��ڵ�ǰ�ǳأ���������䶯
			return;
		c2->troops += c1Num;
	}
	if (c1Num > c2->troops)	//c1����ռ��
	{
		c2->belong = belong;//c2��ռ��
		c2->troops -= c1Num;
		c1->distance++;		//ռ��ǳأ�������������
		c2->distance++;		//c2��ռ��
	}
	else if (c1->troops == c2->troops)//������ͬ
	{
		c2->belong = "����";		//�ǳ�����
		c2->troops = 0;
	}
	else
	{
		c2->troops -= c1Num;
	}
}

void City::show()
{
	cout << "�ǳ�ʣ�������" << troops << "�ǳصĹ�����" << belong << endl;
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
	cout << "ѡ���ɳ����ӵ�����" << endl;
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