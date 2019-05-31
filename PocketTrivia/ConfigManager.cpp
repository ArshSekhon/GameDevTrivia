#include "ConfigManager.h"
#include <allegro.h>

/*
load_config
Accepts: Configuration File Name
Loads config from config file into globals
*/
void ConfigManager::load_config(const char* configFile) {
	push_config_state();
	set_config_file(configFile);
	//get resolution settings
	resolution_x = get_config_int("GRAPHICS", "resolution_x", resolution_x);
	resolution_y = get_config_int("GRAPHICS", "resolution_y", resolution_y);
	//get fullscreen settings
	fullscreen = get_config_int("GRAPHICS", "fullscreen", fullscreen);

	//get settings for sound
   sound_volume = get_config_int("SOUND", "sound_volume", sound_volume);
   music_volume = get_config_int("SOUND", "music_volume", music_volume);

   pop_config_state();

}

/*
write_config
Accepts: Configuration File Name
Writes config into config file from globals
*/
void ConfigManager::save_config(const char* configFile) {
	push_config_state();
	set_config_file(configFile);
	//save resolution settings
	set_config_int("GRAPHICS", "resolution_x", resolution_x);
	set_config_int("GRAPHICS", "resolution_y", resolution_y);
	//save fullscreen settings
	set_config_int("GRAPHICS", "fullscreen", fullscreen);
	//save settings for sound
	set_config_int("SOUND", "sound_volume", sound_volume);
	set_config_int("SOUND", "music_volume", music_volume);
	pop_config_state();

}