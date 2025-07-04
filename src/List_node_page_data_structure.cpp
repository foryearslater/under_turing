#include "init_globle_variable.h"

//链表型数据结构需要的函数
//创建新的功能类型为1的页面结点
Node_page* Get_new_node_page(long long qq) {
	Node_page *p = (Node_page*)malloc(sizeof(Node_page));
	p->Editor_qq = qq;
	p->Next_page = NULL;
	p->Image_address_background = NULL;
	p->Object_controlled.Image_address = NULL;
	p->Object_controlled.Image_address_SRCAND = NULL;
	p->Object_controlled.Image_address_SRCPAINT = NULL;
	p->NPC_1.Image_address_phone_chat_bubble_SRCAND = NULL;
	p->Meet_page_door = NULL;
	p->Meet_page_door_2 = NULL;
	p->Meet_page_wall = NULL;
	p->NPC_1.Meet = NULL;
	p->NPC_2.Meet = NULL;
	p->NPC_3.Meet = NULL;
	p->Object_mobile.Image_address_SRCAND = NULL;
	p->Object_mobile.Image_address_SRCPAINT = NULL;
	p->Object_mobile.Image_address_scoreboard_SRCPAINT = NULL;
	p->Object_mobile.Meet = NULL;
	p->NPC_1.Image_address_rectangle_chat_bubble[0] = NULL;
	p->NPC_2.Image_address_rectangle_chat_bubble[0] = NULL;
	p->NPC_3.Image_address_rectangle_chat_bubble[0] = NULL;
	p->NPC_1.Image_address_phone_chat_bubble[0] = NULL;
	p->NPC_2.Image_address_phone_chat_bubble[0] = NULL;
	p->NPC_3.Image_address_phone_chat_bubble[0] = NULL;
	p->Meet_finish_game = NULL;
	return p;
};

/*
参考代码：
ListNode* getNewNode(int val) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));		//声明一个链表节点类型的指针变量p，初始化该指针：申请一片存储空间，让指针p指向该空间的首地址
	p->data = val;											//让待插入的值，储存到该链表节点的数据域中
	p->next = NULL;											//初始化该链表节点的指针域，让其指向空，NULL；
	return p;												//当代码到了25行，说明新的链表节点创建完成，返回节点类型的指针p，即节点地址；
}
typedef struct Node_page {
	long long Editor_qq;						//编写该页面节点编写者的qq号码
	int Type;									//该页面结点类型：0为片头，1为按键切换，2为移动物体到传送门切换，3为满足游戏条件切换，4为片尾
	struct Node_page *Next_page;				//下一个页面结点的首地址
	int Chapter;								//当前页面结点所处在的章节
	char Name[30];								//页面结点的名字————用于查找页面时，确认页面
	LPCTSTR Image_address_background;							//背景图片的文件地址指针
	LPCTSTR Image_address_object_controlled;					//当前页面的可控制物体图片的文件地址指针
	int Object_controlled_born_x;				//可控制物体在当前页面的的出生点横坐标（即一开始进入页面时，可控制物体所在的横坐标）
	int Object_controlled_born_y;				//可控制物体在当前页面的的出生点纵坐标（即一开始进入页面时，可控制物体所在的纵坐标）
	//int Object_controlled_x;					//可控制物体的当前横坐标——这两个好像不太需要，属于全局变量，暂时注释掉
	//int Object_controlled_y;					//可控制物体的当前纵坐标
	int Object_controlled_speed_x;				//可控制物体在当前页面的横坐标速度
	int Object_controlled_speed_y;				//可控制物体在当前页面的纵坐标速度
	LPCTSTR Image_address_object_mobile;						//当前页面的自动移动物体图片的文件地址指针——游戏关卡
	int Object_mobile_born_x;					//自动移动物体在当前页面的出生点横坐标
	int Object_mobile_born_y;					//自动移动物体在当前页面的出生点纵坐标
	//int Object_mobile_x;
	//int Object_mobile_y;
	int Object_mobile_speed_x;					//当前页面下，自动移动物体的横坐标移动速度
	int Object_mobile_speed_y;					//当前页面下，自动移动物体的纵坐标移动速度
	LPCTSTR Image_address_NPC_1;						//当前页面下，1号NPC的图片文件地址指针
	LPCTSTR Image_address_NPC_2;						//当前页面下，1号NPC的图片文件地址指针
	LPCTSTR Image_address_NPC_3;						//当前页面下，1号NPC的图片文件地址指针
	void (*Meet_page_wall)();					//当前页面下，碰撞墙壁的函数指针
	void (*Meet_page_door)();					//当前页面下，碰撞传送门的函数指针
	void (*Meet_page_NPC_1)();					//当前页面下，碰撞1号NPC的函数指针
	void (*Meet_page_NPC_2)();					//当前页面下，碰撞2号NPC的函数指针
	void (*Meet_page_NPC_3)();					//当前页面下，碰撞3号NPC的函数指针
	int Sum_rectangle_chat_bubble;							//当前页面下，矩形聊天气泡图片总数量
	LPCTSTR Image_address_rectangle_chat_bubble[20];		//当前页面下，矩形聊天气泡图片的文件地址指针数组
	int Sum_phone_chat_bubble;								//当前页面下，手机聊天气泡图片总数量
	LPCTSTR Image_address_phone_chat_bubble[20];			//当前页面下，手机聊天气泡图片的文件地址指针数组
} Node_page;			//此处的作用是，设置结构体名称的简写；结构体全称为struct Node_page，简写为Node_page；
*/



