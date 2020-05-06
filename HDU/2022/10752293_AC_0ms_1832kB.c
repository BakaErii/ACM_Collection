#include <stdio.h>
#include <math.h>

int main(void)
{
	int m, n, x, y, s, tmpx, tmpy, tmps;
	while (scanf("%d %d", &m, &n) != EOF)
	{
		s = 0;
		x = 0;
		y = 0;
		// 行
		for (tmpx = 0; tmpx< m; tmpx++)
		{
			// 列
			for (tmpy = 0; tmpy< n; tmpy++)
			{
				// 获取分数
				scanf("%d", &tmps);
				if (abs(tmps) > abs(s))
				{
				    s=tmps;
				    x=tmpx+1;
				    y=tmpy+1;
				}
			}
		}
		printf("%d %d %d\n",x,y,s);
	}
	return 0;
}