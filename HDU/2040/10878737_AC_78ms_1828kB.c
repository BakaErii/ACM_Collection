#include <stdio.h>

int main(void) {
	int line, a, b, i, j, tmp;
	scanf("%d", &line);
	for (i = 0; i < line; i++)
	{
		scanf("%d %d", &a, &b);
		//初始化变量
		tmp = 0;
		//分解并相加赋值给tmp
		for (j = 1; j < a; j++)
		{
			if ((a % j) == 0)
			{
				tmp += j;
			}
		}
		if (tmp == b)
		{
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}