/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-13 12:28:43
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int i, n;
	char r[233];
	while (scanf("%d", &n) != EOF) {
		//初始化变量
		i = 0;
		while (n != 0) {
			//数字加48为当前数字的ASCII码
			r[i] = n % 2 + 48;
			i++;
			n = n / 2;
		}
		//逆向输出
		for (i = i - 1; i > -1; i--)
		{
			printf("%c", r[i] );
		}
		printf("\n");
	}
	return 0;
}