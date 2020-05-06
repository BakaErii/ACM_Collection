#include <stdio.h>

int main(void)
{
	int day, num, i;
	while (scanf("%d", &day) != EOF)
	{
		// day=2~29
		num = 1;
		for (i = 0; i < day - 1; i++)
		{
			num = (num + 1) * 2;
		}
		printf("%d\n", num);
	}
	return 0;
}