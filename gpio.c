#include <wiringPi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "controller.h"

int main()
{
   initControllers();

   while (true)
   {
      uint8_t old = CTRL[PLAYER_0].buttons;
      getControllerState(PLAYER_0);
      
      if (old & 1 == 0 && CTRL[PLAYER_0].buttons & 1 == 1)
	 printf("Pressed A");
   }

   return 0;
}

