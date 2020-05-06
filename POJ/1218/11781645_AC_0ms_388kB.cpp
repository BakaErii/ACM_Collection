/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-30 18:24:48
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int T, N;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		printf("%d\n", (int)sqrt(N));
	}
	return 0;
}