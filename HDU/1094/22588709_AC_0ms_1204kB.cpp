#include <stdio.h>

int main(void) {
	int sum, tmp, n;
	while (scanf("%d", &n)!=EOF) {
		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum );
	}
	return 0;
}