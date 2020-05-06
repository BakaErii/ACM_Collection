#include <stdio.h>

int main(void)
{
	int num[99], i, min, minp, n;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			return 0;
		}
		// 循环读入
		for (i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}
		// 初始化变量
		min = num[0];
		minp = 0;
		// 判断最小值数值及位置
		for (i = 0; i < n; i++)
		{
			if (num[i] < min)
			{
				min = num[i];
				minp = i;
			}
		}
		// 交换位置
		num[minp] = num[0];
		num[0] = min;
		// 输出数组
		for (i = 0; i < n; i++)
		{
			printf("%d", num[i]);
			if (i != n - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}