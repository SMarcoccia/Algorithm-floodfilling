#include"floodfill.h"

SStack *pStack;
SStack *pTmp;

void FloodCreateInit_Stack(s32 x, s32 y)
{
  pTmp=NULL;
  pStack=malloc(sizeof*pStack);
  pStack->x=x;
  pStack->y=y;
  pStack->next=NULL;
}

void FloodCreateCell(s32 x, s32 y)
{
  pTmp=malloc(sizeof*pTmp);
  pTmp->next=pStack;
  pStack=pTmp;
  pStack->x=x;
  pStack->y=y;
  pTmp=NULL;
}

void FloodFreeCell()
{
  pTmp=pStack;
  pStack=pStack->next;
  free(pTmp);
  pTmp=NULL;
}

void FloodScanline()
{
  s32 x=Gen.nMousePosX;
  s32 y=Gen.nMousePosY;
  u8 clrPix=GlobalGetClrPix(x, y);  
  u8 pixDown,pixUp;

  if(clrPix==0xFF)
    return;

  FloodCreateInit_Stack(x,y);

  while(pStack!=NULL)
  {
    pixDown=FALSE;  
    pixUp=FALSE;

    x=pStack->x;
    y=pStack->y;

    FloodFreeCell();

    while(x>=0 && GlobalGetClrPix(x, y)==clrPix)
      x--;

    x++;

    while(x<WIN_W && GlobalGetClrPix(x,y)==clrPix)
    {  
      GlobalPutPixel(x,y,0xFF);
      if(y>0)
        {
          if(GlobalGetClrPix(x,y-1)==clrPix)
          {
            if(!pixDown)
              {
                FloodCreateCell(x,y-1);
                pixDown=TRUE;
              }
          }
          else if(pixDown)
          pixDown=FALSE;
        }

      if(y<WIN_H-1)
      {
        if(GlobalGetClrPix(x,y+1)==clrPix)
        {
        if(!pixUp)
          {
            FloodCreateCell(x,y+1);
            pixUp=TRUE;
          }
        }
        else if(pixUp)
        pixUp=FALSE;
      }
      x++;      
    }
  }
}

