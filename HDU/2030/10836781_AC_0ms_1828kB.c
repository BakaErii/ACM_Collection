#include <stdio.h>

int main(void) {
	int line, i, j, r;
	char ljb[2333];
	scanf("%d", &line);
	getchar();
	for (i = 0; i < line; i++)
	{
		gets(ljb);
		r = 0;
		for (j = 0; ljb[j] != '\0'; j++)
		{
			if (ljb[j] < 0) {
				r++;
			}
		}
		r = r / 2;
		printf("%d\n", r );
	}
	return 0;
}