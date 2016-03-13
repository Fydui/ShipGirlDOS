#include "stdafx.h"
#include "GameStart.h"


using namespace std;
using namespace Gcom;
using namespace Gsta;

typedef void(*gc)();	//定义gc
void Gsta::GameStart()
{	
	GameStory::GameStory();
}

void Gsta::Gmap() {
	
		map<string, gc>Gcm;		//新建map并且使string对应函数
		Gcm["Start"] = Gcom::Start;
		Gcm["Continue"] = Gcom::Continue;
		Gcm["Help"] = Gcom::Help;
		Gcm["Exit"] = Gcom::Exit;

	while (1){

		string user_in;
		cin >> user_in;		//用户输入命令
		map<string, gc>::iterator iter;
		iter = Gcm.find(user_in);
		if (iter != Gcm.end()){	
			Gcm[user_in]();
		}

		else{
			cout << "请输入正确的命令,注意区分大小写.请重试:" << endl;
			system("pause");
		}
	}
	
}

void Gsta::GameSta()
{
	map<string, gc>Gcm;		//新建map并且使string对应函数
	Gcm["Start"] = Gcom::Start;
	Gcm["Continue"] = Gcom::Continue;
	Gcm["Help"] = Gcom::Help;
	Gcm["Exit"] = Gcom::Exit;

	while (1) {

		string user_in;
		cin >> user_in;		//用户输入命令
		map<string, gc>::iterator iter;
		iter = Gcm.find(user_in);
		if (iter != Gcm.end()) {
			Gcm[user_in]();
		}

		else {
			cout << "请输入正确的命令,注意区分大小写.请重试:" << endl;
			system("pause");
		}
	}
}

void Gsta::GameHom()
{	
	system("cls");
	cout << "          ";
	for (int i = 0; i < 60; i++)
	cout << "*";
	cout << endl;
	for (int k = 0; k < 1; k++)
	{
		cout << "          *";
		for (int j = 0; j < 58; j++)
			cout << " ";
		cout << "*";
		cout << endl;
	}

		cout << "          *                     1.舰队编辑(SGedit )                  *\n"
			 << "          *                     2.大建一发(SGbuild)                  *\n"
			 << "          *                     3.舰队出征( SGgo  )                  *\n"
			 << "          *                     3.舰队改造( SGbu  )                  *\n"
			 << "          *                     4.主线任务( MStory)                  *\n"
			 << "          *                     5.支线任务( SStory )                 *\n"
			 << "          *                                                          *\n";
	
	cout << "          ";
	for (int i = 0; i < 60; i++)
		cout << "*";
	
/*	map<string, gc>Gcm;		//新建map并且使string对应函数
	Gcm["SGedit"] = Gcom::Start;
	Gcm["SGbulid"] = Gcom::Continue;
	Gcm["SGgo"] = Gcom::Help;
	Gcm["SGbu"] = Gcom::Exit;
	Gcm["MStory"] = Gcom::;
	Gcm["SStory"] = Gcom::;
	while (1) {

		string user_in;
		cin >> user_in;		//用户输入命令
		map<string, gc>::iterator iter;
		iter = Gcm.find(user_in);
		if (iter != Gcm.end()) {
			Gcm[user_in]();
		}

		else {
			cout << "请输入正确的命令,注意区分大小写.请重试:" << endl;
			system("pause");
		}
	}*/
}
