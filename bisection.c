#include <FPT.h>

double mysin(degrees)
{
double xm, ym;
double xc, yc;
double x0, y0, x1, y1;
double xbase, ybase;
double cdegrees, cdegreeschange;
double test;

// INITIALIZE WHICH QUADRANT OF UNIT CIRCLE AND WHICH HALF OF QUADRANT

if (degrees >= 360)
{
	while (degrees >= 360)
	{
	degrees = degrees - 360;
	}
}

if (degrees < 0)
{
	while (degrees < 0)
	{
	degrees = degrees + 360;
	}
}

if (degrees < 90)
{
x0 = 1;
y0 = 0;
x1 = 0;
y1 = 1;
cdegrees = 45;
}

if (degrees > 91 && degrees < 180)
{
x0 = 0;
y0 = 1;
x1 = -1;
y1 = 0;
cdegrees = 135;
}

if (degrees > 181 && degrees < 270)
{
x0 = -1;
y0 = 0;
x1 = 0;
y1 = -1;
cdegrees = 225;
}

if (degrees > 271 && degrees < 360)
{
x0 = 0;
y0 = -1;
x1 = 1;
y1 = 0;
cdegrees = 315;
}

if (degrees == 0)
{return 0;}
if (degrees == 45)
{return sqrt(2)/2;}
if (degrees == 90)
{return 1;}
if (degrees == 135)
{return sqrt(2)/2;}
if (degrees == 180)
{return 0;}
if (degrees == 225)
{return -sqrt(2)/2;}
if (degrees == 270)
{return -1;}
if (degrees == 315)
{return -sqrt(2)/2;}

cdegreeschange = 22.5;

// LOOP UNTIL ANSWER//

while (degrees != cdegrees)
{
xm = (x0 + x1) / 2;
ym = (y0 + y1) / 2;

xc = (xm) / (sqrt(pow(xm, 2) + pow(ym, 2)));
yc = (ym) / (sqrt(pow(xm, 2) + pow(ym, 2)));

if (degrees > cdegrees)
{
x0 = xc; 
y0 = yc;
cdegrees = cdegrees + (cdegreeschange);
}
else
{
x1 = xc;
y1 = yc; 
cdegrees = cdegrees - (cdegreeschange);
}
cdegreeschange = cdegreeschange/2;
}
return yc; 
}





double mycos(degrees)
{
double xm, ym;
double xc, yc;
double x0, y0, x1, y1;
double xbase, ybase;
double cdegrees, cdegreeschange;
double test;

// INITIALIZE WHICH QUADRANT OF UNIT CIRCLE AND WHICH HALF OF QUADRANT

if (degrees >= 360)
{
	while (degrees >= 360)
	{
	degrees = degrees - 360;
	}
}

if (degrees < 0)
{
	while (degrees < 0)
	{
	degrees = degrees + 360;
	}
}

if (degrees < 90)
{
x0 = 1;
y0 = 0;
x1 = 0;
y1 = 1;
cdegrees = 45;
}

if (degrees > 91 && degrees < 180)
{
x0 = 0;
y0 = 1;
x1 = -1;
y1 = 0;
cdegrees = 135;
}

if (degrees > 181 && degrees < 270)
{
x0 = -1;
y0 = 0;
x1 = 0;
y1 = -1;
cdegrees = 225;
}

if (degrees > 271 && degrees < 360)
{
x0 = 0;
y0 = -1;
x1 = 1;
y1 = 0;
cdegrees = 315;
}

if (degrees == 0)
{return 1;}
if (degrees == 45)
{return sqrt(2)/2;}
if (degrees == 90)
{return 0;}
if (degrees == 135)
{return -sqrt(2)/2;}
if (degrees == 180)
{return -1;}
if (degrees == 225)
{return -sqrt(2)/2;}
if (degrees == 270)
{return 0;}
if (degrees == 315)
{return sqrt(2)/2;}

cdegreeschange = 22.5;

// LOOP UNTIL ANSWER//

while (degrees != cdegrees)
{
xm = (x0 + x1) / 2;
ym = (y0 + y1) / 2;

xc = (xm) / (sqrt(pow(xm, 2) + pow(ym, 2)));
yc = (ym) / (sqrt(pow(xm, 2) + pow(ym, 2)));

if (degrees > cdegrees)
{
x0 = xc; 
y0 = yc;
cdegrees = cdegrees + (cdegreeschange);
}
else
{
x1 = xc;
y1 = yc; 
cdegrees = cdegrees - (cdegreeschange);
}
cdegreeschange = cdegreeschange/2;
}
return xc; 
}


int main()
{
double degrees;
double sin;
double cos;


printf("Input an angle.\n");
scanf("%lf", &degrees);
sin = mysin(degrees);
cos = mycos(degrees);

printf("Sin: %lf\n\nCos: %lf\n", sin, cos);
}