#include <FPT.h>

double function(double l, double ypiece, double y) {
double w = pow(l,2) * ypiece * (200 - y);
return w;
}

int main() {

double stupidwork = (1.0/3.0) * 200.0 * (100.0 * 100.0) * 200.0;
double smartwork = 0;

double input;

printf("Input number of pieces:\n");
scanf("%lf", &input);

double xpiece = 100.0 / input;
double l = 100.0;
double ypiece = 200.0 / input;
double y = 200 - ypiece;

for (int i = 0; i < input; i++) {
smartwork += function(l, ypiece, y);
l = l - xpiece;
y = y - ypiece;
}

double ratio = stupidwork/smartwork;

printf("The ratio of stupid to smart work is %lf\n", ratio);

}