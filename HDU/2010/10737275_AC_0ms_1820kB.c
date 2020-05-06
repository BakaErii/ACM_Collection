#include <stdio.h>

int main(void)
{
	int m, n, isnum, i, g, s, b;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		isnum = 0;
		for (i = m; i < n + 1 ; i++)
		{
			g = i % 10;
			s = i / 10 % 10;
			b = i / 100;
			if (i == g * g * g + b * b * b + s * s * s)
			{
				if (isnum != 0)
				{
					printf(" ");
				}
				printf("%d", i);
				isnum++;
			}
		}
		if (isnum == 0)
		{
			printf("no\n");
		}
		else
		{
			printf("\n");
		}
	}
	return 0;
}