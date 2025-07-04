#include "init_globle_variable.h"
int Window_width = 1280;
int Window_height = 720;

//链表式数据结构的全局变量初始化方式

List_page* Game_data_under_turing = Get_list_page();
extern Node_page* Pointer_present_node_page = &(Game_data_under_turing->Head);
Node_page* Pointer_indicator_new_page = Pointer_present_node_page;


int Signal_page_level = 1;						//记录当前页面层数，表达现在第几层所有不同的地图背景层数加起来大约为70层左右；
int Signal_meet_NPC_1 = 0;						//记录角色当前是否碰撞到当前地图的1号NPC，碰撞到为1，没有则为0；
int Signal_meet_NPC_2 = 0;						//记录角色当前是否碰撞到当前地图的2号NPC，碰撞到为1，没有则为0；
int Signal_meet_NPC_3 = 0;						//记录角色当前是否碰撞到当前地图的3号NPC，碰撞到为1，没有则为0；
int Signal_meet_door = 0;						//记录角色当前是否碰撞到传送门，碰撞到为1，没有则为0；
int Signal_meet_coin = 0;						//记录角色当前是否碰到游戏内的金币，碰撞到【加1】，没有则为0；
int Signal_meet_document_icon = 0;				//记录角色当前是否碰到游戏内的文档图标，碰撞到【加1】，没有则为0；
int Signal_meet_choice_box = 0;							//记录角色当前是否碰到选项；碰到“忘了”返回1，碰到“5个”返回2，碰到“6个”返回3，碰到“7个”返回4，没有则为0

int Signal_rectangle_chat_bubble_1_level = 0;				//记录当前打印了几个矩形聊天气泡，同样场景下，矩形聊天气泡不超过10层，没打印时则为0层，打印了第一段话后为1，打印了第二段话后变为2，帮助确定下一个打印哪个矩形聊天气泡
int Signal_rectangle_chat_bubble_2_level = 0;				//记录当前打印了几个矩形聊天气泡，同样场景下，矩形聊天气泡不超过10层，没打印时则为0层，打印了第一段话后为1，打印了第二段话后变为2，帮助确定下一个打印哪个矩形聊天气泡
int Signal_rectangle_chat_bubble_3_level = 0;				//记录当前打印了几个矩形聊天气泡，同样场景下，矩形聊天气泡不超过10层，没打印时则为0层，打印了第一段话后为1，打印了第二段话后变为2，帮助确定下一个打印哪个矩形聊天气泡


int Signal_phone_chat_bubble_1_level = 0;					//记录当前打印了几个手机聊天界面，同样场景下，手机聊天界面不超过10层，没打印时则为0层，打印了第一段话后为1，打印了第二段话后变为2，来帮助确定下一个打印哪个手机聊天界面
int Signal_phone_chat_bubble_2_level = 0;
int Signal_phone_chat_bubble_3_level = 0;

int Object_controlled_x = 0;					//可被控制移动的物体的横坐标
int Object_controlled_y = 0;					//可被控制移动的物体的纵坐标
int Object_mobile_big_coin_y1 = 0;
int Object_mobile_big_coin_y2 = 0;
int Object_mobile_big_coin_y3 = 0;
int Signal_exist_object_mobile_big_coin_1 = 1;
int Signal_exist_object_mobile_big_coin_2 = 1;
int Signal_exist_object_mobile_big_coin_3 = 1;
int Signal_scoreboard = 0;

int Object_mobile_document_icon_y1 = 0;
int Object_mobile_document_icon_y[6] = { 360, -500, -545, -580, -610, -900 };
int Object_mobile_document_icon_x[6] = { 300, 270, 400, 710, 500, 400 };
int Signal_exist_object_mobile_document_icon_1 = 1;
int Signal_exist_object_mobile_document_icon[6] = { 1,1,1,1,1,1 };

int Signal_exist_boss = 1;				//初始化，boss活着；
int Signal_exist_player = 1;			//初始化，玩家活着；
int Gif_n = 0;							//初始化，动图循环数字从0开始；
int BOSS_x;								//记录BOSS所在的横坐标
int BOSS_y;								//记录BOSS所在的横坐标
int BOSS_blood_number;					//玩家血量数字
int BOSS_blood_rectangle;				//玩家血量矩形长度
int Player_x;							//记录玩家所在的横坐标
int Player_y;							//记录玩家所在的横坐标
int Player_direction;					//记录玩家方向
int Player_blood_number;				//玩家血量数字
int Player_blood_rectangle;				//玩家血量矩形长度
ExMessage Player_action;				//玩家消息
int Bullet_amount = 30;					//玩家子弹数量；
bullet Player_bullet[30];				//玩家子弹结构体
int Speed_bullet = 60;					//玩家子弹移动速度
int End_credit_y = 0;					//片尾

//子弹相关的结构体

