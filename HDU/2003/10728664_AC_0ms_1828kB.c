#include <stdio.h>

int main()
{
	double a, r;
	while (scanf("%lf", &a) != EOF)
	{
		if (a > 0)
		{
			r = a;
		}
		if (a < 0)
		{
			r = -a;
		}
		if (a = 0)
		{
			r = 0.00;
		}
		printf("%.2lf\n", r);
	}
	return 0;
}