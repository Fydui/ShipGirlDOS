#pragma once
#include<string>
#include <iostream>
#include<vector>
#include "GameIniFile.h"
#include "GameStart.h"
//#include "IniFile.h"
#include <fstream>

using namespace std;

namespace Gcom {
	void Start();		//���ǿ�ʼ����
	void Help();		//�������ȵİ���~
	void Exit();		//�����˳�Ŷ
	void Load();		//��ȡ
	void Save(char** Arg_s);		//����
	void SGedit();		//���ӱ༭
	void Ret();			//���Ƿ���
	void in_ini(string id,int lv);		//��ȡini
	void ou_ini();		//д��ini
	int GK_Num();	//�ؿ����� 
	void Ship_Check(); //�ʹ浵�й�,��ȡ�浵����½�����Ƿ����ظ��Ĵ�
	vector<string> Split(string o_str, string fenge);	//����Ƿָ��ı���,����ʵ�ְ�һ�³���һ���ı�,��Ҫ��¥�¶������ʳ��~     --���Կ������������
	string ReadFile(string name);						//�����һ�����ܰ��ı�ȫ�����������溯��,�������ǻ���..                  --���Կ������������
}
