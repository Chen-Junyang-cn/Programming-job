 #include "City.h"
City::City(const string s)
{
	troops = 1000;
	belong = s;
	if (s == "����")
		distance = 1;
	else if (s == "����")
		distance = 3;
	else
		distance = 2;
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
	while (abs(c1->distance - c2->distance) > 1) //�����ǳؾ������1���޷�ֱ�ӹ���
	{
		cout << "��ľ����޷�ֱ�ӵ���óǳأ�������ѡ��" << endl;
		c2 = &CardPackage::findCity();
	}
	int c1Num = selectTroops();	//ѡ����������׶�
	while (c1Num > c1->troops)
	{
		cout << "��ı������㣬������ѡ��" << endl;
		c1Num = selectTroops();
	}
	c1->troops -= c1Num;
	if (difference == 0) {//���ݲɼ�
		difference = c1Num;
	}
	if (c1->belong == c2->belong) // ս���ж��׶�
	{
		c2->troops += c1Num;//������ͬ���ͱ�
		cout << "����ѡ���ͱ���ս���غϽ���" << endl;
		return;
	}

	if (c1Num > c2->troops)	//c1����ռ��
	{
		c2->belong = belong;//c2��ռ��
		c2->troops -= c1Num;
	}
	else if (c1Num == c2->troops)//������ͬ
	{
		//�������ĳǳع������ı�
		c2->troops = 0;
	}
	else
	{
		c2->troops -= c1Num;
	}
}

void City::show()
{
	cout << "�ǳ�ʣ�������" << troops << endl;
	cout << "�ǳصĹ�����" << belong << endl;
}

void City::adjustDistance()
{
	if (belong == "����")	//����ĳǳ�
	{
		if (distance == 3)	//����δ�ı�
			distance = 2;	//���������Ǿ����ֵ
		else 
			distance = 3;
	}
	else//����ĳǳ�
	{
		if (distance == 1) // δ�ı�
			distance = 2;
		else
			distance = 1;
	}
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

City& City::operator+=(const  City& temp)
{
	this->troops += temp.troops;
	return *this;
}
City& City::operator-=(const  City& temp)
{
	this->troops -= temp.troops;
	return *this;
}
double City::difference = 0;
void City::change_static(double diff)
{
	difference = diff + difference;
}
void City::change_static(bool flag)
{
	if (flag) {
		troops = troops + difference;
	}
	else troops = (troops + difference) / 2.0;
}
