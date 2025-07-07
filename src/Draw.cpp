#include "init_globle_variable.h"
extern Node_page* Pointer_present_node_page;
void Draw_page() {
	switch (Pointer_present_node_page->Type) {
	case 1:						//��ǰҳ������Ϊ�������л��͡�
		Bgm_adventure_island_1();
		BeginBatchDraw();					//������ͼ����ͼǰ������
		Draw_page_background();				//������Ӧҳ�汳��
		FlushBatchDraw();					//������ͼ����ͼǰ������
		break;
	case 2:						//��ǰҳ������Ϊ�����������ƶ����������л�ҳ���͡�
		Bgm_adventure_island_1();
		BeginBatchDraw();					//������ͼ����ͼǰ������
		Draw_page_background();				//������Ӧҳ��ı���
		Draw_object_controlled();			//�����ɿ����ƶ�������
		Draw_rectangle_chat_bubble();		//����������������
		Draw_phone_chat_bubble();			//�����ֻ��������
		//Draw_NPC();						//����NPC�����������ǣ�NPC����������ֱ�Ӹ�����ԭͼ�ϵģ�������Ҫ����ػ�����
		FlushBatchDraw();		//������ͼ����ͼǰ������
		break;
	case 3:
		Bgm_adventure_island_2();
		BeginBatchDraw();
		Draw_page_background();
		Draw_object_controlled();
		Draw_object_mobile();
		Draw_scoreboard();
		Draw_rectangle_chat_bubble();		//����������������
		FlushBatchDraw();
		break;
	case 4:
		BeginBatchDraw();
		huiji();
		Meet_door_to_next_page();
		//��������ͼ
		//����ͣ��
		//��Ѫ��
		//���ƶ������
		//���ƶ��ĵ���
		//����ҵ��ӵ�
		//�����˵��ӵ�
		//�������ţ��������ȫ���������˵Ļ���
		FlushBatchDraw();
		break;
	case 5:
		Bgm_adventure_island_2();
		BeginBatchDraw();
		Draw_page_background();			//����BOSS�ؿ���ͼ
		Draw_player();					//��������
		Draw_object_mobile();			//����BOSS
		Draw_blood();					//����Ѫ��
		Draw_bullet();					//���ӵ�
		Draw_door_to_essay();			//��ͨ��С���ĵĴ�����
		FlushBatchDraw();
		break;
	case 6:
	case 7:
		BeginBatchDraw();				//������ͼ����ͼǰ������
		Draw_page_background();			//������Ӧҳ�汳��
		FlushBatchDraw();				//������ͼ����ͼǰ������
		break;
	case 9:
		Bgm_birthday();
		BeginBatchDraw();					//������ͼ����ͼǰ������
		Draw_page_background();				//������Ӧҳ�汳��
		FlushBatchDraw();					//������ͼ����ͼǰ������
		break;
	case 8:
		BeginBatchDraw();								//������ͼ����ͼǰ������
		Draw_page_background();							//������Ӧҳ�汳��
		IMAGE end_credit;
		Bgm_end_credit();
		loadimage(&end_credit, _T("./res/Images/end/end.png"));
		putimage(0, End_credit_y, &end_credit);
		End_credit_y -= 3;
		//Sleep(5000);
		//Init_game_date_end_credit();
		FlushBatchDraw();				//������ͼ����ͼǰ������
		break;

	}
	return;
}


void Draw_page_background() {
	IMAGE img;
	loadimage(&img, Pointer_present_node_page->Image_address_background, Window_width, Window_height);
	putimage(0, 0, &img);
	//printf("ִ�л�ͼ���%d\n", Pointer_present_node_page->Image_address_background);
	if (Pointer_present_node_page->Type == 5 && Signal_exist_boss == 1) {
		switch (Gif_n % 12) {
		case 4:
			putimage(-8, 0, &img);
			break;
		case 5:
			putimage(8, 0, &img);
			break;
		case 6:
			putimage(5, -5, &img);
			break;
		case 7:
			putimage(5, 5, &img);
			break;
		case 8:
			putimage(-3, 3, &img);
			break;
		case 9:
			putimage(3, 3, &img);
			break;
		case 10:
			putimage(0, 0, &img);
			break;
		}
	}
	return;
}



