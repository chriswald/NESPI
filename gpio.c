#include <wiringPi.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

#define LATCH1 4
#define CLK1   17
#define DATA1  27

#define CTRL_A      0
#define CTRL_B      1
#define CTRL_SELECT 2
#define CTRL_START  3
#define CTRL_UP     4
#define CTRL_DOWN   5
#define CTRL_LEFT   6
#define CTRL_RIGHT  7

#define US_DELAY 6

uint8_t CTRL1, CTRL2;

void pulsePin(uint8_t pin);

int main()
{
   wiringPiSetupGpio();

   pinMode(LATCH1, OUTPUT);
   pinMode(CLK1,   OUTPUT);
   pinMode(DATA1,  INPUT);

   digitalWrite(LATCH1, LOW);
   digitalWrite(CLK1,   LOW);

   while (true)
   {
      uint8_t old = CTRL1;
      CTRL1 = 0;
      pulsePin(LATCH1);
      CTRL1 |= digitalRead(DATA1) << CTRL_A;
      
      if (old == 0 && CTRL1 == 1)
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
