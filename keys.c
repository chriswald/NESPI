#include "keys.h"
#include <xdo.h>

xdo_t* x;

void initKeys()
{
	x = xdo_new(":0.0");
}

void keyDown(const char* keyseq)
{
	xdo_keysequence_down(x, CURRENTWINDOW, keyseq, 0);
}

void keyUp(const char* keyseq)
{
	xdo_keysequence_up(x, CURRENTWINDOW, keyseq, 0);
}