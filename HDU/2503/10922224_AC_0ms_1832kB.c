#include <stdio.h>

int main(void) {
	int line, a, b, c, d, e, f, tmp, big, s, r, i;
	scanf("%d", &line);
	for (i = 0; i < line; i++)
	{
		//初始化变量
		tmp = 1;
		r = 1;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		f = b * d;
		e = a * d + b * c;
		//暴力nmp 都TLE了 辗转相除
		//赋值 big为大数 s为小数
		if (f > e)
		{
			big = f;
			s = e;
		} else {
			big = e;
			s = f;
		}
		while (r != 0) {
			//辗转相除取余r
			r = big % s;
			if (r == 0)
			{
				tmp = s;
				break;
			} else {
				//made...自己理解错能怪谁
				big = s;
				s = r;
				continue;
			}
		}
		//此时tmp为最大公约数
		f = f / tmp;
		e = e / tmp;
		printf("%d %d\n", e, f );
	}
	return 0;
}