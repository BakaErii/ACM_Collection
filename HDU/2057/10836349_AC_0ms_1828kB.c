#include <stdio.h>

int main(void) {
	long long a, b, c;
	while (scanf("%llX%llX", &a, &b) != EOF) {
		c = a + b;
		if (c < 0)
		{
			c = -c;
			printf("-%llX\n", c);
		} else {
			printf("%llX\n", c );
		}
	}
	return 0;
}