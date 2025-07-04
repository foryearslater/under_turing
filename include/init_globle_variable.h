#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <easyx.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>
#include "List_node_page_data_structure.h"
//元气骑士中所需要的头文件；
# pragma once
# include <process.h>
# include <math.h>
# include <mmsystem.h>
# pragma comment (lib,"winmm.lib")

#define max_op 20

/*
《全局变量及函数名称——命名规范》：
1、全是英文全称；
2、空格用下划线_替代，每一个单词之间都需要一个下划线“_”；
3、只有名称的第一个单词的开头字母是大写，其余全是小写字母；
*/


void Key_control();						//键盘控制函数，上下左右会改变需要打印的可移动物体的横纵坐标

void If_new_page();					//判定是否是新的一页，从而确定是否需要重置人物坐标

//画图相关的函数
void Draw_page();						//画出所有页面中需要的内容
void Draw_page_background();			//画出页面对应的背景图像，即在(0, 0)位置上打印出和窗口大小相等的全页面的图像
void Draw_object_controlled();			//画出页面对应的可控制物体的图像
void Draw_object_mobile();				//画出页面对应的自动移动物体的图像
void Draw_rectangle_chat_bubble();		//画出矩形聊天气泡
void Draw_phone_chat_bubble();			//画出手机聊天界面
void Draw_scoreboard();					//画出游戏关卡的记分牌
void Draw_blood();						//画出BOSS关卡中人物和怪物的血量
void Draw_bullet();						//接受鼠标消息，移动子弹，子弹碰撞判定，画出子弹的子弹合集
void Create_bullet();					//接收鼠标消息，创建子弹；
void Draw_each_bullet();				//画出每一个子弹
void Move_bullet();						//子弹移动函数
void Hit_BOSS_bullet();					//子弹碰撞判定
void Draw_door_to_essay();				//画通向小作文的传送门

//BGM函数
void Bgm_shadow();
void Bgm_adventure_island_1();
void Bgm_adventure_island_2();
void Bgm_end_credit();
void Bgm_birthday();
//判定碰撞相关的函数
void Meet();							//碰撞判定合集
void Meet_door();						//碰撞传送门判定
void Meet_NPC();						//碰撞NPC判定
void Meet_wall();						//碰撞围墙判定
void Meet_finish_game();				//满足游戏条件判定
void Meet_object_mobile();				//碰撞自动移动物体判定
void Meet_auto_play();					//自动播放画面的页面，停留一段时间后自动跳转

//碰撞传送门函数
void Meet_door_to_next_page();
void Meet_door_bilibili_vedio_end();
void Meet_door_communication_group();
void Meet_door_right_choice_box();
void Meet_door_wrong_choice_box();
void Meet_door_girls_on_the_snow();
void Meet_door_corridor();
void Meet_door_station();
void Meet_door_computer();
void Meet_door_group_introduction_meeting();

void Meet_door_chapter_2_library();
void Meet_door_2_chapter_2_library();
void Meet_door_chapter_2_game_easter_eggs();
void Meet_door_chapter_2_game_easter_eggs_to_library();

void Meet_door_chapter_3_library();

void Meet_door_chapter_4_cycle_1_40km();
void Meet_door_chapter_4_cycle_2_25km();
void Meet_door_chapter_4_cycle_3_10km();
void Meet_door_chapter_4_cycle_4();
void Meet_door_chapter_4_lobby_conversation();

//碰撞NPC函数《混吃等死篇》
void Meet_NPC_1_brother_east_on_the_snow();
void Meet_NPC_1_girls_on_the_snow();
void Meet_NPC_1_corridor();
void Meet_NPC_1_group_meeting();
void Meet_NPC_1_station();
void Meet_NPC_2_station();
void Meet_NPC_3_station();
//碰撞NPC函数《产品经理篇》
void Meet_NPC_1_chapter_2_library();
void Meet_NPC_2_chapter_2_library();
//碰撞NPC函数《催命记录官篇》
void Meet_NPC_1_chapter_3_library_phone();
//碰撞NPC函数《技术官篇》
void Meet_NPC_1_chapter_4_lobby_conversation();
void Meet_NPC_2_chapter_4_lobby_conversation();


//碰撞围墙函数
void Meet_wall_video_left();
void Meet_wall_tree_house_on_the_snow();
void Meet_wall_tree_house_girls_on_the_snow();
void Meet_wall_corridor();
void Meet_wall_station();
void Meet_wall_computer();
void Meet_wall_group_introduction_left();
void Meet_wall_big_coin_computer();

