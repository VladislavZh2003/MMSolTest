#include <stdio.h>

double diff(double n,double mid);
double cubicRoot(double n);

int main()
{
	double n;

    scanf("%lf", &n);
	printf("Cubic root of %lf is %lf\n",n, cubicRoot(n));
	
    return 0;
}

double diff(double n,double mid)
{
	if (n > (mid*mid*mid))
		return (n-(mid*mid*mid));
	else
		return ((mid*mid*mid) - n);
}

double cubicRoot(double n)
{
	double start = 0, end = n;

	double e = 0.0000001;
    int i = 0;
	while (1)
	{
		double mid = (start + end)/2;
		double error = diff(n, mid);

		if (error <= e)
			return mid;
            
		if ((mid*mid*mid) > n)
			end = mid;
		else
			start = mid;
	}
}
