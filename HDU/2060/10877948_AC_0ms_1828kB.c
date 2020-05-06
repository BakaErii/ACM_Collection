#include <stdio.h>

int main(void)
{
	int line, ball_left, rball, oball, ps, os, s, i, j;
	scanf("%d", &line);
	for (i = 0; i < line; i++)
	{
		scanf("%d %d %d", &ball_left, &ps, &os);
		//初始化变量
		rball = 0;
		oball = 0;
		s = 0;
		//计算各个球的数量
		if (ball_left > 6)
		{
			rball = ball_left - 6;
			oball = 6;
		} else {
			oball = ball_left;
		}
		//计算最多得分
		if (rball != 0)
		{
			s = rball + 7 * rball + 2 + 3 + 4 + 5 + 6 + 7;
		} else {
			for (j = 0; j < oball; j++)
			{
				s = s + (7 - j);
			}
		}
		//测试输出
		//printf("[%d]\n", s );
		//比较
		if ((ps + s) >= os)
		{
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}