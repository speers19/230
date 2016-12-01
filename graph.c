#include <FPT.h>

int main()
{
  double x1 ,y1, x2, y2; //drawing the function
  double Tr=4, Ty=-1, Tx=2; //graph radius and center coordinates
  double Pr, Px, Py; 
  double w; //window size
  double gap; //distance between tick marks/ units of 1 on graph
  double xgap, ygap;
  int first = 0; //makes only one mouse click get registered
  int zoomcond = 0; //engages part of zoom process once graph has moved all the way
  double newx, newy, newCx, newCy; //determines new point to move to
  double p[2]; //mouse click
  double s = 1; //speed
  double xax, yax;
  double px1,py1,px2,py2 ;
  double tx,ty ;
  double px, py;


w = 600; //window size
G_init_graphics (w, w);
Pr = w/2;
Px = w/2 ;
Py = w/2 ;
gap = w/(Tr*2);   





while (Pr == w/2) //main while loop allowing animation
{
  G_clear();
  G_rgb(1,1,1);
  G_fill_rectangle(0,0,w,w);

yax = (tx - Tx) / Tr * Pr + Px ;
xax = (ty - Ty) / Tr * Pr + Py ;

  G_rgb(0,0,0);
  G_line(yax, 0, yax, w-1);
  G_line(0, xax, w-1, xax);


  if (first == 0) //ticker marks (disappear upon animation)
{
    int tick;
    for (tick=1;tick<=2*Tr;tick++)
    {
      G_line((yax-10), (tick*gap), (yax+10), (tick*gap));
      G_line((tick*gap), xax-10, (tick*gap), xax+10);
    }
}

  G_rgb(1,0,0);

  x1 = Tx - Tr ;
  while (x1<= Tx + Tr)
    {
      x2 = x1 + 0.01*Tr ;
      y1 = (x1 - 1)/(pow(x1, 3) - 1);
      y2 = (x2 - 1)/(pow(x2, 3) - 1);

      px1 = (x1 - Tx)/Tr * Pr + Px ;
      py1 = (y1 - Ty)/Tr * Pr + Py ;

      px2 = (x2 - Tx)/Tr * Pr + Px ;
      py2 = (y2 - Ty)/Tr * Pr + Py ;

      G_line(px1,py1,  px2,py2) ;
      x1 = x1+.01*Tr ;
    }





    if (first == 1) //makes circle move with graph 
    {
    px = (newx - Tx)/Tr * Pr + Px;
    py = (newy - Ty)/Tr * Pr + Py ;
    G_rgb(0,0,1);
	G_fill_circle(px, py, 3);
	G_draw_string("CLICK THAT SHIT BOY!",px-100,py+30);
	G_draw_string("GOVERNMENT GOT NO POWER OVER ME",px-150, py-45);    
	}






    if (first == 0) //collects mouse click info first time so animation can occur
    {
      G_wait_click(p);
      px = p[0];
      newx = (px - Px) / Pr * Tr + Tx ;
      newy = (newx - 1)/(pow(newx, 3) - 1);
      py = (newy - Ty)/Tr * Pr + Py ;
      G_rgb(0,0,1);
      G_fill_circle(px,py, 3);
      first++;
      G_draw_string("CLICK THAT SHIT BOY!",px-100,py+30);
      }
    

    if (newx < Tx)
    {
      Tx = Tx - 0.01*Tr;
	}

    if (newx > Tx)
    {
      Tx = Tx + 0.01*Tr ;
    }


    if (newy < Ty)
    {
      Ty = Ty - 0.01*Tr ;
    }

    if (newy > Ty)
    {
      Ty = Ty + 0.01*Tr ;
    }


    if (  (fabs(newx - Tx) < 0.02*Tr)  && (fabs(newy - Ty) < 0.02*Tr) ) {

      Tr = Tr*0.98;
      G_draw_string("ZOOM BABY ZOOM",px-150, py-75);  

    }





    
    G_wait_key();

 } // end big while
    
    G_wait_key();
}