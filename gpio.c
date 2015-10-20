#include <wiringPi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#include "controller.h"
#include "keys.h"
#include "config.h"

int main()
{
   initControllers();
   initKeys();
   initConfig();

   getControllerState(PLAYER_1);
   getControllerState(PLAYER_2);

   while (true)
   {
      for (int i = 0; i < NUM_PLAYERS; i ++)
      {
	 uint8_t old = CTRL[i].buttons;
	 getControllerState(i);
	 uint8_t new = CTRL[i].buttons;
	 
	 for (int j = 0; j < CTRL_BTNS; j ++)
	 {
	    if ((old & (1 << j)) && !(new & (1 << j)))
	    {
	       printf("A%d released\n", j);
	       //keyUp(j);
	    } 
	    else if ((new & (1 << j)) && !(old & (1 << j)))
	    {
	       printf("A%d pressed\n", j);
	       //keyDown(j);
	    }
	 }
      }
   }

   return 0;
}

