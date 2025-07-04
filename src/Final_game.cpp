#include "init_globle_variable.h"

typedef struct wjjg
{
	int x1 = 200, y1 = 200;//玩家x坐标,玩家y坐标
	int direction = 0;//玩家的方向
	int dz = 0;//角色的八个动作
	int sm = 9;//玩家文字生命
	int xl = 0;//玩家的血量
}WJJG;

typedef struct gwjg
{
	int x1 = 500, y1 = 200;//怪物x，y坐标
	int x2 = 0, y2 = 0;//是玩家上一次x，y坐标,也就是怪物目的地坐标
	int zy = 0;//是怪物在敌人的左边还是右边a
	int jljsjl = 0;//距离角色距离
	int sm = 9, xl = 0;//sm是怪物的文字生命，xl是怪物的血量
	bool live = false;//判断怪物存活
}GWJG;

typedef struct zdjg
{
	int x1 = 0, y1 = 0;//子弹x, y坐标
	int x2 = 0, y2 = 0;//子弹目的地x, y坐标
	int x3 = 0, y3 = 0;//子弹初始坐标
	int zdbj = 0;//子弹的边界判断
	bool live = false;//判断子弹是否抵达目的地
}ZDJG;

ExMessage wjxx;//玩家鼠标或者键盘消息
WJJG wj;//玩家角色
GWJG gw[gwsl];//怪物数量
ZDJG wjzd[zidan_slwj], gwzd[zidan_slgw];//wjzd是玩家的子弹，gwzd是怪物的子弹
int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//防止怪物或者子弹反复横跳
int dtqh = 0;//菜单切换
char ch[10][5] = { "0/9","1/9", "2/9", "3/9", "4/9", "5/9", "6/9", "7/9", "8/9", "9/9" };//玩家血量
char gwsm[10][5] = { "0/9","1/9", "2/9", "3/9", "4/9", "5/9", "6/9", "7/9", "8/9", "9/9" };//怪物血量
int gwch = gwsl;//判断怪物是否归零
int dt[WINDOW_WIDTH][WINDOW_HEIGHT];
int mydr = gwsl;

IMAGE jiemian[5];
IMAGE DTSJ;
IMAGE z, Z;
IMAGE move0, move1, move2, move3;
IMAGE zd1, zd2;
IMAGE jszd1, jszd11;
IMAGE bjy, bjz;
IMAGE zt, ztcd;
IMAGE yxjs;

