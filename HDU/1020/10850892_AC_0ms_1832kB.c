#include <stdio.h>
#include <string.h>

int main(void) {
	int line, i, j, len, add;
	char ljb[10000], tmp;
	scanf("%d", &line);
	getchar();
	for (i = 0; i < line; i++)
	{
		gets(ljb);
		len = strlen(ljb);
		tmp = ljb[0];
		add = 1;
		for (j = 1; j < len; j++)
		{
			//相同
			if (tmp == ljb[j])
			{
				add++;
			}
			//不同
			if (tmp != ljb[j])
			{
				if (add != 1) {
					printf("%d", add );
				}
				printf("%c", tmp );
				add = 1;
				tmp = ljb[j];
			}
			//最后
			if (j == len - 1)
			{
				if (add != 1) {
					printf("%d", add );
				}
				printf("%c\n", tmp );
			}

		}
	}
	return 0;
}