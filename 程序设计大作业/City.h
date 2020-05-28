#pragma once
#ifndef _City_h_
#define _City_h_
#include <iostream>
#include <cstring>
using std::ostream; using std::istream; using std::endl; using std::string; using std::cout;
//using namespace std;
#include "CardPackage.h"
class City
{
	//friend void CardPackage::test1();
	
public:
	City(const string s);
	int changeTroops(bool ,int);//�ı���������ر仯��ֵ
	void show() ;		//������ж��ٱ���
	void fight();		//ս���׶�
	void adjustTroops(double);//��һ������ӿ����ڸı�˽�����ݵı���
	bool judge();		//�ж��׶�
	int selectTroops(); //ѡ������ľ�������
	string checkBelong();	  //�ӿڣ��鿴�ǳصĹ���

	int distance;		//�������롣������1��������3�������ǳ���2
private:
	double troops;		//����
	string belong;		//����
};
#endif
