#include <FPT.h>

int main()
{

double w = 600; //window size
G_init_graphics (w,w);

double Tr = 10;

double Pr = w/2;
double Px = w/2;
double Py = w/2;

int n = 11; //number of points before line is drawn

double p[2];
double x[n];
double y[n];



for (int q = 0; q < n; q++) {
x[q] = -1;}

int drawline = 0;

int i = 0; //counter for x and y coordinates

while (Pr == w/2) {

	G_clear();
	G_rgb(1,1,1);
	G_fill_rectangle(0,0,w,w);


	for (double tick = 1; tick < 10; tick++) //DRAWS GRAPH LINES
	{
	G_rgb(.933, .913, .913);
	G_line(tick*(w/Tr), 0, tick*(w/Tr), 600);
	G_line(0, tick*(w/Tr), 600, tick*(w/Tr));
	}



	for (int c = 0; c < n; c++) //DRAWS HIGHLIGHTED POINTS
	{
		if (x[c] >= 0) {
		G_rgb(0,0,1);
		G_fill_circle(x[c], y[c], 3);
		}
	}


	if (drawline == 0) { //COLLECTS MOUSECLICKS 
	G_wait_click(p);
		if (p[0] > 600) {
		drawline = 1;
		break;}
	x[i] = p[0];
	y[i] = p[1];
	i++;
		if (i==n) {
		drawline = 1; }
	}
		
	/*if (drawline == 1)
	double xsum = 0;
	double ysum = 1;
	
	for (int r = 0; r < n-1 ; r++) {
	xsum += xsum + x[r];
	ysum += ysum + y[r];
	}
	
	double u = xsum / (n-1);
	double v = ysum / (n-1);	*/	

//G_wait_key();

}

}