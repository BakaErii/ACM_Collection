/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-13 18:01:47
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int n, time, floor, tmp, i;
	while (scanf("%d", &n) != EOF) {
		//初始化变量
		time = 0;
		floor = 0;
		//输入结束
		if (n == 0)
		{
			return 0;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d", &tmp);
			//判断上下楼
			if (tmp >= floor)
			{
				time += (tmp - floor) * 6;
				time += 5;
				floor = tmp;
			} else {
				time += (floor - tmp) * 4;
				time += 5;
				floor = tmp;
			}
		}
		printf("%d\n", time );
	}
	return 0;
}