List_page* Get_list_page() {
	List_page* p = (List_page*)malloc(sizeof(List_page));
	p->Head.Next_page = NULL;
	p->Length = 0;
	return p;
};

/*
参考代码：
List* getLinkList() {
	List* l = (List*)malloc(sizeof(List));		//声明一个链表类型的指针变量l，初始化指针l指向链表首地址，开辟新的存储空间，大小为链表变量类型的大小
	l->head.next = NULL;						//初始化该链表头指针的指针域，指向空，NULL
	l->Length = 0;								//初始化链表长度为0；
	return l;
}
*/


//写到这里，发现一个问题，那就是，插入函数ind，也不得不那啥记住每一张，除非，在一个篇章里，单独设计该篇章最开始的ind，其他的都是ind + 1, ind + 2, ..., ind + i;
//第二个问题是：指针在不断地指向下一个的遍历过程中，不能不断地变换指针类型；
int Insert_new_node_page(List_page* Under_turing, int ind, long long qq) {
	if (Under_turing == NULL) return 0;
	if (ind < 0 || ind > Under_turing->Length) return 0;
	Node_page* p = &(Under_turing->Head), * node = Get_new_node_page(qq);
	while (ind--) p = p->Next_page;
	node->Next_page = p->Next_page;
	p->Next_page = node;
	Under_turing->Length += 1;
	return 1;
};

/*
int insert(List* l, int ind, int val) {
	if (l == NULL) return 0;								//如果指向链表首地址的指针为空，插入失败，则返回0；
	if (ind < 0 || ind > l->Length) return 0;				//待插入位置小于0，或者带插入位置大于链表长度，插入失败，返回0；
	ListNode* p = &(l->head), * node = getNewNode(val);		//声明一个链表节点类型的指针p，初始化为头节点的首地址（即，链表类型变量中的head），声明一个链表节点类型的指针node，指向一个新开辟节点的首地址
	while (ind--) p = p->next;								//p从指向头节点开始，指向p的下一个节点的首地址；如此循环ind次（意味着，头节点就是-1号位置的节点，指向的第一个节点是0号位置的节点）
	node->next = p->next;									//令新节点的指针域，指向从头节点往后走了ind步以后，的节点的下一个节点的首地址（这样就就有两个指针指向它了，p->next 和 node->next）
	p->next = node;											//再让原来辛辛苦苦走了n步的指针所指向的节点，的指针域，指向新开辟节点的首地址
	l->Length += 1;											//当代码执行到42行的时候，说明插入节点，调整指针的操作完成，链表长度加1；
	return 1;												//当代码执行到底43行的时候，说明插入节点，调整链表的操作完成，返回1；
}
*/



int Erase_node_page(List_page* Under_turing, int ind) {
	if (Under_turing == NULL) return 0;							//现在知道这些指针判空操作有多重要了
	if (ind < 0 || ind > Under_turing->Length) return 0;
	Node_page* p = &(Under_turing->Head), * q;
	while (ind--) p = p->Next_page;
	q = p->Next_page;
	if (q != NULL) p->Next_page = q->Next_page;					//原来的代码是 p->Next_page = q->Next_page，q有可能是空指针，使得调用了NULL指针，中途退出，退出代码为：-1073741819
	else p->Next_page = q;
	free(q);
	Under_turing->Length -= 1;
	return 1;
}