void load_img(void)
{
	//开始菜单的
	loadimage(&jiemian[0], "./resource/Images/tupian//游戏界面.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	loadimage(&jiemian[1], "./resource/Images/tupian//公告.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	loadimage(&jiemian[2], "./resource/Images/tupian//版本信息2.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	loadimage(&jiemian[3], "./resource/Images/tupian//设置.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	loadimage(&jiemian[4], "./resource/Images/tupian//关音乐.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	//游戏内
	loadimage(&DTSJ, "./resource/Images/tupian//DTSJ.png", WINDOW_WIDTH, WINDOW_HEIGHT);
	loadimage(&Z, "./resource/Images/tupian//Little monster_2.png");
	loadimage(&z, "./resource/Images/tupian//Little monster_1.png");
	loadimage(&move0, "./resource/Images/tupian//move0.png");
	loadimage(&move1, "./resource/Images/tupian//move1.png");
	loadimage(&move2, "./resource/Images/tupian//move2.png");
	loadimage(&move3, "./resource/Images/tupian//move3.png");
	loadimage(&zd1, "./resource/Images/tupian//zd2.png", zidan_WIDTH, zidan_HEIGHT);
	loadimage(&zd2, "./resource/Images/tupian//zd22.png", zidan_WIDTH, zidan_HEIGHT);
	loadimage(&jszd1, "./resource/Images/tupian//jszd1.png", zidan_WIDTH, zidan_HEIGHT);
	loadimage(&jszd11, "./resource/Images/tupian//jszd11.png", zidan_WIDTH, zidan_HEIGHT);
	loadimage(&bjy, _T("./resource/Images/tupian/八戒右.png"));
	loadimage(&bjz, _T("./resource/Images/tupian/八戒左.png"));
	//loadimage(&bjy, "tupian//八戒右.png"); 
	//loadimage(&bjz, "tupian//八戒左.png");
	loadimage(&zt, "./resource/Images/tupian//游戏暂停.png");
	loadimage(&ztcd, "./resource/Images/tupian//游戏继续.png", 300, 300);
	loadimage(&yxjs, "./resource/Images/tupian//游戏结束.png", 300, 300);

	return;
}


//汇集函数
void huiji(void)
{
	load_img();
	initgwwz();
	initzd(wjzd, zidan_slwj);
	initzd(gwzd, zidan_slgw);
	int t = 1;
	while (1 == t)
	{
		show1();
		Sleep(80);
		++wj.dz;
		wj.dz %= 8;
		if (0 == dtqh)
		{
			wjkz();										//玩家控制
			//Sleep(80);
			//++wj.dz;
			/*
			if (wj.dz > 4)//保证n在0-3之间
			{
				wj.dz = 0;
			}
			*/
			ycgwyd1();									//怪物移动，坐标刷新
			createwjzd();								//接受鼠标消息，创建玩家发射的子弹
			creategwzd();								//怪物发射的子弹
			gyzdydhs(wjzd, zidan_slwj, wjzdsd);			//每一轮改变一次所有玩家子弹的坐标
			gyzdydhs(gwzd, zidan_slgw, gwzdsd);			//每一轮改变一次所有怪物子弹的坐标
		}
		t = ztks();
		if (0 == t)
		{
			initxy();
		}
		if (dtqh == 2) {
			if (wj.x1 <= 300 && wj.x1 >= 50 && wj.y1 >= 580) t = 0;
		}
	}

	return;
}

//返回主菜单进行初始化函数
void initxy(void)
{
	//初始化玩家结构
	wj.x1 = 200, wj.y1 = 200, wj.direction = 0; wj.sm = 9, wj.xl = 0;
	//初始化怪物结构
	for (int i = 0; i < gwsl; ++i)
	{
		gw[i].x1 = 500, gw[i].y1 = 200;
		gw[i].x2 = wj.x1, gw[i].y2 = wj.y1;
		gwzd[0].x1 = gw[i].x1, gwzd[0].y1 = gw[i].y1;
		gwzd[0].x2 = wj.x1, gwzd[0].y2 = wj.y1;
		gw[i].sm = 9, gw[i].xl = 0;
		gw[i].live = false;
	}
	gwch = gwsl;

	return;
}

//显示函数
void show1(void)
{
	//暂停菜单
	if (1 == dtqh)
	{
		putimage(500, 200, &ztcd);
	}
	else if (0 == dtqh)
	{
		//地图
		putimage(0, 0, &DTSJ);
		//暂停键
		putimage(1180, 0, &zt);
		//血条
		xuetiao();
		//玩家移动
		switch (wj.direction)
		{
		case 1:
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjz,
				wj.dz * PEOPLE_WIDTH, 0, SRCAND);
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjz,
				wj.dz * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
			break;
		case 0:
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjy,
				wj.dz * PEOPLE_WIDTH, 0, SRCAND);
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjy,
				wj.dz * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
			break;
		}
		//敌人移动
		for (int i = 0; i < gwsl; ++i)
		{
			if (!gw[i].live)
			{
				if ((i & 1) == 1) {
					putimage(gw[i].x1, gw[i].y1,
						PEOPLE_WIDTH, PEOPLE_HEIGHT,
						&z,
						(wj.dz % 6) * PEOPLE_WIDTH, 0, SRCAND);
					putimage(gw[i].x1, gw[i].y1,
						PEOPLE_WIDTH, PEOPLE_HEIGHT,
						&z,
						(wj.dz % 6) * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
				}
				if ((i & 1) == 0) {
					putimage(gw[i].x1, gw[i].y1,
						PEOPLE_WIDTH, PEOPLE_HEIGHT,
						&Z,
						(wj.dz % 6) * PEOPLE_WIDTH, 0, SRCAND);
					putimage(gw[i].x1, gw[i].y1,
						PEOPLE_WIDTH, PEOPLE_HEIGHT,
						&Z,
						(wj.dz % 6) * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
				}
				//putimage(gw[i].x1, gw[i].y1, &z, SRCAND);
				//putimage(gw[i].x1, gw[i].y1, &Z, SRCPAINT);
			}
		}

		//玩家的子弹
		for (int i = 0; i < zidan_slwj; i++)
		{
			if (wjzd[i].live)
			{
				putimage(wjzd[i].x1, wjzd[i].y1, &jszd11, SRCAND);
				putimage(wjzd[i].x1, wjzd[i].y1, &jszd1, SRCPAINT);
				//检查，每一次打印子弹的时候，子弹的坐标改变是否是对的
				//printf("子弹坐标(%d, %d)\n", wjzd[i].x1, wjzd[i].y1);
				//printf("子弹速度 = %d\n", wjzdsd);
				//printf("子弹横坐标移动速度 = %f\n", wjzdsd * ((wjzd[i].x2 - wjzd[i].x3) / sqrt((wjzd[i].x2 - wjzd[i].x3) * (wjzd[i].x2 - wjzd[i].x3) + (wjzd[i].y2 - wjzd[i].y3) * (wjzd[i].y2 - wjzd[i].y3))));
				//printf("子弹纵坐标移动速度 = %f\n", wjzdsd * ((wjzd[i].y2 - wjzd[i].y3) / sqrt((wjzd[i].x2 - wjzd[i].x3) * (wjzd[i].x2 - wjzd[i].x3) + (wjzd[i].y2 - wjzd[i].y3) * (wjzd[i].y2 - wjzd[i].y3))));
			}
		}
		//敌人的子弹
		for (int i = 0; i < zidan_slgw; i++)
		{
			if (gwzd[0].live)
			{
				putimage(gwzd[0].x1, gwzd[0].y1, &zd1, SRCAND);
				putimage(gwzd[0].x1, gwzd[0].y1, &zd2, SRCPAINT);
			}
		}
	}
	else if (2 == dtqh)
	{
		//putimage(490, 200, &yxjs);								//显示暂停画面
		printf("当且页面类型为：dtqh = %d\n", dtqh);
		wjkz();
		//地图
		putimage(0, 0, &DTSJ);
		//暂停键
		putimage(1180, 0, &zt);
		//血条
		xuetiao();
		//玩家移动
		switch (wj.direction)
		{
		case 1:
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjz,
				wj.dz * PEOPLE_WIDTH, 0, SRCAND);
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjz,
				wj.dz * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
			break;
		case 0:
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjy,
				wj.dz * PEOPLE_WIDTH, 0, SRCAND);
			putimage(wj.x1, wj.y1,
				PEOPLE_WIDTH, PEOPLE_HEIGHT,
				&bjy,
				wj.dz * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
			break;
		}
		//
		IMAGE door1, door2;
		loadimage(&door1, "./resource/Images/tupian/transfer_gate.png");
		loadimage(&door2, "./resource/Images/tupian/transfer_gate.png");
		putimage(100, 580, PEOPLE_WIDTH, PEOPLE_HEIGHT, &door1, wj.dz * PEOPLE_WIDTH, 0, SRCAND);
		putimage(100, 580, PEOPLE_WIDTH, PEOPLE_HEIGHT, &door2, wj.dz * PEOPLE_WIDTH, PEOPLE_HEIGHT, SRCPAINT);
		//++wj.dz;
	}

	FlushBatchDraw();

	return;
}

