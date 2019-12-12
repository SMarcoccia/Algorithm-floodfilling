
#include "global.h"



void GlobalInitSDL()
{
  if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      fprintf(stderr, "Unable to init SDL : %s\n", SDL_GetError());
      atexit(SDL_Quit);
    }

  if((Gen.pScreen=SDL_SetVideoMode(WIN_W,WIN_H,BPP,FLAGS))==NULL)
    {
      fprintf(stderr,"Unable to display SDL : %s\n",SDL_GetError());
      exit(0);
    }

  SDL_SetColorKey(Gen.pScreen, SDL_SRCCOLORKEY,SDL_MapRGB(Gen.pScreen->format,0xff,0x0,0xff));

  SDL_WM_SetCaption("Flood filling",NULL);
}

u8 GlobalEventHandler()
{
  SDL_Event event;
  while(SDL_PollEvent(&event))
    {
      switch(event.type)
	{
	case SDL_KEYDOWN :
	  Gen.Key[event.key.keysym.sym]=TRUE;
	  if(Gen.Key[SDLK_ESCAPE])
	    return FALSE;
	  break;
	case SDL_KEYUP :
	  Gen.Key[event.key.keysym.sym]=FALSE;
	  break;
	case SDL_MOUSEBUTTONDOWN :
	  switch(event.button.button)
	    {
	    case SDL_BUTTON_LEFT :
	      Gen.nMouseButton=nMouseBtnLeft;
	      break;
	    case SDL_BUTTON_RIGHT :
	      return FALSE;
	    }
	  break;
	case SDL_MOUSEBUTTONUP :
	  switch(event.button.button)
	    {
	    case SDL_BUTTON_LEFT :
	      Gen.nMouseButton=0;
	      break;
	    case SDL_BUTTON_RIGHT :
	      Gen.nMouseButton=0;
	      break;
	    }
	  break;
	case SDL_MOUSEMOTION :
	  Gen.nMousePosX=event.motion.x;
	  Gen.nMousePosY=event.motion.y;
	  break;
	case SDL_QUIT :
	  exit(0);
	  break;
	}
    }
  return TRUE;
}

void GlobalPutPixel(u32 x, u32 y, u8 clr)
{
  u8 *pix=(u8*)Gen.pScreen->pixels;
  *(pix+(Gen.pScreen->pitch*y)+x)=clr;
}

u8 GlobalGetClrPix(u32 x,u32 y)
{
  u8 *pix=(u8*)Gen.pScreen->pixels;
  SDL_LockSurface(Gen.pScreen);
  u8 val=*(pix+(Gen.pScreen->pitch*y)+x);
  SDL_UnlockSurface(Gen.pScreen);
  return val;
}

u8 GlobalMouseGetClrPixel()
{
  u8 *pix=(u8*)Gen.pScreen->pixels;
  SDL_LockSurface(Gen.pScreen);
  u8 val=*(pix+(Gen.pScreen->pitch*Gen.nMousePosY)+Gen.nMousePosX);
  SDL_UnlockSurface(Gen.pScreen);
 return val;
}