void Draw_object_controlled() {
	if (Pointer_present_node_page->Object_controlled.Image_address != NULL) {
		IMAGE img;
		loadimage(&img, Pointer_present_node_page->Object_controlled.Image_address, Pointer_present_node_page->Object_controlled.Width, Pointer_present_node_page->Object_controlled.Height);
		putimage(Object_controlled_x, Object_controlled_y, &img);
	}
	if (Pointer_present_node_page->Object_controlled.Image_address_SRCAND != NULL && Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT != NULL) {
		IMAGE img1, img2;
		loadimage(&img1, Pointer_present_node_page->Object_controlled.Image_address_SRCAND, Pointer_present_node_page->Object_controlled.Width, Pointer_present_node_page->Object_controlled.Height);
		loadimage(&img2, Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT, Pointer_present_node_page->Object_controlled.Width, Pointer_present_node_page->Object_controlled.Height);
		putimage(Object_controlled_x, Object_controlled_y, &img1, SRCAND);
		putimage(Object_controlled_x, Object_controlled_y, &img2, SRCPAINT);
	}
	//����Ҫ��һ������ָ�룬ִ�в�ͬҳ���Χǽ�����ж��������Ͳ���дһ��case�ˣ�ֻ��Ҫдÿһҳ���Ե���ײ������Ȼ���ú���ָ��ִ����ײ�����ͺã�
	return;
}

void Draw_rectangle_chat_bubble() {
	if (Signal_meet_NPC_1 == 1 && Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[0] != NULL) {			//��ǰ��ͼ�£��������1��NPC�����ӡ1��NPC��Ӧ����������
		IMAGE img;
		loadimage(&img, Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble[Signal_rectangle_chat_bubble_1_level], 805, 210);
		putimage(238, 48, &img);
	}
	if (Signal_meet_NPC_2 == 1 && Pointer_present_node_page->NPC_2.Image_address_rectangle_chat_bubble[0] != NULL) {			//��ǰ��ͼ�£��������2��NPC�����ӡ2��NPC��Ӧ����������
		IMAGE img;
		loadimage(&img, Pointer_present_node_page->NPC_2.Image_address_rectangle_chat_bubble[Signal_rectangle_chat_bubble_2_level], 805, 210);
		putimage(238, 48, &img);
	}
	if (Signal_meet_NPC_3 == 1 && Pointer_present_node_page->NPC_3.Image_address_rectangle_chat_bubble[0] != NULL) {			//��ǰ��ͼ�£��������3��NPC�����ӡ3��NPC��Ӧ����������
		IMAGE img;
		loadimage(&img, Pointer_present_node_page->NPC_3.Image_address_rectangle_chat_bubble[Signal_rectangle_chat_bubble_3_level], 805, 210);
		putimage(238, 48, &img);
	}
	return;
}


void Draw_phone_chat_bubble() {
	if (Signal_meet_NPC_1 == 1 && Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[0] != NULL) {			//��ǰ��ͼ�£��������1��NPC�����ӡ1��NPC��Ӧ����������
		IMAGE img1, img2;
		loadimage(&img1, Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble_SRCAND, 400, 680);
		loadimage(&img2, Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble[Signal_phone_chat_bubble_1_level], 400, 680);
		putimage(440, 20, &img1, SRCAND);
		putimage(440, 20, &img2, SRCPAINT);
	}
	if (Signal_meet_NPC_2 == 1 && Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[0] != NULL) {			//��ǰ��ͼ�£��������1��NPC�����ӡ1��NPC��Ӧ����������
		IMAGE img1, img2;
		loadimage(&img1, Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble_SRCAND, 400, 680);
		loadimage(&img2, Pointer_present_node_page->NPC_2.Image_address_phone_chat_bubble[Signal_phone_chat_bubble_2_level], 400, 680);
		putimage(440, 20, &img1, SRCAND);
		putimage(440, 20, &img2, SRCPAINT);
	}
	if (Signal_meet_NPC_3 == 1 && Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[0] != NULL) {			//��ǰ��ͼ�£��������1��NPC�����ӡ1��NPC��Ӧ����������
		IMAGE img1, img2;
		loadimage(&img1, Pointer_present_node_page->NPC_1.Image_address_phone_chat_bubble_SRCAND, 400, 680);
		loadimage(&img2, Pointer_present_node_page->NPC_3.Image_address_phone_chat_bubble[Signal_phone_chat_bubble_3_level], 400, 680);
		putimage(440, 20, &img1, SRCAND);
		putimage(440, 20, &img2, SRCPAINT);
	}
	return;
}

