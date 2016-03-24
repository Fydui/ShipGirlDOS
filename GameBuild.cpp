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


void Gbui::ExecSQL(char * sql)	//写完用这个添加数据库
{
	sqlite3_exec(conn, sql, UserResult, 0, 0);
}

char ** Gbui::SrawQuery(char * sql, int * row, int * column, char ** result)	
{
	sqlite3_get_table(conn, sql, &result, row, column, 0);
	return result;
}

/*void Gbui::SQL_()
{
	Open_DB(sql);
	char* sq_1 = "CREATE TABLE SG(                           
		ID INTEGER PRIMARY KEY AUTOINCREMENT,            
		CLASS TEXT, NAME TEXT, LV INTEGER,                 
		ATK INTEGER, HP INTEGER,                        
		ARMOR INTEGER, CONSUME INTEGER,                
		PLANE INTEGER, AAIR INTEGER,                     
		BUILD INTEGER, TXT TEXT                         
	ExecSQL(sq_1);
	char* sq_2 = "INSERT INTO SG VALUES (1,'CL','夕张',1,30,30,20,40,0,30,40,30,35,'高科技清醒巡洋舰夕张报告,我就是IJN的科技结晶!');";
	ExecSQL(sq_2);
	char* sq_3 = "INSERT INTO SG VALUES (2,'DD','空想',1,20,20,20,30,0,30,60,50,40,'急如空想!空想号驱逐舰哦~来追我呀~');";
	ExecSQL(sq_3);
	char* sq_4 = "INSERT INTO SG VALUES (3,'CA','昆西',1,50,60,50,40,0,30,0,0,30,'昆西崑西崑~Quincy OvO~重型巡洋舰昆西加入');";
	ExecSQL(sq_4);
	char* sq_5 = "INSERT INTO SG VALUES (4,'DD','岛风',1,20,20,15,30,0,30,60,50,40,'嘿嘿,是岛风啦,谁也追不上我哦！空想?')";
	ExecSQL(sq_5);
	char* sq_6 = "INSERT INTO SG VALUES (5,'DD','欧根亲王',1,50,60,50,40,0,30,0,0,30,'欧根欧根欧~很高兴成为您的护卫舰...我会好好保护您的...请多指教');";
	ExecSQL(sq_6);
	char* sq_7 = "INSERT INTO SG VALUES (6,'CA','爱宕',1,40,45,35,40,0,0,0,20,35,'人家叫是爱宕(dàng)啦,提督一点也不可爱');";
	ExecSQL(sq_7);
	char* sq_8 = "INSERT INTO SG VALUES (7,'DD','基林',1,10,20,10,40,0,10,20,30,30,'基林级驱逐舰首舰基...呜，咬到舌头了……');";
	ExecSQL(sq_8);
	char* sq_9 = "INSERT INTO SG VALUES (8,'DD','吹雪',1,10,15,10,40,0,10,20,20,20,'你才是欠雷!我是吹雪型驱逐舰首舰吹雪号~');";
	ExecSQL(sq_9);
	char* sq_10 = "INSERT INTO SG VALUES (9,'CL','海伦娜',1,35,30,30,40,0,30,0,25,30,'我是轻巡洋舰，海伦娜号...请别用这样的眼神看着我，我真的是轻巡洋舰哦。');";
	ExecSQL(sq_10);
	char* sq_11 = "INSERT INTO SG VALUES (10,'DD','响',1,10,15,10,40,0,10,30,20,40,'那个。。对不起，我是响号驱逐舰。');";
	ExecSQL(sq_11);
	char* sq_12 = "INSERT INTO SG VALUES (11,'CL','037',1,40,40,40,40,0,40,40,40,20,'首长,,啊不提督好..037战列..啊不,037猎潜艇向您报到!');";
	ExecSQL(sq_12);
	char* sq_13 = "INSERT INTO SG VALUES (12,'DD','07鞍山',1,15,20,15,40,0,10,20,30,30,'07形驱逐舰鞍山级鞍山号向您报到~');";
	ExecSQL(sq_13);
	char* sq_14 = "INSERT INTO SG VALUES (13,'DD','Z16',1,10,20,10,40,0,10,25,20,30,'你好长官，我是Z系驱逐舰Z16号。我会好好加油的！');";
	ExecSQL(sq_14);
	char* sq_15 = "INSERT INTO SG VALUES (14,'DD','萤火虫',1,10,15,10,40,0,15,20,30,35,'减速减速！啊呼...这里是G级驱逐舰的萤火虫号，指挥官您愿意和我做朋友吗？');";
	ExecSQL(sq_15);
	char* sq_16 = "INSERT INTO SG VALUES (15,'DD','Z1',1,10,20,10,40,0,10,25,20,20,'Z系列一号舰，Z1.这个。。。那个。。。您好！');";
	ExecSQL(sq_16);
	char* sq_17 = "INSERT INTO SG VALUES (16,'DD','绫波',1,10,15,10,40,0,10,30,20,42,'驱逐舰，绫波。为提督效力');";
	ExecSQL(sq_17);
	char* sq_18 = "INSERT INTO SG VALUES (17,'CL','平海',1,20,20,13,40,0,12,16,20,40,'天朝驱逐舰平海报道!平海会越来越厉害，我们的海军梦一定会实现！');";
	ExecSQL(sq_18);
	char* sq_19 = "INSERT INTO SG VALUES (18,'CL','宁海',1,20,20,13,40,0,12,16,20,40,'轻巡洋舰，宁海。虽然我不是中国出身，但身为中国的战舰也感到非常高兴。');";
	ExecSQL(sq_19);
	char* sq_20 = "INSERT INTO SG VALUES (19,'CL','逸仙',1,12,18,10,40,0,20,10,25,30,'在下逸仙，是中国自行设计的战舰.');";
	ExecSQL(sq_20);
	char* sq_21 = "INSERT INTO SG VALUES (20,'CL','曙光女神',1,17,14,15,40,0,28,10,28,30,'神的曙光将照耀着您.轻型巡洋舰曙光女神。');";
	ExecSQL(sq_21);
	char* sq_22 = "INSERT INTO SG VALUES (21,'DD','雪风',1,10,16,10,40,0,20,24,21,40,'炎阳型驱逐舰八号舰,雪风!绝对、大丈夫！');";
	ExecSQL(sq_22);
	char* sq_23 = "INSERT INTO SG VALUES (22,'DD','马汉',1,10,16,10,40,0,10,24,25,30,'我是DD-364马汉号。无尽的大海中蕴含着无尽的梦想！守护大海的职责就交给我吧！');";
	ExecSQL(sq_23);
	char* sq_24 = "INSERT INTO SG VALUES (23,'CA','肯特',1,40,50,40,50,0,35,30,0,40,'肯特号重型巡洋舰,,,,呜……装甲薄弱也不是我的错啊……');";
	ExecSQL(sq_24);
	char* sq_25 = "INSERT INTO SG VALUES (24,'BB','俾斯麦',1,80,90,80,90,0,40,0,0,50,'德意志的科(通)学(海)技(阀)术世界第一！！！');";
	ExecSQL(sq_25);
	char* sq_26 = "INSERT INTO SG VALUES (25,'BB','华盛顿',1,88,74,72,95,0,60,0,0,50,'提督您号,当自由受到威胁，我便会挺身而出。');";
	ExecSQL(sq_26);
	char* sq_27 = "INSERT INTO SG VALUES (26,'BB','科罗拉多',1,80,77,80,95,0,40,0,0,30,'这里的空气不错呢。BB-45，科罗拉多前来报道。非常期待今后的舰队作战。');";
	ExecSQL(sq_27);
	char* sq_28 = "INSERT INTO SG VALUES (27,'BB','密苏里',1,85,85,80,80,0,70,0,0,50,'密苏里号战列舰向您报到,很期待之后的生活呢.');";
	ExecSQL(sq_28);
	char* sq_29 = "INSERT INTO SG VALUES (28,'BB','胡德',1,70,75,70,70,0,50,0,0,50,'贵安，我是皇家海军的荣耀，胡德。提督，要来一杯红茶么?');";
	ExecSQL(sq_29);
	char* sq_30 = "INSERT INTO SG VALUES (29,'BB','维内托',1,80,75,78,90,0,40,0,0,40,'Buongiorno signor ammiraglio有幸与提督会面，接下来的军务有劳提督协助我一同处理.');";
	ExecSQL(sq_30);
	char* sq_31 = "INSERT INTO SG VALUES (30,'BB','狮',1,85,80,80,90,0,60,0,0,50,'妾身终于可以和大哥并肩作战了呢');";
	ExecSQL(sq_31);
	char* sq_32 = "INSERT INTO SG VALUES (31,'BB','大和',1,90,90,88,90,0,60,0,0,60,'准备好了吗？在拂晓的水平线上刻下胜利吧！');";
	ExecSQL(sq_32);
	char* sq_33 = "INSERT INTO SG VALUES (32,'BB','声望',1,83,65,60,70,0,60,0,0,30,'声望级战列巡洋舰1号舰，声望在此。战斗和侍奉都会潇洒应对。');";
	ExecSQL(sq_33);
	char* sq_34 = "INSERT INTO SG VALUES (33,'BB','反击',1,83,65,60,70,0,60,0,0,30,'声望级战列巡洋舰2号舰，反击在此。今后您就是我的主人了');";
	ExecSQL(sq_34);
	char* sq_35 = "INSERT INTO SG VALUES (34,'BB','威尔士亲王',1,80,75,80,90,0,70,0,0,40,'提督，我们今天砍谁？');";
	ExecSQL(sq_35);
	char* sq_36 = "INSERT INTO SG VALUES (35,'BB','扶桑',1,75,67,60,85,0,30,0,0,40,'超弩级战列舰，扶桑。和妹妹山城一起请多关照。');";
	ExecSQL(sq_36);
	char* sq_37 = "INSERT INTO SG VALUES (36,'BB','山城',1,75,67,60,80,0,30,0,0,40,'小女子山城，请多指教……');";
	ExecSQL(sq_37);
	char* sq_38 = "INSERT INTO SG VALUES (37,'BB','日向',1,80,75,70,85,0,30,0,0,30,'不要试图隐藏了，我早已看穿了你的一切');";
	ExecSQL(sq_38);
	char* sq_39 = "INSERT INTO SG VALUES (38,'BB','伊势',1,80,75,70,85,0,30,0,0,30,'提督,要一起去看海吗?');";
	ExecSQL(sq_39);
	char* sq_40 = "INSERT INTO SG VALUES (39,'BB','安德烈亚多利亚',1,60,60,60,70,0,40,0,0,30,'我叫安德烈亚·多利亚！不是秋月爱莉！再说错轰飞你哦！');";
	ExecSQL(sq_40);
	char* sq_41 = "INSERT INTO SG VALUES(40,'CV','列克星敦',1,35,60,50,55,80,70,50,30,40,'长官您好,这里是列克星敦号航空母舰~');";
	ExecSQL(sq_41);
	char* sq_42 = "INSERT INTO SG VALUES(41,'CV','萨拉托加',1,35,60,50,55,80,80,50,30,40,'萨拉托航母加报告,您有看见我姐姐吗?');";
	ExecSQL(sq_42);
	char* sq_43 = "INSERT INTO SG VALUES(42,'CV','埃塞克斯',1,30,60,50,60,90,60,50,30,30,'埃塞克斯航空母舰就绪~你才是饺子!你才是CV-⑨!');";
	ExecSQL(sq_43);
	char* sq_44 = "INSERT INTO SG VALUES(43,'CV','企业',1,30,50,40,55,80,70,50,40,40,'企业航空母舰，向您报道,让对面一起上♀吧.');";
	ExecSQL(sq_44);
	char* sq_45 = "INSERT INTO SG VALUES(44,'CV','翔鹤',1,40,62,60,30,75,60,40,40,40,'翔鹤号空母参上。啊啦~这就是提督嘛~');";
	ExecSQL(sq_45);
	char* sq_46 = "INSERT INTO SG VALUES(45,'CV','瑞鹤',1,40,62,60,30,75,60,40,40,40,'瑞鹤号航空母舰。作为最新锐的空母，很想在战场上大显身手呢');";
	ExecSQL(sq_46);
	char* sq_47 = "INSERT INTO SG VALUES(46,'CV','赤城',1,30,70,32,60,90,70,50,20,50,'提督提督~咱吃,,,啊不,咱跟定你了~');";
	ExecSQL(sq_47);
	char* sq_48 = "INSERT INTO SG VALUES(47,'CV','加贺',1,30,70,32,60,90,70,50,20,50,'加贺号空母.饭后来瓶清酒真是难得的享受啊。提督，你也来一杯？');";
	ExecSQL(sq_48);
	char* sq_49 = "INSERT INTO SG VALUES (48,'SS','大青花鱼',1,10,12,10,15,0,0,60,40,20,'鱼，好大的鱼，大青花鱼♪(^∇^*)人家是潜艇啦');";
	ExecSQL(sq_49);
	char* sq_50 = "INSERT INTO SG VALUES (49,'SS','射水鱼',1,10,12,10,15,0,0,60,40,20,'我是射水鱼号潜艇。嘘，小声点，不要惊动敌人。');";
	ExecSQL(sq_50);
	char* sq_51 = "INSERT INTO SG VALUES (50,'SS','M1',30,1,12,10,20,0,0,50,30,20,'M级重炮潜艇M1号，前来支援舰队咯~！在敌人看不见的地方给她来上一炮吧！');";
	ExecSQL(sq_51);
	char* sq_52 = "CREATE TABLE SG_S(                     
			ID      INTEGER PRIMARY KEY AUTOINCREMENT, 
			CLASS TEXT, NAME    TEXT, LV INTEGER, ATK  
			HP      INTEGER, ARMOR   INTEGER,          
			CONSUME INTEGER, PLANE   INTEGER,        
			AAIR    INTEGER, TORPEDO INTEGER,        
			ASUB    INTEGER, TXT     TEXT               
			); ";
	ExecSQL(sq_52);
	char* sq_53 = "INSERT INTO SG_S VALUES (1,'CL','夕张',1,50,35,35,50,0,50,70,60,'夕张号改装完毕,白大褂很帅哦~');";
	ExecSQL(sq_53);
	char* sq_54 = "INSERT INTO SG_S VALUES (2,'DD','空想',1,40,37,34,40,0,60,80,80,'急如空想!空想号改装好啦,提督你肯定追不上我~');";
	ExecSQL(sq_54);
	char* sq_55 = "INSERT INTO SG_S VALUES (3,'CA','昆西',1,70,58,56,40,0,50,0,0,'昆西号改,,咦?我台词本呢.提~督!还给我啦!');";
	ExecSQL(sq_55);
	char* sq_56 = "INSERT INTO SG_S VALUES (4,'DD','岛风',1,36,36,40,40,0,60,100,50,'啦啦啦,岛风号改装了呢,速度更快了哦.');";
	ExecSQL(sq_56);
	char* sq_57 = "INSERT INTO SG_S VALUES (5,'CA','欧根亲王',1,60,70,70,40,0,60,50,0,'欧根欧根欧~欧根亲王改装完毕,阿古斯之盾将守护您到永远.');";
	ExecSQL(sq_57);
	char* sq_58 = "INSERT INTO SG_S VALUES (6,'CA','爱宕',1,60,45,50,40,0,48,60,0,'最强宙斯盾..不对,重巡巡洋舰爱宕改装完毕,是爱dàng!再叫错就不理你哦!');";
	ExecSQL(sq_58);
	char* sq_59 = "INSERT INTO SG_S VALUES (7,'CA','基林',1,30,20,23,40,0,50,70,60,'基林号改装好了,嘿嘿我是不是很厉害?呜，咬到舌头了……');";
	ExecSQL(sq_59);
	char* sq_60 = "INSERT INTO SG_S VALUES (8,'DD','吹雪',1,30,15,20,40,0,40,77,50,'胡说!叫欠雪也不行,不行不行不行~');";
	ExecSQL(sq_60);
	char* sq_61 = "INSERT INTO SG_S VALUES (9,'CL','海伦娜',1,70,48,57,40,0,85,0,75,'海伦娜改造完毕,任何敌人都将毁灭于152舰炮之下.');";
	ExecSQL(sq_61);
	char* sq_62 = "INSERT INTO SG_S VALUES (10,'DD','信赖',1,35,35,40,40,0,48,82,70,'从现在开始,我就是信赖了.有点怀念第六驱逐舰队的小伙伴了呢……');";
	ExecSQL(sq_62);
	char* sq_63 = "INSERT INTO SG_S VALUES (11,'CL','037',1,70,70,70,70,0,50,70,80,'首长,,啊不提督好..037战列..啊不,037猎潜艇向您报到!');";
	ExecSQL(sq_63);
	char* sq_64 = "INSERT INTO SG_S VALUES (12,'DD','07鞍山',1,30,20,23,40,0,50,60,50,'鞍山号改造完毕,不知道果敢妹妹在哪儿.');";
	ExecSQL(sq_64);
	char* sq_65 = "INSERT INTO SG_S VALUES (13,'DD','Z16',1,38,38,40,40,0,64,80,60,'嗯哼~Z16变成大人了哦~');";
	ExecSQL(sq_65);
	char* sq_66 = "INSERT INTO SG_S VALUES (14,'DD','萤火虫',1,38,30,50,40,0,50,80,70,'维多利亚十字勋章的光芒仍然不及您所做的荣耀无畏之举！啊?这个勋章是给我的吗?谢谢提督~');";
	ExecSQL(sq_66);
	char* sq_67 = "INSERT INTO SG_S VALUES (15,'DD','Z1',1,38,38,40,40,0,64,80,60,'Z1改造好咯.咦，这是什么奇怪的装备？我会像姐姐一样努力的~');";
	ExecSQL(sq_67);
	char* sq_68 = "INSERT INTO SG_S VALUES (16,'DD','绫波',1,40,30,38,40,0,48,95,60,'雪型11号舰，绫波。改造完毕');";
	ExecSQL(sq_68);
	char* sq_69 = "INSERT INTO SG_S VALUES (17,'CL','平海',1,48,35,39,40,0,40,66,70,'平海越来越厉害了！照这样下去我们的海军梦就能实现了！');";
	ExecSQL(sq_69);
	char* sq_70 = "INSERT INTO SG_S VALUES (18,'CL','宁海',1,48,35,39,40,0,40,66,70,'感谢提督给予我改造的机会，我不会辜负您的期望的。');";
	ExecSQL(sq_70);
	char* sq_71 = "INSERT INTO SG_S VALUES (19,'CL','逸仙',1,37,20,30,40,0,50,60,65,'哎?新衣服?谢谢,,提督,,在下会更加努力的');";
	ExecSQL(sq_71);
	char* sq_72 = "INSERT INTO SG_S VALUES (20,'CL','重庆',1,50,40,42,40,0,66,60,78,'来自皇家海军的银色妖精，重庆号愿胜利的曙光与人民同在，时刻准备着！');";
	ExecSQL(sq_72);
	char* sq_73 = "INSERT INTO SG_S VALUES (21,'DD','雪风',1,16,30,20,40,0,50,75,50,'炎阳型驱逐舰八号舰,雪风!绝对、大丈夫！');";
	ExecSQL(sq_73);
	char* sq_74 = "INSERT INTO SG_S VALUES (22,'DD','马汉',1,16,29,22,40,0,40,74,55,'不要问我王朝是谁！张龙赵虎也不认识！！');";
	ExecSQL(sq_74);
	char* sq_75 = "INSERT INTO SG_S VALUES (23,'CA','肯特',1,64,60,45,40,0,75,60,0,'肯特号重型巡洋舰,,,,呜……好像被欺负了……');";
	ExecSQL(sq_75);
	char* sq_76 = "INSERT INTO SG_S VALUES (24,'BB','俾斯麦',1,180,100,100,90,0,67,0,0,'已经没有人能阻止我前进了,请铭记在心。');";
	ExecSQL(sq_76);
	char* sq_77 = "INSERT INTO SG_S VALUES (25,'BB','华盛顿',1,170,80,92,90,0,90,0,0,'我是北卡罗来纳级，华盛顿号战列舰,改造完毕,我将继续为自由而战!');";
	ExecSQL(sq_77);
	char* sq_78 = "INSERT INTO SG_S VALUES (26,'BB','科罗拉多',1,160,77,91,95,0,65,0,0,'科罗拉多号改装好了.多谢提督.要出去散步吗~');";
	ExecSQL(sq_78);
	char* sq_79 = "INSERT INTO SG_S VALUES (27,'BB','密苏里',1,190,110,100,100,0,100,0,0,'密苏里号宇宙战舰改造完毕.曲率引擎启动中.');";
	ExecSQL(sq_79);
	char* sq_80 = "INSERT INTO SG_S VALUES (28, 'BB', '胡德', 1, 180, 80, 87, 100, 0, 85, 0, 0, '经过精心的改造，重点强化了水平装甲，这次应该没问题了蛐蛐俾斯麦别跑!'); ";
	ExecSQL(sq_80);
	char* sq_81 = "INSERT INTO SG_S VALUES (29, 'BB', '维内托', 1, 170, 85, 98, 90, 0, 62, 0, 0, '早上好提督,维内托号改造完毕,这下可以更好的帮助提督了.'); ";
	ExecSQL(sq_81);
	char* sq_82 = "INSERT INTO SG_S VALUES (30,'BB','狮',1,185,95,90,90,0,95,0,0,'妾身终于可以和大哥并肩作战了呢');";
	ExecSQL(sq_82);
	char* sq_83 = "INSERT INTO SG_S VALUES (31,'BB','大和',1,180,100,100,100,0,100,0,0,'准备好了吗？在拂晓的水平线上刻下胜利吧！');";
	ExecSQL(sq_83);
	char* sq_84 = "INSERT INTO SG_S VALUES (32, 'BB', '声望', 1, 180, 80, 80, 90, 0, 90, 0, 0, '瀟洒瀟洒瀟洒瀟洒！已經沒有什麼能阻擋我了！'); ";
	ExecSQL(sq_84);
	char* sq_85 = "INSERT INTO SG_S VALUES (33, 'BB', '反击', 1, 180, 80, 80, 90, 0, 90, 0, 0, '主人,反击号改装完毕,今后能更好的为主人服务了'); ";
	ExecSQL(sq_85);
	char* sq_86 = "INSERT INTO SG_S VALUES (34,'BB','威尔士亲王',1,180,100,100,90,0,67,0,0,'再看不到您，我可能就真的忘记您了，这可不是在开玩笑.');";
	ExecSQL(sq_86);
	char* sq_87 = "INSERT INTO SG_S VALUES (35,'BB','扶桑',1,160,75,80,80,0,80,0,0,'超弩级战列舰，扶桑改造完毕。加强了装甲.');";
	ExecSQL(sq_87);
	char* sq_88 = "INSERT INTO SG_S VALUES (36,'BB','山城',1,160,75,80,80,0,80,0,0,'感谢提督赐予小女子改造的机会,我会和姐姐一样努力');";
	ExecSQL(sq_88);
	char* sq_89 = "INSERT INTO SG_S VALUES (37,'BB','日向',1,170,80,80,90,40,50,0,0,'不要试图隐藏了，我早已看穿了你的一切');";
	ExecSQL(sq_89);
	char* sq_90 = "INSERT INTO SG_S VALUES (38,'BB','伊势',1,170,80,80,90,40,50,0,0,'伊势号改装完毕,提督,要一起去看海吗?');";
	ExecSQL(sq_90);
	char* sq_91 = "INSERT INTO SG_S VALUES (39,'BB','安德烈亚多利亚',1,175,75,80,90,0,70,0,0,'安德烈亚多利亚，现代化改装归来！！,不要再叫我什么奇怪的名字了!');";
	ExecSQL(sq_91);
	char* sq_92 = "INSERT INTO SG_S VALUES(40,'CA','列克星敦',1,50,90,70,70,100,100,60,40,'休假完毕~哎,提..提督,这个小盒子是给我的吗?');";
	ExecSQL(sq_92);
	char* sq_93 = "INSERT INTO SG_S VALUES(41,'CA','萨拉托加',1,50,90,70,70,100,100,60,40,'嗯~~我休息的非常舒服哦，接下来要更加努力了！');";
	ExecSQL(sq_93);
	char* sq_94 = "INSERT INTO SG_S VALUES(42,'CA','埃塞克斯',1,45,80,70,90,120,120,70,60,'不要再叫我CV⑨啦,我生气了!');";
	ExecSQL(sq_94);
	char* sq_95 = "INSERT INTO SG_S VALUES(43,'CA','企业',1,50,75,70,90,100,120,60,50,'企业航空母舰，向您报道,让对面一起上♀吧.');";
	ExecSQL(sq_95);
	char* sq_96 = "INSERT INTO SG_S VALUES(44,'CA','翔鹤',1,50,80,70,80,110,90,60,60,'翔鹤号空母改装好了,啊啦啊啦,提督害羞的样子真可爱呢');";
	ExecSQL(sq_96);
	char* sq_97 = "INSERT INTO SG_S VALUES(45, 'CA', '瑞鹤', 1, 50, 80, 70, 80, 110, 90, 60, 60, '瑞鹤号航空母舰改造完毕,哼哼,不比姐姐差哦'); ";
	ExecSQL(sq_97);
	char* sq_98 = "INSERT INTO SG_S VALUES(46, 'CA', '赤城', 1, 45, 85, 75, 80, 95, 95, 60, 60, '提督提督~改造好了哦,吶,我们出去吃饭吧,你请客哦'); ";
	ExecSQL(sq_98);
	char* sq_99 = "INSERT INTO SG_S VALUES(47, 'CA', '加贺', 1, 45, 85, 75, 80, 95, 95, 60, 60, '加贺号空母改装完毕,感谢提督,要不要来杯清酒呢/'); ";
	ExecSQL(sq_99);
	char* sq_100 = "INSERT INTO SG_S VALUES (48, 'SS', '大青花鱼', 1, 40, 40, 40, 40, 0, 0, 150, 90, '咕噜噜,你看不见我~看不见我~'); ";
	ExecSQL(sq_100);
	char* sq_101 = "INSERT INTO SG_S VALUES (49, 'SS', '射水鱼', 1, 40, 40, 40, 40, 0, 0, 150, 90, '射水鱼改造完毕,添加了新式鱼雷哦~'); ";
	ExecSQL(sq_101);
	char* sq_102 = "INSERT INTO SG_S VALUES (50, 'SS', 'M1', 1, 50, 25, 30, 40, 0, 0, 110, 90, 'M级重炮潜艇M1号，改造好啦~'); ";
	ExecSQL(sq_102);
	char* sq_103 = "CREATE TABLE DS (                     
		ID      INTEGER PRIMARY KEY AUTOINCREMENT, 
		CLASS TEXT, NAME    TEXT, LV INTEGER, ATK  
		HP      INTEGER, ARMOR   INTEGER,             
		PLANE   INTEGER,                           
		AAIR    INTEGER, TORPEDO INTEGER,            
		ASUB    INTEGER                            ";
	ExecSQL(sq_103);
	char* sq_104 = "INSERT INTO DS VALUES (1,'DD','Ⅰ级',1,10,10,10,0,0,0,0);";
	ExecSQL(sq_104);
	char* sq_105 = "INSERT INTO DS VALUES (2,'DD','Ⅲ级 ',1,30,30,30,0,30,30,30);";
	ExecSQL(sq_105);
	char* sq_106 = "INSERT INTO DS VALUES (3,'DD','Ⅵ级',1,40,40,40,0,40,40,40);";
	ExecSQL(sq_106);
	char* sq_107 = "INSERT INTO DS VALUES (4,'DD','Ⅷ级',1,50,50,50,0,60,50,50);";
	ExecSQL(sq_107);
	char* sq_108 = "INSERT INTO DS VALUES (5,'CL','X级',1,60,60,60,0,50,70,60);";
	ExecSQL(sq_108);
	char* sq_109 = "INSERT INTO DS VALUES (6,'CL','S级',1,70,70,40,0,80,90,80);";
	ExecSQL(sq_109);
	char* sq_110 = "INSERT INTO DS VALUES (7,'BB','MK1',1,50,50,50,0,30,0,0);";
	ExecSQL(sq_110);
	char* sq_111 = "INSERT INTO DS VALUES (8,'BB','MK2',1,60,60,50,0,50,0,0);";
	ExecSQL(sq_111);
	char* sq_112 = "INSERT INTO DS VALUES (9,'BB','MK3',1,70,70,70,0,70,0,0);";
	ExecSQL(sq_112);
	char* sq_113 = "INSERT INTO DS VALUES (10,'BB','MK4',1,80,80,80,40,70,0,0);";
	ExecSQL(sq_113);
	char* sq_114 = "INSERT INTO DS VALUES (11,'BB','MK6',1,120,120,100,60,70,0,0);";
	ExecSQL(sq_114);
	char* sq_115 = "INSERT INTO DS VALUES (12,'BB','MK10',1,233,233,70,60,90,50,0);";
	ExecSQL(sq_115);
	char* sq_116 = "INSERT INTO DS VALUES (13,'CV','α级',1,30,30,30,30,30,0,0);";
	ExecSQL(sq_116);
	char* sq_117 = "INSERT INTO DS VALUES (14,'CV','Δ级',1,50,50,50,40,50,0,0);";
	ExecSQL(sq_117);
	char* sq_118 = "INSERT INTO DS VALUES (15,'CV','Θ级',1,60,60,60,40,60,0,0);";
	ExecSQL(sq_118);
	char* sq_119 = "INSERT INTO DS VALUES (16,'CV','D-LEX',1,80,80,80,50,80,0,0);";
	ExecSQL(sq_119);
	char* sq_120 = "INSERT INTO DS VALUES (17,'CV','D-SAR',1,100,100,70,100,100,0,0);";
	ExecSQL(sq_120);
	char* sq_121 = "INSERT INTO DS VALUES (18,'CV','D-LIA',1,120,120,70,120,120,0,0);";
	ExecSQL(sq_121);
	char* sq_122 = "INSERT INTO DS VALUES (19,'SS','DEEP',1,0,10,10,0,0,50,40);";
	ExecSQL(sq_122);
	char* sq_123 = "INSERT INTO DS VALUES (20,'SS','DARK',1,0,20,20,0,0,70,50);";
	ExecSQL(sq_123);
	char* sq_124 = "INSERT INTO DS VALUES (21,'SS','FANTASY',1,50,25,20,0,0,90,50);";
	ExecSQL(sq_124);
	char* sq_125 = "INSERT INTO DS VALUES (22,'SS','VAN',1,50,50,40,0,0,120,70);";
	ExecSQL(sq_125);
	char* sq_126 = "SELECT * FROM SG ORDER BY ID ASC ;";
	ExecSQL(sq_126);
	char* sq_127 = "SELECT * FROM SG_S ORDER BY ID ASC ;";
	ExecSQL(sq_127);
	char* sq_128 = "";
	ExecSQL(sq_128);

	Close_DB();
}*/

void Gbui::xunhuan()
{
	ofstream mm("233.txt", ios::out);
	if (!mm)
	{
		cout << "error";
	}
	else
	{
		for (int i = 1; i < 126; i++)
		{
			mm << "char* sq_" << i << " = " << ";" << endl;
			mm << "ExecSQL(sq_" << i << ");" << endl;
		}
		mm.close();
	}

}

int Gbui::UserResult(void *NotUsed, int argc, char **argv, char **azColName)	//将Selectuserd建造出来的数据输出存储
{	
	
	char* Arg_s[15];
	char* Lv[2];
	for (int i = 0; i < argc; i++)
	{
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << ". ";
		Arg_s[i] = (argv[i] ? argv[i] : "NULL");	
		RetBu(Arg_s[i]);	//将属性传递出去
		cout <<  Arg_s[i] << endl;
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

