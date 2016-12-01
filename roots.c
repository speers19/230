#include <FPT.h>

int main() {

//////// FORMAT POLYNOMIAL //////////
int degree;
int temp;

printf("Input the degree of the polynomial\n");
scanf("%d", &degree);

int coefficients[degree];

printf("Input the coefficients of each term in the polynomial\n");
for (int i = 0; i <= degree; i++) {
scanf("%d", &temp);
coefficients[i] = temp;
}

int exp = degree;
printf("Your polynomial looks like:\n");
for (int i = 0; i <= degree; i++) {
temp = coefficients[i];
printf("%dx^%d ", coefficients[i], exp);
exp = exp - 1;
}
printf("\n");


//////// FIND P AND Q /////////

int firstint = coefficients[0];
double first = coefficients[0];
int lastint = coefficients[degree];
double last = coefficients[degree];

double q[abs(firstint)];
double p[abs(lastint)];


int count = 0;
printf("Divisors of constant: \n");
for (double i = 1; i <= fabs(last); i++) {
	if (last / i == floor(last / i)) {
	p[count] = i;
	printf("%.f \n",p[count]);
	count++;
	}
}

count = 0;
printf("Divisors of leading coefficient: \n");
for (double i = 1; i <= fabs(first); i++) {
	if (first / i == floor(first / i)) {
	q[count] = i;
	printf("%.f \n", q[count]);
	count++;
	}
}

/////LENGTH OF P AND Q////////

int plength = 0;
int qlength = 0;

int g = 0;
while (p[g] != 0) {
plength++;
g++;}

g = 0;
while (q[g] != 0) {
qlength++;
g++;}

//////// FIND ROOTS ////////

int donetop[degree];
int donebottom[degree];
int donecount = 0;


printf("Roots:\n");
for (int i = 0; i < plength; i++) {
	if (p[i] == 0) {break;}
	for (int j = 0; j < qlength; j++) {
		if (q[j] == 0) {break;}
	int degreetemp = degree;
	double partialsum = 0;
		
	for (int g = 0; g <= degree; g++) {
	partialsum +=(coefficients[g] * pow(p[i],degreetemp) * pow(q[j],g));
	degreetemp = degreetemp - 1;
	}
		
	if (partialsum == 0) {
	int top = p[i];
	int bottom = q[j];
		for (int c = 0; c < donecount; c++)
		{if (top * donebottom[c] == bottom * donetop[c]) {goto SKIP1;}}
	printf("%.f / %.f\n", p[i], q[j]);
	donetop[donecount] = p[i];
	donebottom[donecount] = q[j];
	donecount++;
	}
	
	SKIP1:
	
	partialsum = 0;
	degreetemp = degree;
	
	for (int g = 0; g <= degree; g++) {
	partialsum +=(coefficients[g] * pow(-p[i],degreetemp) * pow(q[j],g));
	degreetemp = degreetemp - 1;
	}
		
	if (partialsum == 0) {
	int top = - p[i];
	int bottom = q[j];
		for (int c = 0; c < donecount; c++)
		{if (top * donebottom[c] == bottom * donetop[c]) {goto SKIP2;}}
	printf("- %.f / %.f\n", p[i], q[j]);
	donetop[donecount] = - p[i];
	donebottom[donecount] = q[j];
	donecount++;
	}
	
	SKIP2:
	printf("");
}
}
if (coefficients[degree] == 0) {printf("0\n");}
}

