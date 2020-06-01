#pragma once
#ifndef _Cards_h_
#define _Cards_h_
#include <iostream>
#include "CardNumber.h"
#include "CardPackage.h"
using namespace std;

class Node
{
public:
	string name;
	Node* next;
	Node() : next(nullptr) {}
};

//玩家拥有的手牌，用链表表示
class Cards :public CardNumber, public CardPackage
{
public:
	Cards(const string n);//构造函数，生成一个头节点
	void insertCard();//获得手牌
	void useCard();
	void deleteCard(string);
	void showCard();
	static string find_name;
	Node* findhead() { return head; }//找头节点
private:
	Node* head;
};
#endif
