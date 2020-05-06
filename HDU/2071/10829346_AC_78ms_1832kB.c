#include <stdio.h>

int main(void) {
	int classnum, stunum, i, j;
	float max, tmp;
	while (scanf("%d", &classnum) != EOF) {
		for (i = 0; i < classnum; i++) {
			max = 0;
			scanf("%d", &stunum);
			for (j = 0; j < stunum; j++) {
				scanf("%f", &tmp);
				if (tmp > max)
				{
					max = tmp;
				}
			}
			printf("%.2f\n", max );
		}
	}
	return 0;
}