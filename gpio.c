#include <wiringPi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "pins.h"

#define CTRL_A      0
#define CTRL_B      1
#define CTRL_SELECT 2
#define CTRL_START  3
#define CTRL_UP     4
#define CTRL_DOWN   5
#define CTRL_LEFT   6
#define CTRL_RIGHT  7

#define US_DELAY 6

uint8_t CTRL[2];

void pulsePin(uint8_t pin);
void getControllerState(uint8_t ctrl);

int main()
{
   wiringPiSetup();

   pinMode(LATCH(1), OUTPUT);
   pinMode(CLK(1),   OUTPUT);
   pinMode(DATA(1),  INPUT);

   digitalWrite(LATCH(1), LOW);
   digitalWrite(CLK(1),   LOW);

   while (true)
   {
      uint8_t old = CTRL[1];
      getControllerState(1);
      
      if (old & 1 == 0 && CTRL[1] & 1 == 1)
	 printf("Pressed A");
   }

   return 0;
}

void pulsePin(uint8_t pin)
{
   digitalWrite(pin, HIGH);
   delayMicroseconds(US_DELAY);
   digitalWrite(pin, LOW);
}

void getControllerState(uint8_t num)
{
    CTRL[num] = 0;
    pulsePin(LATCH(num));
    CTRL[num] |= digitalRead(DATA(num)) << CTRL_A;
    pulsePIn(CLK(num));
    CTRL[num] |= digitalRead(DATA(num)) << CTRL_B;
    pulsePIn(CLK(num));
    CTRL[num] |= digitalRead(DATA(num)) << CTRL_SELECT;
    pulsePIn(CLK(num));
    CTRL[num] |= digitalRead(DATA(num)) << CTRL_START;
    pulsePIn(CLK(num));
    CTRL[num] |= digitalRead(DATA(num)) << CTRL_UP;
    pulsePIn(CLK(num));
    CTRL[num] |= digitalRead(DATA(num)) << CTRL_DOWN;
    pulsePIn(CLK(num));
    CTRL[num] |= digitalRead(DATA(num)) << CTRL_LEFT;
    pulsePIn(CLK(num));
    CTRL[num] |= digitalRead(DATA(num)) << CTRL_RIGHT;
}
