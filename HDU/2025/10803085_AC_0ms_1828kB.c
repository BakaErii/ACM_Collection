#include <stdio.h>

int main(void)
{
	int i, j;
	char ljb[101], max;
	while (gets(ljb))
	{
		// 初始化变量
		max = 'A';
		// 获取最大
		for (i = 0; ljb[i] != '\0'; i++)
		{
			if (ljb[i] > max)
			{
				max = ljb[i];
			}
		}
		// 输出
		for (j = 0; ljb[j] != '\0'; j++)
		{
			printf("%c", ljb[j]);
			if (ljb[j] == max)
			{
				printf("(max)");
			}
		}
		printf("\n");
	}
	return 0;
}