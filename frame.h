#ifndef __FRAME_H__
#define __FRAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>

#include "ctypes.h"

#define FPS_Default (1000/60)

u32 nTimer1;

void frameInit();
void frameWait();

#endif
