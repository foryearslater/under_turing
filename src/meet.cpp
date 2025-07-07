#include "init_globle_variable.h"


void Meet() {
	Meet_door();								//�ж�����ҿ��Ƶ�λ���Ƿ�������������door������ת����һҳ��
	Meet_NPC();									//�ж�����ҿ��Ƶ�λ���Ƿ�������NPC���������Ի�����ӡ��������
	Meet_wall();								//�ж�����ҿ��Ƶ�λ���Ƿ������ϰ������ͨ��
	Meet_object_mobile();						//�ж���ҿ��Ƶĵ�λ�Ƿ�ײ���Զ��ƶ��ĵ�λ��0Ϊûײ����1Ϊײ����1��
	Meet_finish_game();
	Meet_auto_play();							//�����Զ����ţ���¼ѭ����ͬһ������ļ���������ÿ��һ�Σ���һ��ֱ��0������һ�ţ�
	//Meet_enermy();
	//Meet_drug();
	return;
}

void Meet_door() {
	if (Pointer_present_node_page->Type == 2 && Pointer_present_node_page->Meet_page_door != NULL) {
		Pointer_present_node_page->Meet_page_door();
	}
	if (Pointer_present_node_page->Type == 2 && Pointer_present_node_page->Meet_page_door_2 != NULL) {
		Pointer_present_node_page->Meet_page_door_2();
	}
	return;
}

void Meet_NPC() {
	if (Pointer_present_node_page->Type == 2 || Pointer_present_node_page->Type == 3) {						//��������������֮ǰд�ɡ�=�����ˣ������޸��˺ܾã�������
		if (Pointer_present_node_page->NPC_1.Meet != NULL) {
			Pointer_present_node_page->NPC_1.Meet();					//�ж��Ƿ�ײ����ǰҳ���1��NPC
		}
		if (Pointer_present_node_page->NPC_2.Meet != NULL) {
			Pointer_present_node_page->NPC_2.Meet();					//�ж��Ƿ�ײ����ǰҳ���1��NPC
		}
		if (Pointer_present_node_page->NPC_3.Meet != NULL) {
			Pointer_present_node_page->NPC_3.Meet();					//�ж��Ƿ�ײ����ǰҳ���1��NPC
		}
	}
	return;
}

void Meet_wall() {
	if ((Pointer_present_node_page->Type == 2 || Pointer_present_node_page->Type == 3) && Pointer_present_node_page->Meet_page_wall != NULL) {
		Pointer_present_node_page->Meet_page_wall();
	}
	return;
}


void Meet_object_mobile() {
	if (Pointer_present_node_page->Type == 3 && Pointer_present_node_page->Object_mobile.Meet != NULL) {
		Pointer_present_node_page->Object_mobile.Meet();
	}
}

void Meet_finish_game() {
	if (Pointer_present_node_page->Type == 3 && Pointer_present_node_page->Meet_finish_game != NULL) {
		Pointer_present_node_page->Meet_finish_game();
	}
}

void Meet_auto_play() {
	if (Pointer_present_node_page->Type == 6) {
		Sleep(300);
		Meet_door_to_next_page();
	}
	if (Pointer_present_node_page->Type == 7) {
		Sleep(20);
		Meet_door_to_next_page();
	}
	return;
}



//--------------------------------------------------------------------------------------------------------------------------
//����������ײ�����ϼ���

void Meet_door_to_next_page() {
	Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Object_controlled_x = Pointer_present_node_page->Object_controlled.Born_x;
	Object_controlled_y = Pointer_present_node_page->Object_controlled.Born_y;
	return;
}

void Meet_door_bilibili_vedio_end() {
	if (Object_controlled_x >= 1000) Meet_door_to_next_page();
	return;
}

void Meet_door_communication_group() {
	if (Object_controlled_y <= 330 && Object_controlled_x <= 380 && Object_controlled_x >= 300) Meet_door_to_next_page();
	return;
}

