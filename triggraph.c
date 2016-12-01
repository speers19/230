#include <FPT.h>

double func(double x)
{
double y = sin(x);
return y;
}

double func2(double x)
{
double y = cos(x);
return y;
}

double func3(double x, double h)
{
double y = (sin(x+h) - sin(x))/h;
return y;
}

int main()
{
  double x1 ,y1, x2, y2; //drawing the function
  double Tr=7, Ty=0, Tx=0; //graph radius and center coordinates
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
  double pxx, pyy;
  double newxx, newyy;
  double b,m;
double test = 5;

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
      y1 = func(x1);
      y2 = func(x2);

      px1 = (x1 - Tx)/Tr * Pr + Px ;
      py1 = (y1 - Ty)/Tr * Pr + Py ;

      px2 = (x2 - Tx)/Tr * Pr + Px ;
      py2 = (y2 - Ty)/Tr * Pr + Py ;

      G_line(px1,py1,  px2,py2) ;
      x1 = x1+.01*Tr ;
    }

  x1 = Tx - Tr ;
  while (x1<= Tx + Tr)
    {
    G_rgb(0,1,0);
      x2 = x1 + 0.01*Tr ;
      y1 = func2(x1);
      y2 = func2(x2);

      px1 = (x1 - Tx)/Tr * Pr + Px ;
      py1 = (y1 - Ty)/Tr * Pr + Py ;

      px2 = (x2 - Tx)/Tr * Pr + Px ;
      py2 = (y2 - Ty)/Tr * Pr + Py ;

      G_line(px1,py1,  px2,py2) ;
      x1 = x1+.01*Tr ;
    }
    
    double h = 1;
      x1 = Tx - Tr ;
  while (x1<= Tx + Tr)
    {
    G_rgb(0,0,1);
      x2 = x1 + 0.01*Tr ;
      y1 = func3(x1,h);
      y2 = func3(x2,h);

      px1 = (x1 - Tx)/Tr * Pr + Px ;
      py1 = (y1 - Ty)/Tr * Pr + Py ;

      px2 = (x2 - Tx)/Tr * Pr + Px ;
      py2 = (y2 - Ty)/Tr * Pr + Py ;

      G_line(px1,py1,  px2,py2) ;
      x1 = x1+.01*Tr ;
      h = h*.98;
    }



    if (first == 1) //makes circle move with graph 
    {
    px = (newx - Tx)/Tr * Pr + Px;
    py = (newy - Ty)/Tr * Pr + Py ;
    G_rgb(0,0,1);
	G_fill_circle(px, py, 3);
	
	double slopest = (m * 0) + b;
	double slopeend = (m * 599) + b;
	
	    	b = py - (m*px);
	
	G_line(0,slopest, 599,slopeend);
	
	
	
	G_draw_string("CLICK THAT SHIT BOY!",px-100,py+30);
	G_draw_string("GOVERNMENT GOT NO POWER OVER ME",px-150, py-45);    
	}






    if (first == 0) //collects mouse click info first time so animation can occur
    {
      G_wait_click(p);
      px = p[0];
      pxx = px + 1;
      newx = (px - Px) / Pr * Tr + Tx ;
      newxx = (pxx - Px) / Pr * Tr + Tx;
      newy = func(newx);
      newyy = func(newxx);
      py = (newy - Ty)/Tr * Pr + Py ;
      pyy = (newyy - Ty)/Tr * Pr + Py;
      
     	m = ((py) - (pyy)) / ((px) - (pxx));
      b = py - (m*px);
      
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