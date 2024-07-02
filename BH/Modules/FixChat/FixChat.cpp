#include "FixChat.h"
#include "../../BH.h"
#include "../../D2Ptrs.h"
#include "../../D2Stubs.h"
#include "../../D2Version.h"
#include <vector>

//This code was written by RND2K
using namespace Drawing;
map<std::string, Toggle> FixChat::Toggles;


void __fastcall ReplaceChatText(wchar_t* str) {
	// макс размер буфера для чата 256 символов 
	wchar_t wc_buff[256] = { 0 };
	char mb_buff[256] = { 0 };

	if (GetLangId() == 11) { //LANG_RUS
		int len = WideCharToMultiByte(1252, 0, str, -1, 0, 0, 0, 0);
		WideCharToMultiByte(1252, 0, str, -1, mb_buff, len, 0, 0);

		len = MultiByteToWideChar(1251, 0, mb_buff, -1, 0, 0);
		MultiByteToWideChar(1251, 0, mb_buff, -1, wc_buff, len);

		lstrcpynW(str, wc_buff, 256);
	}
}


// конвертируется по одному символу
__declspec (naked) void ReplaceInputText_Interception() {
	static wchar_t temp[2];
	__asm
	{
		pushad;
		pushfd;
		movzx eax, word ptr [esp + 0x3E]; // mov cx, word ptr ss:[esp+0x16] + 0x24 pushd + 4 ret
		mov dword ptr [temp], eax;
		lea ecx, temp;
		call ReplaceChatText;
		popfd;
		popad;

		//fix and original code
		mov ecx, dword ptr [temp]; // mov cx, word ptr ss:[esp+0x16]
		ret;
	}
}


// конвертируется вся строка
__declspec (naked) void ReplaceOutputText_Interception113c() {
	__asm
	{
		pushad;
		pushfd;
		lea ecx, [esp + 0x7C]; //0x54 + 0x24 pushd + 4 ret // ptr wtext 
		call ReplaceChatText;
		popfd;
		popad;
		// original code
		lea edx, [esp + 0x58];  // 0x54 + 4 ret //ptr wtext
		lea ecx, [esp + 0x920]; // 0x91C + 4 ret
		ret;
	}
}


// конвертируется вся строка
__declspec (naked) void ReplaceOutputText_Interception113d() {
	__asm
	{
		pushad;
		pushfd;
		lea ecx, [esp + 0x94]; //0x6C + 0x24 pushd + 4 ret // ptr wtext 
		call ReplaceChatText;
		popfd;
		popad;
		// original code
		lea edx, [esp + 0x70]   // 0x6C + 4 ret //ptr wtext
		lea ecx, [esp + 0x938]  // 0x934 + 4 ret
		ret;
	}
}


Patch* replace_input_text = new Patch(Call, D2CLIENT, { 0x70D46, 0xB2626 }, (int)ReplaceInputText_Interception, 5);
Patch* replace_output_text113c = new Patch(Call, D2CLIENT, { 0x7FA9B, 0x0 }, (int)ReplaceOutputText_Interception113c, 11);
Patch* replace_output_text113d = new Patch(Call, D2CLIENT, { 0x0, 0x78898 }, (int)ReplaceOutputText_Interception113d, 11);


void FixChat::OnLoad() {
	replace_input_text->Install();
	replace_output_text113c->Install();
	replace_output_text113d->Install();
}

void FixChat::OnGameJoin() {

}

void FixChat::OnKey(bool up, BYTE key, LPARAM lParam, bool* block) {

}

void FixChat::OnRightClick(bool up, int x, int y, bool* block) {

}

void FixChat::OnDraw() {

}

void FixChat::OnAutomapDraw() {

}

void FixChat::OnGamePacketRecv(BYTE* packet, bool* block) {

}

void FixChat::OnGameExit() {

}
