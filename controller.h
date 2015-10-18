#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

#include <stdint.h>

#define CTRL_A      0
#define CTRL_B      1
#define CTRL_SELECT 2
#define CTRL_START  3
#define CTRL_UP     4
#define CTRL_DOWN   5
#define CTRL_LEFT   6
#define CTRL_RIGHT  7

#define PLAYER_1    0
#define PLAYER_2    1

typedef struct
{
    uint8_t LATCH, CLK, DATA;
    uint8_t buttons;
} Controller;

extern Controller CTRL[2];

void initControllers();
void getControllerState(uint8_t player);

#endif // __CONTROLLER_H__
