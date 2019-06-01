#include "GameManager.h"
#include "Constants.h"
#include "ConfigManager.h"
#include "MainMenu.h"

#include <allegro.h> 

ConfigManager configManager;

// close button
volatile int close_button_flag = 0;
void close_button_handler(void)
{
	close_button_flag = 1;
}
END_OF_FUNCTION(close_button_handler)


GameManager::GameManager() { 

	gameState = GAME_STATE_LOAD_SCREEN;
	loadScreen = NULL;
	mainMenu = NULL;
}
int filter(int c, int w, int h, int color_depth) {
	if (c == GFX_SAFE || c == GFX_AUTODETECT_FULLSCREEN || c == GFX_AUTODETECT_WINDOWED)
			return 0;
	return -1;
}



int GameManager::init() {
	// initialize allegro
	if (allegro_init() != 0) {
		allegro_message("ERROR: Failed to initialize Allegro.");
		return ERROR_ALLEGRO_INIT;
	}
	
	set_window_title("Game Development Trivia"); 

	// set handler to make the close button work
	LOCK_FUNCTION(close_button_handler);
	set_close_button_callback(close_button_handler); 
	// load configuration
	configManager.load_config(CONFIG_FILENAME);

	// Make sure game continues to run when not in focus
	// REFERENCE: https://www.allegro.cc/manual/4/api/graphics-modes/set_display_switch_mode
	set_display_switch_mode(SWITCH_BACKGROUND);
	set_color_depth(32);
	// set GFX mode
	int gfx_mode = GFX_SAFE;
	if (fullscreen == 1) {
		gfx_mode = GFX_AUTODETECT_FULLSCREEN;
	} 

	//set_color_depth(32);
	if (set_gfx_mode(gfx_mode, resolution_x, resolution_y, 0, 0) != 0) { 
		return ERROR_ALLEGRO_GFX_CHANGE;
	}


	// install sound 
	if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "") != 0) {
		allegro_message("ERROR: Failed to install sound.");
		return ERROR_ALLEGRO_SOUND_INIT;
	}
	set_volume(sound_volume * 25.5, music_volume * 25.5);

	//install mouse
	if (install_mouse() == -1) {
		allegro_message("ERROR: Failed to install Mouse.");
		return ERROR_ALLEGRO_KEYBOARD_INIT;
	}


	//load the custom mouse pointer
	BITMAP* cursor = load_bitmap("assets/ui-elem/cursor-hand.bmp", NULL);
	set_mouse_sprite(cursor);
	show_mouse(screen);

	// set_mouse_sprite_focus(cursor->w / 2, cursor->h / 2); 

	//install keyboard
	if (install_keyboard() != 0) { 
		allegro_message("ERROR: Failed to install Keyboard.");
		return ERROR_ALLEGRO_KEYBOARD_INIT;
	} 



	mainMenu = new MainMenu();


	return 0;
}

void GameManager::runGameLoop() {
	BITMAP* buffer = create_bitmap(resolution_x, resolution_y);  

	while (!key[KEY_ESC] && !close_button_flag) {

	   renderFrameToScreen(buffer);
	   rest(30);
	}; 
}

void GameManager::exit() {
	allegro_exit();
}
 
void GameManager::bufferToScreen(BITMAP* buffer) {
}
void GameManager::renderFrameToScreen(BITMAP* buffer) {
	switch (gameState) {

	case GAME_STATE_LOAD_SCREEN:
		showLoadingScreen(buffer);
		break;
	case GAME_STATE_MAIN_MENU: 
		gameState = mainMenu->showMainMenu(buffer);
		break;
	case GAME_STATE_OPTIONS_SCREEN:
		break;
	case GAME_STATE_GFX_OPTIONS:
		break;
	case GAME_STATE_SOUND_OPTIONS:
		break;
	case GAME_STATE_GAME_MODE_SELECTION:
		break; 
	case GAME_STATE_QUIZ_START_SCREEN:
		break;
	case GAME_STATE_QUESTION_SCREEN:
		break;
	case GAME_STATE_RESULTS_SCREEN:
		break;
	}

	//mouse coordinates
	textprintf(buffer, font, 10, 10, -1, "X:%d Y:%d", mouse_x, mouse_y);
}

 
void GameManager::showLoadingScreen(BITMAP* buffer) { 
	if(this->loadScreen == NULL)
		loadScreen = load_bitmap("assets/ui-elem/LoadScreenBanner.bmp", NULL);

	rectfill(buffer, 0, 0, SCREEN_W, SCREEN_H, COLOR_BG);
	if (SCREEN_W <= 640 || SCREEN_H <= 480) {
		masked_stretch_blit(loadScreen, buffer, 0, 0, loadScreen->w, loadScreen->h, SCREEN_W * 0.2, SCREEN_H * 0.2, SCREEN_W * 0.6, SCREEN_H * 0.6);
	}
	else {
		masked_stretch_blit(loadScreen, buffer, 0, 0, loadScreen->w, loadScreen->h, (SCREEN_W- loadScreen->w)/2 , (SCREEN_H- loadScreen->h) / 2, loadScreen->w, loadScreen->h);
	}

	//draw buffer to screen and clear buffer
	blit(buffer, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
	clear_bitmap(buffer);
	rest(1000);

	gameState = GAME_STATE_MAIN_MENU;
}

