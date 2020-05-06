#include <stdio.h>

int main(void) {
	int n, sum, tmp;
	while (scanf("%d", &n) != EOF) {
		sum = 0;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum );
	}
	return 0;
}