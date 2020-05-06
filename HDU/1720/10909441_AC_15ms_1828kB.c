#include <stdio.h>

int main(void) {
	int a, b, tmp;
	while (scanf("%x %x", &a, &b) != EOF) {
		tmp = a + b;
		printf("%d\n", tmp );
	}
	return 0;
}