/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-10 15:51:43
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int n, i;
	unsigned long long tmpa, tmpb, r;
	while (scanf("%d", &n) != EOF) {
		//初始化变量
		r = 0L;
		tmpa = 1L;
		tmpb = 2L;
		if (n == 1)
		{
			printf("1\n");
		}
		if (n == 2)
		{
			printf("2\n");
		}
		if (n > 2)
		{
			for (i = 0; i < n - 2; i++)
			{
				r = tmpa + tmpb;
				tmpa = tmpb;
				tmpb = r;
			}
			printf("%llu\n", r );
		}
	}
	return 0;
}