
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <3ds.h>

#include "costable.h"
#include "text.h"
#include "output.h"
#include "ftp.h"


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



void lightPixel(int pixel, u8* framebuffer)
{
	int p;
	p = pixel * 3;
	framebuffer[p] = 0xFF;
	framebuffer[p+1] = 0xFF;
	framebuffer[p+2] = 0xFF;
}

void drawPixel(int pixel, u8* framebuffer, int r, int g, int b)
{
	int p;
	p = pixel * 3;
	framebuffer[p] = r;
	framebuffer[p+1] = g;
	framebuffer[p+2] = b;
}


int main()
{
	// Initialize services
	srvInit();
	aptInit();
	hidInit(NULL);
	gfxInit();
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
				bufAdr[v]=(pcCos(i+cnt)+4096)/32;
				bufAdr[v+1]=(pcCos(j-256+cnt)+4096)/64;
				bufAdr[v+2]=(pcCos(i+128-cnt)+4096)/32;
			}
		}

		gfxDrawText(GFX_TOP, GFX_LEFT, NULL, "Hello WORLD .-. carrotcakes\n", 240-fontDefault.height*1, 10);

		cnt++;

		u32 kDown = hidKeysDown();
		if (kDown & KEY_START)
			break; // break in order to return to hbmenu

		// Example rendering code that displays a white pixel
		// Please note that the 3DS screens are sideways (thus 240x400 and 240x320)

		u8* fb = gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
		memset(fb, 0, 240*400*3);
		for(int i = 0; i < 12; i++){
			lightPixel(i);
		}
		for(int i = 240; i < 1681; i + 240){
			lightPixel(i+5);
		}
		for(int i = 1680; i < 1692; i++){
			lightPixel(i);
		}


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
