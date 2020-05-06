#include <stdio.h>

int main(void)
{
	// x<y
	// r==0 ok r==1 no
	int x, y, n, i, count, r, ii;
	while (scanf("%d %d", &x, &y) != EOF)
	{
		if (x == 0 && y == 0)
		{
			return 0;
		}
		 r = 0;
		for (i = x; i < y + 1; i++)
		{
			count = i * i + i + 41;
			for (ii = 2; ii < y; ii++)
			{
				if (count % ii == 0)
				{
					r = 1;
				}
			}
		}
		switch (r)
		{
		case 0:
			printf("OK\n");
			break;
		case 1:
			printf("Sorry\n");
			break;
		}
	}
	return 0;
}