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

void CardPackage::test2()//saber
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
void CardPackage::test1()
{
	cout << "ѡ����Ҫ����ĳǳأ�" << endl;
	City* temp = &findCity();//ʹ��ָ�룬�޸��Ǹ�Ŀ���������
	cout << "test function 1";
	(*temp).adjustTroops(1.2);//������Ϊԭ����1.2��
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