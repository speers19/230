#include <FPT.h>

int main()
{
  double x1 ,y1, x2, y2; //drawing the function
  double Tr=5, Ty=0, Tx=0; //graph radius and center coordinates
  double Pr, Px, Py; 
  double w; //window size
  double xgap, ygap;
  int first = 0; //makes only one mouse click get registered
  int zoomcond = 0; //engages part of zoom process once graph has moved all the way
  double newx, newy, newCx, newCy; //determines new point to move to
  double p[2]; //mouse click
  double xax, yax;
  double px1,py1,px2,py2 ;
  double tx, ty;
  double px, py;


w = 600; //window size
G_init_graphics (w, w);
Pr = w/2;
Px = w/2 ;
Py = w/2 ; 

	double m0 = 1;
	double mx0 = -1;
	double my0 = 0;
	double mx0v = 0;
	double my0v = 0;
	
	double m1 = .001;
	double mx1 = 1;
	double my1 = 0;
	double mx1v = 0;
	double my1v = .5;

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

  G_rgb(1,0,0);

 	double R = sqrt( pow((mx1 - mx0),2) + pow((my1 - my0),2));
      
    G_wait_key();

 } // end big while
    
    G_wait_key();
}