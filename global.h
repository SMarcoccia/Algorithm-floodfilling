#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "ctypes.h"


#define WIN_W 700
#define WIN_H 500
#define BPP 8
#define FLAGS SDL_SWSURFACE | SDL_DOUBLEBUF
#define TRUE -1
#define FALSE 0

#define nMouseBtnLeft 1
#define nMouseBtnRight 2

typedef u8 bool;

typedef struct SGen
{
  SDL_Surface *pScreen; /*buffer SDL*/
  u32 nMousePosX, nMousePosY; /*pos mouse*/
  u8 nMouseButton; /*state button 1 (left) or 2 (right)*/
  u8 Key[SDLK_LAST];  /*buffer keyboard*/
  u8 nKeyButton; /*state key 0 or 1*/
}SGen;

struct SGen Gen;

void GlobalInitSDL();
void GlobalPutPixel(u32 x,u32 y, u8 clr);

u8   GlobalEventHandler();
u8   GlobalGetClrPix(u32 x, u32 y);
u8   GlobalMouseGetClrPixel();

#endif
