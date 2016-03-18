#include "stdafx.h"
#include "GameBuild.h"

//#define random(x) (rand()%x)

using namespace Gcom;
using namespace Gbui;
using namespace std;


int lat;
sqlite3* conn = NULL;
char* sql = "SGB.db";


SQLITE_API int Gbui::Sqlite3_Open()
{
	const char *filename = NULL;   // Database filename (UTF-8) 
	sqlite3 **conn = NULL;          // OUT: SQLite db handle 
	return SQLITE_API int();
}

void Gbui::Open_DB(char* sql)		//打开数据库
{		
	char* err_msg = NULL;
	// char sql[200] = ""; //这东西干啥的我也不清楚==暂时注释掉

	// 打开数据库, 创建连接
	if (sqlite3_open(sql, &conn) != SQLITE_OK)
	{
		cout <<"无法打开,错误代码:"<< sqlite3_errmsg(conn) << endl;
	}
	else 
	{
		cout << "成功打开数据库~\n";
	}
}

void Gbui::Close_DB()	//关闭数据库
{
	char* err_msg = NULL;
	//char sql[200] = ""; //这东西干啥的我也不清楚==暂时注释掉

	// 关闭连接。
	if (sqlite3_close(conn) != SQLITE_OK)
	{
		cout << "无法关闭，错误代码: %s\n" << sqlite3_errmsg(conn) << endl;
		exit(-1);
	}
	else
	{
		cout << "成功关闭数据库~\n";
	}
}

void Gbui::BRandom()	//大建随机函数
{
	cout << endl;
	int md;
	int a = 0;
	int b = 600;				//首先设随机数空间为[1,600)
	srand((unsigned)time(NULL));
	md = (rand() % (b - a)) + a;//产生[a,b)的随机整数

	//感谢无哥提供算法,赞美无哥.这算法已经被我魔改了 如果您发现算法有误 请通知我 谢谢~
	//设x为被除数,公式:(md/x)+第一个=最后一个
	//一共50个数,通过下列算法随机抽取(数字为每艘船的编号)

	if (md <= 300)				    //当随机抽取的md <=300的时候 出现1-23的概率为50%
	{								//驱逐舰的抽取
		int S1 = 0;
		S1 = ((md / 13.63) + 1);	
		SelectUser(S1);
	}
	else if (md > 300 && md <= 510)	//当随机抽取的md >300并且<=510的时候 出现24-39的概率为35%
	{								//战列舰的抽取
		int S2 = 0;
		S2 = ((md - 300) / 14) +24;
		SelectUser(S2);
	}
	else if (md>510 && md <= 570)	//当随机抽取的md >=510并且<=570的时候 出现40-47的概率为10%
	{								//航母的抽取
		 int S3 = 0;
		 S3 = ((md - 510) / 8.57) + 40;
		 SelectUser(S3);
	}
	else if (md > 570)			    //当随机抽取的md >570的时候 出现47-50的概率为5%
	{								//潜艇的抽取
		int S4 = 0;
		S4 = ((md - 570) / 10) + 48;
		SelectUser(S4);
	}
	
		 
	
	
}
/*
void Gbui::Sql_MD(string name, string fenge, int sum)
{
	char sql[10];
	cout << "请输入数据库名字(没有将会新建): " << endl;
	cin >> sql;
	Open_DB(sql);

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


	//int sum;										//你想让文本分几次出现呢 请在文本里添加#标识符
	char* sq= "";
	string str_ = "";
	for (int i = 0; i < sum; i++) {
		//cout << str_list.at(i) << endl;
		strcpy_s(sq,1000, str_list.at(i).c_str());
		ExecSQL(sq);

		system("pause");
		delete [] sq;
	}
}*/

void Gbui::ExecSQL(char * sql)
{
	sqlite3_exec(conn, sql, UserResult, 0, 0);
}

char ** Gbui::SrawQuery(char * sql, int * row, int * column, char ** result)
{
	sqlite3_get_table(conn, sql, &result, row, column, 0);
	return result;
}

int Gbui::UserResult(void *NotUsed, int argc, char **argv, char **azColName)	//将Selectuserd建造出来的数据输出存储
{	
	
	char* Arg_s[15];
	for (int i = 0; i < argc; i++)
	{
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << ". ";
		Arg_s[i] = (argv[i] ? argv[i] : "NULL");	
		RetBu(Arg_s[i]);	//将属性传递出去
		//cout <<  Arg_s[i] << endl;
	}
	Gcom::Save(Arg_s);
	
	cout << endl;
	
	return 0;
} 

string Gbui::RetBu(string BU)
{
	return BU;
}

int Gbui::SelectUser(int bu) //调出数据函数
{	
	
	Open_DB(sql);
	
	char* cErrMsg = "";
	char s[4] = "";	
	sprintf_s(s,"%d",bu);
	s[2] = ';';
	char d[100] = "SELECT * FROM SG WHERE ID = ";
	strcat_s(d, s);
	//cout << s;

	int res = sqlite3_exec(conn,d, UserResult, NULL, &cErrMsg);	//调用sqlite3_exec.直接往里输sql命令就好啦~

	if (res != SQLITE_OK)
	{

		cout << "查询失败: " << cErrMsg << endl;
		Close_DB();
		return false;
	}
	else
	{
		//
	}
	Close_DB();
	return 0;
}

int Gbui::LA_T(int l)
{
	lat += l;
	cout << "提督咱的辣条数为:" << lat << "根~" << endl;
	return lat;
}

void Gbui::SGbuild()
{
	cout << "提督咱现在有:" << lat << " 根辣条~" << endl;
	cout << "每次建造需要一根辣条,请问要来一发吗?0v0" << endl;
	if (lat>=1)
	{
		BRandom();
		lat -= 1;
		cout << "请输入..返回啦" << endl;
	}
	else
	{
		cout << "提督咱的辣条不够呢,就不要强行建造啦.\n";
		cout << "出征,或者完成主线剧情or支线剧情都可以获得辣条哦0v0" << endl;
		cout << "请输入..返回啦";
	}
}

