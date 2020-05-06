#include <stdio.h>

int main(void) {
	int n, status, i;
	while (scanf("%d", &n) != EOF) {
		status = 0;
		for (i = 0; i < n; i++)
		{
			if (n % (i + 1) == 0)
			{
				switch (status) {
				case 0:
					status = 1;
					break;
				case 1:
					status = 0;
					break;
				}
			}
		}
		printf("%d\n", status );
	}
	return 0;
}