void Meet_wall_chapter_2_library();
void Meet_wall_chapter_2_game_easter_eggs_room();

void Meet_wall_chapter_4_cycle_1_40km();
void Meet_wall_chapter_4_cycle_2_25km();
void Meet_wall_chapter_4_cycle_3_10km();
void Meet_wall_chapter_4_cycle_4();
void Meet_wall_chapter_4_lobby_conversation();

//游戏关卡碰撞围墙函数
void Meet_object_mobile_big_coin();
void Meet_object_mobile_document_icon();

//游戏关卡，满足结束游戏条件的函数
void Meet_finish_game_get_3_big_coin();
void Meet_finish_game_get_1_document_icon();
void Meet_finish_game_get_6_document_icon();
void Meet_NPC_1_chapter_3_level_2_game_over();

//操作链表型数据结构需要的函数——增删
Node_page* Get_new_node_page(long long qq);												//创建新的页面结点
List_page* Get_list_page();																//获取新的链表

int Insert_new_node_page(List_page* Under_turing, int ind, long long qq);				//向链表插入新的页面节点，所需要的参数包括：1、链表首地址；2、链表的第几个位置；3、插入者的qq号）
int Erase_node_page(List_page* Under_turing, int ind);									//在链表种消除页面结点，所需要的参数包括：1、链表首地址；2、链表的第几个位置
void Output_all_node_page(List_page* Under_turing);									//输出链表所有的页面结点，所需要的参数包括：1、链表首地址

void Clear_node_page(Node_page* Node_page);												//清空页面结点，所需要的参数包括：页面结点的首地址
void Clear_list_page(List_page* Under_turing);											//清空链表，所需要的参数包括：链表首地址

//初始化数据对应的函数
void Init_game_data_chapter_0();
void Init_game_data_chapter_1();
void Init_game_data_chapter_2();
void Init_game_data_chapter_3();
void Init_game_data_chapter_4();
void Init_game_data_chapter_4_push_computer();
void Init_BOSS_chapter();
void Init_game_date_end_credit();
//下面是全局变量的声明

//记录游戏窗口大小
extern int Window_width;		//游戏窗口的长度
extern int Window_height;		//游戏窗口的高度

extern List_page* Game_data_under_turing;		//指向链表首地址的指针，以链表形式记录《图灵之下——浪惊风云夜》所有游戏数据
extern Node_page* Pointer_present_node_page;	//指向页面结点首地址的指针，记录当前所在页面
extern Node_page* Pointer_indicator_new_page;	//和当前页面作比较，如果发生了改变，意味着到了新的一页，需要重置人物坐标；

//一些在所有地图中都用得上的全局变量
extern int Signal_page_level;					//记录当前页数，表达现在第几层所有不同的地图背景层数加起来大约为70层左右；
extern int Signal_meet_NPC_1;					//记录角色当前是否碰撞到NPC1，碰撞到为1，没有则为0；
extern int Signal_meet_NPC_2;					//记录角色当前是否碰撞到NPC2，碰撞到为1，没有则为0；
extern int Signal_meet_NPC_3;					//记录角色当前是否碰撞到NPC3，碰撞到为1，没有则为0；
extern int Signal_meet_door;					//记录角色当前是否碰撞到传送门，碰撞到为1，没有则为0；
extern int Signal_meet_coin;					//记录角色当前是否碰到游戏内的金币，碰撞到【加1】，没有则为0；
extern int Signal_meet_document_icon;			//记录角色当前是否碰到游戏内的文档图标，碰撞到【加1】，没有则为0；
extern int Signal_meet_choice_box;							//记录角色当前是否碰到选项；碰到“忘了”返回1，碰到“5个”返回2，碰到“6个”返回3，碰到“7个”返回4，没有则为0
extern int Signal_rectangle_chat_bubble_1_level;				//记录当前应该打印的矩形聊天气泡“层数”，同样场景下，矩形聊天气泡不超过10层，来帮助确定下一个打印哪个矩形聊天气泡
extern int Signal_rectangle_chat_bubble_2_level;				//记录当前应该打印的矩形聊天气泡“层数”，同样场景下，矩形聊天气泡不超过10层，来帮助确定下一个打印哪个矩形聊天气泡
extern int Signal_rectangle_chat_bubble_3_level;				//记录当前应该打印的矩形聊天气泡“层数”，同样场景下，矩形聊天气泡不超过10层，来帮助确定下一个打印哪个矩形聊天气泡

