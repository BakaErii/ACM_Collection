#include <stdio.h>

int main(void) {
	char fuck[233];
	double num, price, result;
	result = 0;
	while (scanf("%s %lf %lf", &fuck, &num, &price) != EOF) {
		getchar();
		result = result + price * num;
	}
	printf("%.1f\n", result );
	getchar();
	return 0;
}