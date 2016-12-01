#include <FPT.h>

double mylog(double z)
{

double zb = 1;
double zt = 10;
double cb = 0;
double ct = 1;
double ez = sqrt(10);
double answer;

if (z == 1)
{return 0;}
if (z == 10)
{return 1;}
if (z == .5)
{return sqrt(10);}

while (ez != z)
{
answer = (cb + ct)/2;
ez = sqrt(zb*zt);

if (z > ez)
{
zb = ez;
cb = answer;
}
if (z < ez)
{
zt = ez;
ct = answer;
}

}

return answer;
}


int main()
{
double z;

printf("Give me an argument for log base 10.\n");

scanf("%lf",&z);
printf("\n");

double loganswer = mylog(z);

printf("Log of %lf is %lf\n", z, loganswer);
}