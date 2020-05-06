#include <stdio.h>

int main(void) {
	int line, i, j;
	int num[31][31];
	//初始化数组
	for (i = 0; i < 31; i++) {
		for (j = 0; j < 31; j++)
		{
			num[i][j] = 1;
		}
	}
	//生成杨辉三角二维数组
	for (i = 1; i < 31; i++)
	{
		/*生成每行(从第二行算起)*/
		for (j = 0; j < i ; j++)
		{
			num[i][j + 1] = num[i - 1][j] + num[i - 1][j + 1];
		}
	}
	//获取输出
	while (scanf("%d", &line) != EOF) {
		//打印首行
		printf("1\n");
		for (i = 0; i < line - 1; i++)
		{
			//从第二开始打印
			for (j = 0; j < i + 2; j++)
			{
				printf("%d", num[i][j] );
				if (j != i + 1)
				{
					printf(" ");
				} else {
					printf("\n");
				}
			}
		}
		//换行
		printf("\n");
	}
	return 0;
}