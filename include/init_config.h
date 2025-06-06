#ifndef INIT_CONFIG_H
#define INIT_CONFIG_H

#define BUZZER_PIN 21
#define BUZZER_FREQUENCY 100

#include "ssd1306.h"

void display_init(ssd1306_t *ssd);

void buzzer_init();

void init_pins();

#endif