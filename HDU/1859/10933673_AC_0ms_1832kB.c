/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-05 01:05:53
 */

#include <stdio.h>

int main(void) {
	int minx, miny, maxx, maxy, isEnd, isFirst, x, y;
	while (233) {
		//大循环
		//初始化变量
		minx = 233;
		miny = 233;
		maxx = -233;
		maxy = -233;
		isEnd = 0;
		isFirst = 1;
		while (233) {
			//小循环
			scanf("%d %d", &x, &y);
			//判断结束
			if (x == 0 && y == 0)
			{
				//判断全完了
				if (isFirst == 1)
				{
					isEnd = 1;
					break;
				}
				break;
			} else {
				isFirst = 0;
			}
			//赋值
			if (x < minx)
			{
				minx = x;
			}
			if (x > maxx)
			{
				maxx = x;
			}
			if (y < miny)
			{
				miny = y;
			}
			if (y > maxy)
			{
				maxy = y;
			}
		}
		//小循环的结束
		if (isEnd != 1)
		{
			printf("%d %d %d %d\n", minx, miny, maxx, maxy );
		} else {
			break;
		}
	}
	return 0;
}