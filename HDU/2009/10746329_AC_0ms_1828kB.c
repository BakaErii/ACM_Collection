#include <stdio.h>
#include <math.h>

int main(void)
{
	int n, m, i;
	float r,num;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		r = n;
		num=n;
		for (i = 0; i < m - 1; i++)
		{
		    num=sqrt(num);
			r = r + num;
		}
		printf("%.2f\n", r);
	}
	 return 0;
}