#include <FPT.h>

double mypower(double x, double p)
{
int n = 0;
int count = 0;
double storep;
double partanswer = 1;
double wholep = 0;
double pb; //answer bottom bound
double ep; //exponent
double pt; //answer top bound
double answer = 1; 

//checks for whole number
if (p == floor(p))
{

	while (n < fabs(p))
	{
	answer = answer * x;
	n++;
	}
	
	if (p<0)
	{
	answer = 1/answer;
	}
	
return answer;
}	

// ^^^ correct
//bisection

storep = p;
p = fabs(p);

if (p > 1) 
{
wholep = floor(p);
p = p - wholep;
}
 
if (fabs(p) == .5)
	{ 
	partanswer = sqrt(x);
	if(fabs(wholep)>=1)
	{
		while (n<wholep)
		{
		answer = answer * x;
		n++;
		}
	answer = answer * partanswer;
	if (storep<0)
	{return 1/answer;}
	return answer;
	}
	}
	
if (p<.5)
{
pb = 1;
pt = sqrt(sqrt(fabs(x)));
ep = .25;
}
else
{
pb = sqrt(sqrt(fabs(x)));
pt = sqrt(fabs(x));
ep = .75;
}

double epchange = .125;

while (ep != p)
{
partanswer = pb * pt;

if (p > ep)
{
pb = sqrt(partanswer);
ep = ep + epchange;
}
else if (p < ep)
{
pt = sqrt(partanswer);
ep = ep - epchange;
}

epchange = epchange / 2; 

}

if(wholep>=1)
{
while (n<wholep)
{
answer = answer * x;
n++;
}
}


answer = answer * partanswer;

if (storep<0)
{answer = 1/answer;}

return answer; 

}

int main()
{
double x;
double p;

printf("Give me a base and an exponent.\n");

scanf("%lf",&x);
scanf("%lf",&p);
printf("\n");

double answer = mypower(x, p);

printf("%lf to the %lf is %lf\n", x, p, answer);
}