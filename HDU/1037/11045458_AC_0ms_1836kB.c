/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-13 18:14:40
 * #滑稽 没看懂
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int h1, h2, h3;
	while (scanf("%d %d %d", &h1, &h2, &h3) != EOF) {
		//判断哪个会撞
		if (h1 <= 168)
		{
			printf("CRASH %d\n", h1 );
			continue;
		}
		if (h2 <= 168)
		{
			printf("CRASH %d\n", h2 );
			continue;
		}
		if (h3 <= 168)
		{
			printf("CRASH %d\n", h3 );
			continue;
		}
		printf("NO CRASH\n");
	}
	return 0;
}