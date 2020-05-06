#include <stdio.h>

// QwQ宝宝不想军训丫 ╯﹏╰

int main(void)
{
	int num, i, r, fuck;
	while(scanf("%d", &num) != EOF)
	{
		r = 1;
		 for (i = 0; i < num; i++)
		{
			scanf("%d", &fuck);
			if (fuck % 2 != 0)
			{
				r = r * fuck;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}