extern int Signal_phone_chat_bubble_1_level;					//记录当前应该打印的手机聊天界面“层数”，同样场景下，手机聊天界面不超过10层，来帮助确定下一个打印哪个手机聊天界面
extern int Signal_phone_chat_bubble_2_level;
extern int Signal_phone_chat_bubble_3_level;

//记录可控制单位的横纵坐标，以及对应的移动速度，以方便跟随键盘进行变化
extern int Object_controlled_x;				//可被控制移动的物体的横坐标
extern int Object_controlled_y;				//可被控制移动的物体的纵坐标

//记录自动移动单位的横纵坐标
extern int Object_mobile_x;							//自动移动的物体的横坐标
extern int Object_mobile_big_coin_y1;				//自动移动的金币1的纵坐标
extern int Object_mobile_big_coin_y2;
extern int Object_mobile_big_coin_y3;
extern int Signal_exist_object_mobile_big_coin_1;				//判定金币1号是否存在，1为存在，则打印，并且可被碰撞；0为不存在，则不打印，并且不可被碰撞
extern int Signal_exist_object_mobile_big_coin_2;
extern int Signal_exist_object_mobile_big_coin_3;
extern int Signal_scoreboard;


//可行性分析，开发计划表、需求文档、功能流程图、产品原型图、详细功能概述
extern int Object_mobile_document_icon_y1;
extern int Object_mobile_document_icon_y[];
extern int Object_mobile_document_icon_x[];
extern int Signal_exist_object_mobile_document_icon_1;
extern int Signal_exist_object_mobile_document_icon[];

//片尾文字纵坐标
extern int End_credit_y;


//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------
//元气骑士游戏所需要的文件变量及函数

//窗口的宽和高
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

//人物的宽高
# define PEOPLE_WIDTH 120
# define PEOPLE_HEIGHT 120

//移动速度
# define wjsd 25//玩家速度
# define drsd 10//怪物速度

//子弹的大小
# define zidan_WIDTH 16
# define zidan_HEIGHT 16

//子弹数量
# define zidan_slwj 30//玩家的
# define zidan_slgw 1//怪物的

//子弹速度
# define wjzdsd 60//玩家子弹速度
# define gwzdsd 40//怪物子弹速度


//怪物数量
# define gwsl 2

//配置图片
extern IMAGE jiemian[5];
extern IMAGE DTSJ;
extern IMAGE z, Z;
extern IMAGE move0, move1, move2, move3;
extern IMAGE zd1, zd2;
extern IMAGE jszd1, jszd11;
extern IMAGE bjy, bjz;
extern IMAGE zt, ztcd;
extern IMAGE yxjs;
//进入游戏后与返回菜单变量
extern int t;




void huiji(void);//函数汇集

void show1(void);//显示输出数据图片函数
void wjkz(void);// 控制玩家函数
void ycgwyd1(void);//远程怪物移动函数1
void ycgwyd2(char, char, char, struct gwjg*);//远程怪物移动函数2
void initzd(struct zdjg*, int);//初始化子弹属性函数
void createwjzd(void);//创建一个玩家子弹函数
void creategwzd(void);//创建一个敌人子弹函数
void gyzdydhs(struct zdjg*, int, int);//共用的子弹移动函数
void wjzdpz(struct zdjg*, int, int);//玩家子弹碰撞函数
void gwzdpz(struct zdjg*, int, int);//怪物子弹碰撞函数
int ztks(void);//暂停开始函数
void initxy(void);//返回菜单重新初始化数据
void xuetiao(void);//血条函数
void initgwwz(void);//初始化怪物随机位置
bool gwbch(int);//怪物不重合函数


void load_img(void);				//加载图片数据

//---------------------------------------------------------------
//BOSS关卡所需要的函数：
//void BOSS(void);					//BOSS关卡
void Draw_player();					//根据人物方向，画出人物；
//玩家与BOSS所需要的全局变量
extern int Signal_exist_boss;				//BOSS是否存活的指标，1为存活，0为死亡；
extern int Signal_exist_player;				//玩家是否存活的指标，1为存活，0为死亡；
extern int Gif_n;							//记录动图的循环
extern int BOSS_x;							//记录BOSS所在的横坐标
extern int BOSS_y;							//记录BOSS所在的横坐标
extern int BOSS_blood_number;				//玩家血量数字
extern int BOSS_blood_rectangle;			//玩家血量矩形长度
extern int Player_x;						//记录BOSS所在的横坐标
extern int Player_y;						//记录BOSS所在的横坐标
extern int Player_direction;				//记录玩家方向
extern int Player_blood_number;				//玩家血量数字
extern int Player_blood_rectangle;			//玩家血量矩形长度
extern ExMessage Player_action;				//玩家的行为消息
extern int Bullet_amount;					//玩家子弹数量
extern bullet Player_bullet[];				//玩家子弹
extern int Speed_bullet;					//玩家子弹移动速度

