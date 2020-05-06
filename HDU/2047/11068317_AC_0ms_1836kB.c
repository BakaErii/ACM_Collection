/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-14 19:12:12
 * 好想吃牛肉干....
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int n,i;
	//0=E 1=O 2=F
	unsigned long long r[3], tmp;
	while (scanf("%d", &n) != EOF) {
		//心疼校长 这牛肉干一定很硬
		//初始化变量
		r[0] = 1;
		r[1] = 1;
		r[2] = 1;
		tmp = 3;
		for (i = 0; i < n - 1; i++)
		{
			r[1] = tmp - r[1];
			r[0] = tmp;
			r[2] = tmp;
			tmp = r[0] + r[1] + r[2];
		}
		printf("%llu\n", tmp );
	}
	return 0;
}