//
// Test input from buttons
//

#ifndef GBA_KEYS_H
#define GBA_KEYS_H

#include "gba_types.h"

#define KEY_A      0x01
#define KEY_B      0x02
#define KEY_SELECT 0x04
#define KEY_START  0x08
#define KEY_RIGHT  0x10
#define KEY_LEFT   0x20
#define KEY_UP     0x40
#define KEY_DOWN   0x80
#define KEY_R      0x01
#define KEY_L      0x02

//FIRE RED AREAS
#define KEYS            *(volatile u8*)0x0300311E
#define KEYSHOLD        *(volatile u8*)0x0300311C
#define KEYSSCROLL      *(volatile u8*)0x03003120
#define KEYSLR          *(volatile u8*)0x0300311F
#define KEYSHOLDLR      *(volatile u8*)0x0300311D
#define KEYSSCROLLLR    *(volatile u8*)0x03003121
//

#define keyPressed(k)     (KEYS & k)
#define keyHeldDown(k)    (KEYSHOLD & k)
#define keyScrolling(k)   (KEYSSCROLL & k)
#define keyPressedLR(k)   (KEYSLR & k)
#define keyHeldDownLR(k)  (KEYSHOLDLR & k)
#define keyScrollingLR(k) (KEYSSCROLLLR & k)

#endif