//暂停开始函数
int ztks(void)
{
	peekmessage(&wjxx, EX_MOUSE);

	switch (wjxx.message)
	{
	case WM_LBUTTONDOWN:
		if (wjxx.x > 1180 && wjxx.y < 85 && 0 == dtqh)
		{
			dtqh = 1;//暂停界面
		}
		else if (wjxx.x > 585 && wjxx.x < 710 && wjxx.y > 400 && wjxx.y < 480 && 1 == dtqh)
		{
			dtqh = 0;//返回游戏
		}
		else if (wjxx.x > 500 && wjxx.x < 580 && wjxx.y > 400 && wjxx.y < 480 && 1 == dtqh)
		{
			dtqh = 0;//暂停返回主菜单
			return 0;
		}
		/*
		else if (wjxx.x > 585 && wjxx.x < 680 && wjxx.y > 400 && wjxx.y < 480 && 2 == dtqh)
		{
			dtqh = 2;																		//游戏结束返回主菜单
			return 0;
		}
		*/
		break;
	}

	return 1;
}

//玩家控制函数
void wjkz(void)
{
	if (dtqh == 0 || dtqh == 1) {																//当在有敌人的关卡中，主角会考虑和敌人的体积碰撞，不重合
		if (GetAsyncKeyState('W') && wj.y1 > 0)//W		
		{
			int i;
			mydr = gwsl;
			for (i = 0; i < gwsl; ++i)
			{
				if ((gw[i].y1 < (wj.y1 - wjsd)) && ((gw[i].y1 + 102) > (wj.y1 - wjsd)) &&
					((gw[i].x1 < wj.x1) && ((gw[i].x1 + 74) > wj.x1) ||
						(wj.x1 < gw[i].x1) && ((wj.x1 + 120) > gw[i].x1)))
				{
					--mydr;
				}
			}
			if (gwsl == mydr)
			{
				wj.y1 -= wjsd;
				mciSendString("play ./resource/Images/tupian/走路.mp3", NULL, NULL, NULL);
			}
		}
		if (GetAsyncKeyState('S') && wj.y1 < 450)//S
		{
			int i;
			mydr = gwsl;
			for (i = 0; i < gwsl; ++i)
			{
				if (((wj.y1 + wjsd) < gw[i].y1) && ((wj.y1 + wjsd + 120) > gw[i].y1) &&
					((gw[i].x1 < wj.x1) && ((gw[i].x1 + 74) > wj.x1) ||
						(wj.x1 < gw[i].x1) && ((wj.x1 + 120) > gw[i].x1)))
				{
					--mydr;
				}
			}
			if (gwsl == mydr)
			{
				wj.y1 += wjsd;
				mciSendString("play ./resource/Images/tupian/走路.mp3", NULL, NULL, NULL);;
			}
		}
		if (GetAsyncKeyState('A') && wj.x1 > 0)//A
		{
			int i;
			mydr = gwsl;
			for (i = 0; i < gwsl; ++i)
			{
				if ((gw[i].x1 < (wj.x1 - wjsd)) && ((gw[i].x1 + 74) > (wj.x1 - wjsd)) &&
					((gw[i].y1 < wj.y1) && ((gw[i].y1 + 102) > wj.y1) ||
						(wj.y1 < gw[i].y1) && ((wj.y1 + 120) > gw[i].y1)))
				{
					--mydr;
				}
			}
			if (gwsl == mydr)
			{
				wj.x1 -= wjsd;
				mciSendString("play ./resource/Images/tupian/走路.mp3", NULL, NULL, NULL);;
			}
			wj.direction = 1;
		}
		if (GetAsyncKeyState('D') && wj.x1 < 860)//D
		{
			int i;
			mydr = gwsl;
			for (i = 0; i < gwsl; ++i)
			{
				if (((wj.x1 + wjsd) < gw[i].x1) && ((wj.x1 + wjsd + 120) > gw[i].x1) &&
					((gw[i].y1 < wj.y1) && ((gw[i].y1 + 102) > wj.y1) ||
						(wj.y1 < gw[i].y1) && ((wj.y1 + 120) > gw[i].y1)))
				{
					--mydr;
				}
			}
			if (gwsl == mydr)
			{
				wj.x1 += wjsd;
				mciSendString("play ./resource/Images/tupian/走路.mp3", NULL, NULL, NULL);;
			}
			wj.direction = 0;
		}
	}

	if (dtqh == 2) {															//当消灭所有敌人后，不考虑与敌人的体积碰撞
		if (GetAsyncKeyState('W') && wj.y1 > 0)//W		
		{
			wj.y1 -= wjsd;
			mciSendString("play ./resource/Images/tupian/走路.mp3", NULL, NULL, NULL);
		}
		if (GetAsyncKeyState('S') && ((wj.y1 < 450 && wj.x1 >= 300) || wj.x1 <= 300))//S
		{

			wj.y1 += wjsd;
			mciSendString("play ./resource/Images/tupian/走路.mp3", NULL, NULL, NULL);;

		}
		if (GetAsyncKeyState('A') && wj.x1 > 0)//A
		{
			wj.x1 -= wjsd;
			mciSendString("play ./resource/Images/tupian/走路.mp3", NULL, NULL, NULL);;
			wj.direction = 1;
		}
		if (GetAsyncKeyState('D') && wj.x1 < 860)//D
		{
			wj.x1 += wjsd;
			mciSendString("play ./resource/Images/tupian/走路.mp3", NULL, NULL, NULL);;
			wj.direction = 0;
		}
	}
	//上面的围墙
	if (wj.y1 <= 100) wj.y1 = 100;
	return;
}

