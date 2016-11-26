
#include "ssd1306.h"
#include "icon.h"

void drawble(uint8_t px, uint8_t py) {
	uint8_t col, row, i, j, temp;
	uint8_t w = BT_WIDTH, h= BT_HEIGHT;
	col = px+2; row = py;
	for(i = 0; i < h; i++) {
		temp = bluetooth_icon[i];
		for(j = 0; j < 8; j++) {
			if(temp & 0x80)
				ssd1306_draw_pixel( col, row, 1);
			temp = temp << 1;
			row ++;
			if(row - py == h) {
				row = py;
				col ++;
				break;
			}
		}
	}
	ssd1306_draw_round_rect(px, py, 12, 16, 1, 1);
}

