/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-13 19:43:30
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	//emmmmmm
	int n, i, tmp, tmpi;
	int num[100000] ;
	while (scanf("%d", &n) != EOF) {
		//初始化数组
		for (i = 0; i < 100000; i++)
		{
			num[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			num[tmp]++;
		}
		tmp = 0;
		tmpi = 0;
		for (i = 0; i < 10001; i++)
		{
			if (num[i] > tmp) {
				tmp = num[i];
				tmpi = i;
			}
		}
		printf("%d\n", tmpi);
	}
	return 0;
}