#pragma once
#include "..//Constants.h"
#include "..//Utility.h"
#include <allegro.h>
class SettingsMenu
{
private:
	BITMAP* bannerBitmap;
	GameState* gameState;

public:
	SettingsMenu(GameState* gs);
	~SettingsMenu();
	void showSettingsMenu(BITMAP* buffer);
	BoundingBox soundSettingButton;
	BoundingBox gfxSettingButton;
	BoundingBox backButton;
};

