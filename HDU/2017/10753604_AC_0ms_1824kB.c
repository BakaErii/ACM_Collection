#include <stdio.h>

int main(void)
{
	int line, r, i, j;
	char nya[233];
	scanf("%d", &line);
	// 去回车
	getchar();
	for (i = 0; i < line; i++)
	{
		r = 0;
		for (j = 0; j < 233; j++)
		{
			// 获取字符
			nya[j] = getchar();
			// 数字ascii码48~57
			if (nya[j] >= 48 && nya[j] <= 57)
			{
				r++;
			}
			// 换行结束
			if (nya[j] == '\n')
			{
				break;
			}
		}
		printf("%d\n",r);
	}
	return 0;
}