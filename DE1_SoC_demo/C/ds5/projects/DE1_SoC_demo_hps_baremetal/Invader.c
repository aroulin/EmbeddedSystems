#include "Invader.h"
#include <stdint.h>
#include "Sprite.h"

uint32_t invader_pixels[FIXED_INVADER_SPRITE_WIDTH/4 * FIXED_INVADER_SPRITE_HEIGHT] = {
		0x00000000, 0x00000000, 0x1c1c0000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001c1c, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x1c1c0000, 0x0000001c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c000000, 0x00001c1c, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x1c000000, 0x00001c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c0000, 0x0000001c, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x001c1c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c1c00, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x1c1c1c00, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x001c1c1c, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x1c1c0000, 0x0000001c, 0x00000000, 0x00000000, 0x1c000000, 0x00001c1c, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x1c1c1c00, 0x00001c1c, 0x00000000, 0x00000000, 0x1c1c0000, 0x001c1c1c, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x1c000000, 0x1c1c1c1c, 0x001c1c1c, 0x00000000, 0x00000000, 0x1c1c1c00, 0x1c1c1c1c, 0x0000001c, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x1c1c0000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00001c1c, 0x1c1c0000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00001c1c, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x1c1c1c00, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x001c1c1c, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0xe0e0e0e0, 0xffffe0e0, 0xe0e0ffff, 0x1c1c1c1c, 0x1c1c1c1c, 0xe0e0e0e0, 0xffffffff, 0xe0e0e0e0, 0x00000000, 0x00000000,
		0x00000000, 0xe0000000, 0xe0e0e0e0, 0xffffe0e0, 0xe0e0ffff, 0x1c1c1c1c, 0x1c1c1c1c, 0xe0e0e0e0, 0xffffffff, 0xe0e0e0e0, 0x000000e0, 0x00000000,
		0x00000000, 0x1c1c0000, 0xe0e01c1c, 0xffe0e0e0, 0xe0e0ffff, 0xe0e0e0e0, 0xe0e0e0e0, 0xe0e0e0e0, 0xffffffe0, 0x1c1ce0e0, 0x00001c1c, 0x00000000,
		0x00000000, 0x1c1c1c00, 0xe0e01c1c, 0xe0e0e0e0, 0xe0e0ffff, 0xe0e0e0e0, 0xe0e0e0e0, 0xe0e0e0e0, 0xffffe0e0, 0x1c1ce0e0, 0x001c1c1c, 0x00000000,
		0x00000000, 0x1c1c1c1c, 0xe0e01c1c, 0xe0e0e0e0, 0xe0e0e0e0, 0x1c1c1c1c, 0x1c1c1c1c, 0xe0e0e0e0, 0xe0e0e0e0, 0x1c1ce0e0, 0x1c1c1c1c, 0x00000000,
		0x1c000000, 0x1c1c1c1c, 0xe0e01c1c, 0xe0e0e0e0, 0xe0e0e0e0, 0x1c1c1c1c, 0x1c1c1c1c, 0xe0e0e0e0, 0xe0e0e0e0, 0x1c1ce0e0, 0x1c1c1c1c, 0x0000001c,
		0x1c1c0000, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x00001c1c,
		0x1c1c1c00, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x001c1c1c,
		0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c,
		0x1c1c1c1c, 0x1c00001c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c00001c, 0x1c1c1c1c,
		0x1c1c1c1c, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x1c1c1c1c,
		0x1c1c1c1c, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x1c1c1c1c,
		0x1c1c1c1c, 0x00000000, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x00000000, 0x1c1c1c1c,
		0x1c1c1c1c, 0x00000000, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x00000000, 0x1c1c1c1c,
		0x1c1c1c1c, 0x00000000, 0x1c1c1c1c, 0x00001c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c0000, 0x1c1c1c1c, 0x00000000, 0x1c1c1c1c,
		0x1c1c1c1c, 0x00000000, 0x1c1c1c1c, 0x00001c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c0000, 0x1c1c1c1c, 0x00000000, 0x1c1c1c1c,
		0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x1c000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x0000001c, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x00000000,
		0x00000000, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x00000000,
	};


