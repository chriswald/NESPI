#ifndef __KEYS_H__
#define __KEYS_H__

#include <stdint.h>
#include <X11/keysym.h>

void initKeys();
void keyDown(uint32_t button);
void keyUp(uint32_t button);

#endif // __KEYS_H__
