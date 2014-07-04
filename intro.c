
#define TIMER   ((long*)0x020370BC)
#define init     ((u8*)0x020370B8)

#define save1				((u8 *)(*(u32*)0x03005008))

#define speed       (*(u8 *) 0x020370C8)

#include "include/gba_keys.h"
#include "include/gba_regs.h"

//326 is title screen song.

void Main()
{
	if(init[26] != 123)
	{
		speed = 1;
		if(init[26] == 0)
		{
			playSong(327);
		}
		if(init[26] == 122)
		{
			initMap(3,19,10,10);
			unfadeScreen();
		}
		
		init[26] = init[26]+1;
	}

	if(keyHeldDown(KEY_LEFT))
		setMapXVel(-speed);
	else if(keyHeldDown(KEY_RIGHT))
		setMapXVel(speed);
	else
		setMapXVel(0);

	if(keyHeldDown(KEY_UP))
		setMapYVel(-speed);
	else if(keyHeldDown(KEY_DOWN))
		setMapYVel(speed);
	else
		setMapYVel(0);

	if(keyPressed(KEY_B))
		fullRerender();

	if(keyPressed(KEY_L))
		speed = speed - 1;

	if(keyPressed(KEY_R))
		speed = speed + 1;

	updateMapRenderer();


	if(keyPressed(KEY_A) || keyPressed(KEY_START))
   	{
     	int (*func)(void) = (int (*)(void))0x0800CC6B;
		int x = func();
	}

	updateEverything();

	return;
}

#include <string.h>
#include "include/gba.h"
#include "useful.h"
#include "overworld.c"

