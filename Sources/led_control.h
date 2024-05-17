#include "Events.h"
#include "RED_LED.h"
#include "TU1.h"
#include "GREEN_LED.h"
#include "BLUE_LED.h"
#include "TU2.h"
#include "TSS1.h"
#include "Broad.h"


int LED_RGB_Loop();
void LED_Game_start();
void LED_Game_over();
void LED_Game_continue();
void set_led(uint16_t PWM_Red, uint16_t PWM_Green, uint16_t PWM_Blue);
void show_seq(int round, int sequence[], int white_region, int white_length,int white_enable);
