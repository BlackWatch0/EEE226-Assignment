/*==========================================================================
This file define all the function need to control the light.
    wait()
    TSS_Monitor()
    rand_gen()
    TTS_InputAndCheck()
==========================================================================*/

#include "Broad.h"
#include "led_control.h"

/// @brief this is a software wait function
/// @param wait_ms How long the wait should be.(MAY NOT BE ACCURATE)
void wait(int wait_ms)
{
    unsigned int i, j;
    for (i = 0; i < wait_ms; i++)
    {
        for (j = 0; j < 785; j++)
        {
            __asm("nop");
        }
    }
}

/// @brief this function will monitor the Touchpad for an input
/// @return the touchpad positon inputed
uint8_t TSS_Monitor()
{
    TSS1_Configure();
    ispressed = 0;
    while (ispressed < 2)
    {
        TSS_Task();
    }
    return TSS1_cKey0.Position;
}

/// @brief          generate a random int in a certain range
/// @param Rand_MIN The lower limit of the random number
/// @param Rand_MAX The upper limit of the random number
/// @return         a random number in the limit
int rand_gen(int Rand_MIN, int Rand_MAX)
{
    return Rand_MIN + rand() % (Rand_MAX - Rand_MIN + 1);
}

/// @brief Input the white seq and check if they are right
/// @param sequence The initial light sequence
/// @param white_region The start of white
/// @param white_length The length of white
/// @return a flag indicate if the input light squence is same with the initial sequence
int TTS_InputAndCheck(int sequence[], int white_region, int white_length)
{
    int input_times = 0, input_light_num;
    uint8_t input_position;
    int i = 0;
    int input_seq[50] = {};

    // input
    for (input_times = 0; input_times < white_length + 1; input_times++)
    {
        input_position = TSS_Monitor();
        if (input_position < 56)
        {
            input_light_num = 1;
            set_led(PWM_MAX, PWM_OFF, PWM_OFF);
            wait(1000);
            set_led(PWM_OFF, PWM_OFF, PWM_OFF);
            wait(500);
        }
        else if (input_position < 200)
        {
            input_light_num = 2;
            set_led(PWM_OFF, PWM_MAX, PWM_OFF);
            wait(1000);
            set_led(PWM_OFF, PWM_OFF, PWM_OFF);
            wait(500);
        }
        else if (input_position >= 200)
        {
            input_light_num = 3;
            set_led(PWM_OFF, PWM_OFF, PWM_MAX);
            wait(1000);
            set_led(PWM_OFF, PWM_OFF, PWM_OFF);
            wait(500);
        }
        input_seq[input_times] = input_light_num;
    }

    // check if the input is right
    for (i = 0; i < white_length + 1; i++)
    {
        if (input_seq[i] != sequence[i + white_region])
            return 0;
    }
    return 1;
}
