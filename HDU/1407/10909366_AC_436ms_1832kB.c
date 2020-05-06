#include <stdio.h>

int main(void) {
	int x, y, z, num, i, j, k;
	while (scanf("%d", &num) != EOF) {
		for (x = 1; x < 101; x++)
		{
			for (y = 1; y < 101; y++)
			{
				for (z = 1; z < 101; z++) {
					if (x * x + y * y + z * z == num)
					{
						printf("%d %d %d\n", x, y, z );
						goto End;
					}
				}
			}
		}
	End:;
	}
	return 0;
}