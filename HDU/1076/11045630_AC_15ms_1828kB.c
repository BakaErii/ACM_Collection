/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-13 18:26:53
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int t, n, y, year, i, j;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &y, &n);
		//初始化变量
		year = 0;
		while (year != n) {
			if (y % 4 == 0 && y % 100 != 0)
			{
				year++;
				y++;
			} else {
				//特殊情况
				if (y % 400 == 0)
				{
					year++;
				}
				y++;
			}
		}
		printf("%d\n", --y );
	}
	return 0;
}