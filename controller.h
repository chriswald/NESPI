#include <stdint.h>

typedef struct
{
    uint8_t LATCH, CLK, DATA;
    uint8_t buttons;
} Controller;

extern Controller CTRL[2];
