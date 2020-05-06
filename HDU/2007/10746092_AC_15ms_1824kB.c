#include <stdio.h>

// ╯﹏╰腰好疼吖

int main(void)
{
	int m, n, i, x, y, tmp;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		x = 0;
		y = 0;
		if (m > n)
		{
			tmp = m;
			m = n;
			n = tmp;
		}
		 for (i = m; i <= n; i++)
		{
			if (i % 2 == 0)
			{
				x = x + i * i;
			}
			if (i % 2 == 1 || i % 2 == -1)
			{
				y = y + i * i * i;
			}
		}
		printf("%d %d\n", x, y);
	}
	return 0;
}