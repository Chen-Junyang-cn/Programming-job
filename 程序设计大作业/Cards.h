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

//���ӵ�е����ƣ��������ʾ
class Cards :public CardNumber, public CardPackage
{
public:
	Cards();//���캯��������һ��ͷ�ڵ�
	void insertCard();//�������
	void useCard();
	void deleteCard(string);
	void showCard();
private:
	Node* head;
};
#endif
