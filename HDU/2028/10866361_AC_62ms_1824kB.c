#include <stdio.h>

int main(void) {
	int n, num[233], max, r, i;
	while (scanf("%d", &n) != EOF) {
		//循环读入
		for (i = 0; i < n; i++)
		{
			scanf("%d", &num[i]);
		}
		//初始化变量
		max = num[0];
		for (i = 0; i < n; i++)
		{
			//寻找最大值
			if (num[i] > max) {
				max = num[i];
			}
		}
		//暴力运算
		while (1) {
			//计算是否能够全部整除
			r = 0;
			for (i = 0; i < n; i++)
			{
				if (max % num[i] != 0)
				{
					r = 1;
					break;
				}
			}
			//判断结果
			if (r == 0) {
				printf("%d\n", max );
				break;
			} else {
				max++;
			}
		}
	}
	return 0;
}