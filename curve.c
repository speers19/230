#include <FPT.h>

double function(double x) {
double y = (4.0/3.0) * x * sqrt(x);
return y;
}

int main() {

double input;
double output = 0;

printf("Input number of pieces:\n");
scanf("%lf", &input);

double xpiece = 4.0 / input;
double x = 2 + xpiece;
double ypiece;

for (int i = 0; i < input; i++) {
ypiece = function(x) - function(x - xpiece);
output += sqrt( pow(xpiece,2) + pow(ypiece,2) );
x = x + xpiece;
}

printf("The length of the curve is approximately %lf\n", output);

}