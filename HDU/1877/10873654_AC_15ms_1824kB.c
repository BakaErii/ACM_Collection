#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m, a, b;
	long tmp;
	char ljb[233];
	while (scanf("%d", &m) != EOF) {
		//输入结束
		if (m == 0)
		{
			return 0;
		}
		//获取a,b
		scanf("%d %d", &a, &b);
		//计算输出
		tmp = a + b;
		itoa(tmp, ljb, m);
		puts(ljb);
	}
	return 0;
}