#include "ConfigManager.h"
#include <allegro.h>

/*
load_config
Accepts: Configuration File Name
Loads config from config file into globals
*/
void ConfigManager::load_config(const char* configFile, GameState* gs) {
	push_config_state();
	set_config_file(configFile);
	//get resolution settings
	gs->resolution_x = get_config_int("GRAPHICS", "resolution_x", gs->resolution_x);
	gs->resolution_y = get_config_int("GRAPHICS", "resolution_y", gs->resolution_y);
	//get fullscreen settings
	gs->fullscreen = get_config_int("GRAPHICS", "fullscreen", gs->fullscreen);

	//get settings for sound
	gs->sound_volume = get_config_int("SOUND", "sound_volume", gs->sound_volume);
	gs->music_volume = get_config_int("SOUND", "music_volume", gs->music_volume);

   pop_config_state();

}

/*
write_config
Accepts: Configuration File Name
Writes config into config file from globals
*/
void ConfigManager::save_config(const char* configFile, GameState* gs) {
	push_config_state();
	set_config_file(configFile);
	//save resolution settings
	set_config_int("GRAPHICS", "resolution_x", gs->resolution_x);
	set_config_int("GRAPHICS", "resolution_y", gs->resolution_y);
	//save fullscreen settings
	set_config_int("GRAPHICS", "fullscreen", gs->fullscreen);
	//save settings for sound
	set_config_int("SOUND", "sound_volume", gs->sound_volume);
	set_config_int("SOUND", "music_volume", gs->music_volume);
	pop_config_state();

}