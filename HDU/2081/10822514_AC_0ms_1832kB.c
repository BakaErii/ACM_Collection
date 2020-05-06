#include <stdio.h>

int main(void)
{
	int line, i, j;
	char ljb[11];
	scanf("%d", &line);
	getchar();
	for (i = 0; i < line; i++)
	{
		gets(ljb);
		// 取后5位
		// 为什么我们学校就没小号呢
		printf("6");
		for (j = 6; j < 11; j++)
		{
			printf("%c", ljb[j]);
		}
		printf("\n");
	}
	return 0;
}