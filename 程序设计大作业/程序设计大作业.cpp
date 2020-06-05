// 程序设计大作业.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstring>
#include <ctime>
#include<windows.h>
#include<Mmsystem.h>
#include "City.h"
#include "Cards.h"
#include "CardPackage.h"
#include "CardNumber.h"
#pragma comment(lib,"winmm.lib")
using namespace std;
City cityL("刘邦"), cityX("项羽"), cityMid("战略城池");
Cards cardsL("刘邦"), cardsX("项羽");
int main()
{
	PlaySound(L"bgm.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	CardNumber numberL, numberX;
	while (cityL.checkBelong() == "刘邦" && cityX.checkBelong() == "项羽" && cityL.judge() && cityX.judge())
	{
		cout << "刘邦回合：" << endl;
		cardsL.insertCard();
		cardsL.showCard();
		cardsL.useCard();
		cardsL.showCard();
		cityL.fight();	//刘邦对项羽进攻
		cityL.show();			//刘邦城池的状态
		if (cityX.checkBelong() != "项羽")//项羽已经被打败
			break;
		cout << endl << "项羽回合：" << endl;
		cardsX.insertCard();
		cardsX.showCard();
		cardsX.useCard(); 
		cityX.fight();	//项羽对刘邦进攻
		cityX.show();		//项羽城池的状态
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
