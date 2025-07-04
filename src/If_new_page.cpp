#include "init_globle_variable.h"

void If_new_page() {
	if ((Pointer_present_node_page->Type == 2 || Pointer_present_node_page->Type == 3) && Pointer_indicator_new_page != Pointer_present_node_page) {
		Object_controlled_x = Pointer_present_node_page->Object_controlled.Born_x;
		Object_controlled_y = Pointer_present_node_page->Object_controlled.Born_y;
		Signal_exist_object_mobile_big_coin_1 = 1;
		Signal_exist_object_mobile_big_coin_2 = 1;
		Signal_exist_object_mobile_big_coin_3 = 1;
		Signal_scoreboard = 0;
		Object_mobile_big_coin_y1 = 370;
		Object_mobile_big_coin_y2 = 270;
		Object_mobile_big_coin_y3 = 170;
		Object_mobile_document_icon_y[0] = { 360 };
		Object_mobile_document_icon_y[1] = { -500 };
		Object_mobile_document_icon_y[2] = { -545 };
		Object_mobile_document_icon_y[3] = { -580 };
		Object_mobile_document_icon_y[4] = { -610 };
		Object_mobile_document_icon_y[5] = { -900 };
		//{360, -500, -545, -580, -610, -900};
		Signal_exist_object_mobile_document_icon[0] = { 1 };
		Signal_exist_object_mobile_document_icon[1] = { 1 };
		Signal_exist_object_mobile_document_icon[2] = { 1 };
		Signal_exist_object_mobile_document_icon[3] = { 1 };
		Signal_exist_object_mobile_document_icon[4] = { 1 };
		Signal_exist_object_mobile_document_icon[5] = { 1 };
		Pointer_indicator_new_page = Pointer_present_node_page;
	}
	if (Pointer_present_node_page->Type == 5 && Pointer_indicator_new_page != Pointer_present_node_page) {
		Init_BOSS_chapter();
		Pointer_indicator_new_page = Pointer_present_node_page;
	}
	Gif_n++;			//改变动图数目
	Gif_n %= 24;		//人物动图是8张，BOSS是12张，取最小公倍数24循环
	return;
}