#include <FPT.h>

int main()
{

double particles;
printf("Enter number of fuel particles\n");
scanf("%lf", &particles);

double p = .9 / particles;
double m = 1;
double v = 0;

for (int i = 1; i <= particles; i++) {
m = m - p;
v = v + p*(6000/m);
}

printf("%lf\n", v);

}