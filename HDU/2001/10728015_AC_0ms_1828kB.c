#include <stdio.h>
#include <math.h>

int main(void)
{
	float x1, x2, y1, y2;
	float r;
	while (scanf("%f %f %f %f", &x1, &y1, &x2, &y2) != EOF)
	{
		r = 0;
		r = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		printf("%.2f\n", r);
	}
	return 0;
}