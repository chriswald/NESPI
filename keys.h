#ifndef __KEYS_H__
#define __KEYS_H__

#define K_W     "W"
#define K_A     "A"
#define K_S     "S"
#define K_D     "D"
#define K_Up    "Up"
#define K_Left  "Left"
#define K_Down  "Down"
#define K_Right "Right"

void initKeys();
void keyDown(const char* keyseq);
void keyUp(const char* keyseq);

#endif // __KEYS_H__
