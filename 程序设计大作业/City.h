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
	int changeTroops(bool ,int);//改变兵力，返回变化后值
	void show() ;		//输出还有多少兵力
	void fight();		//战斗阶段
	void adjustTroops(double);//留一个对外接口用于改变私有数据的兵力
	bool judge();		//判定阶段
	int selectTroops(); //选择出击的军队数量
	string checkBelong();	  //接口，查看城池的归属

	int distance;		//攻击距离。刘邦是1，项羽是3，中立城池是2
private:
	double troops;		//兵力
	string belong;		//归属
};
#endif
