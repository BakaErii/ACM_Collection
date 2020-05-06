#include <stdio.h>

int main(void) {
	int t, line, x, y, i, add;
	scanf("%d", &t);
	for (i = 0; i < t; i++)
	{
		scanf("%d", &line);
		for (y = 0; y < line; y++)
		{
			add = 0;
			for (x = 0; x < line; x++)
			{
				if (x == y || x + y == line - 1) {
					printf("X");
					add++;
					if (y == line/2)
					{
						printf("\n");
						break;
					}
					if (add == 2)
					{
						printf("\n");
						break;
					}
				} else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	return 0;
}