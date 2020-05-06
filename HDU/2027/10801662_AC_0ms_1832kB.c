#include <stdio.h>

int main(void) {
	int line, i, j, k, r[5];
	char nya[100];
	scanf("%d", &line);
	getchar();
	for (i = 0; i < line; i++)
	{
		for (k = 0; k < 5; k++)
		{
			r[k] = 0;
		}
		gets(nya);
		for (j = 0; nya[j] != '\0'; j++)
		{
			if (nya[j] == 'a')
			{
				r[0]++;
			}
			if (nya[j] == 'e')
			{
				r[1]++;
			}
			if (nya[j] == 'i')
			{
				r[2]++;
			}
			if (nya[j] == 'o')
			{
				r[3]++;
			}
			if (nya[j] == 'u')
			{
				r[4]++;
			}
		}
		printf("a:%d\n", r[0] );
		printf("e:%d\n", r[1] );
		printf("i:%d\n", r[2] );
		printf("o:%d\n", r[3] );
		printf("u:%d\n", r[4] );
		if (i != line - 1)
		{
			printf("\n");
		}
	}
	return 0;
}