//远程怪物移动函数1
void ycgwyd1(void)
{
	for (int i = 0; i < gwsl; ++i)
	{
		//敌人在右
		if (wj.x1 >= 0 && wj.x1 <= 120)
		{
			//将玩家和怪物的每一次最新坐标之和除2赋给敌人的目的地
			gw[i].x2 = wj.x1 - gw[i].jljsjl, gw[i].y2 = wj.y1 - gw[i].jljsjl;
			gw[i].x2 += 130, gw[i].y2 += 17;
			gw[i].zy = 0;
		}
		//敌人在左
		else if (wj.x1 >= 740 && wj.x1 <= 860)
		{
			//将玩家的每一次最新坐标赋给敌人的目的地
			gw[i].x2 = wj.x1 - gw[i].jljsjl, gw[i].y2 = wj.y1 - gw[i].jljsjl;
			gw[i].x2 -= 130, gw[i].y2 += 17;
			gw[i].zy = 1;
		}
		//怪物在右
		else if (0 == gw[i].zy)
		{
			gw[i].x2 = wj.x1 - gw[i].jljsjl, gw[i].y2 = wj.y1 + gw[i].jljsjl;
			gw[i].x2 += 130, gw[i].y2 += 17;
		}
		//怪物在左
		else if (1 == gw[i].zy)
		{
			gw[i].x2 = wj.x1 - gw[i].jljsjl, gw[i].y2 = wj.y1 - gw[i].jljsjl;
			gw[i].x2 -= 130, gw[i].y2 += 17;
		}
		//敌人中间
		if (gw[i].x1 < gw[i].x2 && gw[i].y1 == gw[i].y2)
		{
			if (gwbch(0))
			{
				ycgwyd2(0, 'x', 0, &gw[i]);
			}
		}
		else if (gw[i].x1 > gw[i].x2 && gw[i].y1 == gw[i].y2)
		{
			if (gwbch(1))
			{
				ycgwyd2(1, 'x', 0, &gw[i]);
			}
		}
		else if (gw[i].y1 < gw[i].y2 && gw[i].x1 == gw[i].x2)
		{
			if (gwbch(2))
			{
				ycgwyd2(2, 0, 'y', &gw[i]);
			}
		}
		else if (gw[i].y1 > gw[i].y2 && gw[i].x1 == gw[i].x2)
		{
			if (gwbch(3))
			{
				ycgwyd2(3, 0, 'y', &gw[i]);
			}
		}
		else if (gw[i].x1 < gw[i].x2 && gw[i].y1 < gw[i].y2)
		{
			if (gwbch(4))
			{
				ycgwyd2(4, 'x', 'y', &gw[i]);
			}
		}
		else if (gw[i].x1 > gw[i].x2 && gw[i].y1 > gw[i].y2)
		{
			if (gwbch(5))
			{
				ycgwyd2(5, 'x', 'y', &gw[i]);
			}
		}
		else if (gw[i].x1 < gw[i].x2 && gw[i].y1 > gw[i].y2)
		{
			if (gwbch(6))
			{
				ycgwyd2(6, 'x', 'y', &gw[i]);
			}
		}
		else if (gw[i].x1 > gw[i].x2 && gw[i].y1 < gw[i].y2)
		{
			if (gwbch(7))
			{
				ycgwyd2(7, 'x', 'y', &gw[i]);
			}
		}
	}

	return;
}
//远程怪物移动函数2
void ycgwyd2(char ch, char chx, char chy, struct gwjg* pgw)
{
	int t = 0;

	switch (ch)
	{
	case 0:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 + a[i] == pgw->x2)
			{
				pgw->x1 += a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 += drsd;
			break;
		}
	case 1:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 - a[i] == pgw->x2)
			{
				pgw->x1 -= a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 -= drsd;
			break;
		}

	case 2:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->y1 + a[i] == pgw->y2)
			{
				pgw->y1 += a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->y1 += drsd;
			break;
		}

	case 3:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->y1 - a[i] == pgw->y2)
			{
				pgw->y1 -= a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->y1 -= drsd;
			break;
		}
	case 4:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 + a[i] == pgw->x2)
			{
				pgw->x1 += a[i];
				t = 1;
				break;
			}
			else if (pgw->y1 + a[i] == pgw->y2)
			{
				pgw->y1 += a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 += drsd;
			pgw->y1 += drsd;
			break;
		}
	case 5:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 - a[i] == pgw->x2)
			{
				pgw->x1 -= a[i];
				t = 1;
				break;
			}
			else if (pgw->y1 - a[i] == pgw->y2)
			{
				pgw->y1 -= a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 -= drsd;
			pgw->y1 -= drsd;
			break;
		}
	case 6:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 + a[i] == pgw->x2)
			{
				pgw->x1 += a[i];
				t = 1;
				break;
			}
			else if (pgw->y1 - a[i] == pgw->y2)
			{
				pgw->y1 -= a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 += drsd;
			pgw->y1 -= drsd;
			break;
		}
	case 7:
		for (int i = 0; i < 10; i++)
		{
			if (pgw->x1 - a[i] == pgw->x2)
			{
				pgw->x1 -= a[i];
				t = 1;
				break;
			}
			else if (pgw->y1 + a[i] == pgw->y2)
			{
				pgw->y1 += a[i];
				t = 1;
				break;
			}
		}
		if (0 == t)
		{
			pgw->x1 -= drsd;
			pgw->y1 += drsd;
			break;
		}
	}

	return;
}

