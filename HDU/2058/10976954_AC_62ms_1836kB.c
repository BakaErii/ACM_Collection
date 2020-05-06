/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-07 23:09:52
 */

//求和 求和 求和

#include <stdio.h>
#include <math.h>

int main(void) {
	unsigned long long n, m, tmp, i, j, a;
	double maxi;
	while (scanf("%llu %llu", &n, &m) != EOF)
	{
		if (n == 0 && m == 0)
		{
			return 0;
		}
		//求最多的项数
		maxi = sqrt((double)m * 2);
		for (i = maxi; i > 0; i--)
		{
			a =  m / i -  (i - 1)  / 2;
			if ((a + a + i - 1)*i / 2 == m)
			{
				printf("[%llu,%llu]\n", a, a + i - 1);
			}
		}
		printf("\n");
	}
	return 0;
}