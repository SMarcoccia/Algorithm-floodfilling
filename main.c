#include <stdlib.h>
#include <stdio.h>

#include "SDL/SDL.h"

#include "ctypes.h"
#include "global.h"
#include "floodfill.h"
#include "frame.h"

int main(int argc, char** argv)
{
  bool nLoop=TRUE;
  SDL_Surface *gfx=NULL;

  GlobalInitSDL();

  gfx=SDL_LoadBMP("Bkg_test.bmp");
  if(gfx==NULL)
    {
      fprintf(stderr,"Loading IMG failed : %s",SDL_GetError());
      atexit(SDL_Quit);
    }

  SDL_BlitSurface(gfx,NULL,Gen.pScreen,NULL);
  SDL_Flip(Gen.pScreen);
  frameInit();

  while(nLoop)
    {
 
      nLoop=GlobalEventHandler();
      if(Gen.nMouseButton & nMouseBtnLeft)
	{
	  FloodScanline();
	  Gen.nMouseButton=0;
	}
      frameWait();
      SDL_Flip(Gen.pScreen);
    }
  

  SDL_FreeSurface(gfx);
  SDL_FreeSurface(Gen.pScreen);

  (void)argc; (void)argv;
  return EXIT_SUCCESS;
}