//子弹、玩家、怪物图片变量
IMAGE BOSS;								//BOSS图像
IMAGE img_player_left;					//玩家朝左
IMAGE img_player_right;					//玩家朝右
IMAGE img_boss_bullet_SRCAND;			//怪物子弹
IMAGE img_boss_bullet_SRCPAINT;			//怪物子弹
IMAGE img_player_bullet_SRCAND;			//玩家子弹
IMAGE img_player_bullet_SRCPAINT;		//玩家子弹


int Level = 0, N_level;

//初始化开头的所以游戏数据
void Init_game_data_chapter_0() {
	ExMessage msg;

	int i = 0, t = 0;//i是不同界面判断，t是进入游戏判断
	int a = 0, k = 0;//判断音乐开关变量
	//加载图片

	//开始菜单
	IMAGE start_screen[5];
	loadimage(&start_screen[0], _T("./resource/Images/start_screen/1.png"), Window_width, Window_height);
	loadimage(&start_screen[1], _T("./resource/Images/start_screen/2.png"), Window_width, Window_height);
	loadimage(&start_screen[2], _T("./resource/Images/start_screen/3.png"), Window_width, Window_height);
	loadimage(&start_screen[3], _T("./resource/Images/start_screen/4.png"), Window_width, Window_height);
	loadimage(&start_screen[4], _T("./resource/Images/start_screen/5.png"), Window_width, Window_height);
	Bgm_shadow();
	while (!t) {
		putimage(0, 0, &start_screen[i]);
		FlushBatchDraw();
		msg = getmessage(EX_MOUSE);

		//鼠标点击
		switch (msg.message)
		{
		case WM_LBUTTONDOWN:
			if (msg.x > 35 && msg.x < 125 && msg.y > 305 && msg.y < 380 && i == 0)
			{
				i = 1;
			}
			else if (msg.x > 975 && msg.x < 1035 && msg.y > 115 && msg.y < 170)
			{
				i = 0;
			}
			else if (msg.x > 35 && msg.x < 125 && msg.y > 410 && msg.y < 480 && i == 0)
			{
				i = 2;
			}
			else if (msg.x > 945 && msg.x < 1035 && msg.y > 135 && msg.y < 195)
			{
				i = 0;
			}
			else if (msg.x > 35 && msg.x < 125 && msg.y > 625 && msg.y < 690 && i == 0)
			{
				if (a == 0)
				{
					i = 3;
				}
				else if (a == 1)
				{
					i = 4;
				}
			}
			else if (msg.x > 35 && msg.x < 125 && msg.y > 520 && msg.y < 585 && (i == 3 || i == 4))
			{
				if (i == 3)
				{
					i = 4;
					k = 1;
					a = 1;
				}
				else if (i == 4)
				{
					i = 3;
					k = 0;
					a = 0;
				}
			}
			else if (msg.x > 565 && msg.x < 710 && msg.y > 630 && msg.y < 670 && i == 0)
			{
				t = 1;
			}
			else if (msg.x > 125 && msg.x < 1270 && (i == 3 || i == 4))
			{
				i = 0;
			}
			break;
		}
		if (!k)
		{
			mciSendString(_T("open ./resource/Audios/shadow.mp3"), NULL, NULL, NULL);
			mciSendString(_T("play ./resource/Audios/shadow.mp3 repeat"), NULL, NULL, NULL);
		}
		else if (k)
		{
			mciSendString(_T("close ./resource/Audios/shadow.mp3"), NULL, NULL, NULL);
		}
	}
}

//初始化第一个篇章的所有游戏数据
void Init_game_data_chapter_1() {
	printf("进入初始化数据的函数了嘛？\n");

	//head部分的背景图，以及类型
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/0.png");				//当前指向head结点，片头地图为./Page_background/0.png
	Pointer_present_node_page->Type = 1;																//将head的页面功能类型type设置为0；因为按键部分还没有设置片头的处理
	printf("完成初始化第0个地图数据。\n");
	//第一部分的背景图以及类型；

	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);								//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;			//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 1;														//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/1.png");		//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;																//将2号页面的功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/2.png");		//设置1号页面片头地图为：./Page_background/2.png
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);