void Meet_door_right_choice_box() {
	if (Object_controlled_x >= 685 && Object_controlled_y >= 520 && Object_controlled_x <= 810 && Object_controlled_y <= 570) {
		Meet_door_to_next_page();
	}
	return;
}

void Meet_door_wrong_choice_box() {
	if ((Object_controlled_x >= 450 && Object_controlled_y >= 520 && Object_controlled_x <= 570 && Object_controlled_y <= 570) ||
		(Object_controlled_x >= 200 && Object_controlled_y >= 520 && Object_controlled_x <= 320 && Object_controlled_y <= 570) ||
		(Object_controlled_x >= 930 && Object_controlled_y >= 520 && Object_controlled_x <= 1050 && Object_controlled_y <= 570)) {
		Pointer_present_node_page = &(Game_data_under_turing->Head);
		int N_level = 2;
		while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
		Object_controlled_x = Pointer_present_node_page->Object_controlled.Born_x;
		Object_controlled_y = Pointer_present_node_page->Object_controlled.Born_y;
	}
	return;
}

void Meet_door_girls_on_the_snow() {
	if (Object_controlled_y <= 360 && Object_controlled_x <= 800 && Object_controlled_x >= 700) Meet_door_to_next_page();
	return;
}

void Meet_door_corridor() {
	if (Object_controlled_x >= 1260) Meet_door_to_next_page();
	return;
}

void Meet_door_station() {
	if (Object_controlled_x <= 50) Meet_door_to_next_page();
	return;
}

void Meet_door_computer() {
	if (Object_controlled_x >= 460 && Object_controlled_x <= 490 && Object_controlled_y >= 370 && Object_controlled_y <= 405) Meet_door_to_next_page();
	return;
}

void Meet_door_group_introduction_meeting() {
	if (Object_controlled_x >= 870) Meet_door_to_next_page();
	return;
}

void Meet_door_chapter_2_library() {
	if (Object_controlled_y >= 720 && Object_controlled_x <= 685 && Object_controlled_x >= 540) {
		for (int i = 0; i < 13; i++)Pointer_present_node_page = Pointer_present_node_page->Next_page;
		Meet_door_to_next_page();
	}
	return;
}
void Meet_door_2_chapter_2_library() {
	if (Object_controlled_y <= 160) Meet_door_to_next_page();
	return;
}

void Meet_door_chapter_2_game_easter_eggs() {
	if ((Object_controlled_x >= 120 && Object_controlled_x <= 240) && (Object_controlled_y >= 400 && Object_controlled_y <= 480)) {
		Bgm_birthday();
		Meet_door_to_next_page();
	}
	return;
}
void Meet_door_chapter_2_game_easter_eggs_to_library() {
	if (Object_controlled_y >= 720 && Object_controlled_x <= 685 && Object_controlled_x >= 540) {
		mciSendString("close ./resource/Audios/ѧ�����ո�.mp3", 0, 0, 0);
		Meet_door_to_next_page();
	}
	return;
}

void Meet_door_chapter_3_library() {
	if (Object_controlled_y >= 720 && Object_controlled_x <= 685 && Object_controlled_x >= 540) Meet_door_to_next_page();
	return;
}

void Meet_door_chapter_4_cycle_1_40km() {
	if (Object_controlled_y <= 520 && Object_controlled_x <= 120) Meet_door_to_next_page();
	return;
}

void Meet_door_chapter_4_cycle_2_25km() {
	if (Object_controlled_x >= 400 && Object_controlled_x <= 540 && Object_controlled_y <= 480) Meet_door_to_next_page();
	return;
}

void Meet_door_chapter_4_cycle_3_10km() {
	if (Object_controlled_x <= 480) Meet_door_to_next_page();
	return;
}

void Meet_door_chapter_4_cycle_4() {
	if (Object_controlled_x <= 800) Meet_door_to_next_page();
	return;
}

