#include <stdio.h>

int main(void)
{
	int a, b, r;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		r = a + b;
		printf("%d\n", r);
	}
	return 0;
}

/*如果提交成功了也不算数 学长dalao提供的思路 #手动滑稽*/