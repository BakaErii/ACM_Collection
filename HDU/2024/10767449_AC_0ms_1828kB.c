#include <stdio.h>

int main(void)
{
	int line, i, j, r, tmp;
	char nya[49];
	while (scanf("%d", &line) != EOF)
	{
		//消除换行
		getchar();
		for (i = 0; i < line; i++)
		{
			r = 0;
			for (j = 0; j < 50; j++)
			{
				nya[j] = getchar();
				//发现换行直接退出
				if (nya[j] == '\n')
				{
					break;
				}
				//判断空格
				if (nya[j] == 32) {
					r = 1;
				}
				//判断标识符名称
				if (((nya[j] >= 48 && nya[j] <= 57) || (nya[j] >= 65 && nya[j] <= 90)) || ((nya[j] >= 97 && nya[j] <= 122) || nya[j] == 95))
				{
					//do nothing
				}
				else {
					r = 1;
				}
			}
			//判断首位数字
			if (nya[0] >= 48 && nya[0] <= 57)
			{
				r = 1;
			}
			switch (r) {
			case 1:
				printf("no\n");
				break;
			case 0:
				printf("yes\n");
				break;
			}
		}
	}
	return 0;
}