#include <stdio.h>

int main(void) {
	int t, sum, tmp, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			sum += tmp;
		}
		printf("%d\n", sum );
	}
	return 0;
}