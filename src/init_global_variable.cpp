#include "init_globle_variable.h"
int Window_width = 1280;
int Window_height = 720;

//����ʽ���ݽṹ��ȫ�ֱ�����ʼ����ʽ

List_page* Game_data_under_turing = Get_list_page();
extern Node_page* Pointer_present_node_page = &(Game_data_under_turing->Head);
Node_page* Pointer_indicator_new_page = Pointer_present_node_page;


int Signal_page_level = 1;						//��¼��ǰҳ�������������ڵڼ������в�ͬ�ĵ�ͼ����������������ԼΪ70�����ң�
int Signal_meet_NPC_1 = 0;						//��¼��ɫ��ǰ�Ƿ���ײ����ǰ��ͼ��1��NPC����ײ��Ϊ1��û����Ϊ0��
int Signal_meet_NPC_2 = 0;						//��¼��ɫ��ǰ�Ƿ���ײ����ǰ��ͼ��2��NPC����ײ��Ϊ1��û����Ϊ0��
int Signal_meet_NPC_3 = 0;						//��¼��ɫ��ǰ�Ƿ���ײ����ǰ��ͼ��3��NPC����ײ��Ϊ1��û����Ϊ0��
int Signal_meet_door = 0;						//��¼��ɫ��ǰ�Ƿ���ײ�������ţ���ײ��Ϊ1��û����Ϊ0��
int Signal_meet_coin = 0;						//��¼��ɫ��ǰ�Ƿ�������Ϸ�ڵĽ�ң���ײ������1����û����Ϊ0��
int Signal_meet_document_icon = 0;				//��¼��ɫ��ǰ�Ƿ�������Ϸ�ڵ��ĵ�ͼ�꣬��ײ������1����û����Ϊ0��
int Signal_meet_choice_box = 0;							//��¼��ɫ��ǰ�Ƿ�����ѡ����������ˡ�����1��������5��������2��������6��������3��������7��������4��û����Ϊ0

int Signal_rectangle_chat_bubble_1_level = 0;				//��¼��ǰ��ӡ�˼��������������ݣ�ͬ�������£������������ݲ�����10�㣬û��ӡʱ��Ϊ0�㣬��ӡ�˵�һ�λ���Ϊ1����ӡ�˵ڶ��λ����Ϊ2������ȷ����һ����ӡ�ĸ�������������
int Signal_rectangle_chat_bubble_2_level = 0;				//��¼��ǰ��ӡ�˼��������������ݣ�ͬ�������£������������ݲ�����10�㣬û��ӡʱ��Ϊ0�㣬��ӡ�˵�һ�λ���Ϊ1����ӡ�˵ڶ��λ����Ϊ2������ȷ����һ����ӡ�ĸ�������������
int Signal_rectangle_chat_bubble_3_level = 0;				//��¼��ǰ��ӡ�˼��������������ݣ�ͬ�������£������������ݲ�����10�㣬û��ӡʱ��Ϊ0�㣬��ӡ�˵�һ�λ���Ϊ1����ӡ�˵ڶ��λ����Ϊ2������ȷ����һ����ӡ�ĸ�������������


int Signal_phone_chat_bubble_1_level = 0;					//��¼��ǰ��ӡ�˼����ֻ�������棬ͬ�������£��ֻ�������治����10�㣬û��ӡʱ��Ϊ0�㣬��ӡ�˵�һ�λ���Ϊ1����ӡ�˵ڶ��λ����Ϊ2��������ȷ����һ����ӡ�ĸ��ֻ��������
int Signal_phone_chat_bubble_2_level = 0;
int Signal_phone_chat_bubble_3_level = 0;

int Object_controlled_x = 0;					//�ɱ������ƶ�������ĺ�����
int Object_controlled_y = 0;					//�ɱ������ƶ��������������
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

int Signal_exist_boss = 1;				//��ʼ����boss���ţ�
int Signal_exist_player = 1;			//��ʼ������һ��ţ�
int Gif_n = 0;							//��ʼ������ͼѭ�����ִ�0��ʼ��
int BOSS_x;								//��¼BOSS���ڵĺ�����
int BOSS_y;								//��¼BOSS���ڵĺ�����
int BOSS_blood_number;					//���Ѫ������
int BOSS_blood_rectangle;				//���Ѫ�����γ���
int Player_x;							//��¼������ڵĺ�����
int Player_y;							//��¼������ڵĺ�����
int Player_direction;					//��¼��ҷ���
int Player_blood_number;				//���Ѫ������
int Player_blood_rectangle;				//���Ѫ�����γ���
ExMessage Player_action;				//�����Ϣ
int Bullet_amount = 30;					//����ӵ�������
bullet Player_bullet[30];				//����ӵ��ṹ��
int Speed_bullet = 60;					//����ӵ��ƶ��ٶ�
int End_credit_y = 0;					//Ƭβ

