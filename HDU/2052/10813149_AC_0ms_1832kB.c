#include <stdio.h>

int main(void) {
	int width, height, i, j;
	while (scanf("%d %d", &width, &height) != EOF) {
		//输出顶行
		printf("+");
		for (i = 0; i < width; i++) {
			printf("-");
		}
		printf("+\n");
		//输出中间的
		for (j = 0; j < height; j++) {
			printf("|");
			for (i = 0; i < width; i++)
			{
				printf(" ");
			}
			printf("|\n");
		}
		//输出最后一行
		printf("+");
		for (i = 0; i < width; i++) {
			printf("-");
		}
		printf("+\n\n");
	}
	return 0;
}