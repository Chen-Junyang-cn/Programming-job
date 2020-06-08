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
		cout << "���ӵ�еı���Ϊ��" << troops << "������ѡ��" << endl;
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
		c2->troops = c1Num - c2->troops;
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
	if (distance == 2)//���չʾ�����ǳ�
	{
		//����������ɫΪ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cout << "�����ǳع�����" << belong << " ������" << troops << endl;
		//�����ָ�
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN);
		return;
	}
	cout << belong << "�ǳ�ʣ�������" << troops << endl << endl;
}

void City::adjustDistance()
{
	if (belong == "����")	//����ĳǳ�
	{
		if (distance == 3)	//����δ�ı�
			distance = 1;	//���������Ǿ����ֵ
		else 
			distance = 3;
	}
	else//����ĳǳ�
	{
		if (distance == 1) // δ�ı�
			distance = 3;
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

void City::win()
{
	system("cls");
	cout << belong << "�����Ϸʤ����" << endl;
	exit(0);
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
void City::change_static(bool flag)
{
	if (flag) {
		troops = troops + difference*0.4;
	}
	else troops = troops / 2.0;
}
void City::incards_judge(string name)
{
	if (name == "����"&& cityX.army() < 0) {
			cityX.checkBelong() = "����";
	}
	else if (name == "����" && cityL.army() < 0) {
		cityL.checkBelong() = "����";
	}
}