#pragma once 
#define  __INCLUDE_SQL_LITE_HELPER_H__  
#include <iostream>
#include "sqlite3.h"
#include <time.h>  
#include <stdlib.h>  
#include<iomanip>
#include<string>
#include <afx.h>

#include <locale>
#include <cstdlib>
#include<vector>

#pragma comment(lib, "sqlite3.lib")
using namespace std;

namespace Gbui
{	
	
	void Open_DB(char* sql);
	void Close_DB();
	void SGbuild();
	int UserResult(void * NotUsed, int argc, char ** argv, char ** azColName);			//���������
	SQLITE_API int Sqlite3_Open();
	int SelectUser(int bu);  //����󽨳�������
	void BRandom();			 //���������,������0v0
	int LA_T(int l);	//��������ר�ú���ֻҪ998

	char* G2U(const char* gb2312);
	char* U2G(const char* utf8);
	void ExecSQL(char *sql);
	char **SrawQuery(char *sql, int *row, int *column, char **result);
	void SQL_();
	//string SGO;
}