//初始化子弹函数
void initzd(struct zdjg* pzd, int zdsl)
{
	int i;
	for (i = 0; i < zdsl; i++)
	{
		pzd[i].x1 = 0;
		pzd[i].y1 = 0;
		pzd[i].x2 = 0;
		pzd[i].y2 = 0;
		pzd[i].x3 = 0;
		pzd[i].y3 = 0;
		pzd[i].zdbj = 0;
		pzd[i].live = false;
	}

	return;
}

//创建玩家子弹函数
void createwjzd(void)
{
	while (peekmessage(&wjxx, EX_MOUSE))
	{
		switch (wjxx.message)
		{
		case WM_LBUTTONDOWN:
			for (int i = 0; i < zidan_slwj; i++)
			{
				if (!wjzd[i].live && (wjxx.x < 860 || wjxx.y > 85))
				{
					wjzd[i].x1 = wj.x1;
					wjzd[i].y1 = wj.y1;
					wjzd[i].x2 = wjxx.x;
					wjzd[i].y2 = wjxx.y;
					wjzd[i].x3 = wj.x1;
					wjzd[i].y3 = wj.y1;
					wjzd[i].zdbj = 0;
					wjzd[i].live = true;
					//检查，每次点击鼠标以后，计算玩家子弹的速度矢量的所有数据是否正确
					//printf("鼠标点击的坐标为(%d, %d)\n", wjxx.x, wjxx.y);
					//printf("玩家当前的坐标为(%d, %d)\n", wj.x1, wj.y1);
					//printf("子弹横坐标单位时间移动长度：%d\n",wjxx.x - wj.x1);
					//printf("子弹纵坐标单位时间移动长度：%d\n", wjxx.y - wj.y1);
					//printf("子弹坐标(%d, %d)\n", wjzd[i].x1, wjzd[i].y1);
					//printf("子弹速度 = %d\n", wjzdsd);
					//printf("子弹横坐标移动速度 = %f\n", wjzdsd * ((wjzd[i].x2 - wjzd[i].x3) / sqrt((wjzd[i].x2 - wjzd[i].x3) * (wjzd[i].x2 - wjzd[i].x3) + (wjzd[i].y2 - wjzd[i].y3) * (wjzd[i].y2 - wjzd[i].y3))));
					//printf("子弹纵坐标移动速度 = %f\n", wjzdsd * ((wjzd[i].y2 - wjzd[i].y3) / sqrt((wjzd[i].x2 - wjzd[i].x3) * (wjzd[i].x2 - wjzd[i].x3) + (wjzd[i].y2 - wjzd[i].y3) * (wjzd[i].y2 - wjzd[i].y3))));
					//printf("子弹速度算得没有问题，那就是画的问题了；\n");
					mciSendString("play ./resource/Images/tupian/子弹发射.mp3", NULL, NULL, NULL);
					break;
				}
			}
			break;
		}
	}

	return;
}

