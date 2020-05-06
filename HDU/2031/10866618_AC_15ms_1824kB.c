#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, r, type, i;
	char ljb[233];
	while (scanf("%d %d", &n, &r) != EOF) {
		//两种情况
		type = 0;
		if (n < 0)
		{
			n = -n;
			itoa(n, ljb, r);
			type++;
		} else {
			itoa(n, ljb, r);
		}
		//替换大写字母
		for (i = 0; ljb[i] != '\0'; i++)
		{
			if (ljb[i] >= 97 && ljb[i] <= 122)
			{
				ljb[i] -= 32;
			}
		}
		//输出
		if (type != 0)
		{
			printf("-");
		}
		puts(ljb);
	}
	return 0;
}