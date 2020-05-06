#include <stdio.h>

#define PI 3.1415927

int main()
{
	double r, result;
	while (scanf("%lf", &r) != EOF)
	{
		result = 0;
		result = PI*(4.0/3.0)*(r*r*r);
		printf("%.3lf\n",result);
	}
	return 0;
}