/**/
#include "ConfigManager.h"
#include "entities/Quiz.h"   
#include "GameManager.h"
#include "Constants.h"
#include <stdio.h>
#include <allegro.h>

#define MAX_BYTES_PER_CHAR 4

#define LEN 32

//using namespace std;

//#include <fstream>
//#include "Question.h"
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
	

	char the_text[] =
		"I'm text inside a text box.\n\n"
		"I can have multiple lines.\n\n"
		"If I grow too big to fit into my box, I get a scrollbar to "
		"the right, so you can scroll me in the vertical direction. I will never "
		"let you scroll in the horizontal direction, but instead I will try to "
		"word wrap the text.";

	DIALOG d =
	{
		d_textbox_proc,    100, 100,  400,   50,   0,  0,    0,      0,       0,   0,    (char*)(void*)the_text,       NULL, NULL
	};

	if (allegro_init() != 0)
		return 1;
	install_keyboard();
	install_mouse();

	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0) {
		if (set_gfx_mode(GFX_SAFE, 640, 480, 0, 0) != 0) {
			set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
			allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
			return 1;
		}
	}

	gui_fg_color = makecol(0, 0, 0);
	gui_mg_color = makecol(128, 128, 128);
	gui_bg_color = makecol(200, 240, 200);
	set_dialog_color(&d, gui_fg_color, gui_bg_color);


	d.bg = makecol(255, 255, 255);

	//position_dialog(&d, 2, 2);

	BITMAP* buffer = create_bitmap(640, 480);
	BITMAP* bmpScreen = gui_get_screen();

	while (true) {
		show_mouse(screen);
		gui_set_screen(buffer);

		DIALOG_PLAYER* player = init_dialog(&d, -1);

		if (!update_dialog(player))
		{
			// Do something with the dialog data
			shutdown_dialog(player);
		}
		gui_set_screen(bmpScreen);
		blit(buffer, screen, 0, 0, 0, 0, 640, 480);
		clear_bitmap(buffer);
	}

	allegro_exit();
	return 0;


}
END_OF_MAIN()
/**/

/*
#include <stdio.h>
#include <allegro.h>


#define MAX_BYTES_PER_CHAR 4

#define LEN 32

char sel[11];


char* listbox_getter(int index, int* list_size)
{
	static char* strings[] =
	{
	  (char*) "Zero",  (char*)"One",  (char*) "Two",   (char*)"Three", (char*)"Four",  (char*)"Five",
	  (char*) "Six",   (char*)"Seven", (char*)"Eight",(char*) "Nine",  (char*)"Ten"
	};

	if (index < 0) {
		*list_size = 11;
		return NULL;
	}
	else {
		return strings[index];
	}
}


DIALOG d =

{ d_list_proc,       160, 150,  160,   44,   0,  0,    0,      0,       0,   0,    (void*)listbox_getter, sel,  NULL };



int info1(BITMAP* buffer)
{
	char buf1[256];
	char buf2[256] = "";
	int i, s = 0, n;

	listbox_getter(-1, &n);

	for (i = 0; i < n; i++) {
		if (sel[i]) {
			uszprintf(buf1, sizeof buf1, "%i ", i);
			ustrzcat(buf2, sizeof buf2, buf1);
			s = 1;
		}
	}
	if (s)
		ustrzcat(buf2, sizeof buf2, "are in the multiple selection!");
	else
		ustrzcat(buf2, sizeof buf2, "There is no multiple selection!");
	uszprintf(buf1, sizeof buf1, "Item number %i is selected!",
		d.d1);
	
	//alert("Info about the list:", buf1, buf2, "Ok", NULL, 0, 0);

	textout_ex(buffer, font, buf1, 10, 10, makecol(255, 255, 255),-1);
	textout_ex(buffer, font, buf2, 10, 20, makecol(255, 255, 255),-1);

	return D_O_K;
}


int main(int argc, char* argv[])
{


	char the_string[(LEN + 1) * MAX_BYTES_PER_CHAR] = "Change Me!";

	if (allegro_init() != 0)
		return 1;
	install_keyboard();
	install_mouse();

	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0) != 0) {
		if (set_gfx_mode(GFX_SAFE, 640, 480, 0, 0) != 0) {
			set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
			allegro_message("Unable to set any graphic mode\n%s\n", allegro_error);
			return 1;
		}
	} 
	 
	gui_fg_color = makecol(0, 0, 0);
	gui_mg_color = makecol(128, 128, 128);
	gui_bg_color = makecol(200, 240, 200);
	set_dialog_color(&d, gui_fg_color, gui_bg_color);


	d.bg = makecol(255, 255, 255);

	//position_dialog(&d, 2, 2);

	BITMAP* buffer = create_bitmap(640, 480);
	BITMAP* bmpScreen = gui_get_screen(); 

	while(true){
		show_mouse(screen);
		gui_set_screen(buffer); 
		
		DIALOG_PLAYER* player = init_dialog(&d, -1);

		if (!update_dialog(player))
		{
			// Do something with the dialog data
			shutdown_dialog(player);
		}
		gui_set_screen(bmpScreen);
		info1(buffer);
		blit(buffer, screen, 0, 0, 0, 0, 640, 480);
		clear_bitmap(buffer); 
	}

	allegro_exit();
	return 0;
}
END_OF_MAIN()


*/
