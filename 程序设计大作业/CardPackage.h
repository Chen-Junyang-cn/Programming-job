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
	void test1();
	void test2() { cout << "test function 2" << endl; }
	void test3() { cout << "test function 3" << endl; }
	void test4() { cout << "test function 4" << endl; }
	void test5() { cout << "test function 5" << endl; }
	void test6() { cout << "test function 6" << endl; }
	void test7() { cout << "test function 7" << endl; }
	void test8() { cout << "test function 8" << endl; }
	void test9() { cout << "test function 9" << endl; }
	void test10() { cout << "test function 10" << endl; }
};
#endif
