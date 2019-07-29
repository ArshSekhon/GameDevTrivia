#include "ConfigManager.h"
#include "entities/Quiz.h"   
#include "GameManager.h"
#include "Constants.h"
#include <stdio.h>
#include <allegro.h>

#define MAX_BYTES_PER_CHAR 4

#define LEN 32

#define WHITE makecol(255,255,255) 
int main(void) {  
	GameState gs;

	gs.resolution_x = 640;
	gs.resolution_y = 480;
	gs.fullscreen = 0;
	gs.sound_volume = 10;
	gs.music_volume = 10;
	gs.exitGame = 0;

	GameManager gameManager(&gs); 

	gameManager.init();
	gameManager.runGameLoop();
	gameManager.exit(); 
	return 0;
}
END_OF_MAIN()
