/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-08 12:31:47
 * 又是一道数学题
 */

#include <stdio.h>

int main(void) {
	int n, m, i, isYes;
	while (scanf("%d %d", &n, &m) != EOF) {
		isYes = 0;
		//结束输入
		if (n == 0 && m == 0)
		{
			return 0;
		}
		//减少到一次循环 i+j=n j=n-i
		for (i = -10000; i < 10001; i++)
		{
			if (i * (n - i) == m)
			{
				isYes = 1;
				break;
			}
		}
		if (isYes == 1)
		{
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}