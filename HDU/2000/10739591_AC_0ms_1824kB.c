#include <stdio.h>

int main(void)
{
	char i1, i2, i3, tmp;
	while (scanf("%1c%1c%1c", &i1, &i2, &i3) != EOF)
	{
		// 消除换行回车
		getchar();
		if (i1 > i2)
		{
			tmp = i1;
			i1 = i2;
			i2 = tmp;
		}
		if (i2 > i3)
		{
			tmp = i2;
			i2 = i3;
			i3 = tmp;
		}
		if (i1 > i2)
		{
			tmp = i1;
			i1 = i2;
			i2 = tmp;
		}
		 printf("%c %c %c\n", i1, i2, i3);
	}
	return 0;
}