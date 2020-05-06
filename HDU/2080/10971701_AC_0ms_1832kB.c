/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-07 16:59:51
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265359

int main(void) {
	double x1, y1, x2, y2, tmp;
	int line, i;
	scanf("%d", &line);
	for (i = 0; i < line; i++)
	{
		scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
		tmp = (atan2(y1, x1) - atan2(y2, x2)) * 180 / PI;
		if (tmp < 0)
		{
			tmp = -tmp;
		}
		if (tmp == -0)
		{
			tmp = 0;
		}
		printf("%.2lf\n", tmp );
	}
	return 0;
}