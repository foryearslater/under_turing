#include "init_globle_variable.h"
#include<mmsystem.h>
#include <windows.h>
#pragma comment(lib,"winmm.lib")

void Bgm_shadow() {
	mciSendString("close ./resource/Audios/ð�յ�1.mp3", 0, 0, 0);
	mciSendString("close ./resource/Audios/ð�յ�2.mp3", 0, 0, 0);
	mciSendString("close ./resource/Audios/ѧ�����ո�.mp3", 0, 0, 0);
	mciSendString("open ./resource/Audios/shadow.mp3", 0, 0, 0);
	mciSendString("play ./resource/Audios/shadow.mp3 repeat", 0, 0, 0);
}

void Bgm_adventure_island_1() {
	mciSendString("close ./resource/Audios/ð�յ�2.mp3", 0, 0, 0);
	mciSendString("close ./resource/Audios/shadow.mp3", 0, 0, 0);
	mciSendString("close ./resource/Audios/ѧ�����ո�.mp3", 0, 0, 0);
	mciSendString("open ./resource/Audios/ð�յ�1.mp3", 0, 0, 0);
	mciSendString("play ./resource/Audios/ð�յ�1.mp3 repeat", 0, 0, 0);
}
void Bgm_adventure_island_2() {
	mciSendString("close ./resource/Audios/ð�յ�1.mp3", 0, 0, 0);
	mciSendString("close ./resource/Audios/shadow.mp3", 0, 0, 0);
	mciSendString("close ./resource/Audios/ѧ�����ո�.mp3", 0, 0, 0);
	mciSendString("open ./resource/Audios/ð�յ�2.mp3", 0, 0, 0);
	mciSendString("play ./resource/Audios/ð�յ�2.mp3 repeat", 0, 0, 0);
}

void Bgm_end_credit() {
	mciSendString("close ./resource/Audios/ѧ�����ո�.mp3", 0, 0, 0);
	mciSendString("close ./resource/Audios/shadow.mp3", 0, 0, 0);
	mciSendString("close ./resource/Audios/ð�յ�1.mp3", 0, 0, 0);
	mciSendString("close ./resource/Audios/ð�յ�2.mp3", 0, 0, 0);
	mciSendString("open ./resource/Audios/ҹ����.mp3", 0, 0, 0);
	mciSendString("play ./resource/Audios/ҹ����.mp3 repeat", 0, 0, 0);
}

void Bgm_birthday() {
	mciSendString("close ./resource/Audios/ҹ����.mp3 repeat", 0, 0, 0);
	mciSendString("close ./resource/Audios/shadow.mp3", 0, 0, 0);
}