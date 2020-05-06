#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int l, i, ljb;
	double a,b,c;
	scanf("%d", &l);
	for (i = 0; i < l; i++)
	{
		//获取三条边
		scanf("%lf %lf %lf", &a, &b, &c);
		//计算部分
		//初始化变量
		ljb = 1;
		//任意两边之和大于第三边
		if (!(a + b > c && a + c > b && b + c > a))
		{
			ljb = 0;
		}
		//输出
		if (ljb == 0)
		{
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
}