#pragma once
#include "Constants.h"
#include <allegro.h> 
#include <math.h>

namespace Utility {
	extern int inTheBoundingBox(BoundingBox box);
	extern BoundingBox textout_magnified(BITMAP* bmp, FONT* font, int x, int y, double multiplier, const char* msg, int color, int bg);
	extern BoundingBox textout_centre_magnified(BITMAP* bmp, FONT* font, int x, int y, double multiplier, const char* msg, int color, int bg); 
	extern void draw_button(BITMAP* buffer, BITMAP* bitmapBg, BoundingBox box);
	extern BoundingBox create_arrow_left(BITMAP* buffer, int x, int y, int size, int color);
	extern BoundingBox create_arrow_right(BITMAP* buffer, int x, int y, int size, int color);
	extern DIALOG_PLAYER* draw_wrapping_text(BITMAP* bmp, FONT* fontForText, DIALOG* d, char* str, int x, int y, int w, int h, int color);
	extern void create_list(BITMAP* bmp, FONT* fontForText, DIALOG* d, void* listGetter, char* selectedElem, int x, int y, int w, int h, int color);
}