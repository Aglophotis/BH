#pragma once
#include "../../D2Structs.h"
#include "../Module.h"
#include "../../Config.h"
#include "../../Drawing.h"

//This code was written by RND2K
class FixChat : public Module {
	private:

	public:
		static map<std::string, Toggle> Toggles;
		FixChat() : Module("FixChat") {};

		void OnLoad();
		void OnKey(bool up, BYTE key, LPARAM lParam, bool* block);
		void OnGameJoin();
		void OnGameExit();
		void OnRightClick(bool up, int x, int y, bool* block);
		void OnDraw();
		void OnAutomapDraw();
		void OnGamePacketRecv(BYTE* packet, bool *block);
};
