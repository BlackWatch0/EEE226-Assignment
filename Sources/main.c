/* ###################################################################
**     Filename    : main.c
**     Project     : assignment
**     Processor   : MKL25Z128VLK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2023-11-14, 14:24, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "RED_LED.h"
#include "TU1.h"
#include "GREEN_LED.h"
#include "BLUE_LED.h"
#include "TU2.h"
#include "TSS1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* User includes (#include below this line is not maintained by Processor Expert) */

#include "stdlib.h"
#include "led_control.h"
#include "Broad.h"

int ispressed = 0;

#include <stddef.h>

void *_sbrk(int incr)
{
	extern char end asm("end");
	static char *heap_end;
	char *prev_heap_end;

	if (heap_end == 0)
	{
		heap_end = &end;
	}

	prev_heap_end = heap_end;

	// Adjust the heap end
	heap_end += incr;

	return (void *)prev_heap_end;
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
	/* Write your local variable definition here */
	// varibal init
	//===============================================================================================================//
	int i, round, white_region, white_length = 1, rand_num;
	int response;
	int sequence[60] = {};
	int seed;
	//===============================================================================================================//

	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/

	/* Write your code here */
	/* For example: for(;;) { } */

	for (;;)
	{
		// init RGB
		set_led(PWM_OFF, PWM_OFF, PWM_OFF); // init LED
		wait(1000);

		// RGB waiting for start & generate a seed from noise
		seed = LED_RGB_Loop();

		// init game
		srand(seed * 1000+TSS1_cKey0.Position); // set the seed of the random num
		white_length = 0;	// reset white length

		// generate a initial 5 color
		for (i = 1; i < 5; i++)
		{
			rand_num = rand_gen(1, 3);
			sequence[i] = rand_num;
		}

		// sign for game start

		LED_Game_start();

		// game main
		for (round = 5; round < 55; round++)
		{
			wait(3000);

			white_length = round - 5;
			// add a number to the sequence
			sequence[round] = rand_gen(1, 3);

			// generate a white color region
			white_region = rand_gen(1, 5);

			// show the color sequence
			show_seq(round, sequence, white_region, white_length, 0);

			// a sign of continue the game
			wait(2000);
			LED_Game_continue();

			// show the modified color sequence
			show_seq(round, sequence, white_region, white_length, 1);
			wait(2000);

			// wait the user input
			response = TTS_InputAndCheck(sequence, white_region, white_length);

			if (response == 0) // wrong
			{
				LED_Game_over(); 
				break;
			} // game end
			else
			{
				LED_Game_continue();
			} // a sign of continue the game
		}
	}

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
#endif
	/*** End of RTOS startup code.  ***/
	/*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
	for (;;)
	{
	}
	/*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
