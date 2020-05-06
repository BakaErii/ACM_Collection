#include <stdio.h>

int main(void)
{
	int tnum, i, money, r;
	while (scanf("%d", &tnum) != EOF)
	{
		if (tnum == 0)
		{
			return 0;
		}
		r = 0;
		for (i = 0; i < tnum; i++)
		{
			scanf("%d", &money);
			if (money >= 100)
			{
				r = r + money / 100;
				money = money % 100;
			}
			if (money >= 50)
			{
				r = r + money / 50;
				money = money % 50;
			}
			if (money >= 10)
			{
				r = r + money / 10;
				money = money % 10;
			}
			if (money >= 5)
			{
				r = r + money / 5;
				money = money % 5;
			}
			if (money >= 2)
			{
				r = r + money / 2;
				money = money % 2;
			}
			if (money >= 1)
			{
				r = r + money;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}