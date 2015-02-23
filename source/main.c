
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <3ds.h>

#include "costable.h"
#include "text.h"
#include "output.h"


char superStr[8192];
int cnt;

s32 pcCos(u16 v)
{
	return costable[v&0x1FF];
}

int countLines(char* str)
{
	if(!str)return 0;
	int cnt; for(cnt=1;*str=='\n'?++cnt:*str;str++);
	return cnt;
}

void cutLine(char* str)
{
	if(!str || !*str)return;
	char* str2=str;	for(;*str2&&*(str2+1)&&*str2!='\n';str2++);	str2++;
	memmove(str,str2,strlen(str2)+1);
}

void drawFrame()
{
  /*
	u8* bufAdr=gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);


	int i, j;
	for(i=1;i<400;i++)
	{
		for(j=1;j<240;j++)
		{
			u32 v=(j+i*240)*3;
			bufAdr[v]=(pcCos(i+cnt)+4096)/32;
			bufAdr[v+1]=(pcCos(j-256+cnt)+4096)/64;
			bufAdr[v+2]=(pcCos(i+128-cnt)+4096)/32;
		}
	}

	gfxDrawText(GFX_TOP, GFX_LEFT, NULL, "ftPONY v0.1 omega\n", 240-fontDefault.height*1, 10);
	u32 ip = gethostid();
	char bof[256];
	sprintf(bof, "IP: %lu.%lu.%lu.%lu, port 5000, press B at any time to exit\n", ip & 0xFF, (ip>>8)&0xFF, (ip>>16)&0xFF, (ip>>24)&0xFF);
	gfxDrawText(GFX_TOP, GFX_LEFT, NULL, bof, 240-fontDefault.height*2, 10);

	i = countLines(superStr);
	while(i>240/fontDefault.height-3){cutLine(superStr);i--;}
	gfxDrawText(GFX_TOP, GFX_LEFT, NULL, superStr, 240-fontDefault.height*4, 20);
	cnt++;
	*/

	gfxFlushBuffers();
	gfxSwapBuffers();
}

int colour = 1;
int ball = 0;

int ballX = 200;
int ballY = 120;

void drawBall(int xpos, int ypos) {
	gfxDrawText(GFX_TOP, GFX_RIGHT, NULL, "BALL", xpos, ypos);


  /*
	gfxScreen_t screen = GFX_TOP;
	gfx3dSide_t side = GFX_LEFT;
	font_s* f = &fontDefault;
	char* str = "O";
	//s16 x = 240-fontDefault.height*2;
	//s16 y = 10;

  //Place ball
	int x = xpos;
	int y = ypos;


	u16 fbWidth, fbHeight;
	u8* fbAdr=gfxGetFramebuffer(screen, side, &fbWidth, &fbHeight);

	drawString(fbAdr, f, str, y, x, fbHeight, fbWidth);
	*/
}


