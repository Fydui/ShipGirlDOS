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
	void Start();		//我是开始命令
	void Help();		//窝是萌萌的帮助~
	void Exit();		//我是退出哦
	void Load();		//读取
	void Save(char** Arg_s);		//保存
	void SGedit();		//舰队编辑
	void Ret();			//窝是返回
	void in_ini(string id,int lv);		//读取ini
	void ou_ini();		//写入ini
	int GK_Num();	//关卡计数 
	void Ship_Check(); //和存档有关,读取存档检查新建造的是否是重复的船
	vector<string> Split(string o_str, string fenge);	//这个是分割文本的,用来实现按一下出现一段文本,需要和楼下读出配合食用~     --来自凯哥的倾情赞助
	string ReadFile(string name);						//这个是一下子能把文本全读出来的神奇函数,和上面是基友..                  --来自凯哥的倾情赞助
}
