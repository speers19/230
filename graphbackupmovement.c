#include <FPT.h>

int main()
{
  double x1 ,y1, x2, y2; //drawing the function
  double Tr=4, Ty=-1, Tx=2; //graph radius and center coordinates
  double Pr, Px, Py; 
  double w; //window size
  double gap; //distance between tick marks/ units of 1 on graph
  int first = 0; //makes only one mouse click get registered
  double newx, newy, newCx, newCy; //determines new point to move to
  double p[2]; //mouse click
  double s = 3; //speed

double xax, yax;

  w = 600; //window size
  gap = w/8; 

G_init_graphics (w, w);

  Pr = w/2;
  Px = (Pr - (Tx*gap));
  Py = (Pr - (Ty*gap));

yax = Px;
xax = Py;

  //You gotta use a while loop and clear the screen to do the animation - want to reach newCx and newCy.

while (newCx != Pr)
{

G_clear();
G_rgb(1,1,1);
G_fill_rectangle(0,0,w,w);

  G_point(Pr,Pr);

  G_rgb(0,0,0);
  G_line(yax, 0, yax, w-1);
  G_line(0, xax, w-1, xax);

  int tick;
  for (tick=1;tick<=2*Tr;tick++)
    {
      G_line((Px-10), (tick*gap), (Px+10), (tick*gap));
      G_line((tick*gap), Py-10, (tick*gap), Py+10);
    }

  G_rgb(1,0,0);

  x1 = -10;    
  while (x1<=100)
    {
      x2 = x1 + .001;
      y1 = (x1 - 1)/(pow(x1, 3) - 1);
      y2 = (x1 - 1)/(pow(x2, 3) - 1);
      G_line((Px + gap*x1), (Py + gap*y1), (Px + gap*x2), (Py + gap*y2));
      x1 = x1+.001;
    }
    
    if (first == 1)
    { G_rgb(0,0,1);
      G_fill_rectangle(newCx - 3, newCy - 3, 6, 6);
      }


  if (first == 0) //collects mouse click info first time so animation can occur
    {
      G_wait_click(p);
      double clickx = p[0];
      newx = (clickx - Px)/gap;
      newy = (newx - 1)/(pow(newx, 3) - 1);
      G_rgb(0,0,1);
      G_fill_rectangle(clickx-3, Py + gap*newy-3, 6, 6);
      newCx = clickx, newCy = Py + gap*newy;
      first++;
    }
    
    if (newCx > Pr)
    {yax= yax - s;
    newCx = newCx - s;
    x1 = x1 - s;}
    
    
    if (newCx < Pr)
    {yax= yax + s;
    newCx = newCx + s;
    x1 = x1 + s;}
    
    if (newCy > Pr)
    {xax= xax - s;
    newCy = newCy - s;}
    
    if (newCy < Pr)
    {xax = xax + s;
    newCy = newCy + s;}
    

    
    G_wait_key();
    }
    

  G_wait_key();
}