#include "stdafx.h"
#include "GameStory.h"

using namespace std;
using namespace Gcom;
using namespace Gsta;

void Gsto::M_1_1() 
{	
	
	//File_o("./StoryTXT/M_1_1.txt","#",7);
	system("pause");
	system("CLS");
	cout << "��ϲ����" << endl;
	cout << "�����������~" << endl;
	Gbui::LA_T(5);
	Gbui::BRandom();
	//Gsta::GameHom();
}

void Gsto::File_o(string name, string fenge,int sum)
{

	ifstream infile(name);			//���ļ�
	string word = "";				//ȫ���ı�
	string tmp;						//�ڶ��ĵ�ǰ��
	while (getline(infile, tmp)) {
		word += tmp + "\n";
	}
	word = word.substr(0, word.length() - 2); //ɾ�����Ļ��з�

	vector<string>str_list;
	int comma_n = 0;
	while (1) {

		string tmp_s = "";				//"����"�Ƿָ���
		const char* ccfengge = fenge.c_str();
		comma_n = word.find(ccfengge); //���ҷָ�����һ�γ��ֵ�λ��
		if (comma_n == -1) {			//û�ҵ��Ļ�

			str_list.push_back(word);  //��ʣ�µĶ�����ȥ
			break;
		}
		tmp_s = word.substr(0, comma_n);		    //����һ�νض�
		word.erase(0, comma_n + fenge.length());	//����һ��Ĩȥ
		str_list.push_back(tmp_s);					//�ѽضϵ��ַ�����������
	}


	//int sum;								  //�������ı��ּ��γ����� �����ı������#��ʶ��
	for (int i = 0; i < sum; i++) {
		cout << str_list.at(i) << endl;
		system("pause");
	}
}

