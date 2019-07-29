#include "GameManager.h"
#include "Constants.h"
#include "ConfigManager.h"
#include "menus/MainMenu.h"

#include "entities/Quiz.h"

#include <allegro.h> 

ConfigManager configManager;

// close button
volatile int close_button_flag = 0;
void close_button_handler(void)
{
	close_button_flag = 1;
}
END_OF_FUNCTION(close_button_handler)


GameManager::GameManager(GameState* gs) { 
	gameState = gs;
	gs->gameScreen = GAME_SCREEN_LOADING;
	gs->gfxSettingsUpdated = 1;
	loadScreen = NULL;
	mainMenu = NULL;
	gfxSettingsMenu = NULL;
	cursor = NULL;
	cursorHand = NULL;
	pointerAsCursor = 0;
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
	configManager.load_config(CONFIG_FILENAME, gameState);

	// Make sure game continues to run when not in focus
	// REFERENCE: https://www.allegro.cc/manual/4/api/graphics-modes/set_display_switch_mode
	set_display_switch_mode(SWITCH_BACKGROUND);
	set_color_depth(32);
	// set GFX mode
	int gfx_mode = GFX_AUTODETECT_WINDOWED;
	if (gameState->fullscreen == 1) {
		gfx_mode = GFX_AUTODETECT_FULLSCREEN;
	} 

	//set_color_depth(32);
	if (set_gfx_mode(gfx_mode, gameState->resolution_x, gameState->resolution_y, 0, 0) != 0) {
		return ERROR_ALLEGRO_GFX_CHANGE;
	}


	// install sound 
	if (install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "") != 0) {
		allegro_message("ERROR: Failed to install sound.");
		return ERROR_ALLEGRO_SOUND_INIT;
	}
	set_volume(gameState->sound_volume * 25.5, gameState->music_volume * 25.5);

	//install mouse
	if (install_mouse() == -1) {
		allegro_message("ERROR: Failed to install Mouse.");
		return ERROR_ALLEGRO_KEYBOARD_INIT;
	}


	//load the custom mouse pointer
	cursorHand = load_bitmap("assets/ui-elem/cursor-hand.bmp", NULL);
	cursor = load_bitmap("assets/ui-elem/pointer.bmp", NULL);
	set_mouse_sprite(cursor);

	// set_mouse_sprite_focus(cursor->w / 2, cursor->h / 2); 

	//install keyboard
	if (install_keyboard() != 0) { 
		allegro_message("ERROR: Failed to install Keyboard.");
		return ERROR_ALLEGRO_KEYBOARD_INIT;
	} 



	mainMenu = new MainMenu(gameState);
	settingsMenu = new SettingsMenu(gameState);
	gfxSettingsMenu = new GFXSettingsMenu(gameState, &configManager);
	soundSettingsMenu = new SoundSettingsMenu(gameState, &configManager);
	creditsMenu = new CreditsMenu(gameState);
	gameModeSelectionMenu = new GameModeSelectionMenu(gameState);

	gameIntroScreen = new GameIntroScreen(gameState, &configManager);
	soundManager = new SoundManager(gameState);
	gameQuestionScreen = new GameQuestionScreen(gameState, soundManager);

	soundManager->playBgMusic(1);
	


	return 0;
}

void GameManager::runGameLoop() {
	BITMAP* buffer = NULL;
	
	while (!key[KEY_ESC] && !close_button_flag && !gameState->exitGame) {

		if (gameState->mouseHover == 1 && (mouse_b & 1) && gameState->pendingMouseClick==0) {
			soundManager->playSound(SOUND_CLICK, 1000);
		} 

		if ((mouse_b & 1)) {
			gameState->pendingMouseClick = 1;
		}
		if (gameState->gfxSettingsUpdated) {
			gameState->gfxSettingsUpdated = 0;
			buffer = create_bitmap(gameState->resolution_x, gameState->resolution_y);
			show_mouse(screen);
		}

		
	   renderFrameToScreen(buffer);
	   if (gameState->mouseHover == 1 && pointerAsCursor == 0) {
		   set_mouse_sprite(cursorHand);
		   pointerAsCursor = 1;
	   }
	   else if (gameState->mouseHover == 0 && pointerAsCursor == 1) {
		   set_mouse_sprite(cursor);
		   pointerAsCursor = 0;
	   }
	  
	   rest(30);
	}; 

}

void GameManager::exit() {
	allegro_exit();
}
 
void GameManager::bufferToScreen(BITMAP* buffer) {
}
void GameManager::renderFrameToScreen(BITMAP* buffer) {
	switch (gameState->gameScreen) {

	case GAME_SCREEN_LOADING:
		showLoadingScreen(buffer);
		break;
	case GAME_SCREEN_MAIN_MENU: 
		gameState->gameScreen = mainMenu->showMainMenu(buffer);
		break;
	case GAME_SCREEN_SETTINGS:
		settingsMenu->showSettingsMenu(buffer);
		break;
	case GAME_SCREEN_GFX_SETTINGS:
		gfxSettingsMenu->showGfxMenu(buffer);
		break;
	case GAME_SCREEN_SOUND_SETTINGS:
		soundSettingsMenu->showSoundSettingsMenu(buffer);
		break;
	case GAME_SCREEN_GAME_MODE_SELECTION:
		quiz = gameModeSelectionMenu->showGameModeMenu(buffer);
		break; 
	case GAME_SCREEN_QUIZ_START:
		gameIntroScreen->showIntroScreen(buffer);
		break;
	case GAME_SCREEN_QUESTION:
		if(quiz!= NULL)
		gameQuestionScreen->showQuestionScreen(buffer, quiz);
		break;
	case GAME_SCREEN_CREDITS:
		creditsMenu->showCreditsScreen(buffer);
		break;
	}

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

	gameState->gameScreen = GAME_SCREEN_MAIN_MENU;
}

