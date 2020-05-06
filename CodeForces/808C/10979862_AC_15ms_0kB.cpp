/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-08 10:35:33
 */

#include <stdio.h>

int main(void) {
	int n, w, a[100], v[100], i, tmp, remain, tmpmax;
	while (scanf("%d %d", &n, &w) != EOF) {
		//初始化变量
		tmp = 0;
		//循环读入茶杯的容量 并计算茶杯中至少的水量 并判断是否满足最低标准
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
			if (a[i] % 2 == 1)
			{
				v[i] = a[i] / 2 + 1;
			} else {
				v[i] = a[i] / 2;
			}
			tmp = tmp + v[i];
		}
		if (tmp > w) {
			printf("-1\n");
			continue;
		}
		//让每个人都变得很♂爽:只允许多的欺负少的 a[x]>a[y] 但 v[y]<v[x]
		//此时w-tmp为剩余的水量
		remain = w - tmp;
		while (remain) {
			//循环找杯子最大的人
			tmp = 0;
			for (i = 0; i < n; i++)
			{
				if (a[tmp] < a[i])
				{
					tmp = i;
				}
			}
			//现在a[tmp]是最大的杯子 倒水
			while (a[tmp] != v[tmp]) {
				v[tmp]++;
				remain--;
				//判断是不是没水了 跳出循环
				if (remain == 0)
				{
					break;
				}
				continue;
			}
			//这个时候把a[tmp]设置为0 剔出循环
			a[tmp] = 0;
		}
		//输出
		for (i = 0; i < n; i++)
		{
			printf("%d", v[i] );
			if (i != n - 1)
			{
				printf(" ");
			}else{
				printf("\n");
			}
		}
	}
	return 0;
}