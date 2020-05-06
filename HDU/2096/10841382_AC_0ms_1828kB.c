#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int line, a, b, r, i;
	scanf("%d", &line);
	for (i = 0; i < line; i++)
	{
		scanf("%d %d", &a, &b);
		if (a >= 100)
		{
			a = a % 100;
		}
		if (b >= 100)
		{
			b = b % 100;
		}
		r = a + b;
		if (r >= 100)
		{
			r = r % 100;
		}
		printf("%d\n", r);
	}
	return 0;
}