uint32_t invader_pixels2[FIXED_INVADER_SPRITE_WIDTH/4 * FIXED_INVADER_SPRITE_HEIGHT] ={
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c000000, 0x0000001c, 0x1c000000, 0x0000001c, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c0000, 0x0000001c, 0x1c000000, 0x00001c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c1c00, 0x00000000, 0x00000000, 0x001c1c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x001c1c1c, 0x00000000, 0x00000000, 0x1c1c1c00, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x1c000000, 0x00001c1c, 0x00000000, 0x00000000, 0x1c1c0000, 0x0000001c, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x1c1c0000, 0x0000001c, 0x00000000, 0x00000000, 0x1c000000, 0x00001c1c, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x1c1c1c00, 0x00001c1c, 0x00000000, 0x00000000, 0x1c1c0000, 0x001c1c1c, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x1c000000, 0x1c1c1c1c, 0x001c1c1c, 0x00000000, 0x00000000, 0x1c1c1c00, 0x1c1c1c1c, 0x0000001c, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x1c1c0000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00001c1c, 0x1c1c0000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00001c1c, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x1c1c1c00, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x001c1c1c, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0xe0e0e0e0, 0xffffffff, 0xe0e0e0e0, 0x1c1c1c1c, 0x1c1c1c1c, 0xffffe0e0, 0xe0e0ffff, 0xe0e0e0e0, 0x00000000, 0x00000000,
	0x00000000, 0xe0000000, 0xe0e0e0e0, 0xffffffff, 0xe0e0e0e0, 0x1c1c1c1c, 0x1c1c1c1c, 0xffffe0e0, 0xe0e0ffff, 0xe0e0e0e0, 0x000000e0, 0x00000000,
	0x00000000, 0x1c1c0000, 0xe0e01c1c, 0xe0ffffff, 0xe0e0e0e0, 0xe0e0e0e0, 0xe0e0e0e0, 0xffffe0e0, 0xe0e0e0ff, 0x1c1ce0e0, 0x00001c1c, 0x00000000,
	0x00000000, 0x1c1c1c00, 0xe0e01c1c, 0xe0e0ffff, 0xe0e0e0e0, 0xe0e0e0e0, 0xe0e0e0e0, 0xffffe0e0, 0xe0e0e0e0, 0x1c1ce0e0, 0x001c1c1c, 0x00000000,
	0x00000000, 0x1c1c1c1c, 0xe0e01c1c, 0xe0e0e0e0, 0xe0e0e0e0, 0x1c1c1c1c, 0x1c1c1c1c, 0xe0e0e0e0, 0xe0e0e0e0, 0x1c1ce0e0, 0x1c1c1c1c, 0x00000000,
	0x1c1c1c1c, 0x1c1c1c1c, 0xe0e01c1c, 0xe0e0e0e0, 0xe0e0e0e0, 0x1c1c1c1c, 0x1c1c1c1c, 0xe0e0e0e0, 0xe0e0e0e0, 0x1c1ce0e0, 0x1c1c1c1c, 0x1c1c1c1c,
	0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c,
	0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c,
	0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c,
	0x1c1c1c1c, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x1c1c1c1c,
	0x1c1c1c1c, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x1c1c1c1c,
	0x1c1c1c1c, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x1c1c1c1c,
	0x1c1c1c1c, 0x00000000, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x00000000, 0x1c1c1c1c,
	0x00000000, 0x00000000, 0x1c1c1c1c, 0x00001c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c0000, 0x1c1c1c1c, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x1c1c1c1c, 0x00001c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c0000, 0x1c1c1c1c, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x1c000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x0000001c, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x1c1c1c1c, 0x1c1c1c1c, 0x00000000, 0x00000000, 0x00000000,
	0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
};

Invader invaders[NUMBER_INVADER_Y][NUMBER_INVADER_X];

void Invaders_init(void){

	int i = 0;
	int j = 0;
	for(i = 0; i < NUMBER_INVADER_Y; ++i){
		for (j = 0; j < NUMBER_INVADER_X; ++j) {
			invaders[i][j].x =  j * (FIXED_INVADER_GAP_X);
			invaders[i][j].y = i * (FIXED_INVADER_GAP_Y);
			invaders[i][j].alive = true;
			invaders[i][j].sprite.w = FIXED_INVADER_SPRITE_WIDTH;
			invaders[i][j].sprite.h = FIXED_INVADER_SPRITE_HEIGHT;
			invaders[i][j].sprite.pixels = invader_pixels;
		}

	}
}