/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-09 21:47:52
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int n, m, i, j, tmpa, tmpb, r ;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		//初始化变量
		tmpa = 0;
		tmpb = 0;
		r = 0;
		scanf("%d", &m);
		//判断M=1的坑爹情况
		if (m == 1)
		{
			printf("0\n");
			continue;
		}
		//需要跨的台阶数:m-1
		m--;
		//走法数量=上次+上上次
		if (m == 1)
		{
			printf("1\n");
			continue;
		}
		if (m == 2) {
			printf("2\n");
			continue;
		}
		if (m > 2)
		{
			tmpa = 1;
			tmpb = 2;
			for (m -= 2, j = 0; j < m; j++)
			{
				r = tmpa + tmpb;
				tmpa = tmpb;
				tmpb = r;
			}
			printf("%d\n",r );
		}
	}
	return 0;
}