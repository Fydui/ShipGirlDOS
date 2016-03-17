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
	cout << "恭喜过关" << endl;
	cout << "你获得五包辣条~" << endl;
	Gbui::LA_T(5);
	Gbui::BRandom();
	//Gsta::GameHom();
}

void Gsto::File_o(string name, string fenge,int sum)
{

	ifstream infile(name);			//打开文件
	string word = "";				//全部文本
	string tmp;						//在读的当前行
	while (getline(infile, tmp)) {
		word += tmp + "\n";
	}
	word = word.substr(0, word.length() - 2); //删除最后的换行符

	vector<string>str_list;
	int comma_n = 0;
	while (1) {

		string tmp_s = "";				//"这里"是分隔符
		const char* ccfengge = fenge.c_str();
		comma_n = word.find(ccfengge); //查找分隔符第一次出现的位置
		if (comma_n == -1) {			//没找到的话

			str_list.push_back(word);  //把剩下的都塞进去
			break;
		}
		tmp_s = word.substr(0, comma_n);		    //把这一段截断
		word.erase(0, comma_n + fenge.length());	//把这一段抹去
		str_list.push_back(tmp_s);					//把截断的字符串加入容器
	}


	//int sum;								  //你想让文本分几次出现呢 请在文本里添加#标识符
	for (int i = 0; i < sum; i++) {
		cout << str_list.at(i) << endl;
		system("pause");
	}
}

