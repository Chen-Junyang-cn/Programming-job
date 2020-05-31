#pragma once
#ifndef _CardPackage_h_
#define _CardPackage_h_
#include <iostream>
using namespace std;
class City;//前向声明不能#include"City.h"头文件,方便后续更改
extern City cityL;
extern City cityX;
extern City cityMid;
#include "Cards.h"
extern Cards cardsL;
extern Cards cardsX;
class CardPackage //卡牌包，记录各种卡牌，最终设想使用函数指针数组，将各个功能打包放入数组内统一调用
{
	//friend class City;
	
public:
	CardPackage();
	void(CardPackage::* test[10])();//类函数指针数组的声明
	static City& findCity();	//当用户需要指定城市时，调用这个函数，找到用户输入对应的函数
	~CardPackage() {} 
private:
	void test1();
	void test2();//破釜沉舟
	void test3();//反间计
	void test4();//贤者之心
	void test5();//养精蓄锐
	void test6();//战车
	void test7();//步兵
	void test8();//枪兵
	void test9();//弓箭手
	void test10();//佯攻
};

#endif