//子弹、玩家、怪物图片变量
extern IMAGE BOSS;								//BOSS图像
extern IMAGE img_player_left;					//玩家朝左
extern IMAGE img_player_right;					//玩家朝右
extern IMAGE img_boss_bullet_SRCAND;			//怪物子弹
extern IMAGE img_boss_bullet_SRCPAINT;			//怪物子弹
extern IMAGE img_player_bullet_SRCAND;			//玩家子弹
extern IMAGE img_player_bullet_SRCPAINT;		//玩家子弹






//或许，我应该学到的流程来写，先找到所有需要表示的东西，再挨个挨个写函数，控制它
//而不是，挨个挨个函数写，再找到变量来弄；






























//------------------------------------------------------------------------------------------------------------------------
//下面这种是第一个版本的数据结构定义方式，数组式

/*

//Singal类型数据，主要用于记录以下信息：
//当前页面的功能类型，当前页面层数，当前是否碰撞到NPC、当前是否碰撞到传送门，等信息；
extern int Signal_page_type[100];			//记录不同level页面的功能类型：0为片头页面，1为按键直接跳过的剧情页面；2为人物可移动的剧情页面；3为游戏关卡页面；
extern int Signal_page_level;				//记录当前页数，表达现在第几层所有不同的地图背景层数加起来大约为70层左右；
extern int Signal_meet_NPC_1;					//记录角色当前是否碰撞到NPC1，碰撞到为1，没有则为0；
extern int Signal_meet_NPC_2;					//记录角色当前是否碰撞到NPC2，碰撞到为1，没有则为0；
extern int Signal_meet_NPC_3;					//记录角色当前是否碰撞到NPC3，碰撞到为1，没有则为0；
extern int Signal_meet_door;				//记录角色当前是否碰撞到传送门，碰撞到为1，没有则为0；
extern int Signal_meet_coin;				//记录角色当前是否碰到游戏内的金币，碰撞到【加1】，没有则为0；
extern int Signal_meet_document_icon;		//记录角色当前是否碰到游戏内的文档图标，碰撞到【加1】，没有则为0；
extern int Signal_meet_choice_box;							//记录角色当前是否碰到选项；碰到“忘了”返回1，碰到“5个”返回2，碰到“6个”返回3，碰到“7个”返回4，没有则为0
extern int Signal_rectangle_chat_bubble_level;				//记录当前应该打印的矩形聊天气泡“层数”，同样场景下，矩形聊天气泡不超过10层，来帮助确定下一个打印哪个矩形聊天气泡
extern int Signal_phone_chat_bubble_level;					//记录当前应该打印的手机聊天界面“层数”，同样场景下，手机聊天界面不超过10层，来帮助确定下一个打印哪个手机聊天界面


//记录当前移动单位的横纵坐标，以及对应的移动速度，以方便跟随键盘进行变化
extern int Object_controlled_x;				//可被控制移动的物体的横坐标
extern int Object_controlled_y;				//可被控制移动的物体的纵坐标
extern int Object_controlled_speed_x;		//可被控制移动的物体的横坐标移动速度
extern int Object_controlled_speed_y;		//可被控制移动的物体的纵坐标移动速度

extern int Object_mobile_x;					//自动移动的物体的横坐标
extern int Object_mobile_y1;					//自动移动的物体的纵坐标
extern int Object_mobile_y2;
extern int Object_mobile_speed_x;			//自动移动的物体的横坐标移动速度
extern int Object_mobile_speed_y1;			//自动移动的物体的纵坐标移动速度
extern int Object_mobile_speed_y2;


extern LPCTSTR Image_address_page_background[100];				//背景图片的图片地址
extern LPCTSTR Image_address_object_controlled[100];			//可控制移动物体的图片地址

extern IMAGE Image_address_rectangle_chat_bubble[100];			//矩形聊天气泡的图片地址



*/