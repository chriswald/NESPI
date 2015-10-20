#include "controller.h"
#include "pins.h"
#include <wiringPi.h>

#define US_DELAY 6

Controller CTRL[2];

void pulsePin(uint8_t pin, uint8_t duration);

void initControllers()
{
    wiringPiSetup();
    
    CTRL[PLAYER_1].LATCH = LATCH1;
    CTRL[PLAYER_1].CLK = CLK1;
    CTRL[PLAYER_1].DATA = DATA1;

    pullUpDnControl(CTRL[PLAYER_1].LATCH, PUD_OFF);
    pullUpDnControl(CTRL[PLAYER_1].CLK,   PUD_OFF);
    pullUpDnControl(CTRL[PLAYER_1].DATA,  PUD_OFF);
    
    pinMode(CTRL[PLAYER_1].LATCH, OUTPUT);
    pinMode(CTRL[PLAYER_1].CLK,   OUTPUT);
    pinMode(CTRL[PLAYER_1].DATA,  INPUT);

    digitalWrite(CTRL[PLAYER_1].LATCH, LOW);
    digitalWrite(CTRL[PLAYER_1].CLK,   LOW);
}

void getControllerState(uint8_t player)
{
    CTRL[player].buttons = 0;
    pulsePin(CTRL[player].LATCH, 2*US_DELAY);
    CTRL[player].buttons |= digitalRead(CTRL[player].DATA) << CTRL_A;
    pulsePin(CTRL[player].CLK, US_DELAY);
    CTRL[player].buttons |= digitalRead(CTRL[player].DATA) << CTRL_B;
    pulsePin(CTRL[player].CLK, US_DELAY);
    CTRL[player].buttons |= digitalRead(CTRL[player].DATA) << CTRL_SELECT;
    pulsePin(CTRL[player].CLK, US_DELAY);
    CTRL[player].buttons |= digitalRead(CTRL[player].DATA) << CTRL_START;
    pulsePin(CTRL[player].CLK, US_DELAY);
    CTRL[player].buttons |= digitalRead(CTRL[player].DATA) << CTRL_UP;
    pulsePin(CTRL[player].CLK, US_DELAY);
    CTRL[player].buttons |= digitalRead(CTRL[player].DATA) << CTRL_DOWN;
    pulsePin(CTRL[player].CLK, US_DELAY);
    CTRL[player].buttons |= digitalRead(CTRL[player].DATA) << CTRL_LEFT;
    pulsePin(CTRL[player].CLK, US_DELAY);
    CTRL[player].buttons |= digitalRead(CTRL[player].DATA) << CTRL_RIGHT;
    CTRL[player].buttons = ~CTRL[player].buttons;
}

void pulsePin(uint8_t pin, uint8_t duration)
{
   digitalWrite(pin, HIGH);
   delayMicroseconds(duration);
   digitalWrite(pin, LOW);
}
