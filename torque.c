#include <FPT.h>

double function(double y, double h) {
double T = M_PI * y * (y/2.0) * h;
return T;
}

int main() {

double input;

printf("Input number of pieces:\n");
scanf("%lf", &input);

double h = 10.0/input;
double T = 0;
double TotalT = 0;
double x;
double y;

for (int i = 1; i <= input; i++) {
x = i * h;
y = .3 * x;

T = function(y, h) * (x - 2.5);
TotalT += T;

}

printf("The answer is %lf\n", TotalT);

}