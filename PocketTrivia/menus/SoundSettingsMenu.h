#pragma once
#include "..//Constants.h"
#include "..//ConfigManager.h"
#include "..//Utility.h"
#include <allegro.h>

class SoundSettingsMenu
{
public:
	SoundSettingsMenu(GameState* gs, ConfigManager* configManager);
	~SoundSettingsMenu();
	void showSoundSettingsMenu(BITMAP* buffer);
private:
	GameState* gameState;
	ConfigManager* configManager;
	BITMAP* bannerBitmap;
	BoundingBox backButton;
	BoundingBox applyButton; 
	int soundVolume;
	int musicVolume;
	const char** levels;
	BoundingBox* soundVolChangeArrows;
	BoundingBox* musicVolChangeArrows;
	void changeSoundSettings(int musicVol, int soundVol, GameState* gameState);
};