//创建怪物子弹函数
void creategwzd(void)
{
	for (int i = 0; i < zidan_slgw; ++i)
	{
		if (!gw[i].live && !gwzd[i].live && sqrt(pow((wj.x1 - gw[i].x1), 2) + pow(wj.y1 - gw[i].y1, 2)) <= 600)
		{
			gwzd[i].x1 = gw[i].x1;
			gwzd[i].y1 = gw[i].y1;
			gwzd[i].x2 = wj.x1;
			gwzd[i].y2 = wj.y1;
			gwzd[i].x3 = gw[i].x1;
			gwzd[i].y3 = gw[i].y1;
			gwzd[i].zdbj = 0;
			gwzd[i].live = true;
		}
	}

	return;
}





//共用的子弹移动函数
void gyzdydhs(struct zdjg* pzd, int zdsl, int zdsd)
{
	//计算子弹每一轮变化以后的坐标
	for (int i = 0; i < zdsl; ++i)
	{
		if (pzd[i].live)
		{
			wjzdpz(pzd, zdsl, i);
			gwzdpz(pzd, zdsl, i);
			pzd[i].x1 += zdsd * ((pzd[i].x2 - pzd[i].x3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3)));
			pzd[i].y1 += zdsd * ((pzd[i].y2 - pzd[i].y3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3)));
			//printf("子弹坐标(%d, %d)\n", pzd[i].x1, pzd[i].y1);
			//printf("子弹速度 = %d\n", zdsd);
			//printf("子弹横坐标移动速度 = %f\n", zdsd * ((pzd[i].x2 - pzd[i].x3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3))));
			//printf("子弹纵坐标移动速度 = %f\n", zdsd * ((pzd[i].y2 - pzd[i].y3) / sqrt((pzd[i].x2 - pzd[i].x3) * (pzd[i].x2 - pzd[i].x3) + (pzd[i].y2 - pzd[i].y3) * (pzd[i].y2 - pzd[i].y3))));
			if (pzd[i].x1 <= -200 || pzd[i].x1 >= 1500 || pzd[i].y1 <= -200 || pzd[i].y1 >= 1500)
			{
				pzd[i].live = false;
			}
		}
	}
	return;
}

