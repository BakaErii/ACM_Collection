#include <stdio.h>

int line, r, tmp, li, num, numi;

int main(void)
{
	scanf("%d", &line);
	for (li = 0; li < line; li++)
	{
		scanf("%d", &num);
		r = 0;
		for (numi = 0; numi < num; numi++)
		{
			scanf("%d", &tmp);
			r = r + tmp;
		}
		printf("%d\n", r);
	}
	return 0;
}