#ifndef USER_APP_H__
#define USER_APP_H__

#include <stdbool.h>
typedef struct  {
	bool is_advertising;
	bool is_connected;
	bool is_oled_enable;
	uint16_t cur_adc;
	uint8_t oled_data;
} user_app_config_t;

void drawble(uint8_t, uint8_t);

#endif
