#include <stdio.h>

int main(void) {
	//s的位数为当前位置 s[i]的值为编号
	int s[5000];
	int n, line, tmp, i, j, pep, pleft, add;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		//取得人数
		scanf("%d", &pep);
		//初始化数组
		for (j = 0; j < pep; j++)
		{
			s[j] = j + 1;
		}
		while (233) {
			//第一次报数
			pleft = pep;
			add = 0;
			//判断是否结束
			if (pep <= 3)
			{
				break;
			}
			for (j = 0; j < pleft; j++)
			{
				if ((j + 1) % 2 != 0)
				{
					s[add] = s[j];
					add++;
				} else {
					pep--;
				}
			}
			//判断是否结束
			if (pep <= 3)
			{
				break;
			}
			//第二次报数
			pleft = pep;
			add = 0;
			for (j = 0; j < pleft; j++)
			{
				if ((j + 1) % 3 != 0)
				{
					s[add] = s[j];
					add++;
				} else {
					pep--;
				}
			}
			//判断是否结束
			if (pep <= 3)
			{
				break;
			}
		}
		//输出结果
		for (j = 0; j < pep; j++)
		{
			printf("%d", s[j] );
			if (j != pep - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}