int main()
{
	// Initialize services
	srvInit();
	aptInit();
	hidInit(NULL);
	gfxInitDefault();
	//gfxSet3D(true); // uncomment if using stereoscopic 3D

	// Main loop
	while (aptMainLoop())
	{
		gspWaitForVBlank();
		hidScanInput();

		// Your code goes here


		u8* bufAdr=gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
		int i, j;

		for(i=1;i<400;i++)
		{
			for(j=1;j<240;j++)
			{
				u32 v=(j+i*240)*3;
				if (colour == 1) //blue
				{
					//lettuce set screen to blue
					bufAdr[v] = 0xFF;
					bufAdr[v+1] = 0x00;
					bufAdr[v+2] = 0x00;
				}

				if (colour == 2) //green
				{
					bufAdr[v] = 0x00;
					bufAdr[v+1] = 0xFF;
					bufAdr[v+2] = 0x00;
				}

				if (colour == 3) //red
				{
					bufAdr[v] = 0x00;
					bufAdr[v+1] = 0x00;
					bufAdr[v+2] = 0xFF;
				}


				/*
				bufAdr[v]=(pcCos(i+cnt)+4096)/32;
				bufAdr[v+1]=(pcCos(j-256+cnt)+4096)/64;
				bufAdr[v+2]=(pcCos(i+128-cnt)+4096)/32;
				*/
			}
		}

		int k;
		int v;
		int qq;
		int ss;
		int cn;
		int sn;
		int latest;

		if (cn < 15) {
    	//Variable is not too big/NULL.
    } else {
      cn = 2;
    }

		if (sn < 15) {
			//Variable is not too big/NULL.
		} else {
			sn = 2;
		}

		if (latest < 900) {
			//Variable is not too big/NULL.
		} else {
			latest = 1;
		}


		gfxDrawText(GFX_TOP, GFX_LEFT, NULL, "Hello WORLD .-.", 240-fontDefault.height*1, 10);
		//print("\n\nclient has disconnected.\npress B to exit, or wait for next client !\n\n");

		u32 kDown = hidKeysDown();

		//Switch colors w/ R
		if (kDown & KEY_R)
		{
			if (colour < 3)
			{
				colour++;
			} else {
				colour = 1;
			}
		}



		cnt++;

		if (kDown & KEY_A)
		{
			if (qq == 2) {
				//qq = 0;
				cn++;
			} else { //qq == 0
				qq = 2;
				cn++;
			}

		}

		if (qq == 2)
		{
			for (k=2;k<cn;k++) {
				gfxDrawText(GFX_TOP, GFX_LEFT, NULL, "spaghetti", 240-fontDefault.height*k+latest, 10);
				//latest++;
			}
		}

		if (kDown & KEY_B)
		{
			if (cn > 2)
			{
				cn--;
			}
		}

		//carrot

		if (kDown & KEY_X)
		{
			if (ss == 2) {
				//s = 0;
				sn++;
			} else { //ss == 0
				ss = 2;
				sn++;
			}

		}

		if (ss == 2)
		{
			for (v=2;v<sn;v++) {
				//gfxDrawText(GFX_TOP, GFX_RIGHT, NULL, "carrot", 240-fontDefault.height*v+latest, 10);

				gfxScreen_t screen = GFX_TOP;
				gfx3dSide_t side = GFX_RIGHT;
				font_s* f = NULL;
				char* str = "carrot";
				s16 x = 240-fontDefault.height*v+latest;
				s16 y = 10;

				if(!str)return;
				if(!f)f=&fontDefault;

				u16 fbWidth, fbHeight;
				u8* fbAdr=gfxGetFramebuffer(screen, side, &fbWidth, &fbHeight);

				//Lettuce shift to the right
				y=y+60;

				drawString(fbAdr, f, str, y, x, fbHeight, fbWidth);
			}
		}

		if (kDown & KEY_Y)
		{
			if (sn > 2)
			{
				sn--;
			}
		}

		//Ball WHEEEE
		if (kDown & KEY_L)
		{
			if (ball == 0)
			{
				ball = 1;
			} else {
				ball = 0;
			}
		}

		//MOVE DAT BALL
		if (kDown & KEY_DUP)
		{
			ballY=ballY+5;
		}
		if (kDown & KEY_DDOWN)
		{
			ballY=ballY-5;
		}

		if (kDown & KEY_DRIGHT)
		{
			ballX=ballX+5;
		}

		if (kDown & KEY_DLEFT)
		{
			ballX=ballX-5;
		}


		if (ball == 1) {
			drawBall(ballX, ballY);
		}



		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

		// Example rendering code that displays a white pixel
		// Please note that the 3DS screens are sideways (thus 240x400 and 240x320)

		//u8* fb = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
		//memset(fb, 0, 240*400*3);
		//fb[3*(10+10*240)] = 0xFF;
		//fb[3*(10+10*240)+1] = 0xFF;
		//fb[3*(10+10*240)+2] = 0xFF;


		// Flush and swap framebuffers
		gfxFlushBuffers();
		gfxSwapBuffers();
	}

	// Exit services
	gfxExit();
	hidExit();
	aptExit();
	srvExit();
	return 0;
}
