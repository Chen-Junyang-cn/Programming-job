#pragma once
#ifndef _CardPackage_h_
#define _CardPackage_h_
#include <iostream>
using namespace std;
class City;//ǰ����������#include"City.h"ͷ�ļ�,�����������
class Cards;
extern City cityL;
extern City cityX;
extern City cityMid;
extern Cards cardsL;
extern Cards cardsX;
class CardPackage //���ư�����¼���ֿ��ƣ���������ʹ�ú���ָ�����飬���������ܴ������������ͳһ����
{
	//friend class City;
public:
	CardPackage();
	void(CardPackage::* test[10])();//�ຯ��ָ�����������
	static City& findCity();	//���û���Ҫָ������ʱ����������������ҵ��û������Ӧ�ĺ���
	~CardPackage() {} 
private:
	void test1() { cout << "saber" << endl; }//);
	void test2() { cout << "beatback" << endl; }//�Ƹ�����
	void test3() { cout << "sowing_discord" << endl; }//�����
	void test4() { cout << "sage_model" << endl; }//����֮��
	void test5() { cout << "recuperate" << endl; }//��������
	void test6() { cout << "chariot" << endl; }//ս��
	void test7() { cout << "infantry" << endl; }//����
	void test8() { cout << "spearman" << endl; }//ǹ��
	void test9() { cout << "trap" << endl; }//����
	void test10() { cout << "test function 10" << endl; }//��
};

#endif
