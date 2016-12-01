#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()

{
double g;

printf("Input a number\n");
scanf("%lf",&g);

g = (3*(g*g*g) + 10 - (g*g*g)) / (3 * (g*g));

printf("%lf",g);
}