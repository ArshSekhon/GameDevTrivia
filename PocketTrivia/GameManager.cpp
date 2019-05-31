#include "GameManager.h"
#include "Constants.h"
#include "ConfigManager.h"

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

}

int GameManager::init() {
	// initialize allegro
	if (allegro_init() != 0) {
		allegro_message("ERROR: Failed to initialize Allegro.");
		return ERROR_ALLEGRO_INIT;
	}
	
	set_window_title("Game Dev: Pocket Trivia"); 

	// set handler to make the close button work
	LOCK_FUNCTION(close_button_handler);
	set_close_button_callback(close_button_handler); 
	// load configuration
	configManager.load_config(CONFIG_FILENAME);

	// Make sure game continues to run when not in focus
	// REFERENCE: https://www.allegro.cc/manual/4/api/graphics-modes/set_display_switch_mode
	set_display_switch_mode(SWITCH_BACKGROUND);

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

	//install keyboard
	if (install_keyboard() != 0) { 
		allegro_message("ERROR: Failed to install Keyboard.");
		return ERROR_ALLEGRO_KEYBOARD_INIT;
	}
	  
	textout_ex(screen, font, "Hello World!", 1, 1, 10, -1);
	textout_ex(screen, font, "Press ESCape to quit.", 1, 12, 11, -1); 
	rectfill(screen, 10, 10, 1000, 800, 11);
}

void GameManager::runGameLoop() {
	BITMAP* buffer = create_bitmap(resolution_x, resolution_y);

	while (!key[KEY_ESC] && !close_button_flag) {

		rectfill(screen, 10, 10, 1000, 800, 0);
		textprintf(screen, font, 200, 200, 11, "X:%d Y:%d", mouse_x, mouse_y);
		rest(60);
	}; 
}

void GameManager::exit() {
	allegro_exit();
}