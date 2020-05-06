#include <stdio.h>

int main(void) {
	int x[101], y[101], n, i, j, tmp0, tmp1;
	float r;
	while (scanf("%d", &n) != EOF) {
		//结束输入
		if (n == 0)
		{
			return 0;
		}
		//初始化变量
		tmp0 = 0;
		tmp1 = 0;
		//循环读入
		for (i = 0; i < n; i++)
		{
			scanf("%d %d", &x[i], &y[i]);
		}
		//为最后一个赋值
		x[i] = x[0];
		y[i] = y[0];
		//进行循环计算
		for (i = 0; i < n; i++)
		{
			tmp0 = tmp0 + x[i] * y[i + 1];
		}
		for (i = 0; i < n; i++)
		{
			tmp1 = tmp1 + x[i + 1] * y[i];
		}
		r = tmp0 - tmp1;
		r = r / 2;
		printf("%.1f\n", r );
	}
	return 0;
}