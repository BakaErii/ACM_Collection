/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-13 18:42:09
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int n, i;
	while (scanf("%d", &n) != EOF) {
		if (n == 0)
		{
			printf("no\n");
			continue;
		}
		if (n == 1)
		{
			printf("no\n");
			continue;
		}
		//made都是坑....鬼知道这么做...
		if ((n - 2) % 4 == 0)
		{
			printf("yes\n");
		}else{
			printf("no\n");
		}
	}
	return 0;
}