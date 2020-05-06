#include <stdio.h>

int main(void)
{
	int n, i, m, j, ljb, r, tmp;
	int stu[50][5];
	double avg[50], cavg[5];
	while (scanf("%d %d", &n, &m) != EOF)
	{
		// 获取数据
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				scanf("%d", &stu[i][j]);
			}
		}
		// 算学生平均分
		for (i = 0; i < n; i++)
		{
			tmp = 0;
			for (j = 0; j < m; j++)
			{
				tmp = tmp + stu[i][j];
			}
			avg[i] =(double) tmp / m;
		}
		// 算科目平均分
		for (j = 0; j < m; j++)
		{
			tmp = 0;
			for (i = 0; i < n; i++)
			{
				tmp = tmp + stu[i][j];
				// printf("=%lf=",tmp);
			}
			cavg[j] = (double)tmp / n;
		}
		// 算ljb巨佬的个数
		ljb = 0;
		for (i = 0; i < n; i++)
		{
			r = 0;
			for (j = 0; j < m; j++)
			{
				if (stu[i][j] < cavg[j])
				{
					r = 1;
				}
			}
			if (r == 0)
			{
				ljb++;
			}
		}
		// 输出学生平均分
		for (i = 0; i < n; i++)
		{
			printf("%.2f", avg[i]);
			if (i != n - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
		// 输出课程平均分
		for (j = 0; j < m; j++)
		{
			printf("%.2f", cavg[j]);
			if (j != m - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
		printf("%d\n\n", ljb);
	}
	return 0;
}