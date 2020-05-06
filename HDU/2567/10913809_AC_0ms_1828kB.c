#include <stdio.h>
#include <string.h>

int main(void) {
	int n, len, i, j, k;
	char sa[50], sb[50];
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets(sa);
		gets(sb);
		len = strlen(sa);
		for (j = 0; sa[j] != '\0'; j++)
		{
			if (j == len / 2)
			{
				for (k = 0; sb[k] != '\0'; k++)
				{
					printf("%c", sb[k]);
				}
				printf("%c", sa[j] );
			} else {
				printf("%c", sa[j] );
			}
		}
		printf("\n");
	}
	return 0;
}