#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/1.png");		//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//将2号页面的功能类型设置为2
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/2.png");		//设置1号页面片头地图为：./Page_background/2.png
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/3.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/5.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/6.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/7.png");
	Pointer_present_node_page->Object_controlled.Image_address = _T("./resource/Images/Object_controlled/4.png");				//
	Pointer_present_node_page->Object_controlled.Born_x = 360;
	Pointer_present_node_page->Object_controlled.Born_y = 400;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_right_choice_box;
	Pointer_present_node_page->Meet_page_door_2 = Meet_door_wrong_choice_box;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/3.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 0;
	Pointer_present_node_page->Object_controlled.Born_y = 480;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_communication_group;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_tree_house_on_the_snow;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_brother_east_on_the_snow;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 4;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/TuringCollege_door/1.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_1/TuringCollege_door/2.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[2] = _T("./resource/Images/chat_bubble/chapter_1/TuringCollege_door/3.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[3] = _T("./resource/Images/chat_bubble/chapter_1/TuringCollege_door/4.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);



	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 1;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/TuringCollege_meeting/1.png");
	Output_all_node_page(Game_data_under_turing);
	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);



	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/TuringCollege_meeting/2.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/TuringCollege_meeting/3.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/TuringCollege_meeting/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/TuringCollege_meeting/5.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);



	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 0;
	Pointer_present_node_page->Object_controlled.Born_y = 440;
	Pointer_present_node_page->Object_controlled.Speed_x = 30;
	Pointer_present_node_page->Object_controlled.Speed_y = 30;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_girls_on_the_snow;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_tree_house_girls_on_the_snow;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_girls_on_the_snow;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 7;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/NPC/1.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_1/NPC/2.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[2] = _T("./resource/Images/chat_bubble/chapter_1/NPC/3.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[3] = _T("./resource/Images/chat_bubble/chapter_1/NPC/4.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[4] = _T("./resource/Images/chat_bubble/chapter_1/NPC/5.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[5] = _T("./resource/Images/chat_bubble/chapter_1/NPC/6.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[6] = _T("./resource/Images/chat_bubble/chapter_1/NPC/7.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);



	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/5.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 0;
	Pointer_present_node_page->Object_controlled.Born_y = 440;
	Pointer_present_node_page->Object_controlled.Speed_x = 30;
	Pointer_present_node_page->Object_controlled.Speed_y = 30;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_corridor;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_corridor;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_corridor;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 1;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/NPC/8.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_group_meeting;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 1;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/group_meeting/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_group_meeting;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 1;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/group_meeting/3.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_group_meeting;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 1;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/group_meeting/4.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_group_meeting;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 1;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/group_meeting/5.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_group_meeting;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 1;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/group_meeting/6.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_group_meeting;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 1;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/group_meeting/7.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_group_meeting;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 1;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/group_meeting/8.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/6.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 1200;
	Pointer_present_node_page->Object_controlled.Born_y = 180;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_station;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_station;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_station;
	Pointer_present_node_page->NPC_2.Meet = Meet_NPC_2_station;
	Pointer_present_node_page->NPC_3.Meet = Meet_NPC_3_station;
	Pointer_present_node_page->NPC_1.Sum_phone_chat_bubble = 4;
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble_SRCAND = _T("./resource/Images/chat_bubble/chapter_1/station/phone2.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_1/1.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_1/2.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[2] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_1/3.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[3] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_1/4.png");
	Pointer_present_node_page->NPC_2.Sum_phone_chat_bubble = 11;
	Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_2/1.png");
	Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_2/2.png");
	Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[2] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_2/3.png");
	Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[3] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_2/4.png");
	Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[4] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_2/5.png");
	Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[5] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_2/6.png");
	Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[6] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_2/7.png");
	Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[7] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_2/8.png");
	Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[8] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_2/9.png");
	Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[9] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_2/10.png");
	Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[10] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_2/11.png");
	Pointer_present_node_page->NPC_3.Sum_phone_chat_bubble = 19;
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/1.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/2.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[2] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/3.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[3] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/4.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[4] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/5.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[5] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/6.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[6] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/7.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[7] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/8.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[8] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/9.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[9] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/10.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[10] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/11.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[11] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/12.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[12] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/13.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[13] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/14.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[14] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/15.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[15] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/16.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[16] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/17.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[17] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/18.png");
	Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[18] = _T("./resource/Images/chat_bubble/chapter_1/station/trigger_3/19.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);												//
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/7.png");				//用鼠标去触碰腾讯视频
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/4.1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/4.2.png");
	Pointer_present_node_page->Object_controlled.Born_x = 780;
	Pointer_present_node_page->Object_controlled.Born_y = 540;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 10;
	Pointer_present_node_page->Object_controlled.Height = 16;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_computer;
	Pointer_present_node_page->Meet_page_door = Meet_door_computer;
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/8.png");				//自我介绍的视频画面
	Pointer_present_node_page->Object_controlled.Image_address = _T("./resource/Images/Object_controlled/6.png");				//
	Pointer_present_node_page->Object_controlled.Born_x = 400;
	Pointer_present_node_page->Object_controlled.Born_y = 625;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 5;
	Pointer_present_node_page->Object_controlled.Height = 15;
	Pointer_present_node_page->Meet_page_door = Meet_door_group_introduction_meeting;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_group_introduction_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;																//将2号页面的功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/1.png");		//设置1号页面片头地图为：./Page_background/2.png
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif


	return;
}
void Init_game_data_chapter_2() {
	printf("进入初始化数据的函数了嘛？\n");
	//第一部分的背景图以及类型；
#if 1
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 1;																//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/1.png");		//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif


	//进入产品经理篇第一关前
#if 1 
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/1.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/3.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/4.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/5.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/6.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif


	//产品经理篇第一关
#if 1

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_1/1.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_1/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																		//游戏关卡：捡金币——简单版本
	Pointer_present_node_page->Name_number = 333;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_1/3.png");		//设置1号页面片头地图为：./Page_background/2.png
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/2.1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/2.2.png");
	Pointer_present_node_page->Object_controlled.Born_x = 540;
	Pointer_present_node_page->Object_controlled.Born_y = 560;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 30;
	Pointer_present_node_page->Object_controlled.Height = 30;
	Pointer_present_node_page->Object_mobile.Image_address_SRCAND = _T("./resource/Images/object_mobile/big_coin_1.png");
	Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT = _T("./resource/Images/object_mobile/big_coin_2.png");
	Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT = _T("./resource/Images/object_mobile/big_coin_3.png");
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_x = 0;
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_y = 10;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_big_coin_computer;
	Pointer_present_node_page->Object_mobile.Meet = Meet_object_mobile_big_coin;
	Pointer_present_node_page->Meet_finish_game = Meet_finish_game_get_3_big_coin;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_1/4.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#endif


	//第一关后第二关前（图书馆）
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/3.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 85;
	Pointer_present_node_page->Object_controlled.Born_y = 220;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;

	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_chapter_2_library;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 3;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_2/npc/1.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_2/npc/2.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[2] = _T("./resource/Images/chat_bubble/chapter_2/npc/3.png");


	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_2_library;
	Pointer_present_node_page->Meet_page_door_2 = Meet_door_2_chapter_2_library;

	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_library;
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	//彩蛋（超能生日）

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 1220;
	Pointer_present_node_page->Object_controlled.Born_y = 0;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;


	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_2_game_easter_eggs;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_game_easter_eggs_room;


	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	//超能跳舞
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/dance/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 85;
	Pointer_present_node_page->Object_controlled.Born_y = 220;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;

	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_2_library;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_library;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/dance/2.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 105;
	Pointer_present_node_page->Object_controlled.Born_y = 220;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;

	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_2_library;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_library;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/dance/3.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 125;
	Pointer_present_node_page->Object_controlled.Born_y = 220;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;

	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_2_library;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_library;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/dance/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 145;
	Pointer_present_node_page->Object_controlled.Born_y = 220;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;

	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_2_library;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_library;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/dance/5.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 165;
	Pointer_present_node_page->Object_controlled.Born_y = 220;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;

	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_2_library;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_library;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
	//生日祝福界面
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/3.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/4.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/5.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/6.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/7.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

#endif

	//回到图书馆
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 85;
	Pointer_present_node_page->Object_controlled.Born_y = 220;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;

	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_chapter_2_library;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 3;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_2/npc/1.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_2/npc/2.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[2] = _T("./resource/Images/chat_bubble/chapter_2/npc/3.png");


	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_2_game_easter_eggs_to_library;
	//Pointer_present_node_page->Meet_page_door_2 = Meet_door_2_chapter_2_library;

	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_library;
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif


#endif

#endif


	//产品经理篇第二关
#if 1
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_2/1.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_2/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																		//游戏关卡——捡金币——困难版本
	Pointer_present_node_page->Name_number = 3000;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_2/3.png");		//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/2.1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/2.2.png");
	Pointer_present_node_page->Object_controlled.Born_x = 540;
	Pointer_present_node_page->Object_controlled.Born_y = 560;
	Pointer_present_node_page->Object_controlled.Speed_x = 2;
	Pointer_present_node_page->Object_controlled.Speed_y = 2;
	Pointer_present_node_page->Object_controlled.Width = 30;
	Pointer_present_node_page->Object_controlled.Height = 30;
	Pointer_present_node_page->Object_mobile.Image_address_SRCAND = _T("./resource/Images/object_mobile/big_coin_1.png");
	Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT = _T("./resource/Images/object_mobile/big_coin_2.png");
	Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT = _T("./resource/Images/object_mobile/big_coin_3.png");
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_x = 0;
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_y = 3;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_big_coin_computer;
	Pointer_present_node_page->Object_mobile.Meet = Meet_object_mobile_big_coin;
	Pointer_present_node_page->Meet_finish_game = Meet_finish_game_get_3_big_coin;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_2/4.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#endif

	//产品经理第二关后(图书馆)
#if 1
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 85;
	Pointer_present_node_page->Object_controlled.Born_y = 240;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;

	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_chapter_2_library;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 2;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_2/npc/4.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_2/npc/7.png");

	Pointer_present_node_page->NPC_2.Meet = Meet_NPC_2_chapter_2_library;
	Pointer_present_node_page->NPC_2.Sum_rectangle_chat_bubble = 2;
	Pointer_present_node_page->NPC_2.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_2/npc/5.png");
	Pointer_present_node_page->NPC_2.Image_address_rectangle_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_2/npc/6.png");


	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_3_library;
	//Pointer_present_node_page->Meet_page_door_2 = Meet_door_2_chapter_2_library;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_library;
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);


#endif
#endif
}

void Init_game_data_chapter_3() {
#if 1
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 1;																//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/1.png");		//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
	//第一关前
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 85;
	Pointer_present_node_page->Object_controlled.Born_y = 220;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;


	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_chapter_3_library_phone;
	Pointer_present_node_page->NPC_1.Sum_phone_chat_bubble = 4;
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble_SRCAND = _T("./resource/Images/chat_bubble/chapter_1/station/phone2.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_3/phone/1.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_3/phone/2.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[2] = _T("./resource/Images/chat_bubble/chapter_3/phone/3.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[3] = _T("./resource/Images/chat_bubble/chapter_3/phone/4.png");


	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_library;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_3_library;
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
	//需求文档第一关
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/level_1/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																			//游戏关卡——捡文档——简单版本
	Pointer_present_node_page->Name_number = 111;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_3/level_1/3.png");			//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/4.1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/4.2.png");
	Pointer_present_node_page->Object_controlled.Born_x = 540;
	Pointer_present_node_page->Object_controlled.Born_y = 560;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 10;
	Pointer_present_node_page->Object_controlled.Height = 16;
	Pointer_present_node_page->Object_mobile.Image_address_SRCAND = _T("./resource/Images/object_mobile/icon_1.png");
	Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT = _T("./resource/Images/object_mobile/icon_2.png");
	Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT = _T("./resource/Images/object_mobile/icon_2.png");
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_x = 0;
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_y = 15;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_big_coin_computer;
	Pointer_present_node_page->Object_mobile.Meet = Meet_object_mobile_document_icon;
	Pointer_present_node_page->Meet_finish_game = Meet_finish_game_get_1_document_icon;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 1;																//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/level_1/4.png");		//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
	//第一关后第二关前
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/3.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 85;
	Pointer_present_node_page->Object_controlled.Born_y = 220;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;

	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_chapter_2_library;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 2;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_3/npc/1.png");
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_3/npc/3.png");

	Pointer_present_node_page->NPC_2.Meet = Meet_NPC_2_chapter_2_library;
	Pointer_present_node_page->NPC_2.Sum_rectangle_chat_bubble = 1;
	Pointer_present_node_page->NPC_2.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_3/npc/2.png");



	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_library;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_3_library;
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
	//需求文档第二关
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/level_2/1.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																			//游戏关卡——捡文档——简单版本
	Pointer_present_node_page->Name_number = 666;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_3/level_2/2.png");			//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/4.1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/4.2.png");
	Pointer_present_node_page->Object_controlled.Born_x = 540;
	Pointer_present_node_page->Object_controlled.Born_y = 560;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 10;
	Pointer_present_node_page->Object_controlled.Height = 16;
	Pointer_present_node_page->Object_mobile.Image_address_SRCAND = _T("./resource/Images/object_mobile/icon_1.png");
	Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT = _T("./resource/Images/object_mobile/icon_2.png");
	Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT = _T("./resource/Images/object_mobile/icon_2.png");
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_x = 0;
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_y = 25;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_big_coin_computer;
	Pointer_present_node_page->Object_mobile.Meet = Meet_object_mobile_document_icon;
	Pointer_present_node_page->Meet_finish_game = Meet_finish_game_get_6_document_icon;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_chapter_3_level_2_game_over;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 1;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_3/level_2/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 1;																//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/level_2/5.png");		//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
	//第二关后
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 85;
	Pointer_present_node_page->Object_controlled.Born_y = 240;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;

	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_chapter_3_library_phone;
	Pointer_present_node_page->NPC_1.Sum_phone_chat_bubble = 1;
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble_SRCAND = _T("./resource/Images/chat_bubble/chapter_1/station/phone2.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_3/meeting/1.png");


	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_2_library;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_3_library;
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
	//小组会议
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/group_meeting/1.png");		//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/group_meeting/2.png");		//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/group_meeting/3.png");		//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/group_meeting/4.png");		//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//进度条上的B站小电视
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/object_controlled/1.1.png");
	Pointer_present_node_page->Object_controlled.Born_x = 260;
	Pointer_present_node_page->Object_controlled.Born_y = 608;
	Pointer_present_node_page->Object_controlled.Speed_x = 50;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 20;
	Pointer_present_node_page->Object_controlled.Height = 20;
	Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_video_left;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
	return;
}

