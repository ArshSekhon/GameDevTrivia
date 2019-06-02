#pragma once
#include <allegro.h>
#include <winalleg.h> 
#include "../Constants.h"  
#include "../ConfigManager.h"
#include "../Utility.h"

class GFXSettingsMenu
{
public:
	GFXSettingsMenu(GameState* gs, ConfigManager* configManager);
	int showGfxMenu(BITMAP* buffer);
	~GFXSettingsMenu();
private:
	GameState* gameState;
	ConfigManager* configManager;
	BITMAP* bannerBitmap; 
	BoundingBox backButton;
	BoundingBox applyButton;
	const char** gfxResOptions;
	const char** gfxScreenModeOptions;
	int gfxResolutionMode;
	int gfxScreenMode;
	BoundingBox* resolutionChangeArrows;
	BoundingBox* screenModeChangeArrows;
	void changeGfxMode(BITMAP* buffer, int gfxRes, int screenMode, GameState* gameState);
};

