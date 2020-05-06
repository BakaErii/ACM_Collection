#include <stdio.h>

int main(void) {
	int add, time, i, isFinish;
	double vul, d;
	while (scanf("%lf %lf", &vul, &d) != EOF) {
		//初始化变量
		add = 1;
		time = 0;
		isFinish = 0;
		while (233) {
			//滴下N滴
			for (i = 0; i < add; i++)
			{
				vul = vul - d;
				time++;
				//判断滴完
				if (vul <= 0)
				{
					//结束循环
					isFinish = 1;
					break;
				}
			}
			if (isFinish == 1)
			{
				break;
			}
			add++;
			//停一下
			time++;
		}
		//输出结果
		printf("%d\n", time );
	}
	return 0;
}