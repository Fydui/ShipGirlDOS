#pragma once
#include<string>
#include <iostream>
#include<vector>
#include "GameStart.h"
#include <fstream>

using namespace std;

namespace Gcom {
	void Start();		//我是开始命令
	void Help();		//窝是萌萌的帮助~
	void Exit();		//我是退出哦
	void Continue();	//我,,我是继续0w0
	void SGedit();		//舰队编辑
	void Ret();			//窝是返回咯
	
	vector<string> Split(string o_str, string fenge);	//这个是分割文本的,用来实现按一下出现一段文本,需要和楼下读出配合食用~     --来自凯哥的倾情赞助
	string ReadFile(string name);						//这个是一下子能把文本全读出来的神奇函数,和上面是基友..                  --来自凯哥的倾情赞助
}