//玩家子弹碰撞函数
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
				mciSendString("play ./resource/Images/tupian/怪物死亡.mp3", NULL, NULL, NULL);
				if (0 == gwch)																//当怪物存活数为0的时候，即击败了所有怪物
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

//怪物子弹碰撞函数
void gwzdpz(struct zdjg* pzd, int zdsl, int i)
{
	if (zdsl == zidan_slgw && pzd[i].x1 >= wj.x1 && pzd[i].x1 <= wj.x1 + 120 &&
		pzd[i].y1 >= wj.y1 && pzd[i].y1 <= wj.y1 + 120)
	{

		if (0 == wj.sm)
		{
			dtqh = 2;
		}
		else if (++wj.xl && 0 != --wj.sm)
		{
			pzd[i].live = false;
		}
	}
}

//绘制血条函数
void xuetiao(void)
{
	//绘制玩家生命文字
	settextcolor(WHITE);
	settextstyle(20, 0, "楷体");
	outtextxy(0, 0, "生命：");
	//绘制玩家血条边框
	setlinecolor(BLACK);
	roundrect(55, 0, 208, 20, 10, 10);
	//绘制玩家血条填充
	setfillcolor(RED);
	solidroundrect(55, 0, 208 - 17 * wj.xl, 20, 10, 10);
	outtextxy(110, 0, ch[wj.sm]);

	for (int i = 0; i < gwsl; ++i)
	{
		if (!gw[i].live)
		{
			//绘制怪物血条边框
			setlinecolor(BLACK);
			roundrect(gw[i].x1, gw[i].y1 - 20, gw[i].x1 + 90, gw[i].y1, 10, 10);
			//绘制怪物血条填充
			setfillcolor(RED);
			solidroundrect(gw[i].x1, gw[i].y1 - 20, gw[i].x1 + 90 - 10 * gw[i].xl, gw[i].y1, 10, 10);
			outtextxy(gw[i].x1 + 30, gw[i].y1 - 20, gwsm[gw[i].sm]);
		}
	}

	return;
}