void Meet_door_chapter_4_lobby_conversation() {
	if (Object_controlled_x >= 240) Meet_door_to_next_page();
	return;
}


//--------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------------------------------
//��NPC��ײ�����ϼ���

//����Ե���ƪ��
#if 1
void Meet_NPC_1_brother_east_on_the_snow() {
	if (Object_controlled_x >= 420 && Object_controlled_x <= 560 && Object_controlled_y <= 440) {
		Signal_meet_NPC_1 = 1;
	}
	else {
		Signal_meet_NPC_1 = 0;
		Signal_rectangle_chat_bubble_1_level = 0;
	}
	return;
}
void Meet_NPC_1_girls_on_the_snow() {
	if (Object_controlled_x >= 870 && Object_controlled_x <= 1110) {
		Signal_meet_NPC_1 = 1;
	}
	else {
		Signal_meet_NPC_1 = 0;
		Signal_rectangle_chat_bubble_1_level = 0;
	}
	return;
}

void Meet_NPC_1_corridor() {
	if (Object_controlled_x >= 690 && Object_controlled_x <= 810 && Object_controlled_y <= 500) {
		Signal_meet_NPC_1 = 1;
	}
	else {
		Signal_meet_NPC_1 = 0;
		Signal_rectangle_chat_bubble_1_level = 0;
	}
	return;
}

void Meet_NPC_1_group_meeting() {
	if (Object_controlled_x >= 0 && Object_controlled_x <= 1500) {
		Signal_meet_NPC_1 = 1;
	}
	else {
		Signal_meet_NPC_1 = 0;
		Signal_rectangle_chat_bubble_1_level = 0;
	}
	return;
}

void Meet_NPC_1_station() {
	if (Object_controlled_x >= 850 && Object_controlled_x <= 980) {
		Signal_meet_NPC_1 = 1;
	}
	else {
		Signal_meet_NPC_1 = 0;
		Signal_rectangle_chat_bubble_1_level = 0;
		Signal_phone_chat_bubble_1_level = 0;
	}
	return;
}

void Meet_NPC_2_station() {
	if (Object_controlled_x >= 500 && Object_controlled_x <= 640) {
		Signal_meet_NPC_2 = 1;
	}
	else {
		Signal_meet_NPC_2 = 0;
		Signal_rectangle_chat_bubble_2_level = 0;
		Signal_phone_chat_bubble_2_level = 0;
	}
	return;
}

void Meet_NPC_3_station() {
	if (Object_controlled_x >= 200 && Object_controlled_x <= 300) {
		Signal_meet_NPC_3 = 1;
	}
	else {
		Signal_meet_NPC_3 = 0;
		Signal_rectangle_chat_bubble_3_level = 0;
		Signal_phone_chat_bubble_3_level = 0;
	}
	return;
}
#endif


//����Ʒ����ƪ��
#if 1
void Meet_NPC_1_chapter_2_library() {
	if (Object_controlled_x <= 540 && Object_controlled_y >= 520) {
		Signal_meet_NPC_1 = 1;
	}
	else {
		Signal_meet_NPC_1 = 0;
		Signal_rectangle_chat_bubble_1_level = 0;
	}
}
void Meet_NPC_2_chapter_2_library() {
	if (Object_controlled_y >= 520 && (Object_controlled_x >= 660 && Object_controlled_x <= 820)) {
		Signal_meet_NPC_2 = 1;
	}
	else {
		Signal_meet_NPC_2 = 0;
		Signal_rectangle_chat_bubble_2_level = 0;
	}
}

void Meet_NPC_1_chapter_4_lobby_conversation() {
	if (Object_controlled_x >= 70 && Object_controlled_x <= 120) Signal_meet_NPC_1 = 1;
	else {
		Signal_meet_NPC_1 = 0;
		Signal_rectangle_chat_bubble_1_level = 0;
		Signal_phone_chat_bubble_1_level = 0;
	}
	return;
}

