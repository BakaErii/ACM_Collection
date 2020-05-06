#include <stdio.h>

int main(void)
{
	int a, b, rua, ha, i;
	while (scanf("%d", &ha) != EOF)
	{
		if (ha == 0)
		{
			scanf("%d", &rua);
			return 0;
		}
		scanf("%d", &rua);
		// 读初始
		scanf("%d", &a);
		if (rua < a)
		{
			printf("%d ", rua);
		}
		for (i = 0; i < ha - 1; i++)
		{
			printf("%d ", a);
			scanf("%d", &b);
			if (rua > a && rua < b)
			{
				printf("%d ", rua);
			}
			if (rua == b)
			{
				printf("%d ", rua);
			}
			a = b;
		}
		printf("%d\n", b);
	}
	return 0;
}