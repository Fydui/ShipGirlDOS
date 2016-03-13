#include "stdafx.h"
#include "GameCommand.h"

using namespace std;
using namespace Gsta;
//using namespace Gcom;



void Gcom::Start() 
{
	Gsta::GameStart();
}

void Gcom::Continue()
{
	cout << "继续";
}

void Gcom::SGedit()
{
	//
}

void Gcom::Exit() 
{

	cout << "拜拜~记得回来哦~" << endl;
	exit(0);
}
void Gcom::Help() 
{

	system("CLS");		
	string fi = "";		//新建string储存从ReadFile读出来的文本
	fi = ReadFile("./StoryTXT/Help.txt");	
	vector<string>he;	//新建vector储存从Split里切割出来的文本
	he = Split(fi, "#");
	
	int j = 2;			//你想让文本分几次出现呢 请在文本里添加#标识符
	for (int i = 0; i < j; i++) {

		cout << he.at(i) << endl;
		system("pause");
	}
}

void Gcom::Ret()
{
	cout << "输入Ret返回";

}

string Gcom::ReadFile(string name) { //读取文件函数

	ifstream infile(name);			//打开文件
	string word = "";				//全部文本
	string tmp;						//在读的当前行
	while (getline(infile,tmp)){
		word += tmp + "\n";
	}
	word = word.substr(0, word.length() - 2); //删除最后的换行符
	return word;
}

vector<string> Gcom::Split(string o_str, string fenge)
{

	vector<string>str_list;
	int comma_n = 0;
	while (1) {

		string tmp_s = "";				//"这里"是分隔符
		const char* ccfengge = fenge.c_str();
		comma_n = o_str.find(ccfengge); //查找分隔符第一次出现的位置
		if (comma_n == -1) {			//没找到的话

			str_list.push_back(o_str);  //把剩下的都塞进去
			break;
		}
		tmp_s = o_str.substr(0, comma_n);			//把这一段截断
		o_str.erase(0, comma_n + fenge.length());	//把这一段抹去
		str_list.push_back(tmp_s);					//把截断的字符串加入容器
	}

	return str_list;
}

