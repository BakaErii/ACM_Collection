#include <stdio.h>

int i, li, tmp, r;

int main(void)
{
	while (scanf("%d", &i) != EOF)
	{
		if (i != 0)
		{
			/* 初始化变量 */
			r = 0;
			for (li = 0; li < i; li++)
			{
				scanf("%d", &tmp);
				r = r + tmp;
			}
			printf("%d\n", r);
		}
	}
	return 0;
}