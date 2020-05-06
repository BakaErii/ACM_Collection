/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-12 20:31:35
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int n, i, a, b, j, times;
	unsigned long long r, tmp1, tmp2;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);
		//判断需要爬最多几个格子(次)
		times = b - a;
		if (times == 1)
		{
			printf("1\n");
			continue;
		}
		if (times == 2)
		{
			printf("2\n");
			continue;
		}
		//初始化变量
		tmp1 = 1L;
		tmp2 = 2L;
		r = 0L;
		if (times > 2)
		{
			for (j = 0; j < times - 2; j++)
			{
				r = tmp1 + tmp2;
				tmp1 = tmp2;
				tmp2 = r;
			}
			printf("%llu\n", r );
		}
	}
	return 0;
}