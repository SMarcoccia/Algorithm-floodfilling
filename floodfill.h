#ifndef _FLOODFILL_H__
#define _FLOODFILL_H__

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "ctypes.h"
#include "global.h"

typedef struct SStack SStack;
struct SStack
{
  u32 x,y;
  SStack *next;
};

void FloodCreateInit_Stack(s32 x, s32 y);
void FloodCreateCell(s32 x,s32 y);
void FloodFreeCell();
void FloodScanline();

#endif
