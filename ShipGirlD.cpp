// ShipGirlD.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include "GameCommand.h"
#include "GameStart.h"
#include <iostream>
#include "GameStart.h"

using namespace std;
using namespace Gcom;
using namespace Gsta;

int main() {
	
	system("title = 舰少DOS");
	cout << "欢迎来到舰少DOS" << endl;
	cout << "输入Start开始游戏;输入Help查看帮助;"
		<< "输入Continue继续游戏;输入Exit退出游戏;" << endl;
	Gsta::Gmap();
	return 0;
}
