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
	Cards(const string n);//���캯��������һ��ͷ�ڵ�
	void insertCard();//�������
	void useCard();
	void deleteCard(string);
	void showCard();
	static string find_name;
	Node* findhead() { return head; }//��ͷ�ڵ�
private:
	Node* head;
};
#endif
