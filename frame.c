#include "frame.h"


void frameInit()
{
  nTimer1=SDL_GetTicks();
}

void frameWait()
{
  u32 nTimer2;

  while(1)
    {
      nTimer2=SDL_GetTicks()-nTimer1;
      if(nTimer2 >=FPS_Default) break;
      SDL_Delay(3);
    }
  nTimer1=SDL_GetTicks();
}
