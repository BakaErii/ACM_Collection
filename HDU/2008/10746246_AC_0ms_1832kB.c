#include <stdio.h>

int main(void)
{
	int num, z, f, zero, i;
	float target;
	while (scanf("%d", &num))
	{
		if (num == 0)
		{
			return 0;
		}
		 z = 0;
		f = 0;
		zero = 0;
		for (i = 0; i < num; i++)
		{
			scanf("%f", &target);
			if (target > 0)
			{
				z = z + 1;
			}
			if (target < 0)
			{
				f = f + 1;
			}
			if (target == 0)
			{
				zero = zero + 1;
			}
		}
		printf("%d %d %d\n", f, zero, z);
	}
	return 0;
}