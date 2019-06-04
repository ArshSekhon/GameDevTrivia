#pragma once
#include "Constants.h"
#include <allegro.h>

class SoundManager
{
private:
	MIDI* bgMusic;
	SAMPLE* cheeringSound;
	SAMPLE* clickSound;
	SAMPLE* buzzerSound;
	SAMPLE* boingSound;
	GameState* gameState;
public:
	SoundManager(GameState* gameState);
	void playBgMusic(int loop);
	void stopBgMusic(void);
	void playSound(int sfxId, int freq);
};