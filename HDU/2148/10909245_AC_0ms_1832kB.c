#include <stdio.h>

int main(void) {
	int t, n, k, x[1000], i, j, add, s;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		s = 0;
		add = 0;
		scanf("%d %d", &n, &k);
		for (j = 0; j < n; j++)
		{
			//循环输入
			scanf("%d", &x[j]);
			if (j + 1 == k)
			{
				s = x[j];
			}
		}
		for (j = 0; j < n; j++)
		{
			if (s < x[j])
			{
				add++;
			}
		}
		printf("%d\n",add );
	}
	return 0;
}