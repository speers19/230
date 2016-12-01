#include <FPT.h>

int main()
{

int input;
printf("How many points do you want to plot?\n");
scanf("%d",&input);

double w = 600; //window size
G_init_graphics (w,w);

double Tr = 10;

double Pr = w/2;
double Px = w/2;
double Py = w/2;

int n = input + 1; //n - 1 =number of points before line is drawn

double p[2];
double x[n];
double y[n];



for (int q = 0; q < n; q++) {x[q] = -1;} //initialize array to -1

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



	for (int c = 0; c < n-1; c++) //DRAWS HIGHLIGHTED POINTS
	{
		if (x[c] >= 0) {
		G_rgb(0,0,1);
		G_fill_circle(x[c], y[c], 3);
		}
	}


	if (drawline == 0) { //COLLECTS MOUSECLICKS 
	G_wait_click(p);
	x[i] = p[0];
	y[i] = p[1];
	i = i+1;
		if (i==n) {
		drawline = 1; 
		}
	}		
				
	if (drawline == 1) {
	double xsum = 0;
	double ysum = 0;
	double slope = 0;
	double T;
	double smallest = 100000;
	
	for (int r = 0; r < n-1 ; r++) {
	xsum += x[r];
	ysum += y[r];
	}
	
	double u = xsum / (n-1);
	double v = ysum / (n-1);
	
	for (double m = -50; m <= 50; m = m + .1) {
	T = 0;
		for (int r = 0; r < n-1; r++) {
		double b = v - m*u;
		double yline = m*x[r] + b;
		T += 2*(fabs(y[r] - yline));
		}
			if (T < smallest) {
			smallest = T;
			slope = m;
			}
			printf("smallest = %lf\n", smallest);
	}
	
	double y0 = v - slope*u;
	double y1 = slope*(600) + y0;
	
	G_rgb(0,0,0);
	G_line(0, y0, 600, y1);
	
	G_rgb(1,0,0);
	G_fill_circle(u, v, 5);
	G_wait_key();
	
	}


	}

}
