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
public:
	City(const string s);
	City(const double temp) :troops(temp) {};//��������ʱ����
	double army() { return troops; }//���ʱ���
	City& operator+=(const  City&);//�����ı䶯
	City& operator-=(const  City&);
	void show() ;		//������ж��ٱ���
	void fight();		//ս���׶�
	void adjustTroops(double);//��һ������ӿ����ڸı�˽�����ݵı���
	void adjustDistance();//������������֮��Ĺ�������
	bool judge();		//�ж��׶�
	int selectTroops(); //ѡ������ľ�������
	string checkBelong();	  //�ӿڣ��鿴�ǳصĹ���

private:
	int distance;		//�������롣������1��������3�������ǳ���2
	double troops;		//����
	string belong;		//����
};
#endif