void Meet_NPC_2_chapter_4_lobby_conversation() {
	if (Object_controlled_x >= 150 && Object_controlled_x <= 230) Signal_meet_NPC_2 = 1;
	else {
		Signal_meet_NPC_2 = 0;
		Signal_rectangle_chat_bubble_2_level = 0;
		Signal_phone_chat_bubble_2_level = 0;
	}
	return;
}

void Meet_NPC_1_chapter_3_level_2_game_over() {
	if (Signal_exist_object_mobile_document_icon[5] == 0) {
		Signal_meet_NPC_1 = 1;
		Pointer_present_node_page = Pointer_present_node_page->Next_page;		//ָ��ָ��ǰҳ�������һ��ҳ�����׵�ַ
		Object_controlled_x = Pointer_present_node_page->Object_controlled.Born_x;
		Object_controlled_y = Pointer_present_node_page->Object_controlled.Born_y;
		//Signal_page_level += 1;												//�ϰ汾��������ҳ��ʽ

		printf("Pointer_present_node_page->Type = %d\n", Pointer_present_node_page->Type);
		Sleep(300);														//���ⰴ����ţ�������ҳ
	}
	else {
		Signal_meet_NPC_2 = 0;
		Signal_rectangle_chat_bubble_2_level = 0;
		Signal_phone_chat_bubble_2_level = 0;
	}
	return;
}
void Meet_NPC_1_chapter_3_library_phone() {
	if ((Object_controlled_x >= 525 && Object_controlled_x <= 645) && Object_controlled_y <= 360) {
		Signal_meet_NPC_1 = 1;
	}
	else {
		Signal_meet_NPC_1 = 0;
		Signal_phone_chat_bubble_1_level = 0;
	}
}


#endif
//--------------------------------------------------------------------------------------------------------------------------

//��Χǽ��ײ�����ϼ���

//����Ե���ƪ��
#if 1
void Meet_wall_video_left() {
	if (Object_controlled_x <= 260) Object_controlled_x = 260;
}

void Meet_wall_tree_house_on_the_snow() {
	if (Object_controlled_y <= 360 && (Object_controlled_x <= 300 || Object_controlled_x >= 380)) Object_controlled_y = 360;
	if (Object_controlled_y >= 500) Object_controlled_y = 500;
	return;
}

void Meet_wall_tree_house_girls_on_the_snow() {
	if (Object_controlled_y <= 400 && (Object_controlled_x <= 700 || Object_controlled_x >= 800)) Object_controlled_y = 400;
	if (Object_controlled_y >= 460) Object_controlled_y = 460;
	return;
}

void Meet_wall_corridor() {
	if (Object_controlled_y <= 480) Object_controlled_y = 480;
	if (Object_controlled_y >= 560) Object_controlled_y = 560;
	return;
}

void Meet_wall_station() {
	if (Object_controlled_y < (-0.328) * Object_controlled_x + 520) Object_controlled_y = (-0.328) * Object_controlled_x + 520;
	if (Object_controlled_y > (-0.328) * Object_controlled_x + 623) Object_controlled_y = (-0.328) * Object_controlled_x + 623;
	return;
}

void Meet_wall_computer() {
	if (Object_controlled_y >= 620) Object_controlled_y = 620;
	if (Object_controlled_y <= 305) Object_controlled_y = 305;
	if (Object_controlled_x >= 870) Object_controlled_x = 870;
	if (Object_controlled_x <= 380) Object_controlled_x = 380;
	return;
}

void Meet_wall_group_introduction_left() {
	if (Object_controlled_x <= 400) Object_controlled_x = 400;
	return;
}

#endif

