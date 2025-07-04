//定义储存和可控制物体有关的数据的结构体
typedef struct Data_object_controlled {
	LPCTSTR Image_address;				//
	LPCTSTR Image_address_SRCAND;		//当前页面下，可控制物体图片的文件地址指针1
	LPCTSTR Image_address_SRCPAINT;		//当前页面下，可控制物体图片的文件地址指针2——用于去除黑色边框
	int Born_x;							//当前页面下，可控制物体的出生点横坐标（即一开始进入页面时，可控制物体所在的横坐标）
	int Born_y;							//当前页面下，可控制物体的出生点纵坐标（即一开始进入页面时，可控制物体所在的纵坐标）
	int Speed_x;						//当前页面下，可控制物体的横坐标速度
	int Speed_y;						//当前页面下，可控制物体的纵坐标速度
	int Width;							//当前页面下，可控制物体的图片宽度；
	int Height;							//当前页面下，可控制物体的图片高度；
} Data_object_controlled;

typedef struct Data_NPC {
	void (*Meet)();											//当前页面下，碰撞1号NPC的函数指针
	int Sum_rectangle_chat_bubble;							//当前页面下，矩形聊天气泡图片总数量
	LPCTSTR Image_address_rectangle_chat_bubble[20];
	int Sum_phone_chat_bubble;
	LPCTSTR Image_address_phone_chat_bubble[20];
	LPCTSTR Image_address_phone_chat_bubble_SRCAND;
} Data_NPC;

typedef struct Data_object_mobile {
	LPCTSTR Image_address_SRCAND;				//当前页面下，自动移动物体图片的文件地址指针——《游戏关卡》
	LPCTSTR Image_address_SRCPAINT;				//当前页面下，可控制物体图片的文件地址指针2——用于去除黑色边框
	LPCTSTR Image_address_scoreboard_SRCPAINT;	//记分牌的图片文件地址指针
	void (*Meet)();								//当前页面下，碰撞自动移动的物体的函数指针
	int Object_mobile_born_x;					//当前页面下，自动移动物体的出生点横坐标
	int Object_mobile_born_y;					//当前页面下，自动移动物体的出生点纵坐标
	int Object_mobile_speed_x;					//当前页面下，自动移动物体的横坐标移动速度
	int Object_mobile_speed_y;					//当前页面下，自动移动物体的纵坐标移动速度
	int Width;									//当前页面下，自动移动物体的图片宽度；
	int Height;									//当前页面下，自动移动物体的图片高度；
} Data_ojbect_mobile;

//定义存储一个页面所有数据的结构体类型——页面结点
typedef struct Node_page {
	long long Editor_qq;						//编写该页面节点编写者的qq号码
	int Type;									//该页面结点类型：0为片头，1为按键切换，2为移动物体到传送门切换，3为满足游戏条件切换，4为片尾
	struct Node_page *Next_page;				//下一个页面结点的首地址
	int Chapter;								//当前页面结点所处在的章节
	long long Name_number;								//页面结点的名字————用于查找页面时，确认页面
	LPCTSTR Image_address_background;			//背景图片的文件地址指针
	Data_object_controlled Object_controlled;
	Data_NPC NPC_1;
	Data_NPC NPC_2;
	Data_NPC NPC_3;
	void (*Meet_page_wall)();					//当前页面下，碰撞墙壁的函数指针
	void (*Meet_page_door)();					//当前页面下，碰撞传送门的函数指针
	void (*Meet_page_door_2)();					//当前页面下，碰撞传送门的函数指针
	Data_object_mobile Object_mobile;
	void (*Meet_finish_game)();					//满足结束游戏条件的函数；
} Node_page;			//此处的作用是，设置结构体名称的简写；结构体全称为struct Node_page，简写为Node_page；

//定义一个由页面结点连起来的链表
typedef struct List_page {
	Node_page Head;					//头号结点
	int Length;						//链表总长度
} List_page;						//简写为List_page；


//子弹相关的结构体
typedef struct bullet {
	int current_x, current_y;					//子弹当前坐标
	int destination_x, destination_y;			//子弹最终目的地坐标
	int birth_x, birth_y;						//子弹出生地坐标
	bool live;									//子弹是否存活
} bullet;










































/*

	//LPCTSTR Image_address[10];								//当前页面下，1号NPC的图片文件地址指针，NPC不用额外打印，本身就在地图背景中————这种解决了，更改初始化的方式；
	//IMAGE Rectangle_chat_bubble[10];						//拜托了log小学长的问题；
	//我在这里想用一个数组，全部一起初始化，方便后面用循环挨个读取

	//LPCTSTR Image_address_rectangle_chat_bubble_1;			//当前页面下，矩形聊天气泡图片的文件地址
	//bug案发现场：
	//IMAGE Rectangle_chat_bubble[10];							//——这两种定义方式，在结构体中定义后，初始化会出问题：当前页面下，矩形聊天气泡图片的文件地址指针数组
	//LPCTSTR Image_address[10];								//当前页面下，1号NPC的图片文件地址指针，NPC不用额外打印，本身就在地图背景中


	/*
	LPCTSTR Image_address_object_controlled;	//当前页面的可控制物体图片的文件地址指针
	int Object_controlled_born_x;				//可控制物体在当前页面的的出生点横坐标（即一开始进入页面时，可控制物体所在的横坐标）
	int Object_controlled_born_y;				//可控制物体在当前页面的的出生点纵坐标（即一开始进入页面时，可控制物体所在的纵坐标）
	//int Object_controlled_x;					//可控制物体的当前横坐标——这两个好像不太需要，属于全局变量，暂时注释掉
	//int Object_controlled_y;					//可控制物体的当前纵坐标
	int Object_controlled_speed_x;				//可控制物体在当前页面的横坐标速度
	int Object_controlled_speed_y;				//可控制物体在当前页面的纵坐标速度
	*/


	/*
	LPCTSTR Image_address_object_mobile;		//当前页面的自动移动物体图片的文件地址指针——《游戏关卡》
	int Object_mobile_born_x;					//自动移动物体在当前页面的出生点横坐标
	int Object_mobile_born_y;					//自动移动物体在当前页面的出生点纵坐标
	//int Object_mobile_x;
	//int Object_mobile_y;
	int Object_mobile_speed_x;					//当前页面下，自动移动物体的横坐标移动速度
	int Object_mobile_speed_y;					//当前页面下，自动移动物体的纵坐标移动速度
	*/


	/*
	LPCTSTR Image_address_NPC_1;				//当前页面下，1号NPC的图片文件地址指针
	LPCTSTR Image_address_NPC_2;				//当前页面下，1号NPC的图片文件地址指针
	LPCTSTR Image_address_NPC_3;				//当前页面下，1号NPC的图片文件地址指针
	void (*Meet_page_NPC_1)();					//当前页面下，碰撞1号NPC的函数指针
	void (*Meet_page_NPC_2)();					//当前页面下，碰撞2号NPC的函数指针
	void (*Meet_page_NPC_3)();					//当前页面下，碰撞3号NPC的函数指针
	int Sum_rectangle_chat_bubble;							//当前页面下，矩形聊天气泡图片总数量
	LPCTSTR Image_address_rectangle_chat_bubble[20];			//当前页面下，矩形聊天气泡图片的文件地址指针数组
	int Sum_phone_chat_bubble;								//当前页面下，手机聊天气泡图片总数量
	LPCTSTR Image_address_phone_chat_bubble[20];				//当前页面下，手机聊天气泡图片的文件地址指针数组
	*/


