#include "config.h"
#include "keys.h"
#include "controller.h"

#include <stdio.h>

char buttonMapping[CTRL_BTNS][10];

void setupDefaultConfig();

void initConfig()
{
    FILE* fp;
    fp = fopen("keys.config", "r");

    if (fp == NULL)
    {
        setupDefaultConfig();
    }
    else
    {
        if (fscanf(fp, "%s %s %s %s %s %s %s %s", buttonMapping[0], 
                    buttonMapping[1], buttonMapping[2], buttonMapping[3],
                    buttonMapping[4], buttonMapping[5], buttonMapping[6],
                    buttonMapping[7]) != 8)
        {
            setupDefaultConfig();
        }
    }

    fclose(fp);
}

void setupDefaultConfig()
{

}

const char* keyFromButton(uint8_t button)
{
    if (button < CTRL_BTNS)
        return buttonMapping[button];
    else
        return "";
}