//初始化怪物位置
void initgwwz(void)
{
	srand(time(NULL));
	for (int i = 0; i < gwsl; i++)
	{
		gw[i].jljsjl = 60 + (int)rand() % 101;			//怪物距离角色的距离
		gw[i].x1 = 800 + (int)rand() % 201;				//0 - 1280
		gw[i].y1 = 300 + (int)rand() % 201;
		printf("%d\n", gw[i].jljsjl);
	}

	return;
}

//怪物相互不重合函数
bool gwbch(int gwdzbh)//gwdzbh是怪物动作的编号
{
	int wdr = gwsl;//四周无敌人
	for (int i = 0; i < gwsl; ++i)
	{
		switch (gwdzbh)
		{
		case 0:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && ((gw[i].x1 + drsd) < gw[j].x1) && ((gw[i].x1 + drsd + 50) > gw[j].x1) &&
					((gw[j].y1 < gw[i].y1) && ((gw[j].y1 + 50) > gw[i].y1) ||
						(gw[i].y1 < gw[j].y1) && ((gw[i].y1 + 50) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 1:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && (gw[j].x1 < (gw[i].x1 - drsd)) && (gw[j].x1 + 50 > (gw[i].x1 - drsd)) &&
					((gw[j].y1 < gw[i].y1) && ((gw[j].y1 + 50) > gw[i].y1) ||
						(gw[i].y1 < gw[j].y1) && ((gw[i].y1 + 50) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 2:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && ((gw[i].y1 + drsd) < gw[j].y1) && ((gw[i].y1 + drsd + 50) > gw[j].y1) &&
					((gw[j].x1 < gw[i].x1) && ((gw[j].x1 + 50) > gw[i].x1) ||
						(gw[i].x1 < gw[j].x1) && ((gw[i].x1 + 50) > gw[j].x1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 3:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && (gw[j].y1 < (gw[i].y1 - drsd)) && ((gw[j].y1 + 50) > (gw[i].y1 - drsd)) &&
					((gw[j].x1 < gw[i].x1) && ((gw[j].x1 + 50) > gw[i].x1) ||
						(gw[i].x1 < gw[j].x1) && ((gw[i].x1 + 50) > gw[j].x1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 4:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && ((gw[i].x1 + drsd) < gw[j].x1) && ((gw[i].x1 + drsd + 50) > gw[j].x1) &&
					((gw[j].y1 < gw[i].y1 + drsd) && ((gw[j].y1 + 50) > (gw[i].y1 + drsd)) ||
						((gw[i].y1 + drsd) < gw[j].y1) && ((gw[i].y1 + drsd + 50) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 5:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && (gw[j].x1 < (gw[i].x1 - drsd)) && (gw[j].x1 + 74 > (gw[i].x1 - drsd)) &&
					((gw[j].y1 < gw[i].y1 - drsd) && ((gw[j].y1 + 102) > (gw[i].y1 - drsd)) ||
						((gw[i].y1 - drsd) < gw[j].y1) && ((gw[i].y1 - drsd + 102) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 6:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && ((gw[i].x1 + drsd) < gw[j].x1) && ((gw[i].x1 + drsd + 50) > gw[j].x1) &&
					((gw[j].y1 < gw[i].y1 - drsd) && ((gw[j].y1 + 50) > (gw[i].y1 - drsd)) ||
						((gw[i].y1 - drsd) < gw[j].y1) && ((gw[i].y1 - drsd + 50) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		case 7:
			for (int j = 0; j < gwsl; ++j)
			{
				if (i != j && (gw[j].x1 < (gw[i].x1 - drsd)) && ((gw[j].x1 + 50) > (gw[i].x1 - drsd)) &&
					((gw[j].y1 < gw[i].y1 + drsd) && ((gw[j].y1 + 50) > (gw[i].y1 + drsd)) ||
						((gw[i].y1 + drsd) < gw[j].y1) && ((gw[i].y1 + drsd + 50) > gw[j].y1)))
				{
					--wdr;
				}
			}
			if (gwsl == wdr)
			{
				return true;
			}
			else
			{
				return false;
			}
			break;
		}
	}
}



//BOSS关卡-------------------------------------------------------------------------
//额外需要的函数：
