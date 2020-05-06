/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-15 11:50:25
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int c, n, i, j;
	unsigned long long tmp1, tmp2, tmp3, tmp;
	double result;
	scanf("%d", &c);
	for (i = 0; i < c; i++)
	{
		scanf("%d", &n);
		if (n == 1)
		{
			printf("0.00%%\n");
			continue;
		}
		if (n == 2)
		{
			printf("50.00%%\n");
			continue;
		}
		if (n > 2)
		{
			//总数
			tmp1 = 2;
			//上一次有效数据
			tmp2 = 1;
			//有效数据
			tmp3 = 2;
			for (j = 0; j < n - 2; j++)
			{
				tmp = tmp3;
				tmp3 = (tmp2 + tmp3) * (j + 3);
				tmp2 = tmp;
				tmp1 = tmp1 * (j + 3);
			}
			//输出
			result = (double)tmp2 / (double)tmp1;
			printf("%.2f%%\n", result*100 );
		}
	}
	return 0;
}