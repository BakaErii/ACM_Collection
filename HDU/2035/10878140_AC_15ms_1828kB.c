#include <stdio.h>

int main(void) {
	long long tmp;
	int a, b, i;
	while (scanf("%d %d", &a, &b) != EOF) {
		tmp = 1;
		if (a == 0 && b == 0) {
			return 0;
		}
		for (i = 0; i < b; i++)
		{
			tmp = tmp * a;
			tmp = tmp % 1000;
		}
		printf("%d\n", tmp );
	}
	return 0;
}