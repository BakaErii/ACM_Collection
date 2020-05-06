#include <stdio.h>

int main(void)
{
	long a, b;
	int i, line;
	scanf("%d", &line);
	for (i = 0; i < line; i++)
	{
		scanf("%ld %ld", &a, &b);
		if (a % b == 0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}