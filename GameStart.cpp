#include "stdafx.h"
#include "GameStart.h"


using namespace std;
using namespace Gcom;
using namespace Gsta;

typedef void(*gc)();	//����gc
void Gsta::GameStart()
{	
	GameStory::GameStory();
}

void Gsta::Gmap() {
	
		map<string, gc>Gcm;		//�½�map����ʹstring��Ӧ����
		Gcm["Start"] = Gcom::Start;
		Gcm["Continue"] = Gcom::Continue;
		Gcm["Help"] = Gcom::Help;
		Gcm["Exit"] = Gcom::Exit;

	while (1){

		string user_in;
		cin >> user_in;		//�û���������
		map<string, gc>::iterator iter;
		iter = Gcm.find(user_in);
		if (iter != Gcm.end()){	
			Gcm[user_in]();
		}

		else{
			cout << "��������ȷ������,ע�����ִ�Сд.������:" << endl;
			system("pause");
		}
	}
	
}

void Gsta::GameSta()
{
	map<string, gc>Gcm;		//�½�map����ʹstring��Ӧ����
	Gcm["Start"] = Gcom::Start;
	Gcm["Continue"] = Gcom::Continue;
	Gcm["Help"] = Gcom::Help;
	Gcm["Exit"] = Gcom::Exit;

	while (1) {

		string user_in;
		cin >> user_in;		//�û���������
		map<string, gc>::iterator iter;
		iter = Gcm.find(user_in);
		if (iter != Gcm.end()) {
			Gcm[user_in]();
		}

		else {
			cout << "��������ȷ������,ע�����ִ�Сд.������:" << endl;
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

		cout << "          *                     1.���ӱ༭(SGedit )                  *\n"
			 << "          *                     2.��һ��(SGbuild)                  *\n"
			 << "          *                     3.���ӳ���( SGgo  )                  *\n"
			 << "          *                     3.���Ӹ���( SGbu  )                  *\n"
			 << "          *                     4.��������( MStory)                  *\n"
			 << "          *                     5.֧������( SStory )                 *\n"
			 << "          *                                                          *\n";
	
	cout << "          ";
	for (int i = 0; i < 60; i++)
		cout << "*";
	
/*	map<string, gc>Gcm;		//�½�map����ʹstring��Ӧ����
	Gcm["SGedit"] = Gcom::Start;
	Gcm["SGbulid"] = Gcom::Continue;
	Gcm["SGgo"] = Gcom::Help;
	Gcm["SGbu"] = Gcom::Exit;
	Gcm["MStory"] = Gcom::;
	Gcm["SStory"] = Gcom::;
	while (1) {

		string user_in;
		cin >> user_in;		//�û���������
		map<string, gc>::iterator iter;
		iter = Gcm.find(user_in);
		if (iter != Gcm.end()) {
			Gcm[user_in]();
		}

		else {
			cout << "��������ȷ������,ע�����ִ�Сд.������:" << endl;
			system("pause");
		}
	}*/
}
