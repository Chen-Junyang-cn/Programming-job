#pragma once
#ifndef _CardNumber_h_
#define _CardNumber_h_
#include <iostream>

using namespace std;
//���Ƶı��룬��Ҫ����������ת�������ַ������ʹ��
class CardNumber
{
public:
	CardNumber();
	int findNumber(string);	//��ÿ��Ƶı��룬�����Ƶ�ʱ����Ҫ
	string getRandName();	//���������֣��ڳ��ƽ׶���Ҫ
	~CardNumber() {};
	string getname(int order) { return numberPackage[order]; }
private:
	string numberPackage[10];//�����
};
#endif