//����Ʒ����ƪ��
#if 1
void Meet_wall_chapter_2_library() {
	if (Object_controlled_x <= 85) Object_controlled_x = 85;
	if (Object_controlled_x >= 1135) Object_controlled_x = 1135;
	if (Object_controlled_y <= 240 && (Object_controlled_x <= 1035 || Object_controlled_x >= 1155))Object_controlled_y = 240;
	if (Object_controlled_y >= 600 && (Object_controlled_x <= 540 || Object_controlled_x >= 725))Object_controlled_y = 600;
	if (Object_controlled_y >= 330 && (Object_controlled_x >= 85 && Object_controlled_x <= 400))Object_controlled_y = 330;
	if (Object_controlled_x <= 421 && Object_controlled_y >= 390)Object_controlled_x = 421;
}
void Meet_wall_big_coin_computer() {
	if (Object_controlled_y >= 660) Object_controlled_y = 660;
	if (Object_controlled_y <= 295) Object_controlled_y = 295;
	if (Object_controlled_x >= 975) Object_controlled_x = 975;
	if (Object_controlled_x <= 280) Object_controlled_x = 280;
	return;
}
void Meet_wall_chapter_2_game_easter_eggs_room() {
	if (Object_controlled_x <= 0)Object_controlled_x = 0;
	if (Object_controlled_y <= 0)Object_controlled_y = 0;
	if (Object_controlled_x >= Window_width - Pointer_present_node_page->Object_controlled.Width)Object_controlled_x = Window_width - Pointer_present_node_page->Object_controlled.Width;
	if (Object_controlled_y >= Window_height - Pointer_present_node_page->Object_controlled.Height)Object_controlled_y = Window_height - Pointer_present_node_page->Object_controlled.Height;
}
#endif


//������ƪ
void Meet_wall_chapter_4_cycle_1_40km() {
	if (Object_controlled_y <= 520 && Object_controlled_x >= 120) Object_controlled_y = 520;
	return;
}

void Meet_wall_chapter_4_cycle_2_25km() {
	if (Object_controlled_y <= 660 - 0.7 * (Object_controlled_x - 140)) Object_controlled_y = 660 - 0.7 * (Object_controlled_x - 140);
	if (Object_controlled_y <= 660 + 0.428 * (Object_controlled_x - 960)) Object_controlled_y = 660 + 0.428 * (Object_controlled_x - 960);
	return;
}

void Meet_wall_chapter_4_cycle_3_10km() {
	if (Object_controlled_y <= 520 - 0.14 * (Object_controlled_x - 1220)) Object_controlled_y = 520 - 0.14 * (Object_controlled_x - 1220);
	return;
}

void Meet_wall_chapter_4_cycle_4() {
	if (Object_controlled_y >= 600) Object_controlled_y = 600;
	if (Object_controlled_y <= 560) Object_controlled_y = 560;
	return;
}

void Meet_wall_chapter_4_lobby_conversation() {
	if (Object_controlled_x <= 40) Object_controlled_x = 40;
	return;
}


//--------------------------------------------------------------------------------------------------------------------------

//����Ϸ�ؿ�����ײ�ƶ����庯���ϼ���

