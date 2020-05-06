//集合相减定义 属于A但不属于B

#include <stdio.h>

int main(void) {
	int m, n, i, j, r, tmpr, tmp;
	int a[100], b[100], ljb[100];
	while (scanf("%d %d", &n, &m) != EOF) {
		//输入结束
		if (n == 0 && m == 0)
		{
			return 0;
		}
		//读入数据
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d", &b[i]);
		}
		//用a比较b
		/*当r=0时无元素 r!=0时存在输出*/
		r = 0;
		for (i = 0; i < n; i++)
		{
			tmpr = 0;
			for (j = 0; j < m; j++)
			{
				if (a[i] == b[j])
				{
					tmpr = 1;
					break;
				}
			}
			if (tmpr == 0)
			{
				ljb[r] = a[i];
				r++;
			}
		}
		//判断无输出
		if (r == 0)
		{
			printf("NULL\n");
		} else {
			//冒泡排序
			for (i = 0; i < r - 1; i++)
			{
				for (j = 0; j < r - 1; j++)
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
			for (i = 0; i < r; i++)
			{
				printf("%d ", ljb[i]);
			}
			printf("\n");
		}
	}
	return 0;
}