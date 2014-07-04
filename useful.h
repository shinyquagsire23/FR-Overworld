#define BG_PaletteMem          ((u16*)0x020371F8) // Background Palette(256/16 colors) (adjusted for FR callback)
#define BG_PaletteMem2          ((u16*)0x020375F8) // Background Palette(256/16)

typedef struct
{
	u16 x, y;
} Position;

typedef struct
{
	u8 y, flags, x, msbXFlags;
	u16 tileProPal, irrelivant;
} Oam;

typedef struct
{
	Oam oam;
	u32 animation;
	u8 fC, fD, fE, fF;
	u32 f10, objectTemplate, f18, callback;
	Position pos1, pos2;
	u8 pos3x, pos3y, animNr, animFrame, time, f2D;
	Position iPos, iVel;
	u32 derp1, derp2;
	u8 f42, f43, end;
} OamThingy;

typedef struct
{
	u16 f0, f1;
	u32 oam, animation, gfx, animation2, callback;
	u8 end;
} ObjTemplate;

void updateEverything()
{
        int (*callback3)(void) = (int (*)(void))0x08077579;
        callback3();

        int (*callbackOAM)(void) = (int (*)(void))0x08006B5D; //call_back_oam
        callbackOAM();

        int (*writeOAM)(void) = (int (*)(void))0x08006BA9; //write oam
        writeOAM();

        int (*func4)(void) = (int (*)(void))0x080704D1; //idk
        func4();
}

u32 createSprite(int *addr2, int *XPos, int *YPos, int *i)
{
	int (*func2)(u32,u16,u16,u8) = (int (*)(u8))0x08006F8D;
	u32 result = func2(addr2,XPos,YPos,0);
	return result;

}

void loadGFX(int *addr)
{
	int (*func)(u32) = (int (*)(void))0x080086DD; //load_gfx
	func(addr);
}

void loadCompressedGFX(void *addr)
{
	int (*func)(u32) = (int (*)(void))0x0800F035; //load_gfx
	func(addr);
}

int random(int max)
{
	int i = rando();
	i = modulo(i, max);
	return i;
}

int rando()
{
	int (*func)(void) = (int (*)(void))0x08044EC9;
	return func();
}

int modulo(int *input, int *dividend)
{
	int (*func)(void) = (int (*)(void))0x081E4685;
	return func();
}

int spawnOamFromUnk(int *unknown, u8 *x, u8 *y, u8 *derp)
{
	int (*func)(void) = (int (*)(void))0x08006F8D;
	return func();
} __attribute__((__call_from_r4))

void unfadeScreen()
{
	fadeScreen2(0xFFFFFFFF,0x0,0x10,0,0x0000);
}

void fadeScreen()
{
	fadeScreen2(0xFFFFFFFF,0x0,0,0x10,0x0000);
}

void unfadeScreenWhite()
{
	fadeScreen2(0xFFFFFFFF,0x0,0x10,0,0x7FFF);
}

void fadeScreenWhite()
{
	fadeScreen2(0xFFFFFFFF,0x0,0,0x10,0x7FFF);
}

void fadeScreen2(int *bitmask, int *r1, int *r2, int *r3, int *color)
{

	int (*func)(u32,u16,u16,u16,u16) = (int (*)(void))0x08070589;
	func(bitmask,r1,r2,r3,color);

}

void fadeScreenFast()
{
	/*__asm("mov r0, #0x1");
	__asm("mov r1, #0x0");
	int (*func)(void) = (int (*)(void))0x0807A819;
	int x = func();*/
	fadeScreen();
}

void fadeSong()
{
	__asm("mov r0, #0x4");
	int (*func)(void) = (int (*)(void))0x0806b155;
	int x = func();
}

void copyPal(void *source, u8 num)
{
	copyMem(source,BG_PaletteMem+(num*0x10),0x8);
	copyMem(source,BG_PaletteMem2+(num*0x10),0x8);
}

void copyMem(void *source, void *dest, void *size)
{
	__asm("mov r2, #0x8");
	SystemCall(0xC);
}

void playSong(int *songNum)
{
	int (*func)(void) = (int (*)(void))0x081DD0F5;
	int x = func();
}

void playCry(int *pkmnNum, int *fx)
{
	int (*func)(void) = (int (*)(void))0x08071dF1;
	int x = func();
}

void playSound(int *fxNum)
{
	int (*func)(void) = (int (*)(void))0x080722CD;
	int x = func();
}

void drawText(int *foo, int *font, int *x, int *y, int *bar, int *baz, long *str)
{
	//__asm("str r4, [SP,#0xBC]");
	//__asm("str r5, [SP,#0xBC+4]");
	//__asm("str r6, [SP,#0xBC+8]");
	int (*func)(void) = (int (*)(void))0x0812E51D;
	int i = func();
}

void changeIO(int *a, int *b)
{
	int (*func)(void) = (int (*)(void))0x08000A39;
	int i = func();
}

void something2(int *a, int *b, int *c)
{
	int (*func)(void) = (int (*)(void))0x08001B91;
	int i = func();
}

void something(int *a, int *b, int *c)
{
	int (*func)(void) = (int (*)(void))0x080F6F1D;
	int i = func();
}

void clearOAM()
{
	int (*func)(void) = (int (*)(void))0x08006B11;
	int i = func();
}

void oam_rotate(u8 oam, u16 x, u16 y, u16 rot)
{
	int (*func)(u8,u16,u16,u16) = (int (*)(void))0x08075859;
	func(oam,x,y,rot);
}

/*void resetVars()
{
	TIMER[0] = 0;
	TIMER[1] = 0;
	for(int i = 0; i < 90; i++)
	{
		VAR[i] = 0;
	}
}
 Removed cuz buggy.*/

void deleteOAM(int oamNum)
{
	int j = 0x0202063C;
	oamNum = oamNum * 0x44;
	oamNum = oamNum + j;
	deleteOAM_sys(oamNum);
}

void deleteOAM_sys(int *oamNum)
{
	int (*func)(void) = (int (*)(void))0x08007281;
	int i = func();
}

