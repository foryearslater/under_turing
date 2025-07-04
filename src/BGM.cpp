#include "init_globle_variable.h"
#include<mmsystem.h>
#include <windows.h>
#pragma comment(lib,"winmm.lib")

void Bgm_shadow() {
	mciSendString("close ./res/Audios/√∞œ’µ∫1.mp3", 0, 0, 0);
	mciSendString("close ./res/Audios/√∞œ’µ∫2.mp3", 0, 0, 0);
	mciSendString("close ./res/Audios/—ßΩ„…˙»’∏Ë.mp3", 0, 0, 0);
	mciSendString("open ./res/Audios/shadow.mp3", 0, 0, 0);
	mciSendString("play ./res/Audios/shadow.mp3 repeat", 0, 0, 0);
}

void Bgm_adventure_island_1() {
	mciSendString("close ./res/Audios/√∞œ’µ∫2.mp3", 0, 0, 0);
	mciSendString("close ./res/Audios/shadow.mp3", 0, 0, 0);
	mciSendString("close ./res/Audios/—ßΩ„…˙»’∏Ë.mp3", 0, 0, 0);
	mciSendString("open ./res/Audios/√∞œ’µ∫1.mp3", 0, 0, 0);
	mciSendString("play ./res/Audios/√∞œ’µ∫1.mp3 repeat", 0, 0, 0);
}
void Bgm_adventure_island_2() {
	mciSendString("close ./res/Audios/√∞œ’µ∫1.mp3", 0, 0, 0);
	mciSendString("close ./res/Audios/shadow.mp3", 0, 0, 0);
	mciSendString("close ./res/Audios/—ßΩ„…˙»’∏Ë.mp3", 0, 0, 0);
	mciSendString("open ./res/Audios/√∞œ’µ∫2.mp3", 0, 0, 0);
	mciSendString("play ./res/Audios/√∞œ’µ∫2.mp3 repeat", 0, 0, 0);
}

void Bgm_end_credit() {
	mciSendString("close ./res/Audios/—ßΩ„…˙»’∏Ë.mp3", 0, 0, 0);
	mciSendString("close ./res/Audios/shadow.mp3", 0, 0, 0);
	mciSendString("close ./res/Audios/√∞œ’µ∫1.mp3", 0, 0, 0);
	mciSendString("close ./res/Audios/√∞œ’µ∫2.mp3", 0, 0, 0);
	mciSendString("open ./res/Audios/“π∫Ω–«.mp3", 0, 0, 0);
	mciSendString("play ./res/Audios/“π∫Ω–«.mp3 repeat", 0, 0, 0);
}
void Bgm_birthday() {
	mciSendString("close ./res/Audios/“π∫Ω–«.mp3 repeat", 0, 0, 0);
	mciSendString("close ./res/Audios/shadow.mp3", 0, 0, 0);
