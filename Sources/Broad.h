#include "TSS1.h"
#include "stdio.h"
#include "Events.h"

//define the Maxiunm light strength
#define PWM_MAX ((uint16_t)0xC350)
#define PWM_OFF ((uint16_t)0x0000)

void wait(int wait_ms);
uint8_t TSS_Monitor();
int rand_gen(int Rand_MIN, int Rand_MAX);
int TTS_InputAndCheck(int sequence[], int white_region, int white_length);
