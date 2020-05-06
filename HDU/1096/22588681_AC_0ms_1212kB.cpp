#include <stdio.h>

int main(void) {
	int t, n, tmp, sum;
	scanf("%d", &t);
	while (t--) {
		sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum );
		if (t != 0)
			printf("\n");
	}
	return 0;
}