//�ӵ���صĽṹ��

//�ӵ�����ҡ�����ͼƬ����
IMAGE BOSS;								//BOSSͼ��
IMAGE img_player_left;					//��ҳ���
IMAGE img_player_right;					//��ҳ���
IMAGE img_boss_bullet_SRCAND;			//�����ӵ�
IMAGE img_boss_bullet_SRCPAINT;			//�����ӵ�
IMAGE img_player_bullet_SRCAND;			//����ӵ�
IMAGE img_player_bullet_SRCPAINT;		//����ӵ�


int Level = 0, N_level;

//��ʼ����ͷ��������Ϸ����
void Init_game_data_chapter_0() {
	ExMessage msg;

	int i = 0, t = 0;//i�ǲ�ͬ�����жϣ�t�ǽ�����Ϸ�ж�
	int a = 0, k = 0;//�ж����ֿ��ر���
	//����ͼƬ

	//��ʼ�˵�
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

		//�����
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

//��ʼ����һ��ƪ�µ�������Ϸ����
void Init_game_data_chapter_1() {
	printf("�����ʼ�����ݵĺ������\n");

	//head���ֵı���ͼ���Լ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/0.png");				//��ǰָ��head��㣬Ƭͷ��ͼΪ./Page_background/0.png
	Pointer_present_node_page->Type = 1;																//��head��ҳ�湦������type����Ϊ0����Ϊ�������ֻ�û������Ƭͷ�Ĵ���
	printf("��ɳ�ʼ����0����ͼ���ݡ�\n");
	//��һ���ֵı���ͼ�Լ����ͣ�

	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);								//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;			//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 1;														//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/1.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;																//��2��ҳ��Ĺ�����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/2.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/2.png
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);


#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/1.png");		//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//��2��ҳ��Ĺ�����������Ϊ2
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/2.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/2.png
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/3.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/5.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/video/6.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/3.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);



	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 1;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/TuringCollege_meeting/1.png");
	Output_all_node_page(Game_data_under_turing);
	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);



	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/TuringCollege_meeting/2.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/TuringCollege_meeting/3.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/TuringCollege_meeting/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/TuringCollege_meeting/5.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);



	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);



	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/5.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/group_meeting/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/6.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);


	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);												//
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/7.png");				//�����ȥ������Ѷ��Ƶ
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_1/8.png");				//���ҽ��ܵ���Ƶ����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;																//��2��ҳ��Ĺ�����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/1.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/2.png
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif


	return;
}
void Init_game_data_chapter_2() {
	printf("�����ʼ�����ݵĺ������\n");
	//��һ���ֵı���ͼ�Լ����ͣ�
#if 1
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 1;																//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/1.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif


	//�����Ʒ����ƪ��һ��ǰ
#if 1 
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/1.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/3.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/4.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/5.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/phone/6.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif


	//��Ʒ����ƪ��һ��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_1/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																		//��Ϸ�ؿ������ҡ����򵥰汾
	Pointer_present_node_page->Name_number = 333;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_1/3.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/2.png
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_1/4.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#endif


	//��һ�غ�ڶ���ǰ��ͼ��ݣ�
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/3.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	//�ʵ����������գ�

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	//��������
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/dance/1.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/dance/2.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/dance/3.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/dance/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/dance/5.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
	//����ף������
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/3.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/4.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/5.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/6.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 9;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/game_easter_eggs/7.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

#endif

	//�ص�ͼ���
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif


#endif

#endif


	//��Ʒ����ƪ�ڶ���
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_2/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																		//��Ϸ�ؿ��������ҡ������Ѱ汾
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/level_2/4.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#endif

	//��Ʒ����ڶ��غ�(ͼ���)
#if 1
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_2/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);


#endif
#endif
}

void Init_game_data_chapter_3() {
#if 1
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 1;																//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/1.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
	//��һ��ǰ
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
	//�����ĵ���һ��
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/level_1/2.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																			//��Ϸ�ؿ��������ĵ������򵥰汾
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 1;																//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/level_1/4.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
	//��һ�غ�ڶ���ǰ
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/3.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
	//�����ĵ��ڶ���
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 1;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/level_2/1.png");

	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																			//��Ϸ�ؿ��������ĵ������򵥰汾
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 1;																//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/level_2/5.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
	//�ڶ��غ�
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 2;
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/4.png");
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
	//С�����
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/group_meeting/1.png");		//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/group_meeting/2.png");		//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/group_meeting/3.png");		//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);

	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//
	Pointer_present_node_page->Type = 2;																		//
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_3/group_meeting/4.png");		//
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/object_controlled/1.tv.png");		//�������ϵ�BվС����
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
	return;
}

