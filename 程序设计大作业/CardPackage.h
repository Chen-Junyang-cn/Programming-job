#pragma once
#ifndef _CardPackage_h_
#define _CardPackage_h_
#include <iostream>
using namespace std;
class City;//ǰ����������#include"City.h"ͷ�ļ�,�����������
extern City cityL;
extern City cityX;
extern City cityMid;
#include "Cards.h"
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
	void saber();
	void beatback();//�Ƹ�����
	void discord();//�����
	void sage_model();//����֮��
	void recuperate();//��������
	void chariot();//ս��
	void infantry();//����
	void spearman();//ǹ��
	void archer();//������
	void test10();//��
};

#endif