void Draw_object_mobile() {
	if (Pointer_present_node_page->Name_number == 333) {
		if (Signal_exist_object_mobile_big_coin_1 == 1) {
			IMAGE img1, img2;
			loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 60, 60);
			loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT, 60, 60);
			if (Object_mobile_big_coin_y1 > 370) {
				putimage(400, Object_mobile_big_coin_y1, &img1, SRCAND);
				putimage(400, Object_mobile_big_coin_y1, &img2, SRCPAINT);
			}
			Object_mobile_big_coin_y1 += Pointer_present_node_page->Object_mobile.Object_mobile_speed_y;
			if (Object_mobile_big_coin_y1 > 540) Object_mobile_big_coin_y1 = 540;
		}
		if (Signal_exist_object_mobile_big_coin_2 == 1) {
			IMAGE img1, img2;
			loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 60, 60);
			loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT, 60, 60);
			if (Object_mobile_big_coin_y2 > 370) {
				putimage(600, Object_mobile_big_coin_y2, &img1, SRCAND);
				putimage(600, Object_mobile_big_coin_y2, &img2, SRCPAINT);
			}
			Object_mobile_big_coin_y2 += Pointer_present_node_page->Object_mobile.Object_mobile_speed_y;
			if (Object_mobile_big_coin_y2 > 540) Object_mobile_big_coin_y2 = 540;
		}
		if (Signal_exist_object_mobile_big_coin_3 == 1) {
			IMAGE img1, img2;
			loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 60, 60);
			loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT, 60, 60);
			if (Object_mobile_big_coin_y3 > 370) {
				putimage(300, Object_mobile_big_coin_y3, &img1, SRCAND);
				putimage(300, Object_mobile_big_coin_y3, &img2, SRCPAINT);
			}
			Object_mobile_big_coin_y3 += Pointer_present_node_page->Object_mobile.Object_mobile_speed_y;
			if (Object_mobile_big_coin_y3 > 540) Object_mobile_big_coin_y3 = 540;
		}
	}


	if (Pointer_present_node_page->Name_number == 3000) {
		if (Signal_exist_object_mobile_big_coin_1 == 1) {
			IMAGE img1, img2;
			loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 20, 20);
			loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT, 20, 20);
			if (Object_mobile_big_coin_y1 > 360 && Object_mobile_big_coin_y1 < 400) {
				putimage(400, Object_mobile_big_coin_y1, &img1, SRCAND);
				putimage(400, Object_mobile_big_coin_y1, &img2, SRCPAINT);
			}
			Object_mobile_big_coin_y1 += Pointer_present_node_page->Object_mobile.Object_mobile_speed_y;
			if (Object_mobile_big_coin_y1 >= 400) Signal_exist_object_mobile_big_coin_1 = 0;
		}
		if (Signal_exist_object_mobile_big_coin_2 == 1) {
			IMAGE img1, img2;
			loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 20, 20);
			loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT, 20, 20);
			if (Object_mobile_big_coin_y2 > 360 && Object_mobile_big_coin_y2 < 400) {
				putimage(600, Object_mobile_big_coin_y2, &img1, SRCAND);
				putimage(600, Object_mobile_big_coin_y2, &img2, SRCPAINT);
			}
			Object_mobile_big_coin_y2 += Pointer_present_node_page->Object_mobile.Object_mobile_speed_y;
			if (Object_mobile_big_coin_y2 > 420) Signal_exist_object_mobile_big_coin_2 = 0;
		}
		if (Signal_exist_object_mobile_big_coin_3 == 1) {
			IMAGE img1, img2;
			loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 20, 20);
			loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT, 20, 20);
			if (Object_mobile_big_coin_y3 > 360 && Object_mobile_big_coin_y3 < 400) {
				putimage(300, Object_mobile_big_coin_y3, &img1, SRCAND);
				putimage(300, Object_mobile_big_coin_y3, &img2, SRCPAINT);
			}
			Object_mobile_big_coin_y3 += Pointer_present_node_page->Object_mobile.Object_mobile_speed_y;
			if (Object_mobile_big_coin_y3 > 420) {
				Signal_exist_object_mobile_big_coin_3 = 0;
				Meet_door_to_next_page();
			}
		}
	}

	if (Pointer_present_node_page->Name_number == 111) {
		if (Signal_exist_object_mobile_document_icon_1 == 1) {
			IMAGE img1, img2;
			loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 60, 60);
			loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT, 60, 60);
			if (Object_mobile_document_icon_y1 > 360) {
				putimage(400, Object_mobile_document_icon_y1, &img1, SRCAND);
				putimage(400, Object_mobile_document_icon_y1, &img2, SRCPAINT);
			}
			Object_mobile_document_icon_y1 += Pointer_present_node_page->Object_mobile.Object_mobile_speed_y;
			if (Object_mobile_document_icon_y1 > 537) Object_mobile_document_icon_y1 = 537;
		}
	}
	if (Pointer_present_node_page->Name_number == 666) {
		for (int i = 0; i < 6; i++) {
			if (Signal_exist_object_mobile_document_icon[i] == 1) {
				IMAGE img1, img2;
				loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 60, 60);
				loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT, 60, 60);
				if (Object_mobile_document_icon_y[i] > 360) {
					putimage(Object_mobile_document_icon_x[i], Object_mobile_document_icon_y[i], &img1, SRCAND);
					putimage(Object_mobile_document_icon_x[i], Object_mobile_document_icon_y[i], &img2, SRCPAINT);
				}
				Object_mobile_document_icon_y[i] += Pointer_present_node_page->Object_mobile.Object_mobile_speed_y;
				if (Object_mobile_document_icon_y[i] > 580) {
					Signal_exist_object_mobile_document_icon[i] = 0;
				}
			}
		}
	}

	if (Pointer_present_node_page->Name_number == 888) {
		if (Signal_exist_boss == 1) {
			IMAGE img1, img2;
			loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND);
			loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT);
			putimage(BOSS_x, BOSS_y, 300, 300, &img1, (Gif_n % 12) * 300, 0, SRCAND);
			putimage(BOSS_x, BOSS_y, 300, 300, &img2, (Gif_n % 12) * 300, 300, SRCPAINT);

			//�������ʱ����Զ��ƶ���
			if (BOSS_x >= 900) {
				switch (Gif_n % 12) {
				case 0:
					BOSS_y -= 40;
					BOSS_x -= 12;
					break;
				case 1:
					BOSS_y -= 10;
					BOSS_x -= 12;
					break;
				case 2:
					BOSS_x -= 12;
					break;
				case 3:
					BOSS_y += 10;
					BOSS_x -= 12;
					break;
				case 4:
					BOSS_y += 40;
					BOSS_x -= 12;
					break;
				}
			}

			//���﹥�����ʱ����Զ��ƶ���
			if (BOSS_x <= 900) {
				switch (Gif_n % 24) {
				case 4:
					BOSS_y -= 300;
					break;
				case 5:
					BOSS_y -= 300;
					break;
				case 6:
					break;
				case 7:
					BOSS_x = Player_x - 90;
					BOSS_y = Player_y - 1000;
					break;
				case 8:
					break;
				case 9:
					break;
				case 10:
					break;
				case 11:
					break;
				case 12:
					break;
				case 13:
					BOSS_y += 520;
					break;
				case 14:
					BOSS_y += 300;
					//��ұ�����
					if (Player_x <= BOSS_x + 90 && BOSS_x - Player_x <= 120 && (Player_y - BOSS_y <= 230 && Player_y - BOSS_y >= 130)) {
						Player_x -= 240;
						Player_blood_number -= 3;
						Player_blood_rectangle += 3;
					}
					if (Player_x > BOSS_x + 90 && Player_x - BOSS_x <= 300 && (Player_y - BOSS_y <= 230 && Player_y - BOSS_y >= 130)) {
						Player_x += 240;
						Player_blood_number -= 3;
						Player_blood_rectangle += 3;
					}
					if (BOSS_x - Player_x <= 120 && Player_x - BOSS_x <= 300 && (Player_y - BOSS_y >= 180 && Player_y - BOSS_y <= 230)) Player_y += 120;
					if (BOSS_x - Player_x <= 120 && Player_x - BOSS_x <= 300 && (Player_y - BOSS_y <= 180 && Player_y - BOSS_y >= 130)) Player_y -= 120;
					if (Player_blood_number <= 0) {					//���Ѫ������0�����������¿�ʼ��Ϸ�ˣ���ֱ�Ӵ���ѧ���ף������ʼ�������տ��ֵ�����
						Player_blood_number = 1;
						Player_blood_rectangle = 8;
						mciSendString("play ./res/Audios/ѧ�����ո�.mp3 repeat", NULL, NULL, NULL);
					}
					break;
				}
			}
		}
	}
	return;
}