/*
void Init_game_data_chapter_3() {
#if 1
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 1;																//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./Page_background/Chapter_3/1.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																			//��Ϸ�ؿ��������ĵ������򵥰汾
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 578655045);
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;
	Pointer_present_node_page->Type = 3;																			//��Ϸ�ؿ��������ĵ������򵥰汾
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
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
	return;
}
*/

void Init_game_data_chapter_4() {
#if 1
	//Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);									//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;					//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 1;																//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/1.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Output_all_node_page(Game_data_under_turing);														//

	Pointer_present_node_page = &(Game_data_under_turing->Head);										//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 2;																				//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/cycle/1.png");				//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
	Pointer_present_node_page->Object_controlled.Born_x = 1200;
	Pointer_present_node_page->Object_controlled.Born_y = 600;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_4_cycle_1_40km;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_4_cycle_1_40km;
	Output_all_node_page(Game_data_under_turing);														//

	Pointer_present_node_page = &(Game_data_under_turing->Head);										//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 2;																				//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/cycle/2.png");				//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
	Pointer_present_node_page->Object_controlled.Born_x = 680;
	Pointer_present_node_page->Object_controlled.Born_y = 660;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_4_cycle_2_25km;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_4_cycle_2_25km;
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);											//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;							//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 2;																		//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/cycle/3.png");		//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
	Pointer_present_node_page->Object_controlled.Born_x = 1200;
	Pointer_present_node_page->Object_controlled.Born_y = 580;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_4_cycle_3_10km;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_4_cycle_3_10km;
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 2;																				//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/cycle/4.png");				//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
	Pointer_present_node_page->Object_controlled.Born_x = 1220;
	Pointer_present_node_page->Object_controlled.Born_y = 580;
	Pointer_present_node_page->Object_controlled.Speed_x = 20;
	Pointer_present_node_page->Object_controlled.Speed_y = 20;
	Pointer_present_node_page->Object_controlled.Width = 60;
	Pointer_present_node_page->Object_controlled.Height = 60;
	Pointer_present_node_page->Meet_page_door = Meet_door_chapter_4_cycle_4;
	Pointer_present_node_page->Meet_page_wall = Meet_wall_chapter_4_cycle_4;
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 1;																				//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/1.png");				//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 4;																				//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/1.png");				//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 2;																				//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/3.png");				//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Pointer_present_node_page->Object_controlled.Image_address_SRCAND = _T("./resource/Images/Object_controlled/3.1.png");				//С��
	Pointer_present_node_page->Object_controlled.Image_address_SRCPAINT = _T("./resource/Images/Object_controlled/3.2.png");			//С��
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

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif


#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 1;																				//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_2/1.png");				//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif



	//�Զ�����ƪ��
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/level_1/auto/1.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/2.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/3.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/4.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/5.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/6.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/7.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/8.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/9.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/10.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/11.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/12.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 6;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_1/auto/13.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

	Init_game_data_chapter_4_push_computer();
	Init_game_data_chapter_4_push_computer();
	Init_game_data_chapter_4_push_computer();


#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 1;																				//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/Chapter_4/level_2/5.png");				//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Output_all_node_page(Game_data_under_turing);																		//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif


#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);							//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;			//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 5;														//��1�ŵ�ҳ�湦����������Ϊ1
	Pointer_present_node_page->Name_number = 888;												//BOSS�ؿ����˺�
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/tupian/DTSJ.png");				//����1��ҳ��Ƭͷ��ͼΪ��./Page_background/1.png��������֮ǰ�����jpgд��png�ˣ��������bug���������Һþã��������������ͳһ����ͼƬ��ʽ����
	Pointer_present_node_page->Object_controlled.Born_x = 200;
	Pointer_present_node_page->Object_controlled.Born_y = 200;
	Pointer_present_node_page->Object_controlled.Speed_x = 30;
	Pointer_present_node_page->Object_controlled.Speed_y = 30;
	Pointer_present_node_page->Object_mobile.Image_address_SRCAND = _T("./resource/Images/tupian/boss.png");	//BOSS������ͼƬ��
	Pointer_present_node_page->Object_mobile.Image_address_SRCPAINT = _T("./resource/Images/tupian/boss.png");	//BOSS������ͼƬ��
	Pointer_present_node_page->Object_mobile.Object_mobile_born_x = 1300;
	Pointer_present_node_page->Object_mobile.Object_mobile_born_y = 150;

	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif


#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);							//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;			//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 8;														//��1�ŵ�ҳ�湦����������Ϊ8
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/end/end.png");
	Output_all_node_page(Game_data_under_turing);												//

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

}

void Init_game_data_chapter_4_push_computer() {
#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 7;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/1.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 7;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/2.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 7;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/3.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 7;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/4.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 7;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/5.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 7;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/6.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 7;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/7.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 7;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/8.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 7;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/9.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 7;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/10.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
#endif

#if 1
	Level += 1;
	N_level = Level;
	Insert_new_node_page(Game_data_under_turing, Level, 2521054164);													//�����µ�ҳ���㣬
	while (N_level--) Pointer_present_node_page = Pointer_present_node_page->Next_page;									//��ָ��ָ��0�Ž�㡪������˳���ǣ���head, 0, 1, 2, 3, ...��
	Pointer_present_node_page->Type = 7;																				//��ҳ�湦����������Ϊ6����ζ���Զ�����
	Pointer_present_node_page->Image_address_background = _T("./resource/Images/Page_background/chapter_4/push_computer/11.png");
	Output_all_node_page(Game_data_under_turing);

	Pointer_present_node_page = &(Game_data_under_turing->Head);								//��ָ�룬ָ��headҳ����
	printf("��ɳ�ʼ����%d����ͼ���ݡ�\n", Level);
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
		printf("��ѭ����ӡͼƬ�У�i = %d\n", i);
		Sleep(50);
	}
	printf("Ϊʲô���������أ�\n");
}










































/*
//��ʼ��ҳ�汳��ͼƬ�ĵ�ַ����
LPCTSTR Image_address_page_background[100] = {	_T("./Page_background/0.png"), _T("./Page_background/1.jpg"), _T("./Page_background/2.jpg"),
												_T("./Page_background/3.jpg"), _T("./Page_background/4.jpg"), _T("./Page_background/5.jpg"),
												_T("./Page_background/6.jpg"), _T("./Page_background/7.jpg")
};

//����ʽ���ݽṹ��ȫ�ֱ�����ʼ����ʽ
int Signal_page_type[100] = { 0,1,1,2,2,2,3,2 };	//��¼��ǰ��ͼ���ͣ�0ΪƬͷҳ�棬1Ϊ����ֱ�������ľ���ҳ�棻2Ϊ������ƶ��ľ���ҳ�棻3Ϊ��Ϸ�ؿ�ҳ�棻
int Signal_page_level = 1;						//��¼��ǰҳ�������������ڵڼ������в�ͬ�ĵ�ͼ����������������ԼΪ70�����ң�
int Signal_meet_NPC_1 = 0;						//��¼��ɫ��ǰ�Ƿ���ײ����ǰ��ͼ��1��NPC����ײ��Ϊ1��û����Ϊ0��
int Signal_meet_NPC_2 = 0;						//��¼��ɫ��ǰ�Ƿ���ײ����ǰ��ͼ��2��NPC����ײ��Ϊ1��û����Ϊ0��
int Signal_meet_NPC_3 = 0;						//��¼��ɫ��ǰ�Ƿ���ײ����ǰ��ͼ��3��NPC����ײ��Ϊ1��û����Ϊ0��
int Signal_meet_door = 0;						//��¼��ɫ��ǰ�Ƿ���ײ�������ţ���ײ��Ϊ1��û����Ϊ0��
int Signal_meet_coin = 0;						//��¼��ɫ��ǰ�Ƿ�������Ϸ�ڵĽ�ң���ײ������1����û����Ϊ0��
int Signal_meet_document_icon = 0;				//��¼��ɫ��ǰ�Ƿ�������Ϸ�ڵ��ĵ�ͼ�꣬��ײ������1����û����Ϊ0��
int Signal_meet_choice_box = 0;							//��¼��ɫ��ǰ�Ƿ�����ѡ����������ˡ�����1��������5��������2��������6��������3��������7��������4��û����Ϊ0
int Signal_rectangle_chat_bubble_level = 0;				//��¼��ǰ��ӡ�˼��������������ݣ�ͬ�������£������������ݲ�����10�㣬û��ӡʱ��Ϊ0�㣬��ӡ�˵�һ�λ���Ϊ1����ӡ�˵ڶ��λ����Ϊ2������ȷ����һ����ӡ�ĸ�������������
int Signal_phone_chat_bubble_level = 0;					//��¼��ǰ��ӡ�˼����ֻ�������棬ͬ�������£��ֻ�������治����10�㣬û��ӡʱ��Ϊ0�㣬��ӡ�˵�һ�λ���Ϊ1����ӡ�˵ڶ��λ����Ϊ2��������ȷ����һ����ӡ�ĸ��ֻ��������

int Object_controlled_x = 0;					//�ɱ������ƶ�������ĺ�����
int Object_controlled_y = 0;					//�ɱ������ƶ��������������
int Object_controlled_speed_x = 20;				//�ɱ������ƶ�������ĺ������ƶ��ٶ�
int Object_controlled_speed_y = 20;				//�ɱ������ƶ���������������ƶ��ٶ�

int Object_mobile_y1 = 10;
int Object_mobile_y2 = 10;
int Object_mobile_speed_y1 = 30;
int Object_mobile_speed_y2 = 30;


//��ʼ��ҳ�汳��ͼƬ�ĵ�ַ����
LPCTSTR Image_address_page_background[100] = {	_T("./Page_background/0.png"), _T("./Page_background/1.jpg"), _T("./Page_background/2.jpg"),
												_T("./Page_background/3.jpg"), _T("./Page_background/4.jpg"), _T("./Page_background/5.jpg"),
												_T("./Page_background/6.jpg"), _T("./Page_background/7.jpg")
};


//��ʼ���ɿ�������ͼƬ�ĵ�ַ����

LPCTSTR Image_address_object_controlled[100] = { _T("NULL"), _T("NULL"), _T("NULL"),
												_T("./object_controlled/1.png"), _T("./object_controlled/1.png"), _T("./object_controlled/1.png"),
												_T("./object_controlled/2.png"), _T("./object_controlled/3.png")
};
*/


//Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble_0 = _T("./Rectangle_chat_bubble/Chapter_1/0.png");
//Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble_1 = _T("./Rectangle_chat_bubble/Chapter_1/1.png");
//Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble_2 = _T("./Rectangle_chat_bubble/Chapter_1/2.png");
//Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble_3 = _T("./Rectangle_chat_bubble/Chapter_1/3.png");

//һ���ܴ���û������ѧϰ����������ʽ��С����
//Pointer_present_node_page->NPC_1.Image_address[0] = _T("./Rectangle_chat_bubble/Chapter_1/0.png");
//Pointer_present_node_page->NPC_1.Image_address[1] = _T("./Rectangle_chat_bubble/Chapter_1/1.png");
//Pointer_present_node_page->NPC_1.Image_address[2] = _T("./Rectangle_chat_bubble/Chapter_1/2.png");
//Pointer_present_node_page->NPC_1.Image_address[3] = _T("./Rectangle_chat_bubble/Chapter_1/3.png");


//�����ﺯ��������
//���ǣ����滹��
	/*
	�ڳ���img[]��ʱ��LPCTSTR xxx[10]���У�image xxx[10]���У�image xxxҲ����
	*/
	//loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble_0, _T("./Rectangle_chat_bubble/Chapter_1/0.png"));
	//loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble_1, _T("./Rectangle_chat_bubble/Chapter_1/1.png"));
	//loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble_2, _T("./Rectangle_chat_bubble/Chapter_1/2.png"));

	//Pointer_present_node_page->Meet_page_door = Meet_door_bilibili_vedio_end;
	//Pointer_present_node_page->NPC_1.Meet = Meet_NPC_1_brother_east_on_the_snow;
	//Pointer_present_node_page->NPC_1.Sum_rectangle_chat_bubble = 4;
	//Pointer_present_node_page->NPC_1.Image_address_rectangle_chat_bubble_1 = _T("./Rectangle_chat_bubble/Chapter_1/2.png");


	/*

	bug�����ֳ�������ʧ�ܣ����������ǶԵ�

	auto a = (Pointer_present_node_page->NPC_1.Rectangle_chat_bubble);
	loadimage(a, _T("./Rectangle_chat_bubble/Chapter_1/1.png"));
	printf("loadimage��2��ɹ���\n");
	loadimage(&(Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[2]), _T("./Rectangle_chat_bubble/Chapter_1/2.png"));
	loadimage(&(Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[3]), _T("./Rectangle_chat_bubble/Chapter_1/3.png"));

	auto a = &(Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[0]);
	loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[0], _T("./Rectangle_chat_bubble/Chapter_1/0.png"));
	loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[1], _T("./Rectangle_chat_bubble/Chapter_1/1.png"));
	loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[2], _T("./Rectangle_chat_bubble/Chapter_1/2.png"));
	loadimage(&Pointer_present_node_page->NPC_1.Rectangle_chat_bubble[3], _T("./Rectangle_chat_bubble/Chapter_1/3.png"));


	*/

	//�������أ