/*
参考代码：
//定义函数：删除节点操作
//输入参数：待插入的链表节点的首地址，用链表类型的指针变量l来接收，待删除结点的位置
//输出参数：整型变量，删除成功返回1；否则返回0；
int erase(List* l, int ind) {
	if (l == NULL) return 0;						//若指向链表首地址的指针为空，则找不到链表，删除失败，返回0；
	if (ind < 0 || ind >= l->Length) return 0;		//若删除位置小于0，或者超过链表长度Length，则找不到待删除的链表节点，删除失败，返回0；
	ListNode* p = &(l->head), * q;					//声明一个链表节点的指针变量p，初始化为指向链表头节点，声明一个链表节点的指针变量q，未初始化；
	while (ind--) p = p->next;						//指针p从头指针指向指针域中储存的下一个链表节点的首地址，如此往后走ind步（从-1开始走）
	q = p->next;									//令指针q指向待删除节点的首地址，即，ind的节点首地址，即，从-1走完ind步后所在节点的指针域中储存的下一个节点首地址
	p->next = q->next;								//令指针p的指针域指向待删除节点（也就是p->next和q都指向的节点首地址)的下一个节点，即，待删除结点的指针域，指向下一个结点的下一个结点的首地址；（为什么，这里不能只用，一个指针，p->next = (p->next)->next ?)
	free(q);										//释放待删除结点的空间，即，指针q的空间；
	l->Length -= 1;									//链表长度减1
	return 1;										//当代码执行到第58行，意味着删除操作完成，返回1；
}


*/

void Output_all_node_page(List_page* Under_turing) {
	printf("List_page(Length = %d) = [", Under_turing->Length);
	int N_level = 0;
	for (Node_page* p = Under_turing->Head.Next_page; p; p = p->Next_page) {
		printf("(%d, %lld)->",N_level, p->Editor_qq);
		N_level++;
	}
	printf("NULL] \n");
	return;
}

/*
参考代码：
//定义函数：输出链表内容
//输入参数：带输出的链表首地址，用链表类型的指针变量来接收
//输出参数：空
void output(List *l) {
	printf("List(%d) = [", l->Length);						//打印链表，及其长度
	for (ListNode* p = l->head.next; p; p = p->next) {		//声明一个循环过程，指针p指向第0位置节点首地址，即，从头指针的指针域开始，当指针不为空时，进入循环，每完成一次循环，指针指向当前节点的指针域
		printf("%d->", p->data);							//打印节点
	}
	printf("NULL]\n");										//当代码执行到69行，循环结束，意味着p->next为空，最后一个链表的指针域为空，打印NULL
	return;													//当代码执行到70行，意味着打印链表完成，返回空值；
}
*/

void Clear_node_page(Node_page* node) {
	if (node == NULL) return;
	free(node);
	return;
}

/*
参考代码：
//定义函数：清空节点
//输入参数：待清空节点的首地址，用链表节点类型的指针变量来接收
//输出参数：空值
void clear_ListNode(ListNode* node) {
	if (node == NULL) return;			//如果指向节点首地址的指针为空，则返回空值
	free(node);							//当代码执行到第100行，说明不为空，释放该指针所指向的节点所占据的存储空间
	return;								//释放完成，返回空值
}
*/

void Clear_list_page(List_page* Under_turing) {
	if (Under_turing == NULL) return;
	Node_page* p = Under_turing->Head.Next_page, * q;
	while (p) {
		q = p->Next_page;
		Clear_node_page(p);
		p = q;
	}
	free(Under_turing);
	return;
}

/*
参考代码：
//定义函数，清空链表操作
//输入参数：待清空的链表首地址，用链表类型的指针变量来接收
//输出参数：空值
void clear_list(List* l) {
	if (l == NULL) return;				//当指向链表首地址的指针为空，则说明找不到带清空的链表，清空失败，返回空值
	ListNode* p = l->head.next, * q;	//声明2个链表节点类型的指针变量p和q，初始胡指针p，令它指向0号节点
	while (p) {							//当指针p不为空时
		q = p->next;					//令指针q指向指针p指向的节点的下一个节点
		clear_ListNode(p);				//清空指针p
		p = q;							//令指针p指向指针q指向的节点，直至q为空，即p->next为空，
	}
	free(l);							//当代码执行到第115行，后续所有链表节点的清空操作完成，清空链表，即，释放指针l指向的储存链表的空间
	return;								//当代码执行到了116行，清空链表操作完成，返回空值；
}
*/
