#include <FPT.h>

double function(double M, double r) {
double F = M / (pow(r,2));
return F;
}

int main() {

double input;

printf("Input number of pieces:\n");
scanf("%lf", &input);

double M = 10.0 / input;
double r = 5.0;
double F = 0;

for (int i = 0; i < input; i++) {
F += function(M, r);
r += (3.0/input);
}

printf("The answer is %lf\n", F);

}