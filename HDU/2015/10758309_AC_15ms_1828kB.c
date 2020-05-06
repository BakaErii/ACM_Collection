#include <stdio.h>

int main(void)
{
	int n, m, i, count, j, k, tmp;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		j = 1;
		count = n / m;
		for (i = 0; i < count; i++)
		{
			tmp = 0;
			for (k = 0; k < m; k++)
			{
				tmp = tmp + j * 2;
				j++;
			}
			tmp = tmp / m;
			printf("%d", tmp);
			if (i != count - 1)
			{
				printf(" ");
			}
		}
		if (n % m != 0)
		{
			tmp = 0;
			count = n-j+1;
			for (i = 0; i <count; i++)
			{
				tmp = tmp + j * 2;
				j++;
			}
			tmp = tmp / i;
			printf(" %d", tmp);
		}
		printf("\n");
	}
	return 0;
}