/*
void Init_game_data_chapter_3() {
#if 1
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 1;																//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./Page_background/Chapter_3/1.png");		//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./Page_background/Chapter_2/level_1/2_1.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																			//游戏关卡——捡文档——简单版本
	Pointer_present_node_page->Name_number = 111;
	Pointer_present_node_page->Image_address_background = _T("./Page_background/chapter_3/level_1/2.png");			//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./object_controlled/4.1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./object_controlled/4.2.png");
	Pointer_present_node_page->Object_controlled.Born_x = 540;
	Pointer_present_node_page->Object_controlled.Born_y = 560;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 10;
	Pointer_present_node_page->Object_controlled.Height = 16;
	Pointer_present_node_page->Object_mobile.Image_address_SRCAND = _T("./object_mobile/icon_1.png");
	Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT = _T("./object_mobile/icon_2.png");
	Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT = _T("./object_mobile/icon_2.png");
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_x = 0;
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_y = 15;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_big_coin_computer;
	Pointer_present_node_page->Object_mobile.Meet = Meet_object_mobile_document_icon;
	Pointer_present_node_page->Meet_finish_game = Meet_finish_game_get_1_document_icon;

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./Page_background/Chapter_2/level_1/2_1.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																			//游戏关卡——捡文档——简单版本
	Pointer_present_node_page->Name_number = 666;
	Pointer_present_node_page->Image_address_background = _T("./Page_background/chapter_3/level_2/2.png");			//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./object_controlled/4.1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./object_controlled/4.2.png");
	Pointer_present_node_page->Object_controlled.Born_x = 540;
	Pointer_present_node_page->Object_controlled.Born_y = 560;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 10;
	Pointer_present_node_page->Object_controlled.Height = 16;
	Pointer_present_node_page->Object_mobile.Image_address_SRCAND = _T("./object_mobile/icon_1.png");
	Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT = _T("./object_mobile/icon_2.png");
	Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT = _T("./object_mobile/icon_2.png");
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_x = 0;
	Pointer_present_node_page->Object_mobile.Object_mobile_speed_y = 25;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_big_coin_computer;
	Pointer_present_node_page->Object_mobile.Meet = Meet_object_mobile_document_icon;
	Pointer_present_node_page->Meet_finish_game = Meet_finish_game_get_6_document_icon;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_chapter_3_level_2_game_over;
	Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 1;
	Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] = _T("./chat_bubble/chapter_3/level_2/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
	return;
}
*/

