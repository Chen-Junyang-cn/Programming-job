#pragma once
#ifndef _CardPackage_h_
#define _CardPackage_h_
#include <iostream>
using namespace std;
class City;//前向声明不能#include"City.h"头文件,方便后续更改
extern City cityL;
extern City cityX;
extern City cityMid;
class Cards;
extern Cards cardsL;
extern Cards cardsX;
class CardPackage //卡牌包，记录各种卡牌，使用函数指针数组，将各个功能打包放入数组内统一调用
{
	//friend class City;
	
public:
	CardPackage();
	void(CardPackage::* card[11])();//类函数指针数组的声明
	static City& findCity();	//当用户需要指定城市时，调用这个函数，找到用户输入对应的函数
	~CardPackage() {} 
private:
	void saber();//骑兵
	void beatback();//破釜沉舟
	void discord();//反间计
	void sage_model();//贤者之心
	void recuperate();//养精蓄锐
	void chariot();//战车
	void infantry();//步兵
	void spearman();//枪兵
	void archer();//弓箭手
	void dominating();//势如破竹
	void strike();//突袭
};

#endif