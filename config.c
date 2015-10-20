#include "config.h"
#include "keys.h"
#include "controller.h"

#include <stdio.h>
#include <stdint.h>

uint32_t buttonMapping[CTRL_BTNS];

void setupDefaultConfig();

void initConfig()
{
   setupDefaultConfig();
}

void setupDefaultConfig()
{
   buttonMapping[0] = XK_K;
   buttonMapping[1] = XK_J;
   buttonMapping[2] = XK_space;
   buttonMapping[3] = XK_Return;
   buttonMapping[4] = XK_W;
   buttonMapping[5] = XK_S;
   buttonMapping[6] = XK_A;
   buttonMapping[7] = XK_D;
}

uint32_t keyFromButton(uint8_t button)
{
    if (button < CTRL_BTNS)
        return buttonMapping[button];
    else
        return 0;
}
