#pragma once
#ifndef _CardPackage_h_
#define _CardPackage_h_
#include <iostream>
using namespace std;
class City;//前向声明不能#include"City.h"头文件,方便后续更改
class Cards;
extern City cityL;
extern City cityX;
extern City cityMid;
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