void Meet_object_mobile_big_coin() {
	if (Pointer_present_node_page->Name_number == 333) {
		if (Object_controlled_x >= 400 && Object_controlled_x <= 460 &&
			Object_controlled_y >= Object_mobile_big_coin_y1 && Object_controlled_y <= Object_mobile_big_coin_y1 + 60) {
			if (Signal_exist_object_mobile_big_coin_1 == 1) {
				Signal_scoreboard++;													//��֤��������ҵ�ʱ�򣬼�����+1��֮���ֲ���1��ֻ��1�Σ�
				Signal_exist_object_mobile_big_coin_1 = 0;
			}
		}
		if (Object_controlled_x >= 600 && Object_controlled_x <= 660 &&
			Object_controlled_y >= Object_mobile_big_coin_y2 && Object_controlled_y <= Object_mobile_big_coin_y2 + 60) {
			if (Signal_exist_object_mobile_big_coin_2 == 1) {
				Signal_scoreboard++;
				Signal_exist_object_mobile_big_coin_2 = 0;
			}
		}
		if (Object_controlled_x >= 300 && Object_controlled_x <= 360 &&
			Object_controlled_y >= Object_mobile_big_coin_y3 && Object_controlled_y <= Object_mobile_big_coin_y3 + 60) {
			if (Signal_exist_object_mobile_big_coin_3 == 1) {
				Signal_scoreboard++;
				Signal_exist_object_mobile_big_coin_3 = 0;
			}
		}
	}
	if (Pointer_present_node_page->Name_number == 3000) {
		if (Object_controlled_x >= 400 && Object_controlled_x <= 420 &&
			Object_controlled_y >= Object_mobile_big_coin_y1 && Object_controlled_y <= Object_mobile_big_coin_y1 + 60) {
			if (Signal_exist_object_mobile_big_coin_1 == 1) {
				Signal_scoreboard++;													//��֤��������ҵ�ʱ�򣬼�����+1��֮���ֲ���1��ֻ��1�Σ�
				Signal_exist_object_mobile_big_coin_1 = 0;
			}
		}
		if (Object_controlled_x >= 600 && Object_controlled_x <= 620 &&
			Object_controlled_y >= Object_mobile_big_coin_y2 && Object_controlled_y <= Object_mobile_big_coin_y2 + 60) {
			if (Signal_exist_object_mobile_big_coin_2 == 1) {
				Signal_scoreboard++;
				Signal_exist_object_mobile_big_coin_2 = 0;
			}
		}
		if (Object_controlled_x >= 300 && Object_controlled_x <= 320 &&
			Object_controlled_y >= Object_mobile_big_coin_y3 && Object_controlled_y <= Object_mobile_big_coin_y3 + 60) {
			if (Signal_exist_object_mobile_big_coin_3 == 1) {
				Signal_scoreboard++;
				Signal_exist_object_mobile_big_coin_3 = 0;
			}
		}
	}
	return;
}


void Meet_object_mobile_document_icon() {
	if (Pointer_present_node_page->Name_number == 111) {
		if (Object_controlled_x >= 400 && Object_controlled_x <= 460 &&
			Object_controlled_y >= Object_mobile_document_icon_y1 && Object_controlled_y <= Object_mobile_document_icon_y1 + 60) {
			if (Signal_exist_object_mobile_document_icon_1 == 1) {
				Signal_scoreboard++;													//��֤��������ҵ�ʱ�򣬼�����+1��֮���ֲ���1��ֻ��1�Σ�
				Signal_exist_object_mobile_document_icon_1 = 0;
			}
		}
	}

	if (Pointer_present_node_page->Name_number == 666) {
		for (int i = 0; i < 6; i++) {
			if (Object_controlled_x >= Object_mobile_document_icon_x[i] && Object_controlled_x <= Object_mobile_document_icon_x[i] + 60 &&
				Object_controlled_y >= Object_mobile_document_icon_y[i] && Object_controlled_y <= Object_mobile_document_icon_y[i] + 60) {
				if (Signal_exist_object_mobile_document_icon[i] == 1) {
					Signal_scoreboard++;													//��֤��������ҵ�ʱ�򣬼�����+1��֮���ֲ���1��ֻ��1�Σ�
					Signal_exist_object_mobile_document_icon[i] = 0;
					printf("Signal_scoreboard = %d\n", Signal_scoreboard);
				}
			}
		}
	}


	return;
}

//--------------------------------------------------------------------------------------------------------------------------

//����Ϸ�ؿ������������Ϸ�����ĺ����ϼ���

void Meet_finish_game_get_3_big_coin() {
	if (Signal_scoreboard == 3) Meet_door_to_next_page();
	return;
}

void Meet_finish_game_get_1_document_icon() {
	if (Signal_scoreboard == 1) Meet_door_to_next_page();
	return;
}

void Meet_finish_game_get_6_document_icon() {
	if (Signal_scoreboard == 6) {
		printf("�Ǵ�����������һҳ����\n");
		Meet_door_to_next_page();
	}
	return;
}









































