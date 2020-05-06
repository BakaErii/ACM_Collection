#include <stdio.h>

int main(void) {
	int i, j, line, classnum, r;
	float c, s, gpa, ci;
	char name[30];
	while (scanf("%d", &line) != EOF) {
		for (i = 0; i < line; i++)
		{
			scanf("%d", &classnum);
			c = 0;
			ci = 0;
			r = 0;
			s = 0;
			gpa = 0;
			for (j = 0; j < classnum; j++)
			{
				getchar();
				scanf("%s", &name);
				scanf("%f", &c);
				ci = ci + c;
				scanf("%f", &s);
				if (s < 60) {
					r = 1;
				}
				gpa = gpa + c * s;
				// printf("[%f]\n", gpa );
			}
			gpa = gpa / ci;
			if (r == 1) {
				printf("Sorry!\n");
			} else {
				printf("%.2f\n", gpa );
			}
			if (i != line - 1) {
				printf("\n");
			}
		}
	}
	return 0;
}