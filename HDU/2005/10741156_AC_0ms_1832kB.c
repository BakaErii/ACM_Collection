#include <stdio.h>

int main()
{
	int y, m, d, r, spe;
	while (scanf("%d/%d/%d", &y, &m, &d) != EOF)
	{
		spe = 0;
		r = 0;
		// 闰年
		if (y % 4 == 0 && y % 100 != 0)
		{
			spe = 1;
		}
		// 百闰年
		if (y % 400 == 0)
		{
			spe = 1;
		}
		// 二月
		if (m > 2)
		{
			r = r + 28;
			if (spe == 1)
			{
				r = r + 1;
			}
		}
		// 其他月
		r = r + (m - 1) * 30 + m / 2;
		if (m > 2)
		{
			r = r - 30;
		}
			// 日⊙∀⊙！
			r = r + d;
		printf("%d\n", r);
	}
	return 0;
}