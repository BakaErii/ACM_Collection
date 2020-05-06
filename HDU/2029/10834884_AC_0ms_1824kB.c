#include <stdio.h>
#include <string.h>

int main(void) {
	int line, len, i, j	, r;
	char ljb[666];
	while (scanf("%d", &line) != EOF) {
		getchar();
		for (i = 0; i < line; i++)
		{
			r = 0;
			len = 0;
			gets(ljb);
			len = strlen(ljb);
			for (j = 0; j < len / 2; j++)
			{
				if (ljb[j] != ljb[len - j - 1])
				{
					r = 1;
				}
			}
			if (r == 1)
			{
				printf("no\n");
			} else {
				printf("yes\n");
			}
		}
	}
	return 0;
}