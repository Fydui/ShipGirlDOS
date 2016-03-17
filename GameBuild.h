#pragma once 
#define  __INCLUDE_SQL_LITE_HELPER_H__  
#include <iostream>
#include "sqlite3.h"
#include <time.h>  
#include <stdlib.h>  
#include<iomanip>
#include<string>
#include <string.h>
#include <cstring>
#include <afx.h>
#include <locale>
#include <cstdlib>
#include<vector>
#include <fstream>

#pragma comment(lib, "sqlite3.lib")
using namespace std;

namespace Gbui
{	
	
	void Open_DB(char* sql);
	void Close_DB();
	void SGbuild();
	int UserResult(void * NotUsed, int argc, char ** argv, char ** azColName);			//输出大建数据
	SQLITE_API int Sqlite3_Open();
	int SelectUser(int bu);  //抽出大建出的数据
	void BRandom();			 //生成随机数,用来大建0v0
	int LA_T(int l);	//辣条计数专用函数只要998
	void ExecSQL(char *sql);
	char **SrawQuery(char *sql, int *row, int *column, char **result);
	string RetBu(string BU);
	//string SGO;
}