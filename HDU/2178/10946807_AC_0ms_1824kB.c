/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-05 23:28:26
 * 喵喵喵？好像被我暴力推出来了
 */

#include <stdio.h>

int main(void) {
	int t, n , tmp, i, j;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &n);
		tmp = 1;
		for (j = 0; j < n; j++) {
			tmp = tmp * 2;
		}
		printf("%d\n", tmp - 1);
	}
	return 0;
}