#pragma once
#include "Constants.h"
#include <allegro.h> 
#include <math.h>

namespace Utility {
	extern int inTheBoundingBox(BoundingBox box);
	extern BoundingBox textout_magnified(BITMAP* bmp, FONT* font, int x, int y, double multiplier, const char* msg, int color, int bg);
	extern BoundingBox textout_centre_magnified(BITMAP* bmp, FONT* font, int x, int y, double multiplier, const char* msg, int color, int bg);
	extern BoundingBox create_arrow_left(BITMAP* buffer, int x, int y, int size, int color);
	extern BoundingBox create_arrow_right(BITMAP* buffer, int x, int y, int size, int color);
	extern void draw_wrapping_text(BITMAP* bmp, FONT* fontForText, DIALOG* d, char* str, int x, int y, int w, int h, int color);
}