/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-18 20:00:47
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int n, m, i, flag;
	int array[100];
	while (~scanf("%d %d", &n, &m)) {
		flag = 0;
		if (n == 0 && m == 0)
			return 0;
		for (i = 0; i < n; i++)
			scanf("%d", &array[i]);
		for (i = 0; i < n; i++)
		{
			if (flag == 0)
				if (m < array[i]) {
					printf("%d ", m );
					flag = 1;
				}
			printf("%d", array[i]);
			if (i != n - 1)
				printf(" ");
		}
		if (flag == 0)
			printf("%d", m );
		printf("\n");
	}
	return 0;
}