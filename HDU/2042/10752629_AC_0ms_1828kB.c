#include <stdio.h>

int main(void)
{
	int mie, i, n, nya, ha;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		mie = 3;
		scanf("%d", &nya);
		for (ha = 0; ha < nya; ha++)
		{
			mie = (mie - 1) * 2;
		}
		printf("%d\n", mie);
	}
	return 0;
}