#include <stdio.h>
#include <math.h>
#include <stdlib.h> // drand48, atoi
#include <unistd.h> // usleep
#include <time.h> // for G_get_time stuff
#include <sys/time.h> 
#include <string.h> // strcpy, strcat, etc


#include <G_graphics.h>


#include <X_graphics.h>  

int main()
{
  double x1 ,y1, x2, y2;
  double Tr=4, Tx=1, Ty=-2, tx, ty;
  double Pr, Px, Py, px, py;
  double w;
  double tsize;
  double gap;

  w = 600;
  gap = w/8;

  G_init_graphics (w, w);
  Pr = w/2;
  Px = (Pr + (Ty*gap));
  Py = (Pr + (Tx*gap));

G_rgb(1,0,0);
  G_point(Pr,Pr);

  G_rgb(0,0,0);
  G_line(Px, 0, Px, w-1);
  G_line(0, Py, w-1, Py);

  int tick;
  for (tick=1;tick<=8;tick++)
    {
      G_line((Px-10), (tick*gap), (Px+10), (tick*gap));
      G_line((tick*gap), Py-10, (tick*gap), Py+10);
    }

  G_rgb(1,0,0);

  x1 = -10;    
  while (x1<=10)
    {
      x2 = x1 + .01;
      y1 = (x1 - 1)/(pow(x1, 3) - 1);
      y2 = (x1 - 1)/(pow(x2, 3) - 1);
      G_line((Px + gap*x1), (Py + gap*y1), (Px + gap*x2), (Py + gap*y2));
      x1 = x1+.01;
    }

  G_wait_key();


    }