void Draw_scoreboard() {
	if (Pointer_present_node_page->Name_number == 333 && Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT != NULL) {
		IMAGE img1, img2;
		loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 60, 60);
		loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT, 60, 60);
		putimage(915, 480, &img1, SRCAND);
		putimage(915, 480, &img2, SRCPAINT);
		TCHAR s[20];
		_stprintf(s, _T("%d / 3"), Signal_scoreboard);
		setbkmode(TRANSPARENT);
		//settextstyle(20, 0, _T("Consolas"));
		LOGFONT f;
		gettextstyle(&f);							// ��ȡ��ǰ��������
		f.lfHeight = 20;							// ��������߶�Ϊ 48
		f.lfWeight = 1000;							// ���������ϸ�̶�Ϊ 5
		_tcscpy(f.lfFaceName, _T("Consolas"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
		f.lfQuality = ANTIALIASED_QUALITY;			// �������Ч��Ϊ�����  
		settextstyle(&f);							// ����������ʽ
		outtextxy(925, 540, s);
	}
	if (Pointer_present_node_page->Name_number == 3000 && Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT != NULL) {
		IMAGE img1, img2;
		loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 60, 60);
		loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT, 60, 60);
		putimage(915, 480, &img1, SRCAND);
		putimage(915, 480, &img2, SRCPAINT);
		TCHAR s[20];
		_stprintf(s, _T("0 / %d"), 3);
		setbkmode(TRANSPARENT);
		//settextstyle(20, 0, _T("Consolas"));
		LOGFONT f;
		gettextstyle(&f);							// ��ȡ��ǰ��������
		f.lfHeight = 20;							// ��������߶�Ϊ 48
		f.lfWeight = 1000;								// ���������ϸ�̶�Ϊ 5
		_tcscpy(f.lfFaceName, _T("Consolas"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
		f.lfQuality = ANTIALIASED_QUALITY;			// �������Ч��Ϊ�����  
		settextstyle(&f);							// ����������ʽ
		outtextxy(925, 540, s);
	}

	if (Pointer_present_node_page->Name_number == 111 && Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT != NULL) {
		IMAGE img1, img2;
		loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 60, 60);
		loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT, 60, 60);
		putimage(915, 480, &img1, SRCAND);
		putimage(915, 480, &img2, SRCPAINT);
		TCHAR s[20];
		_stprintf(s, _T("%d / 1"), Signal_scoreboard);
		setbkmode(TRANSPARENT);
		//settextstyle(20, 0, _T("Consolas"));
		LOGFONT f;
		gettextstyle(&f);							// ��ȡ��ǰ��������
		f.lfHeight = 20;							// ��������߶�Ϊ 48
		f.lfWeight = 1000;								// ���������ϸ�̶�Ϊ 5
		_tcscpy(f.lfFaceName, _T("Consolas"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
		f.lfQuality = ANTIALIASED_QUALITY;			// �������Ч��Ϊ�����  
		settextstyle(&f);							// ����������ʽ
		outtextxy(925, 540, s);
	}

	if (Pointer_present_node_page->Name_number == 666 && Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT != NULL) {
		IMAGE img1, img2;
		loadimage(&img1, Pointer_present_node_page->Object_mobile.Image_address_SRCAND, 60, 60);
		loadimage(&img2, Pointer_present_node_page->Object_mobile.Image_address_scoreboard_SRCPAINT, 60, 60);
		putimage(915, 480, &img1, SRCAND);
		putimage(915, 480, &img2, SRCPAINT);
		TCHAR s[20];
		_stprintf(s, _T("%d / 6"), Signal_scoreboard);
		setbkmode(TRANSPARENT);
		//settextstyle(20, 0, _T("Consolas"));
		LOGFONT f;
		gettextstyle(&f);							// ��ȡ��ǰ��������
		f.lfHeight = 20;							// ��������߶�Ϊ 48
		f.lfWeight = 1000;								// ���������ϸ�̶�Ϊ 5
		_tcscpy(f.lfFaceName, _T("Consolas"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
		f.lfQuality = ANTIALIASED_QUALITY;			// �������Ч��Ϊ�����  
		settextstyle(&f);							// ����������ʽ
		outtextxy(925, 540, s);
	}
	return;
}


void Draw_player() {
	switch (Player_direction)
	{
	case 1:
		loadimage(&img_player_left, _T("./res/Images/tupian/�˽���.png"));
		loadimage(&img_player_left, _T("./res/Images/tupian/�˽���.png"));
		putimage(Player_x, Player_y, PEOPLE_WIDTH, PEOPLE_HEIGHT, &img_player_left, (Gif_n % 8) * PEOPLE_WIDTH, 0, SRCAND);
		putimage(Player_x, Player_y, PEOPLE_WIDTH, PEOPLE_HEIGHT, &img_player_left, (Gif_n % 8) * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
		break;
	case 0:
		loadimage(&img_player_right, _T("./res/Images/tupian/�˽���.png"));
		loadimage(&img_player_right, _T("./res/Images/tupian/�˽���.png"));
		putimage(Player_x, Player_y, PEOPLE_WIDTH, PEOPLE_HEIGHT, &img_player_right, (Gif_n % 8) * PEOPLE_WIDTH, 0, SRCAND);
		putimage(Player_x, Player_y, PEOPLE_WIDTH, PEOPLE_HEIGHT, &img_player_right, (Gif_n % 8) * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
		break;
	}
	return;
}


//����Ѫ������
void Draw_blood() {
	//���������������
	settextcolor(WHITE);
	settextstyle(20, 0, "����");
	outtextxy(0, 0, "������");
	//�������Ѫ���߿�
	setlinecolor(BLACK);
	roundrect(55, 0, 208, 20, 10, 10);
	//�������Ѫ�����
	setfillcolor(RED);
	solidroundrect(55, 0, 208 - 17 * Player_blood_rectangle, 20, 10, 10);
	char ch[10][5] = { "0/9","1/9", "2/9", "3/9", "4/9", "5/9", "6/9", "7/9", "8/9", "9/9" };
	outtextxy(110, 0, ch[Player_blood_number]);
	TCHAR s[20];
	_stprintf(s, _T("%d / 30"), BOSS_blood_number);
	if (Signal_exist_boss == 1) {
		//���ƹ���Ѫ���߿�
		setlinecolor(BLACK);
		//roundrect(gw[i].x1, gw[i].y1 - 20, gw[i].x1 + 90, gw[i].y1, 10, 10);
		roundrect(BOSS_x, BOSS_y - 20, BOSS_x + 90, BOSS_y, 10, 10);
		//���ƹ���Ѫ�����
		setfillcolor(RED);
		//solidroundrect(gw[i].x1, gw[i].y1 - 20, gw[i].x1 + 90 - 10 * gw[i].xl, gw[i].y1, 10, 10);
		solidroundrect(BOSS_x, BOSS_y - 20, BOSS_x + 300 - 10 * BOSS_blood_rectangle, BOSS_y, 10, 10);
		outtextxy(BOSS_x + 120, BOSS_y - 20, s);
	}
	return;
}


void Draw_bullet() {
	Draw_each_bullet();
	Create_bullet();
	Hit_BOSS_bullet();
	Move_bullet();
	return;
}

void Create_bullet() {
	while (peekmessage(&Player_action, EX_MOUSE)) {
		switch (Player_action.message)
		{
		case WM_LBUTTONDOWN:
			for (int i = 0; i < Bullet_amount; i++) {
				if (!Player_bullet[i].live && (Player_action.x < 860 || Player_action.y > 85))
				{
					Player_bullet[i].current_x = Player_x;
					Player_bullet[i].current_y = Player_y;
					Player_bullet[i].destination_x = Player_action.x;
					Player_bullet[i].destination_y = Player_action.y;
					Player_bullet[i].birth_x = Player_x;
					Player_bullet[i].birth_y = Player_y;
					Player_bullet[i].live = true;
					//mciSendString("play tupian//�ӵ�����.mp3", NULL, NULL, NULL);
					break;
				}
			}
			break;
		}
	}
	return;
}

void Draw_each_bullet() {
	for (int i = 0; i < Bullet_amount; i++) {
		if (Player_bullet[i].live) {
			IMAGE img1, img2;
			loadimage(&img1, _T("./res/Images/object_mobile/big_coin_1.png"), 60, 60);
			loadimage(&img2, _T("./res/Images/object_mobile/big_coin_2.png"), 60, 60);
			putimage(Player_bullet[i].current_x, Player_bullet[i].current_y, &img1, SRCAND);
			putimage(Player_bullet[i].current_x, Player_bullet[i].current_y, &img2, SRCPAINT);
		}
	}
	return;
}

/*
for (int i = 0; i < zidan_slwj; i++)
{
	if (wjzd[i].live)
	{
		putimage(wjzd[i].x1, wjzd[i].y1, &jszd11, SRCAND);
		putimage(wjzd[i].x1, wjzd[i].y1, &jszd1, SRCPAINT);
		//��飬ÿһ�δ�ӡ�ӵ���ʱ���ӵ�������ı��Ƿ��ǶԵ�
		//printf("�ӵ�����(%d, %d)\n", wjzd[i].x1, wjzd[i].y1);
		//printf("�ӵ��ٶ� = %d\n", wjzdsd);
		//printf("�ӵ��������ƶ��ٶ� = %f\n", wjzdsd * ((wjzd[i].x2 - wjzd[i].x3) / sqrt((wjzd[i].x2 - wjzd[i].x3) * (wjzd[i].x2 - wjzd[i].x3) + (wjzd[i].y2 - wjzd[i].y3) * (wjzd[i].y2 - wjzd[i].y3))));
		//printf("�ӵ��������ƶ��ٶ� = %f\n", wjzdsd * ((wjzd[i].y2 - wjzd[i].y3) / sqrt((wjzd[i].x2 - wjzd[i].x3) * (wjzd[i].x2 - wjzd[i].x3) + (wjzd[i].y2 - wjzd[i].y3) * (wjzd[i].y2 - wjzd[i].y3))));
	}
}
*/

void Move_bullet() {
	for (int i = 0; i < Bullet_amount; i++) {
		if (Player_bullet[i].live) {
			Player_bullet[i].current_x += Speed_bullet * ((Player_bullet[i].destination_x - Player_bullet[i].birth_x) / sqrt((Player_bullet[i].destination_x - Player_bullet[i].birth_x) * (Player_bullet[i].destination_x - Player_bullet[i].birth_x) + (Player_bullet[i].destination_y - Player_bullet[i].birth_y) * (Player_bullet[i].destination_y - Player_bullet[i].birth_y)));
			Player_bullet[i].current_y += Speed_bullet * ((Player_bullet[i].destination_y - Player_bullet[i].birth_y) / sqrt((Player_bullet[i].destination_x - Player_bullet[i].birth_x) * (Player_bullet[i].destination_x - Player_bullet[i].birth_x) + (Player_bullet[i].destination_y - Player_bullet[i].birth_y) * (Player_bullet[i].destination_y - Player_bullet[i].birth_y)));
		}
		if (Player_bullet[i].current_x <= -200 || Player_bullet[i].current_x >= 1500 || Player_bullet[i].current_y <= -200 || Player_bullet[i].current_y >= 1500)
		{
			Player_bullet[i].live = false;
		}
	}
	return;
}

/*
//���õ��ӵ��ƶ�����
void gyzdydhs(struct zdjg* pzd, int zdsl, int zdsd)
{
	//�����ӵ�ÿһ�ֱ仯�Ժ������
	for (int i = 0; i < zdsl; ++i)
	{
		if (pzd[i].live)
		{
			wjzdpz(pzd, zdsl, i);
			gwzdpz(pzd, zdsl, i);
			pzd[i].x1 += zdsd * ((pzd[i].x2 - pzd[i].x3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3)));
			pzd[i].y1 += zdsd * ((pzd[i].y2 - pzd[i].y3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3)));
			//printf("�ӵ�����(%d, %d)\n", pzd[i].x1, pzd[i].y1);
			//printf("�ӵ��ٶ� = %d\n", zdsd);
			//printf("�ӵ��������ƶ��ٶ� = %f\n", zdsd * ((pzd[i].x2 - pzd[i].x3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3))));
			//printf("�ӵ��������ƶ��ٶ� = %f\n", zdsd * ((pzd[i].y2 - pzd[i].y3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3))));
			if (pzd[i].x1 <= -200 || pzd[i].x1 >= 1500 || pzd[i].y1 <= -200 || pzd[i].y1 >= 1500)
			{
				pzd[i].live = false;
			}
		}
	}
	return;
}
*/


void Hit_BOSS_bullet() {
	for (int i = 0; i < Bullet_amount; i++) {
		if (Player_bullet[i].live == true && (BOSS_x <= 860 && Gif_n % 12 >= 13 || Gif_n % 12 <= 4) &&
			Player_bullet[i].current_x >= BOSS_x && Player_bullet[i].current_x <= BOSS_x + 300 &&
			Player_bullet[i].current_y >= BOSS_y && Player_bullet[i].current_y <= BOSS_y + 300) {								//����ӵ�����ײ������
			Player_bullet->live = false;
			BOSS_blood_number--;
			BOSS_blood_rectangle++;
		}
	}
	if (BOSS_blood_number <= 0) Signal_exist_boss = 0;
	return;
}

void Draw_door_to_essay() {
	if (Signal_exist_boss == 0) {
		IMAGE door1, door2;
		loadimage(&door1, "./res/Images/tupian/transfer_gate.png");
		loadimage(&door2, "./res/Images/tupian/transfer_gate.png");
		putimage(100, 580, PEOPLE_WIDTH, PEOPLE_HEIGHT, &door1, (Gif_n % 8) * PEOPLE_WIDTH, 0, SRCAND);
		putimage(100, 580, PEOPLE_WIDTH, PEOPLE_HEIGHT, &door2, (Gif_n % 8) * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
		if (Player_x <= 300 && Player_y >= 600) Meet_door_to_next_page();
	}
}




/*
//����ӵ���ײ����
void wjzdpz(struct zdjg* pzd, int zdsl, int i)
{
	for (int j = 0; j < gwsl; ++j)
	{
		if (!gw[j].live && zdsl == zidan_slwj && pzd[i].x1 > gw[j].x1 && pzd[i].x1 < gw[j].x1 + 80 &&
			pzd[i].y1 > gw[j].y1 && pzd[i].y1 < gw[j].y1 + 110)
		{
			if (0 == gw[j].sm)
			{
				--gwch;
				gw[j].live = true;
				mciSendString("play tupian//��������.mp3", NULL, NULL, NULL);
				if (0 == gwch)																//����������Ϊ0��ʱ�򣬼����������й���
				{
					dtqh = 2;
				}
			}
			else if (++gw[j].xl && 0 != --gw[j].sm)
			{
				pzd[i].live = false;
			}
		}
	}

	return;
}

*/






/*
if (Signal_meet_NPC_2 == 1) {			//��ǰ��ͼ�£��������2��NPC�����ӡ2��NPC��Ӧ����������
	IMAGE img;
	putimage(50, 50, &Pointer_present_node_page->NPC_2.Rectangle_chat_bubble[Signal_rectangle_chat_bubble_level]);

	//bug�����ֳ���
	//putimage(50, 50, &Pointer_present_node_page->NPC_2.Rectangle_chat_bubble[Signal_rectangle_chat_bubble_level]);

}
if (Signal_meet_NPC_3 == 1) {			//��ǰ��ͼ�£��������3��NPC�����ӡ2��NPC��Ӧ����������
	IMAGE img;
	putimage(50, 50, &Pointer_present_node_page->NPC_3.Rectangle_chat_bubble[Signal_rectangle_chat_bubble_level]);

	//bug�����ֳ���
	//putimage(50, 50, &Pointer_present_node_page->NPC_2.Rectangle_chat_bubble[Signal_rectangle_chat_bubble_level]);

*/
/*
//�����Ǿɰ汾������ʽ�Ĵ�ӡ��������
void Draw_rectangle_chat_bubble() {
	switch (Signal_page_level) {
	case 7:
		//��ʼ�������������ݵĵ�ַ����
		LPCTSTR Image_address_rectangle_chat_bubble[10] = { _T("./Rectangle_chat_bubble/Chapter_1/1.png"), _T("./Rectangle_chat_bubble/Chapter_1/2.png"), _T("./Rectangle_chat_bubble/Chapter_1/3.png"),
														_T("./Rectangle_chat_bubble/Chapter_1/4.png")
		};
		if (Signal_meet_NPC_1 == 1) {
			IMAGE img;
			loadimage(&img, Image_address_rectangle_chat_bubble[Signal_rectangle_chat_bubble_level], 200, 100);
			putimage(50, 50, &img);
		}

		break;
	}
	return;
}
*/

/*
//���庯�����з���λ�ƶ�
void Move_object_mobile_() {

	Enermy_meet_wall();
	enermy_x += enermy_speed_x;
	enermy_y += enermy_speed_y;
	return;
}

//�з���λײǽ��Ե�����ٶȵ���
void Enermy_meet_wall() {

	if (enermy_x - Enermy_r <= 0) enermy_speed_x = -1 * enermy_speed_x;
	if (enermy_x + Enermy_r >= Window_width) enermy_speed_x = -1 * enermy_speed_x;

	if (enermy_y - Enermy_r <= 0) enermy_speed_y = -1 * enermy_speed_y;
	if (enermy_y + Enermy_r >= Window_height) enermy_speed_y = -1 * enermy_speed_y;

	return;
}
*/

/*

*/