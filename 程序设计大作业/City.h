#pragma once
#ifndef _City_h_
#define _City_h_
#include <iostream>
#include <cstring>
#include <Windows.h>
#include "CardPackage.h"
using namespace std;
class City
{	
public:
	City(const string s);
	City(const double temp) :troops(temp) {};//��������ʱ����
	double army() { return troops; }//���ʱ���
	City& operator+=(const  City&);//�����ı䶯
	City& operator-=(const  City&);
	void show();		//������ж��ٱ���
	void fight();		//ս���׶�
	void adjustTroops(double);//��һ������ӿ����ڸı�˽�����ݵı���
	void changeTroops(double);//�ı����
	void adjustDistance();//������������֮��Ĺ�������
	void win();		//���ʤ���ĺ���
	int selectTroops(); //ѡ������ľ�������
	string checkBelong();	  //�ӿڣ��鿴�ǳصĹ���
	void changeBelong(string);//�ı�ǳصĹ���
	static double difference;//�غϿ������õĲ�ֵ
	void change_static(bool);//���Ƹı�ľ�̬�������ı����
private:
	int distance;		//�������롣������1��������3�������ǳغ�Ϊ2���ɵ��������ǳص������־
	double troops;		//����
	string belong;		//����
};
#endif
