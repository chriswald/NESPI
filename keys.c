#include "keys.h"
#include "config.h"
#include <stdbool.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>

Display* display;

void initKeys()
{
   display = XOpenDisplay(NULL);
}

void keyDown(uint32_t button)
{
   unsigned int keycode;
   keycode = XKeysymToKeycode(display, keyFromButton(button));
   XTestFakeKeyEvent(display, keycode, true, 0);
}

void keyUp(uint32_t button)
{
   unsigned int keycode;
   keycode = XKeysymToKeycode(display, keyFromButton(button));
   XTestFakeKeyEvent(display, keycode, false, 0);
}
