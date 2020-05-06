#include <stdio.h>

int main(void) {
	int n, m, i, j, r, add, tmp;
	int na[10000], ma[10000], ljb[20000];
	while (scanf("%d %d", &n, &m) != EOF) {
		//初始化变量
		add = 0;
		//循环读入
		for (i = 0; i < n; i++)
		{
			scanf("%d", &na[i]);
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d", &ma[i]);
		}
		//用m比对n,结果放在ljb
		for (i = 0; i < n; i++)
		{
			r = 0;
			for (j = 0; j < m; j++)
			{
				if (ma[j] == na[i])
				{
					r = 1;
				}
			}
			if (r == 0)
			{
				ljb[add] = na[i];
				add++;
			}
		}
		//把m都放在ljb里
		for (i = 0; i < m; i++)
		{
			ljb[add] = ma[i];
			add++;
		}
		//冒泡排序咯
		for (i = 0; i < add - 1; i++)
		{
			for (j = 0; j < add - 1; j++)
			{
				if (ljb[j] > ljb[j + 1])
				{
					tmp = ljb[j + 1];
					ljb[j + 1] = ljb[j];
					ljb[j] = tmp;
				}
			}
		}
		//输出
		for (i = 0; i < add; i++)
		{
			printf("%d", ljb[i] );
			if (i != add - 1)
			{
				printf(" ");
			} else {
				printf("\n");
			}
		}
	}
	return 0;
}
