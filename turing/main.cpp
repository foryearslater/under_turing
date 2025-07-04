#include "init_globle_variable.h"

int main() {
	initgraph(Window_width, Window_height);
	printf("sizeof(IMAGE) = %lld\n", sizeof(IMAGE));
	printf("sizeof(LPCTSTR) = %lld\n", sizeof(LPCTSTR));

	Init_game_data_chapter_0();
	Init_game_data_chapter_1();
	Init_game_data_chapter_2();
	Init_game_data_chapter_3();
	Init_game_data_chapter_4();

	while (1) {
		If_new_page();				//判定是否是新的一页，是的话得重置人物坐标、自动移动的物体的坐标等等；
		Draw_page();				//打印页面所有内容
		Key_control();				//键盘控制
		Meet();						//碰撞判定
		Sleep(50);
	}
	getchar();
	return 0;
}
































//早期版本中的注释

	/*
	//测试页面链表型数据结构的增删函数操作：
	srand(time(0));

	List_page* Game_data_under_turing = Get_list_page();
	int op, ind, qq;
	printf("初始化了吗？Game_data_under_turing->length = %d\n", Game_data_under_turing->length);

	printf("准备进入循环\n");
	printf("---------------------------\n");
	for (int i = 0; i < max_op; i++) {
		printf("进行循环：i = %d\n", i);
		printf("随机函数操作前的链表长度：Game_data_under_turing->length = %d\n", Game_data_under_turing->length);
		op = rand() % 4;
		ind = rand() % (Game_data_under_turing->length + 3) - 1;
		qq = rand() % 100;
		printf("随机函数操作前的随机数据：\n");
		printf("操作符：op = %d, 待操作链表节点的下标：ind = %d, 随机qq号：qq = %d\n", op, ind, qq);
		switch (op) {
		case 0:
		case 1:
		case 2:
			printf("insert qq: %d at %d to List = %d\n", qq, ind, Insert_new_node_page(Game_data_under_turing, ind, qq));
			break;
		case 3:
			printf("erase item at %d from List = %d\n", ind, Erase_node_page(Game_data_under_turing, ind));
			break;
		}
		Output_all_node_page(Game_data_under_turing);
		printf("\n");
	}
	Clear_list_page(Game_data_under_turing);


	参考代码：

	srand(time(0));
#define max_op 20
	List* l = getLinkList();
	int op, ind, val;
	for (int i = 0; i < max_op; i++) {
		op = rand() % 4;
		ind = rand() % (l->length + 3) - 1;
		val = rand() % 100;
		switch (op) {
			case 0:
			case 1: {
				printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
			} break;
			case 2: {
				printf("reverse the list\n");
				rev(l);
			} break;
			case 3: {
				printf("erase item at %d from List = %d\n", ind, erase(l, ind));
			} break;
		}
		output(l);
		printf("\n");
	}
	clear_list(l);
	*/