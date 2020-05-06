/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-11 17:16:38
 * #滑稽 试试新东西
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	struct tv {
		//开始时间
		int tis;
		//结束时间
		int tie;
		//花费时间
		int sti;
	};
	struct tv play[100];
	struct tv tmp;
	int line, i, j, time, watch;
	while (scanf("%d", &line) != EOF) {
		//输入结束
		if (line == 0)
		{
			return 0;
		}
		//循环读入
		for (i = 0; i < line; i++)
		{
			scanf("%d %d", &play[i].tis, &play[i].tie);
			play[i].sti = play[i].tie - play[i].tis;
		}
		//排序 结束时间由低到高排列
		for (i = 0; i < line - 1; i++) {
			for (j = 0; j < line - 1; j++)
			{
				if (play[j].tie > play[j + 1].tie)
				{
					tmp = play[j];
					play[j] = play[j + 1];
					play[j + 1] = tmp;
				}
			}
		}
		//调试输出
		// for (i = 0; i < line; i++)
		// {
		// 	printf("%d %d %d\n", play[i].tis, play[i].tie, play[i].sti );
		// }
		//利用现在时间判断是否继续循环 结束时间减去花费时间看是否允许观看 最优选择
		//初始化变量
		time = 0;
		watch = 0;
		for (i = 0; i < line; i++)
		{
			if (play[i].tie >= time && play[i].tis >= time)
			{
				//emmmm...突然发现并不需要计算花费时间....
				time=play[i].tie;
				watch++;
			}
		}
		printf("%d\n",watch );
	}
	return 0;
}