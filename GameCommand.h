#pragma once
#include<string>
#include <iostream>
#include<vector>
#include "GameStart.h"
#include <fstream>

using namespace std;

namespace Gcom {
	void Start();		//���ǿ�ʼ����
	void Help();		//�������ȵİ���~
	void Exit();		//�����˳�Ŷ
	void Continue();	//��,,���Ǽ���0w0
	void SGedit();		//���ӱ༭
	void Ret();			//���Ƿ��ؿ�
	
	vector<string> Split(string o_str, string fenge);	//����Ƿָ��ı���,����ʵ�ְ�һ�³���һ���ı�,��Ҫ��¥�¶������ʳ��~     --���Կ������������
	string ReadFile(string name);						//�����һ�����ܰ��ı�ȫ�����������溯��,�������ǻ���..                  --���Կ������������
}
