#include "stdafx.h"
#include "GameBuild.h"

//#define random(x) (rand()%x)

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

char* Gbui::U2G(const char* utf8)
{
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wstr, len);
	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}

void Gbui::ExecSQL(char * sql)
{
	sqlite3_exec(conn, sql, UserResult, 0, 0);
}

char ** Gbui::SrawQuery(char * sql, int * row, int * column, char ** result)
{
	sqlite3_get_table(conn, sql, &result, row, column, 0);
	return result;
}
/*
void Gbui::SQL_()
{
	Gbui::Open_DB(sql);
	char* sql3 = "CREATE TABLE SG(\
						ID INTEGER PRIMARY KEY AUTOINCREMENT,\
						CLASS TEXT, NAME TEXT,\
						ATK INTEGER, HP INTEGER,\
						ARMOR INTEGER, CONSUME INTEGER,\
						PLANE INTEGER, AAIR INTEGER,\
						TORPEDO INTEGER, ASUB INTEGER,\
						BUILD INTEGER, TXT TEXT ); ";
	Gbui::ExecSQL(sql3);
	
	char* sql_1 = "INSERT INTO SG VALUES (1,'CL','夕张',30,30,20,40,0,30,40,30,35,'高科技清醒巡洋舰夕张报告,我就是IJN的科技结晶!');";
	Gbui::ExecSQL(sql_1);
	char* sql_2 = "INSERT INTO SG VALUES (2,'DD','空想',20,20,20,30,0,30,60,50,40,'急如空想!空想号驱逐舰哦~来追我呀~');";
	Gbui::ExecSQL(sql_2);
	char* sql_3 = "INSERT INTO SG VALUES (3,'CA','昆西',50,60,50,40,0,30,0,0,30,'昆西崑西崑~Quincy OvO~重性巡洋舰昆西加入');";
	Gbui::ExecSQL(sql_3);
	char* sql_4 = "INSERT INTO SG VALUES (4,'DD','岛风',20,20,15,30,0,30,60,50,40,'嘿嘿,是岛风啦,谁也追不上我哦！空想?');";
	Gbui::ExecSQL(sql_4);
	char* sql_5 = "INSERT INTO SG VALUES (5,'DD','欧根亲王',50,60,50,40,0,30,0,0,30,'欧根欧根欧~很高兴成为您的护卫舰...我会好好保护您的...请多指教');";
	Gbui::ExecSQL(sql_5);
	char* sql_6 = "INSERT INTO SG VALUES (6,'CA','爱宕',40,45,35,40,0,0,0,20,35,'人家叫是爱宕(dàng)啦,提督一点也不可爱');";
	Gbui::ExecSQL(sql_6);
	char* sql_7 = "INSERT INTO SG VALUES (7,'DD','基林',10,20,10,40,0,10,20,30,30,'基林级驱逐舰首舰基...呜，咬到舌头了……');";
	Gbui::ExecSQL(sql_7);
	char* sql_8 = "INSERT INTO SG VALUES (8,'DD','吹雪',10,15,10,40,0,10,20,20,20,'你才是欠雷!我是吹雪型驱逐舰首舰吹雪号~');";
	Gbui::ExecSQL(sql_8);
	char* sql_9 = "INSERT INTO SG VALUES (9,'CL','海伦娜',35,30,30,40,0,30,0,25,30,'我是轻巡洋舰，海伦娜号...请别用这样的眼神看着我，我真的是轻巡洋舰哦。');";
	Gbui::ExecSQL(sql_9);
	char* sql_10 = "INSERT INTO SG VALUES (10,'DD','响',10,15,10,40,0,10,30,20,40,'那个。。对不起，我是响号驱逐舰。');";
	Gbui::ExecSQL(sql_10);
	char* sql_11 = "INSERT INTO SG VALUES (11,'CL','037',40,40,40,40,0,40,40,40,20,'首长,,啊不提督好..037战列..啊不,037猎潜艇向您报到!');";
	Gbui::ExecSQL(sql_11);
	char* sql_12 = "INSERT INTO SG VALUES (12,'DD','07鞍山',15,20,15,40,0,10,20,30,30,'07形驱逐舰鞍山级鞍山号向您报到~');";
	Gbui::ExecSQL(sql_12);
	char* sql_13 = "INSERT INTO SG VALUES (13,'DD','Z16',10,20,10,40,0,10,25,20,30,'你好长官，我是Z系驱逐舰Z16号。我会好好加油的！');";
	Gbui::ExecSQL(sql_13);
	char* sql_14 = "INSERT INTO SG VALUES (14,'DD','萤火虫',10,15,10,40,0,15,20,30,35,'减速减速！啊呼...这里是G级驱逐舰的萤火虫号，指挥官您愿意和我做朋友吗？');";
	Gbui::ExecSQL(sql_14);
	char* sql_15 = "INSERT INTO SG VALUES (15,'DD','Z1',10,20,10,40,0,10,25,20,20,'Z系列一号舰，Z1.这个。。。那个。。。您好！');";
	Gbui::ExecSQL(sql_15);
	char* sql_16 = "INSERT INTO SG VALUES (16,'DD','绫波',10,15,10,40,0,10,30,20,42,'驱逐舰，绫波。为提督效力');";
	Gbui::ExecSQL(sql_16);
	char* sql_17 = "INSERT INTO SG VALUES (17,'CL','平海',20,20,13,40,0,12,16,20,40,'天朝驱逐舰平海报道!平海会越来越厉害，我们的海军梦一定会实现！');";
	Gbui::ExecSQL(sql_17);
	char* sql_18 = "INSERT INTO SG VALUES (18,'CL','宁海',20,20,13,40,0,12,16,20,40,'轻巡洋舰，宁海。虽然我不是中国出身，但身为中国的战舰也感到非常高兴。');";
	Gbui::ExecSQL(sql_18);
	char* sql_19 = "INSERT INTO SG VALUES (19,'CL','逸仙',12,18,10,40,0,20,10,25,30,'在下逸仙，是中国自行设计的战舰.');";
	Gbui::ExecSQL(sql_19);
	char* sql_20 = "INSERT INTO SG VALUES (20,'CL','曙光女神',17,14,15,40,0,28,10,28,30,'神的曙光将照耀着您.轻型巡洋舰曙光女神。');";
	Gbui::ExecSQL(sql_20);
	char* sql_21 = "INSERT INTO SG VALUES (21,'DD','雪风',10,16,10,40,0,20,24,21,40,'炎阳型驱逐舰八号舰,雪风!绝对、大丈夫！');";
	Gbui::ExecSQL(sql_21);
	char* sql_22 = "INSERT INTO SG VALUES (22,'DD','马汉',10,16,10,40,0,10,24,25,30,'我是DD-364马汉号。无尽的大海中蕴含着无尽的梦想！守护大海的职责就交给我吧！');";
	Gbui::ExecSQL(sql_22);
	char* sql_23 = "INSERT INTO SG VALUES (23,'CA','肯特',40,50,40,50,0,35,30,0,40,'肯特号重型巡洋舰,,,,呜……装甲薄弱也不是我的错啊……')";
	Gbui::ExecSQL(sql_23);
	char* sql_24 = "INSERT INTO SG VALUES (24,'BB','俾斯麦',80,90,80,90,0,40,0,0,50,'德意志的科(通)学(海)技(阀)术世界第一！！！');";
	Gbui::ExecSQL(sql_24);
	char* sql_25 = "INSERT INTO SG VALUES (25,'BB','华盛顿',88,74,72,95,0,60,0,0,50,'提督您号,当自由受到威胁，我便会挺身而出。')";
	Gbui::ExecSQL(sql_25);
	char* sql_26 = "INSERT INTO SG VALUES (27,'BB','密苏里',85,85,80,80,0,70,0,0,50,'密苏里号战列舰向您报到,很期待之后的生活呢.');";
	Gbui::ExecSQL(sql_26);
	char* sql_27 = "INSERT INTO SG VALUES (27,'BB','密苏里',85,85,80,80,0,70,0,0,50,'密苏里号战列舰向您报到,很期待之后的生活呢.');";
	Gbui::ExecSQL(sql_27);
	char* sql_28 = "INSERT INTO SG VALUES (28,'BB','胡德',70,75,70,70,0,50,0,0,50,'贵安，我是皇家海军的荣耀，胡德。提督，要来一杯红茶么?');";
	Gbui::ExecSQL(sql_28);
	char* sql_29 = "INSERT INTO SG VALUES (29,'BB','维内托',80,75,78,90,0,40,0,0,40,'Buongiorno signor ammiraglio有幸与提督会面，接下来的军务有劳提督协助我一同处理.');";
	Gbui::ExecSQL(sql_29);
	char* sql_30 = "INSERT INTO SG VALUES (30,'BB','狮',85,80,80,90,0,60,0,0,50,'妾身终于可以和大哥并肩作战了呢');";
	Gbui::ExecSQL(sql_30);
	char* sql_31 = "INSERT INTO SG VALUES (31,'BB','大和',90,90,88,90,0,60,0,0,60,'准备好了吗？在拂晓的水平线上刻下胜利吧！');";
	Gbui::ExecSQL(sql_31);
	char* sql_32 = "INSERT INTO SG VALUES (32,'BB','声望',83,65,60,70,0,60,0,0,30,'声望级战列巡洋舰1号舰，声望在此。战斗和侍奉都会潇洒应对。');";
	Gbui::ExecSQL(sql_32);
	char* sql_33 = "INSERT INTO SG VALUES (33,'BB','反击',83,65,60,70,0,60,0,0,30,'声望级战列巡洋舰2号舰，反击在此。今后您就是我的主人了');";
	Gbui::ExecSQL(sql_33);
	char* sql_34 = "INSERT INTO SG VALUES (34,'BB','威尔士亲王',80,75,80,90,0,70,0,0,40,'提督，我们今天砍谁？');";
	Gbui::ExecSQL(sql_34);
	char* sql_35 = "INSERT INTO SG VALUES (35,'BB','扶桑',75,67,60,85,0,30,0,0,40,'超弩级战列舰，扶桑。和妹妹山城一起请多关照。');";
	Gbui::ExecSQL(sql_35);
	char* sql_36 = "INSERT INTO SG VALUES (36,'BB','山城',75,67,60,80,0,30,0,0,40,'小女子山城，请多指教……');";
	Gbui::ExecSQL(sql_36);
	char* sql_37 = "INSERT INTO SG VALUES (37,'BB','日向',80,75,70,85,0,30,0,0,30,'不要试图隐藏了，我早已看穿了你的一切');";
	Gbui::ExecSQL(sql_37);
	char* sql_38 = "INSERT INTO SG VALUES (38,'BB','伊势',80,75,70,85,0,30,0,0,30,'提督,要一起去看海吗?');";
	Gbui::ExecSQL(sql_38);
	char* sql_39 = "INSERT INTO SG VALUES (39,'BB','安德烈亚多利亚',60,60,60,70,0,40,0,0,30,'我叫安德烈亚·多利亚！不是秋月爱莉！再说错轰飞你哦！');";
	Gbui::ExecSQL(sql_39);
	char* sql_40 = "INSERT INTO SG VALUES(40,'CV','列克星敦',35,60,50,55,80,70,50,30,40,'长官您好,这里是列克星敦号航空母舰~');";
	Gbui::ExecSQL(sql_40);
	char* sql_41 = "INSERT INTO SG VALUES(41,'CV','萨拉托加',35,60,50,55,80,80,50,30,40,'萨拉托航母加报告,您有看见我姐姐吗?');";
	Gbui::ExecSQL(sql_41);
	char* sql_42 = "INSERT INTO SG VALUES(42,'CV','埃塞克斯',30,60,50,60,90,60,50,30,30,'埃塞克斯航空母舰就绪~你才是饺子!你才是CV-⑨!');";
	Gbui::ExecSQL(sql_42);
	char* sql_43 = "INSERT INTO SG VALUES(43,'CV','企业',30,50,40,55,80,70,50,40,40,'企业航空母舰，向您报道,让对面一起上♀吧.');";
	Gbui::ExecSQL(sql_43);
	char* sql_44 = "INSERT INTO SG VALUES(44,'CV','翔鹤',40,62,60,30,75,60,40,40,40,'翔鹤号空母参上。啊啦~这就是提督嘛~');";
	Gbui::ExecSQL(sql_44);
	char* sql_45 = "INSERT INTO SG VALUES(45,'CV','瑞鹤',40,62,60,30,75,60,40,40,40,'瑞鹤号航空母舰。作为最新锐的空母，很想在战场上大显身手呢');";
	Gbui::ExecSQL(sql_45);
	char* sql_46 = "INSERT INTO SG VALUES(46,'CV','赤城',30,70,32,60,90,70,50,20,50,'提督提督~咱吃,,,啊不,咱跟定你了~');";
	Gbui::ExecSQL(sql_46);
	char* sql_47 = "INSERT INTO SG VALUES(47,'CV','加贺',30,70,32,60,90,70,50,20,50,'加贺号空母.饭后来瓶清酒真是难得的享受啊。提督，你也来一杯？');";
	Gbui::ExecSQL(sql_47);
	char* sql_48 = "INSERT INTO SG VALUES (48,'SS','大青花鱼',10,12,10,15,0,0,60,40,20,'鱼，好大的鱼，大青花鱼~人家是潜艇啦');";
	Gbui::ExecSQL(sql_48);
	char* sql_49 = "INSERT INTO SG VALUES (49,'SS','射水鱼',10,12,10,15,0,0,60,40,20,'我是射水鱼号潜艇。嘘，小声点，不要惊动敌人。');";
	Gbui::ExecSQL(sql_49);
	char* sql_50 = "INSERT INTO SG VALUES (50,'SS','M1',30,12,10,20,0,0,50,30,20,'M级重炮潜艇M1号，前来支援舰队咯~！在敌人看不见的地方给她来上一炮吧！');";
	Gbui::ExecSQL(sql_50);

	char* sql4 = "CREATE TABLE SG_S (\
					 ID INTEGER PRIMARY KEY AUTOINCREMENT,\
					 CLASS TEXT, NAME TEXT, ATK INTEGER,\
					 HP INTEGER, ARMOR INTEGER,CONSUME INTEGER,\
					 PLANE INTEGER,AAIR INTEGER, TORPEDO INTEGER,\
					 ASUB INTEGER, TXT TEXT); ";
	Gbui::ExecSQL(sql4);
	char* sql_51 = "INSERT INTO SG_S VALUES (1,'CL','夕张',50,35,35,50,0,50,70,60,'夕张号改装完毕,白大褂很帅哦~');";
	Gbui::ExecSQL(sql_51);
	char* sql_52 = "INSERT INTO SG_S VALUES (2,'DD','空想',40,37,34,40,0,60,80,80,'急如空想!空想号改装好啦,提督你肯定追不上我~');";
	Gbui::ExecSQL(sql_52);
	char* sql_53 = "INSERT INTO SG_S VALUES (3,'CA','昆西',70,58,56,40,0,50,0,0,'昆西号改,,咦?我台词本呢.提~督!还给我啦!');";
	Gbui::ExecSQL(sql_53);
	char* sql_54 = "INSERT INTO SG_S VALUES (4,'DD','岛风',36,36,40,40,0,60,100,50,'啦啦啦,岛风号改装了呢,速度更快了哦.');";
	Gbui::ExecSQL(sql_54);
	char* sql_55 = "INSERT INTO SG_S VALUES (5,'CA','欧根亲王',60,70,70,40,0,60,50,0,'欧根欧根欧~欧根亲王改装完毕,阿古斯之盾将守护您到永远.');";
	Gbui::ExecSQL(sql_55);
	char* sql_56 = "INSERT INTO SG_S VALUES (6,'CA','爱宕',60,45,50,40,0,48,60,0,'最强宙斯盾..不对,重巡巡洋舰爱宕改装完毕,再叫错就不理你哦!');";
	Gbui::ExecSQL(sql_56);
	char* sql_57 = "INSERT INTO SG_S VALUES (7,'CA','基林',30,20,23,40,0,50,70,60,'基林号改装好了,嘿嘿我是不是很厉害?呜，咬到舌头了……');";
	Gbui::ExecSQL(sql_57);
	char* sql_58 = "INSERT INTO SG_S VALUES (8,'DD','吹雪',30,15,20,40,0,40,77,50,'胡说!叫欠雪也不行,不行不行不行~');";
	Gbui::ExecSQL(sql_58);
	char* sql_59 = "INSERT INTO SG_S VALUES (9,'CL','海伦娜',70,48,57,40,0,85,0,75,'海伦娜改造完毕,任何敌人都将毁灭于152舰炮之下.');";
	Gbui::ExecSQL(sql_59);
	char* sql_60 = "INSERT INTO SG_S VALUES (10,'DD','信赖',35,35,40,40,0,48,82,70,'从现在开始,我就是信赖了.有点怀念第六驱逐舰队的小伙伴了呢……');";
	Gbui::ExecSQL(sql_60);
	char* sql_61 = "INSERT INTO SG_S VALUES (11,'CL','037',70,70,70,70,0,50,70,80,'首长,,啊不提督好..037战列..啊不,037猎潜艇向您报到!');";
	Gbui::ExecSQL(sql_61);
	char* sql_62 = "INSERT INTO SG_S VALUES (12,'DD','07鞍山',30,20,23,40,0,50,60,50,'鞍山号改造完毕,不知道果敢妹妹在哪儿.');";
	Gbui::ExecSQL(sql_62);
	char* sql_63 = "INSERT INTO SG_S VALUES (13,'DD','Z16',38,38,40,40,0,64,80,60,'嗯哼~Z16变成大人了哦~');";
	Gbui::ExecSQL(sql_63);
	char* sql_64 = "INSERT INTO SG_S VALUES (14,'DD','萤火虫',38,30,50,40,0,50,80,70,'维多利亚十字勋章的光芒仍然不及您所做的荣耀无畏之举！啊?这个勋章是给我的吗?谢谢提督~');";
	Gbui::ExecSQL(sql_64);
	char* sql_65 = "INSERT INTO SG_S VALUES (15,'DD','Z1',38,38,40,40,0,64,80,60,'Z1改造好咯.咦，这是什么奇怪的装备？我会像姐姐一样努力的~');";
	Gbui::ExecSQL(sql_65);
	char* sql_66 = "INSERT INTO SG_S VALUES (16,'DD','绫波',40,30,38,40,0,48,95,60,'雪型11号舰，绫波。改造完毕');";
	Gbui::ExecSQL(sql_66);
	char* sql_67 = "INSERT INTO SG_S VALUES (17,'CL','平海',48,35,39,40,0,40,66,70,'平海越来越厉害了！照这样下去我们的海军梦就能实现了！');";
	Gbui::ExecSQL(sql_67);
	char* sql_68 = "INSERT INTO SG_S VALUES(18, 'CL', '宁海', 48, 35, 39, 40, 0, 40, 66, 70, '感谢提督给予我改造的机会，我不会辜负您的期望的。');";
	Gbui::ExecSQL(sql_68);
	char* sql_69 = "INSERT INTO SG_S VALUES (19,'CL','逸仙',37,20,30,40,0,50,60,65,'哎?新衣服?谢谢,,提督,,在下会更加努力的');#";
	Gbui::ExecSQL(sql_69);
	char* sql_70 = "INSERT INTO SG_S VALUES (20,'CL','重庆',50,40,42,40,0,66,60,78,'来自皇家海军的银色妖精，重庆号愿胜利的曙光与人民同在，时刻准备着！');";
	Gbui::ExecSQL(sql_70);
	char* sql_71 = "INSERT INTO SG_S VALUES (21,'DD','雪风',16,30,20,40,0,50,75,50,'炎阳型驱逐舰八号舰,雪风!绝对、大丈夫！');";
	Gbui::ExecSQL(sql_71);
	char* sql_72 = "INSERT INTO SG_S VALUES (22,'DD','马汉',16,29,22,40,0,40,74,55,'不要问我王朝是谁！张龙赵虎也不认识！！');";
	Gbui::ExecSQL(sql_72);
	char* sql_73 = "INSERT INTO SG_S VALUES (23,'CA','肯特',64,60,45,40,0,75,60,0,'肯特号重型巡洋舰,,,,呜……好像被欺负了……');";
	Gbui::ExecSQL(sql_73);
	char* sql_74 = "INSERT INTO SG_S VALUES (24,'BB','俾斯麦',180,100,100,90,0,67,0,0,'已经没有人能阻止我前进了,请铭记在心。');";
	Gbui::ExecSQL(sql_74);
	char* sql_75 = "INSERT INTO SG_S VALUES (25,'BB','华盛顿',170,80,92,90,0,90,0,0,'我是北卡罗来纳级，华盛顿号战列舰,改造完毕,我将继续为自由而战!');";
	Gbui::ExecSQL(sql_75);
	char* sql_76 = "INSERT INTO SG_S VALUES (26,'BB','科罗拉多',160,77,91,95,0,65,0,0,'科罗拉多号改装好了.多谢提督.要出去散步吗~');";
	Gbui::ExecSQL(sql_76);
	char* sql_77 = "INSERT INTO SG_S VALUES (27,'BB','密苏里',190,110,100,100,0,100,0,0,'密苏里号宇宙战舰改造完毕.曲率引擎启动中.');";
	Gbui::ExecSQL(sql_77);
	char* sql_78 = "INSERT INTO SG_S VALUES (28,'BB','胡德',180,80,87,100,0,85,0,0,'经过精心的改造，重点强化了水平装甲，这次应该没问题了蛐蛐俾斯麦别跑!');";
	Gbui::ExecSQL(sql_78);
	char* sql_79 = "INSERT INTO SG_S VALUES (29,'BB','维内托',170,85,98,90,0,62,0,0,'Buongiorno signor ammiraglio有幸与提督会面，接下来的军务有劳提督协助我一同处理.');";
	Gbui::ExecSQL(sql_79);
	char* sql_80 = "INSERT INTO SG_S VALUES (30,'BB','狮',185,95,90,90,0,95,0,0,'妾身终于可以和大哥并肩作战了呢');";
	Gbui::ExecSQL(sql_80);
	char* sql_81 = "INSERT INTO SG_S VALUES (31,'BB','大和',180,100,100,100,0,100,0,0,'准备好了吗？在拂晓的水平线上刻下胜利吧！');#";
	Gbui::ExecSQL(sql_81);
	char* sql_82 = "INSERT INTO SG_S VALUES (32,'BB','声望',180,80,80,90,0,90,0,0,'瀟洒瀟洒瀟洒瀟洒！已經沒有什麼能阻擋我了！');";
	Gbui::ExecSQL(sql_82);
	char* sql_83 = "INSERT INTO SG_S VALUES (33,'BB','反击',180,80,80,90,0,90,0,0,'主人,反击号改装完毕,今后能更好的为主人服务了');";
	Gbui::ExecSQL(sql_83);
	char* sql_84 = "INSERT INTO SG_S VALUES (34,'BB','威尔士亲王',180,100,100,90,0,67,0,0,'再看不到您，我可能就真的忘记您了，这可不是在开玩笑.');";
	Gbui::ExecSQL(sql_84);
	char* sql_85 = "INSERT INTO SG_S VALUES (35,'BB','扶桑',160,75,80,80,0,80,0,0,'超弩级战列舰，扶桑改造完毕。加强了装甲.');";
	Gbui::ExecSQL(sql_85);
	char* sql_86 = "INSERT INTO SG_S VALUES (36,'BB','山城',160,75,80,80,0,80,0,0,'感谢提督赐予小女子改造的机会,我会和姐姐一样努力');";
	Gbui::ExecSQL(sql_86);
	char* sql_87 = "INSERT INTO SG_S VALUES (37,'BB','日向',170,80,80,90,40,50,0,0,'不要试图隐藏了，我早已看穿了你的一切');";
	Gbui::ExecSQL(sql_87);
	char* sql_88 = "INSERT INTO SG_S VALUES (38,'BB','伊势',170,80,80,90,40,50,0,0,'提督,要一起去看海吗?');";
	Gbui::ExecSQL(sql_88);
	char* sql_89 = "INSERT INTO SG_S VALUES (39,'BB','安德烈亚多利亚',175,75,80,90,0,70,0,0,'安德烈亚多利亚，现代化改装归来！！');";
	Gbui::ExecSQL(sql_89);
	char* sql_90 = "INSERT INTO SG_S VALUES(40,'CA','列克星敦',50,90,70,70,100,100,60,40,'休假完毕~哎,提..提督,这个小盒子是给我的吗?');";
	Gbui::ExecSQL(sql_90);
	char* sql_91 = "INSERT INTO SG_S VALUES(41,'CA','萨拉托加',50,90,70,70,100,100,60,40,'嗯~~我休息的非常舒服哦，接下来要更加努力了！');";
	Gbui::ExecSQL(sql_91);
	char* sql_92 = "INSERT INTO SG_S VALUES(42,'CA','埃塞克斯',45,80,70,90,120,120,70,60,'不要再叫我CV⑨啦,我生气了!');";
	Gbui::ExecSQL(sql_92);
	char* sql_93 = "INSERT INTO SG_S VALUES(43,'CA','企业',50,75,70,90,100,120,60,50,'企业航空母舰，向您报道,让对面一起上♀吧.');";
	Gbui::ExecSQL(sql_93);
	char* sql_94 = "INSERT INTO SG_S VALUES(44,'CA','翔鹤',50,80,70,80,110,90,60,60,'翔鹤号空母参上。啊啦~这就是提督嘛~');";
	Gbui::ExecSQL(sql_94);
	char* sql_95 = "INSERT INTO SG_S VALUES(45,'CA','瑞鹤',50,80,70,80,110,90,60,60,'瑞鹤号航空母舰。作为最新锐的空母，很想在战场上大显身手呢');";
	Gbui::ExecSQL(sql_95);
	char* sql_96 = "INSERT INTO SG_S VALUES(46,'CA','赤城',45,85,75,80,95,95,60,60,'提督提督~咱吃,,,啊不,咱跟定你了~');";
	Gbui::ExecSQL(sql_96);
	char* sql_97 = "INSERT INTO SG_S VALUES(47,'CA','加贺',45,85,75,80,95,95,60,60,'加贺号空母.饭后来瓶清酒真是难得的享受啊。提督，你也来一杯？');";
	Gbui::ExecSQL(sql_97);
	char* sql_98 = "INSERT INTO SG_S VALUES(48,'SS','大青花鱼',40,40,40,40,0,0,150,90,'鱼,好大的鱼,大青花鱼~,人家是潜艇啦~');";
	Gbui::ExecSQL(sql_98);
	char* sql_99 = "INSERT INTO SG_S VALUES (49,'SS','射水鱼',40,40,40,40,0,0,150,90,'我是射水鱼号潜艇。嘘，小声点，不要惊动敌人。');";
	Gbui::ExecSQL(sql_99);
	char* sql_100 = "INSERT INTO SG_S VALUES (50,'SS','M1',50,25,30,40,0,0,110,90,'M级重炮潜艇M1号，前来支援舰队咯~！在敌人看不见的地方给她来上一炮吧！');";
	Gbui::ExecSQL(sql_100);

	char* sql5 = "CREATE TABLE DS (\
		ID      INTEGER PRIMARY KEY AUTOINCREMENT, \
		CLASS TEXT, NAME    TEXT, ATK     INTEGER, \
		HP      INTEGER, ARMOR   INTEGER, \
		PLANE   INTEGER, \
		AAIR    INTEGER, TORPEDO INTEGER, \
		ASUB    INTEGER ); ";
	Gbui::ExecSQL(sql5);
	char* sql_101 = "INSERT INTO DS VALUES (1,'DD','Ⅰ级',10,10,10,0,0,0,0);";
	Gbui::ExecSQL(sql_101);
	char* sql_102 = "INSERT INTO DS VALUES (2,'DD','Ⅲ级 ',30,30,30,0,30,30,30);";
	Gbui::ExecSQL(sql_102);
	char* sql_103 = "INSERT INTO DS VALUES (3,'DD','Ⅵ级',40,40,40,0,40,40,40);";
	Gbui::ExecSQL(sql_103);
	char* sql_104 = "INSERT INTO DS VALUES (4,'DD','Ⅷ级',50,50,50,0,60,50,50);";
	Gbui::ExecSQL(sql_104);
	char* sql_105 = "INSERT INTO DS VALUES (5,'CL','X级',60,60,60,0,50,70,60);";
	Gbui::ExecSQL(sql_105);
	char* sql_106 = "INSERT INTO DS VALUES (6,'CL','S级',70,70,40,0,80,90,80);";
	Gbui::ExecSQL(sql_106);
	char* sql_107 = "INSERT INTO DS VALUES (7,'BB','MK1',50,50,50,0,30,0,0);";
	Gbui::ExecSQL(sql_107);
	char* sql_108 = "INSERT INTO DS VALUES (8,'BB','MK2',60,60,50,0,50,0,0);";
	Gbui::ExecSQL(sql_108);
	char* sql_109 = "INSERT INTO DS VALUES (9,'BB','MK3',70,70,70,0,70,0,0);";
	Gbui::ExecSQL(sql_109);
	char* sql_110 = "INSERT INTO DS VALUES (10,'BB','MK4',80,80,80,40,70,0,0);";
	Gbui::ExecSQL(sql_110);
	char* sql_111 = "INSERT INTO DS VALUES (11,'BB','MK6',120,120,100,60,70,0,0);";
	Gbui::ExecSQL(sql_111);
	char* sql_112 = "INSERT INTO DS VALUES (12,'BB','MK10',233,233,70,60,90,50,0);";
	Gbui::ExecSQL(sql_112);
	char* sql_113 = "INSERT INTO DS VALUES (13,'CV','α级',30,30,30,30,30,0,0);";
	Gbui::ExecSQL(sql_113);
	char* sql_114 = "INSERT INTO DS VALUES (14,'CV','Δ级',50,50,50,40,50,0,0);";
	Gbui::ExecSQL(sql_114);
	char* sql_115 = "INSERT INTO DS VALUES (15,'CV','Θ级',60,60,60,40,60,0,0);";
	Gbui::ExecSQL(sql_115);
	char* sql_116 = "INSERT INTO DS VALUES (16,'CV','D-LEX',80,80,80,50,80,0,0);";
	Gbui::ExecSQL(sql_116);
	char* sql_117 = "INSERT INTO DS VALUES (17,'CV','D-SAR',100,100,70,100,100,0,0);";
	Gbui::ExecSQL(sql_117);
	char* sql_118 = "INSERT INTO DS VALUES (18,'CV','D-LIA',120,120,70,120,120,0,0);";
	Gbui::ExecSQL(sql_118);
	char* sql_119 = "INSERT INTO DS VALUES (19,'SS','DEEP',0,10,10,0,0,50,40);";
	Gbui::ExecSQL(sql_119);
	char* sql_120 = "INSERT INTO DS VALUES (20,'SS','DARK',0,20,20,0,0,70,50);";
	Gbui::ExecSQL(sql_120);
	char* sql_121 = "INSERT INTO DS VALUES (21,'SS','FANTASY',50,25,20,0,0,90,50);";
	Gbui::ExecSQL(sql_121);
	char* sql_122 = "INSERT INTO DS VALUES (22,'SS','VAN',50,50,40,0,0,120,70);";
	Gbui::ExecSQL(sql_122);

	char* sql2 = "SELECT * FROM DS ORDER BY ID";
	char* sql8 = "SELECT * FROM SG_S ORDER BY ID;";
	char* sql9 = "SELECT * FROM SG ORDER BY ID;";
	Gbui::ExecSQL(sql2);
	Gbui::ExecSQL(sql8);
	Gbui::ExecSQL(sql9);
	int row, col;
	char *eee = "i";
	char **result = &eee;
	char **re = Gbui::SrawQuery(sql2, &row, &col, result);
	//char *ll = U2G(re[(1)*col + 1]); //re是指向数组的指针。(2+1)为第3行，1表示第2列。
	//cout << ll << endl;
	Gbui::Close_DB();
}*/



char* Gbui::G2U(const char* gb2312)
{
	int len = MultiByteToWideChar(CP_ACP, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}

int Gbui::UserResult(void *NotUsed, int argc, char **argv, char **azColName)	//将Selectuserd建造出来的数据输出存储
{	
	//char* Name = new char[50];
	//char* Name[50];
	//char* Arg[50];
	string Name_s[50];
	string Arg_s[50];
	for (int i = 0; i < argc; i++)
	{
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << ". ";
		Name_s[i] = azColName[i];
		Arg_s[i] = (argv[i] ? argv[i] : "NULL");
	}
	cout << endl;
	
	return 0;
} 

int Gbui::SelectUser(int bu) //调出数据函数
{	
	
	Open_DB(sql);
	
	char* cErrMsg = "";
	char s[4] = "";	
	//s[2] = _itoa_s(bu,s,10,10);
	sprintf_s(s,"%d",bu);
	s[2] = ';';

	char d[100] = "SELECT * FROM SG WHERE ID = ";
	
	strcat_s(d, s);
	cout << s;

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

