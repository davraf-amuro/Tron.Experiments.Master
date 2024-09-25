// config.h
#ifndef CONFIG_H
#define CONFIG_H

#include "oled_decorator.h"

// parametri per il display OLED
#define OLED_ADDR 0x3C
#define OLED_WIDTH 128
#define OLED_HEIGHT 32
#define OLED_RESET -1 // Reset pin (usato -1 se non collegato)

#define LED_FLASHING 23

extern unsigned long previousMillis; // Dichiarazione della variabile globale
extern const long interval; // Dichiarazione della variabile globale
extern OledDecorator oledDecorator; // Dichiarazione dell'oggetto globale

#endif
