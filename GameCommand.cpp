#include "stdafx.h"
#include "GameCommand.h"

using namespace std;
using namespace Gsta;
//using namespace Gcom;



void Gcom::Start()
{
	Gsto::M_1_1();
}

void Gcom::Save(char** Arg_s)
{
	//将辣条数存进来(未完成)
	//将关卡数存进来(未完成)


	/*char* Arg[5];
	Arg[0] = Arg_s[0];
	ofstream oufile("Load.txt",ios::app);	//打开存档文件 把船id传进来(完成)
	for (int j = 0; j < 2; j++)
		oufile << Arg[j];*/

	cout << "提督,存档成功~" << endl;
}


void Gcom::Load() 
{
	
	ifstream infile("Load.txt");
	if (!infile.is_open())
	{
		cout << "读取文档失败,请不要偷渡欧洲哦~" << endl;
		system("pause");
	}
	while (!infile.eof())
	{	
		char fou[225] = "";
		infile.getline(fou,225);
		Gsta::ou_Load(fou);		
	}
}

void Gcom::SGedit()
{
	//
}

void Gcom::Exit() 
{

	cout << "拜拜~已经存好档了~记得回来哦~" << endl;
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

void Gcom::in_ini(string id, int lv)
{
	string ship_id_key = "ID";
	string ship_lv_key = "LV";
	string o_id = id;
	int o_lv = lv;

	IniFile ini("loadfile.txt");
	if (!ini.write(ship_id_key, o_id))
	{
		cout << "读取存档失败,退出游戏..QAQ" << endl;
		exit(1);
	}
	if (!ini.write(ship_lv_key, o_lv))
	{
		cout << "读取存档失败,退出游戏..QAQ" << endl;
		exit(1);
	}
}

void Gcom::ou_ini()
{
	//
}

int Gcom::GK_Num()
{
	Gk_s++;			 //每调用一次都将关卡数+1
	Gcom::Save(NULL);//然后存档
	return Gk_s++;
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