/*
//�ɰ汾������ʽ��Meet_door������
void Meet_door() {
	switch (Signal_page_level) {
	case 3:										//����ǰҳ��Ϊ��3���ʱ��
		if (Object_controlled_x >= 600) {		//��������ײ��3�㴫���ŵ�����ʱ
			Pointer_present_node_page = Pointer_present_node_page->Next_page;		//�������ݽṹ���л�ҳ�淽ʽ
			//Signal_page_level++;				//ҳ�����+1���������ϰ汾�������л�ҳ�淽ʽ
			Object_controlled_x = 0;			//���ɿ�������ĺ����꣬���Ϊ��һ�صĳ����������
			Object_controlled_y = 0;			//���ɿ�������������꣬���Ϊ��һ�صĳ�����������
			Sleep(200);
		}
		break;
	case 4:
		if (Object_controlled_x >= 600) {
			Pointer_present_node_page = Pointer_present_node_page->Next_page;		//�������ݽṹ���л�ҳ�淽ʽ
			//Signal_page_level++;				//ҳ�����+1���������ϰ汾�������л�ҳ�淽ʽ
			Object_controlled_x = 0;			//���ɿ�������ĺ����꣬���Ϊ��һ�صĳ����������
			Object_controlled_y = 0;			//���ɿ�������������꣬���Ϊ��һ�صĳ�����������
			Sleep(200);
		}
		break;
	case 5:
		if (Object_controlled_x >= 600) {
			Pointer_present_node_page = Pointer_present_node_page->Next_page;		//�������ݽṹ���л�ҳ�淽ʽ
			//Signal_page_level++;				//ҳ�����+1���������ϰ汾�������л�ҳ�淽ʽ
			Object_controlled_x = 0;			//���ɿ�������ĺ����꣬���Ϊ��һ�صĳ����������
			Object_controlled_y = 0;			//���ɿ�������������꣬���Ϊ��һ�صĳ�����������
			Sleep(200);
		}
		break;
	}
	return;
}
*/



/*
void Meet_finish_game() {
	switch (Signal_page_level) {
	case 6:
		if (Signal_meet_coin == 3) Signal_page_level++;
		break;
	}
	return;
}
*/


/*
�ɰ汾��NPC��ײ����
void Meet_NPC() {
	if (Page.NPC_1 != NULL) {
		(*Meet_page_NPC_1)();
	}
	//����Ӧ����һ������ָ�룬ִ�в�ͬҳ�治ͬNPC����ײ�ж��������Ͳ���дһ��case�ˣ�ֻ��Ҫдÿһҳ���Ե���ײ������Ȼ���ú���ָ��ִ����ײ�����ͺã�
	switch (Signal_page_level) {
	case 7:
		if (Object_controlled_y >= 800) Signal_meet_NPC_1 = 1;
		else {
			Signal_meet_NPC_1 = 0;
			Signal_rectangle_chat_bubble_level = 0;
		}
		break;
	}
}
*/


/*

//Ӣ����NPC��������������1������������0
void meet_NPC() {
	if (scene_level_signal == 0) {
		if ((hero_y + hero_r >= NPC_y - NPC_r && hero_y - hero_r <= NPC_y + NPC_r) && (hero_x + hero_r >= NPC_x - NPC_r && hero_x - hero_r <= hero_x + NPC_r)) {				//��ײ���
			meet_NPC_signal = 1;
		}
		else {
			meet_NPC_signal = 0;
			chat_signal = 0;
		}
	}
	return;
}


//Ӣ����з���λ��������������1������������0
void meet_Enermy() {
	if (scene_level_signal == 0) {
		if ((hero_y + hero_r >= enermy_y - Enermy_r && hero_y - hero_r <= enermy_y + Enermy_r) && (hero_x + hero_r >= enermy_x - Enermy_r && hero_x - hero_r <= enermy_x + Enermy_r)) {			//��ײ���
			meet_enermy_signal = 1;
		}
	}

	return;
}
*/