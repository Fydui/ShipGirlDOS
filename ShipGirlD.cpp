// ShipGirlD.cpp : �������̨Ӧ�ó������ڵ㡣
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
	
	system("title = ����DOS");
	cout << "��ӭ��������DOS" << endl;
	cout << "����Start��ʼ��Ϸ;����Help�鿴����; \n"
		<< "����Load������Ϸ;����Exit�˳���Ϸ; \n";
		//<< "����Save������Ϸ.."<<endl;
	Gsta::Gmap();
	return 0;
}
