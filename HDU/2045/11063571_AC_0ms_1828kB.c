/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-13 17:40:42
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	//tmp1*2+tmp2
	int n, i;
	unsigned long long  tmp1, tmp2, r;
	while (scanf("%d", &n) != EOF) {
		if (n == 1)
		{
			printf("3\n");
			continue;
		}
		if (n == 2 || n == 3)
		{
			printf("6\n");
			continue;
		}
		if (n > 3)
		{
			//初始化变量
			tmp1 = 6L;
			tmp2 = 6L;
			r = 0L;
			for (i = 0; i < n - 3; i++)
			{
				r = tmp1 * 2 + tmp2;
				tmp1 = tmp2;
				tmp2 = r;
			}
			printf("%llu\n", r );
		}
	}
	return 0;
}