#define mapMem				((u8 *)(*(u32*)0x03005008))
#define saveX				(*(u16 *)(*(u32*)0x03005008))
#define saveY				(*(u16 *)((*(u32*)0x03005008)+2))
#define mem 				(*(u32*)0x020370FC)		
#define mapLoadingState     ((u8 *)0x03003528)

#define mapAx				(*(u16*)(mem))
#define mapAy				(*(u16*)(mem+2))

#define mapxVel				(*(u32*)(mem+8))
#define mapyVel				(*(u32*)(mem+12))

#define mapX 				(*(u16*)(*(u32*)0x03005008))
#define mapY 				(*(u16*)((*(u32*)0x03005008)+2))

#define playerNPCID			(*(u8*)0x0203707D)

void initMap(u8 bank, u8 map, u8 x, u8 y)
{
	//if(mem != 0)
		//free(mem);
	mem = 0x020D0000;//Overriding here because malloc apparently can't actually give me a non-allocated area .-. //malloc(0x2000);
	(*(u8*)0x0203ADFA) = 3; //Disables map sign thingies on entry. Also gives some nice letterboxing bars if set to 2
	flag_set_(0x4001); //Disable map music change on map change
	(*(u32*)0x03005020) = 0x08059B8F; //Disable initial map music

	mapMem[4] = bank;
	mapMem[5] = map;
	saveX = x;
	saveY = y;

	doMapLoad();
	(*(u32*)0x03005050) = 0;
	(*(u16*)0x03000FC0) = 327; //Map music
}

void setMapXVel(u32 vel)
{
	mapxVel = vel;
}

void setMapYVel(u32 vel)
{
	mapyVel = vel;
}

void doMapLoad()
{
	mapLoadingState[0] = 0;
	int (*mapLoadLoop)(u32) = (int (*)(void))0x08056E5C+1;
	mapLoadLoop(0x03003528);
}

void updateMapRenderer()
{
	moveCam();
	doTheThing();
}

void fullRerender()
{
	int (*drawMap)(void) = (int (*)(void))0x0805A684+1;
	drawMap();
}


void moveCam()
{
	int (*updateCam)(void) = (int (*)(void))0x0805ABB0+1;

	mapAx = mapAx + mapxVel*2;
	mapAy = mapAy + mapyVel*2;
	(*(u32*)0x03005058) = mapxVel;
	(*(u32*)0x0300505C) = mapyVel;

	updateCam();

	init[0] = init[0] + 1;
}

void doTheThing()
{
	coro_del_(coro_getid_(0x0806E83C+1)); //Prevents random wild cries
	npc_hide_(0x02036E38+(((playerNPCID << 3) + playerNPCID) << 2));
	(*(u32*)0x03005020) = 0x08059B8F; //Disable initial map music
	int (*func2)(void) = (int (*)(void))0x0805ABB0+1;
	int (*func3)(void) = (int (*)(void))0x08115798+1;
	int (*adjustOverworlds)(void) = (int (*)(void))0x0805AE28+1;
	int (*func7)(void) = (int (*)(void))0x0806FFBC+1;
	int (*func8)(void) = (int (*)(void))0x080F67B8+1;
	int (*updateAnimsandOWs)(void) = (int (*)(void))0x08056A04+1;

		int (*copyPalToDMA)(void) = (int (*)(void))0x08070474+1;
		copyPalToDMA();

	func2();
	func3();
	adjustOverworlds();
	func7();
	func8();
	updateAnimsandOWs();
}

void coro_del_(int *addr)
{
	int (*func)(u32) = (int (*)(void))0x08077508+1;
	func(addr);
}

int coro_getid_(int *addr)
{
	int (*func)(u32) = (int (*)(void))0x08077688+1;
	return func(addr);
}

int npc_hide_(int *addr)
{
	int (*func)(u32) = (int (*)(void))0x0805E4B4+1;
	return func(addr);
}

void flag_set_(int *flag)
{
	int (*func)(u32) = (int (*)(void))0x0806E680+1;
	return func(flag);
}
