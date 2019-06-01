#pragma once
#define CONFIG_FILENAME "PocketTrivia.cfg"

// GFX RESOLUTIONS

#define GFX_RES_1280_X_960 1
#define GFX_RES_960_X_720 2
#define GFX_RES_640_X_420 1

// Game states
#define GAME_STATE_LOAD_SCREEN 1
#define GAME_STATE_MAIN_MENU 2
#define GAME_STATE_OPTIONS_SCREEN 3
#define GAME_STATE_GFX_OPTIONS 4
#define GAME_STATE_SOUND_OPTIONS 5
#define GAME_STATE_GAME_MODE_SELECTION 6
#define GAME_STATE_QUIZ_START_SCREEN 7
#define GAME_STATE_QUESTION_SCREEN 8
#define GAME_STATE_RESULTS_SCREEN 9




// Error and Exception codes
#define EXCEPTION_READING_QUESTION_FILE 101
#define EXCEPTION_READING_ANSWER_FILE 102

#define ERROR_ALLEGRO_INIT 103
#define ERROR_ALLEGRO_SOUND_INIT 104
#define ERROR_ALLEGRO_KEYBOARD_INIT 105
#define ERROR_ALLEGRO_GFX_CHANGE 106


// colors

#define COLOR_BG makecol(18,39,34)




struct GameState {

	int resolution_x;
	int resolution_y;
	// full screen 
	int fullscreen;

	// sound settings
	int sound_volume;
	int music_volume;

	int gameState;
};