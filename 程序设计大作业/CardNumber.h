#pragma once
#ifndef _CardNumber_h_
#define _CardNumber_h_
#include <iostream>

using namespace std;
//卡牌的编码，主要将卡牌名字转化成数字方便后续使用
class CardNumber
{
public:
	CardNumber();
	int findNumber(string);	//获得卡牌的编码，在用牌的时候需要
	string getRandName();	//随机获得名字，在抽牌阶段需要
	~CardNumber() {};
	string getname(int order) { return numberPackage[order]; }
private:
	string numberPackage[10];//编码包
};
#endif