void Init_game_data_chapter_4() {
#if 1
	//Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 1;																//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/1.png");		//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Output_all_node_page(Game_data_under_turing);														//

	Pointer_present_node_page = &(Game_data_under_turing->Head);										//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 2;																				//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/cycle/1.png");				//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 1200;
	Pointer_present_node_page->Object_controlled.Born_y = 600;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_4_cycle_1_40km;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_4_cycle_1_40km;
	Output_all_node_page(Game_data_under_turing);														//

	Pointer_present_node_page = &(Game_data_under_turing->Head);										//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 2;																				//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/cycle/2.png");				//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 680;
	Pointer_present_node_page->Object_controlled.Born_y = 660;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_4_cycle_2_25km;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_4_cycle_2_25km;
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);											//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 2;																		//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/cycle/3.png");		//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 1200;
	Pointer_present_node_page->Object_controlled.Born_y = 580;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_4_cycle_3_10km;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_4_cycle_3_10km;
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 2;																				//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/cycle/4.png");				//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 1220;
	Pointer_present_node_page->Object_controlled.Born_y = 580;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_4_cycle_4;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_4_cycle_4;
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 1;																				//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/1.png");				//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 4;																				//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/1.png");				//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 2;																				//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/3.png");				//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//小埋
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//小埋
	Pointer_present_node_page->Object_controlled.Born_x = 40;
	Pointer_present_node_page->Object_controlled.Born_y = 560;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 0;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_4_lobby_conversation;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_4_lobby_conversation;
	Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_chapter_4_lobby_conversation;
	Pointer_present_node_page->NPC_1.Sum_phone_chat_bubble = 8;
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble_SRCAND = _T("./resource/Images/chat_bubble/chapter_1/station/phone2.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_4/4.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_4/5.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[2] = _T("./resource/Images/chat_bubble/chapter_4/6.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[3] = _T("./resource/Images/chat_bubble/chapter_4/7.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[4] = _T("./resource/Images/chat_bubble/chapter_4/8.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[5] = _T("./resource/Images/chat_bubble/chapter_4/9.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[6] = _T("./resource/Images/chat_bubble/chapter_4/10.png");
	Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[7] = _T("./resource/Images/chat_bubble/chapter_4/11.png");
	Pointer_present_node_page->NPC_2.Meet = Meet_NPC_2_chapter_4_lobby_conversation;
	Pointer_present_node_page->NPC_2.Sum_rectangle_chat_bubble = 3;
	Pointer_present_node_page->NPC_2.Image_address_rectangle_chat_bubble[0] = _T("./resource/Images/chat_bubble/chapter_4/12.png");
	Pointer_present_node_page->NPC_2.Image_address_rectangle_chat_bubble[1] = _T("./resource/Images/chat_bubble/chapter_4/13.png");
	Pointer_present_node_page->NPC_2.Image_address_rectangle_chat_bubble[2] = _T("./resource/Images/chat_bubble/chapter_4/14.png");

	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif


#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 1;																				//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_2/1.png");				//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif



	//自动播放篇章
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/level_1/auto/1.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/2.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/3.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/4.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/5.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/6.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/7.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/8.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/9.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/10.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/11.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/12.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 6;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/13.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

	Init_game_data_chapter_4_push_computer();
	Init_game_data_chapter_4_push_computer();
	Init_game_data_chapter_4_push_computer();


#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 1;																				//将1号的页面功能类型设置为1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_2/5.png");				//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Output_all_node_page(Game_data_under_turing);																		//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif


#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);							//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;			//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 5;														//将1号的页面功能类型设置为1
	Pointer_present_node_page->Name_number = 888;												//BOSS关卡的账号
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/tupian/DTSJ.png");				//设置1号页面片头地图为：./Page_background/1.png————之前这里的jpg写成png了！！！这个bug想了找了我好久！！！！！（最好统一所有图片格式！）
	Pointer_present_node_page->Object_controlled.Born_x = 200;
	Pointer_present_node_page->Object_controlled.Born_y = 200;
	Pointer_present_node_page->Object_controlled.Speed_x = 30;
	Pointer_present_node_page->Object_controlled.Speed_y = 30;
	Pointer_present_node_page->Object_mobile.Image_address_SRCAND = _T("./resource/Images/tupian/boss.png");	//BOSS的连续图片；
	Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT = _T("./resource/Images/tupian/boss.png");	//BOSS的连续图片；
	Pointer_present_node_page->Object_mobile.Object_mobile_born_x = 1300;
	Pointer_present_node_page->Object_mobile.Object_mobile_born_y = 150;

	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif


#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);							//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;			//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 8;														//将1号的页面功能类型设置为8
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/end/end.png");
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

}

void Init_game_data_chapter_4_push_computer() {
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 7;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/1.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 7;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/2.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 7;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/3.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 7;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/4.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 7;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/5.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 7;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/6.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 7;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/7.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 7;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/8.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 7;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/9.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 7;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/10.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//插入新的页面结点，
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//令指针指向0号结点——链表顺序是：（head, 0, 1, 2, 3, ...）
	Pointer_present_node_page->Type = 7;																				//将页面功能类型设置为6，意味着自动播放
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/11.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//将指针，指回head页面结点
	printf("完成初始化第%d个地图数据。\n", Level);
#endif

	return;
}


void Init_BOSS_chapter() {
	Player_x = Pointer_present_node_page->Object_controlled.Born_x;
	Player_y = Pointer_present_node_page->Object_controlled.Born_y;
	BOSS_x = Pointer_present_node_page->Object_mobile.Object_mobile_born_x;
	BOSS_y = Pointer_present_node_page->Object_mobile.Object_mobile_born_y;
	Player_blood_number = 9;
	Player_blood_rectangle = 0;
	BOSS_blood_number = 30;
	BOSS_blood_rectangle = 0;
	for (int i = 0; i < Bullet_amount; i++) {
		Player_bullet[i].live = false;
	}
	return;
}

void Init_game_date_end_credit() {
	IMAGE end_credit;
	Bgm_end_credit();
	loadimage(&end_credit, _T("./resource/Images/end/end.png"));
	for (int i = 0; i < 8500; i++) {
		putimage(0, -1 * i, &end_credit);
		printf("在循环打印图片中：i = %d\n", i);
		Sleep(50);
	}
	printf("为什么会跳出来呢？\n");
}










































/*
//初始化页面背景图片的地址数组
LPCTSTR Image_address_page_background[100] = {	_T("./Page_background/0.png"), _T("./Page_background/1.jpg"), _T("./Page_background/2.jpg"),
												_T("./Page_background/3.jpg"), _T("./Page_background/4.jpg"), _T("./Page_background/5.jpg"),
												_T("./Page_background/6.jpg"), _T("./Page_background/7.jpg")
};

//数组式数据结构的全局变量初始化方式
int Signal_page_type[100] = { 0,1,1,2,2,2,3,2 };	//记录当前地图类型：0为片头页面，1为按键直接跳过的剧情页面；2为人物可移动的剧情页面；3为游戏关卡页面；
int Signal_page_level = 1;						//记录当前页面层数，表达现在第几层所有不同的地图背景层数加起来大约为70层左右；
int Signal_meet_NPC_1 = 0;						//记录角色当前是否碰撞到当前地图的1号NPC，碰撞到为1，没有则为0；
int Signal_meet_NPC_2 = 0;						//记录角色当前是否碰撞到当前地图的2号NPC，碰撞到为1，没有则为0；
int Signal_meet_NPC_3 = 0;						//记录角色当前是否碰撞到当前地图的3号NPC，碰撞到为1，没有则为0；
int Signal_meet_door = 0;						//记录角色当前是否碰撞到传送门，碰撞到为1，没有则为0；
int Signal_meet_coin = 0;						//记录角色当前是否碰到游戏内的金币，碰撞到【加1】，没有则为0；
int Signal_meet_document_icon = 0;				//记录角色当前是否碰到游戏内的文档图标，碰撞到【加1】，没有则为0；
int Signal_meet_choice_box = 0;							//记录角色当前是否碰到选项；碰到“忘了”返回1，碰到“5个”返回2，碰到“6个”返回3，碰到“7个”返回4，没有则为0
int Signal_rectangle_chat_bubble_level = 0;				//记录当前打印了几个矩形聊天气泡，同样场景下，矩形聊天气泡不超过10层，没打印时则为0层，打印了第一段话后为1，打印了第二段话后变为2，帮助确定下一个打印哪个矩形聊天气泡
int Signal_phone_chat_bubble_level = 0;					//记录当前打印了几个手机聊天界面，同样场景下，手机聊天界面不超过10层，没打印时则为0层，打印了第一段话后为1，打印了第二段话后变为2，来帮助确定下一个打印哪个手机聊天界面

int Object_controlled_x = 0;					//可被控制移动的物体的横坐标
int Object_controlled_y = 0;					//可被控制移动的物体的纵坐标
int Object_controlled_speed_x = 20;				//可被控制移动的物体的横坐标移动速度
int Object_controlled_speed_y = 20;				//可被控制移动的物体的纵坐标移动速度

int Object_mobile_y1 = 10;
int Object_mobile_y2 = 10;
int Object_mobile_speed_y1 = 30;
int Object_mobile_speed_y2 = 30;


//初始化页面背景图片的地址数组
LPCTSTR Image_address_page_background[100] = {	_T("./Page_background/0.png"), _T("./Page_background/1.jpg"), _T("./Page_background/2.jpg"),
												_T("./Page_background/3.jpg"), _T("./Page_background/4.jpg"), _T("./Page_background/5.jpg"),
												_T("./Page_background/6.jpg"), _T("./Page_background/7.jpg")
};


//初始化可控制物体图片的地址数组

LPCTSTR Image_address_object_controlled[100] = { _T("NULL"), _T("NULL"), _T("NULL"),
												_T("./object_controlled/1.png"), _T("./object_controlled/1.png"), _T("./object_controlled/1.png"),
												_T("./object_controlled/2.png"), _T("./object_controlled/3.png")
};
*/


//Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble_0 = _T("./Rectangle_chat_bubble/Chapter_1/0.png");
//Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble_1 = _T("./Rectangle_chat_bubble/Chapter_1/1.png");
//Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble_2 = _T("./Rectangle_chat_bubble/Chapter_1/2.png");
//Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble_3 = _T("./Rectangle_chat_bubble/Chapter_1/3.png");

//一个很粗心没有认真学习数组声明方式的小错误
//Pointer_present_node_page->NPC_1.Image_address[0] = _T("./Rectangle_chat_bubble/Chapter_1/0.png");
//Pointer_present_node_page->NPC_1.Image_address[1] = _T("./Rectangle_chat_bubble/Chapter_1/1.png");
//Pointer_present_node_page->NPC_1.Image_address[2] = _T("./Rectangle_chat_bubble/Chapter_1/2.png");
//Pointer_present_node_page->NPC_1.Image_address[3] = _T("./Rectangle_chat_bubble/Chapter_1/3.png");


//到这里函数结束了
//不是，下面还有
	/*
	在尝试img[]的时候，LPCTSTR xxx[10]不行；image xxx[10]不行；image xxx也不行
	*/
	//loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble_0, _T("./Rectangle_chat_bubble/Chapter_1/0.png"));
	//loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble_1, _T("./Rectangle_chat_bubble/Chapter_1/1.png"));
	//loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble_2, _T("./Rectangle_chat_bubble/Chapter_1/2.png"));

	//Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	//Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_brother_east_on_the_snow;
	//Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 4;
	//Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble_1 = _T("./Rectangle_chat_bubble/Chapter_1/2.png");


	/*

	bug案发现场：加载失败，但是类型是对的

	auto a = (Pointer_present_node_page->NPC_1.Rectangle_chat_bubble);
	loadimage(a, _T("./Rectangle_chat_bubble/Chapter_1/1.png"));
	printf("loadimage第2句成功！\n");
	loadimage(&(Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[2]), _T("./Rectangle_chat_bubble/Chapter_1/2.png"));
	loadimage(&(Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[3]), _T("./Rectangle_chat_bubble/Chapter_1/3.png"));

	auto a = &(Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[0]);
	loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[0], _T("./Rectangle_chat_bubble/Chapter_1/0.png"));
	loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[1], _T("./Rectangle_chat_bubble/Chapter_1/1.png"));
	loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[2], _T("./Rectangle_chat_bubble/Chapter_1/2.png"));
	loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[3], _T("./Rectangle_chat_bubble/Chapter_1/3.png"));


	*/

	//函数名呢？