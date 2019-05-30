#include <allegro.h> 

//#include <fstream>
//#include "Question.h"
#define WHITE makecol(255,255,255)

int main(void) {
	//Question question();
	allegro_init();
	//set_color_depth(32);
	allegro_message("hello");
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	install_keyboard();
	//textout_ex(screen, font, "Hello World! "+SCREEN_H, 10, 10, 10, -1);
	textout_ex(screen, font, "Press ESCape to quit. ", 10, 22, 11, -1);
	textprintf_ex(screen, font, 10,10, 10, -1, "Resolution: %d x %d", screen->w, screen->h);
	rectfill(screen, 960, 10, 1100, 600, WHITE);
	while (!key[KEY_ESC]) {};
	allegro_exit();
	return 0;
}
END_OF_MAIN()